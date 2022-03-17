//TETRIS_2022

#ifndef _RECORD_
#define _RECORD_

class Record { ///Класс, в котором хранится рекорд 1-го человека
public:
    string person_name; ///nickname
    int score;          ///Счет

    Record() : person_name("LOX"), score(0) {}          ///Нулевой конструктор
    Record(string n, int s): person_name(n), score(s) {}///Нормальный конструктор
    bool operator< (const Record& r2) {
        return score < r2.score;
    }
    bool operator> (const Record& r2) {
        return score > r2.score;
    }
    bool operator== (const Record& r2) {
        return score == r2.score;
    }
    bool operator<= (const Record& r2) {
        return score <= r2.score;
    }
    bool operator>= (const Record& r2) {
        return score >= r2.score;
    }
    bool operator!= (const Record& r2) {
        return score != r2.score;
    }
    friend ofstream& operator<< (ofstream& out, const Record& r) {
        out << r.person_name << " " << r.score << "\n";
        return out;
    }
    friend ifstream& operator>> (ifstream& in, Record& r) {
        in >> r.person_name >> r.score;
        return in;
    }
    friend ostream& operator<< (ostream& out, const Record& r) {
        out << r.person_name << " " << r.score << "\n";
        return out;
    }
    friend istream& operator>> (istream& in, Record& r) {
        in >> r.person_name >> r.score;
        return in;
    }
    Record& operator= (const Record r) {
        person_name = r.person_name;
        score = r.score;
        return *this;
    }
};
vector<Record> records; ///Массив всех рекордов(максимум 9)

bool cmp(Record A, Record B); ///Компаратор
void records_load();          ///Загружает рекорды из файла "records.txt"
void records_save();          ///Сохраняет 8 рекордов в файл "records.txt"
void record_add(Record r);    ///Добавление нового рекорда
void records_draw();          ///Отрисовка всех рекордов
void open_records();          ///Открытие <<Вкладки>> рекордов

bool cmp(Record A, Record B) {
    return A > B;
}

void records_load() {
    ifstream in;
    in.open("records.txt");
    Record t;
    while(in >> t) {
        records.push_back(t);
        if (records.size() == 8)
            break;
    }
    sort(records.begin(), records.end(), cmp);
    in.close();
}

void records_save () {
    ofstream out;
    out.open("records.txt");
    for (int i = 0; i < min((int)records.size(), 8); i++) {
        out << records[i];
    }
    out.close();
}

void record_add(Record r) {
    records.push_back(r);
    sort(records.begin(), records.end(), cmp);
}

void records_draw() {
    txSelectFont ("Serifiqo 4F Free Capitals", 35, 10, 1000);
    txSetFillColor(RGB(150, 150, 150));
    txClear();
    txSetColor(TX_BLACK);
    txDrawText(0, 50, 1080, 110, "Records:");
    txSetTextAlign(TA_LEFT);
    for (int i = 0; i < min(8, (int) records.size()); i++) {
        char str_score[10];
        sprintf(str_score, "%d", records[i].score);
        txDrawText(100, 100 + i * 70 + 50, 500, 160 + i * 70  + 50, records[i].person_name.c_str(), DT_WORD_ELLIPSIS );
        txDrawText(100 + 500, 100 + i * 70  + 50, 500 + 500, 160 + i * 70  + 50, str_score, DT_WORD_ELLIPSIS);
        sprintf(str_score, "%d:", i + 1);
        txDrawText(40 + 10, 100 + i * 70 + 44 - 4, 80 + 10, 160 + i * 70  + 48 - 4, str_score);
    }
}

void open_records() {
    txSetFillColor(RGB(150, 150, 150));
    txClear();
    Button Exit({1011 - 3 , 3 - 3}, {1075 + 5, 67 + 5},
                    "Menu", TX_NULL, TX_BLACK);
    records_draw();
    Exit.draw();
    while(!Exit.get());
    while(GetAsyncKeyState(VK_LBUTTON));
}
/*int main() {

    srand(time(NULL));
    Record p("Me", rand() % 10000);



} */
#endif
