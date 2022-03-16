//TETRIS_2022

#ifndef _BASE_
#define _BASE_
#include <map>
#include <vector>
#include <TXLib.h>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#define BLOCK_SIZE 36
#define X_LEFT 360
#define WIDTH 10 * BLOCK_SIZE
#define Y_UP 0
#define HEIGHT 20 * BLOCK_SIZE
#define AREA_Y_SIZE 23
#define AREA_X_SIZE 16

using namespace std;

enum Figure_type {LINE,
             L_SHAPED1,
             L_SHAPED2,
             SQUARE,
             Z_SHAPED1,
             Z_SHAPED2,
             T_SHAPED,
             NOT_FIGURE};
enum Figure_state {OUT_OF_AREA,
                   STATIC,
                   MOVE};
enum Key_type {
             KA,
             KB,
             KC,
             KD,
             KE,
             KF,
             KG,
             KH,
             KI,
             KJ,
             KK,
             KL,
             KM,
             KN,
             KO,
             KP,
             KQ,
             KR,
             KS,
             KT,
             KU,
             KV,
             KW,
             KX,
             KY,
             KZ,
             KUP,
             KDOWN,
             KLEFT,
             KRIGHT,
             KRMB,
             KLMB,
             KALT,
             KSHIFT,
             KCTRL,
             KSPACE,
             KNULL};

struct Point {
    double x;
    double y;
};

map<Figure_type, map<int, vector<Point>>> dict; ///Словарь, который по типу фигуры и ее повороту выдает массив точек,
                                                ///Где координаты точки - это смещение в блоках до центра опрделенного
                                                ///Квадрата фигуры
map<Figure_type, Point> start_pos;              ///Словарь стартовых координат каждой фигуры
map <Key_type, string> key_dict;
map <string, Key_type> reverse_key_dict;
vector<COLORREF> useful_colors;                 ///Массив всех цветов, пригодных для использования
vector<vector<pair<bool, COLORREF>>> static_arr (AREA_Y_SIZE,
                                     vector<pair<bool, COLORREF>>
                                     (AREA_X_SIZE, {1, TX_BLACK}));     ///Массив статичных блоков
vector<Figure_type> figure_type_arr;                                    ///Массив типов фигур


Key_type rl = KQ;
Key_type rr = KE;
Key_type ml = KA;
Key_type md = KS;
Key_type mr = KD;
Key_type h  = KR;
void build ();                                                          ///Заполняет все что можно заполнить
void sqr_draw(Point p, COLORREF cl, double s);                                    ///Рисует квадрат в заданной точке и заданного цвета (с черным краем)
void static_draw();                                                     ///Рисует статичные блоки
void settings_save();
void settings_load();
void settings_print();
void settings_default();

void settings_save() {
    ofstream out;
    out.open("save.txt");
    out << key_dict[rl] << "\n";
    out << key_dict[rr] << "\n";
    out << key_dict[ml] << "\n";
    out << key_dict[mr] << "\n";
    out << key_dict[md] << "\n";
    out << key_dict[h] << "\n";
    out.close();
}

void settings_load() {
    ifstream in;
    in.open("save.txt");
    if (!in.is_open())
        return;
    string key_name;
    getline(in, key_name);
    rl = reverse_key_dict[key_name];
    getline(in, key_name);
    rr = reverse_key_dict[key_name];
    getline(in, key_name);
    ml = reverse_key_dict[key_name];
    getline(in, key_name);
    mr = reverse_key_dict[key_name];
    getline(in, key_name);
    md = reverse_key_dict[key_name];
    getline(in, key_name);
    h = reverse_key_dict[key_name];
}

void settings_print() {
    cout << "ROTATE LEFT - " << key_dict[rl] << "\n";
    cout << "ROTATE RIGHT - " << key_dict[rr] << "\n";
    cout << "MOVE LEFT - " << key_dict[ml] << "\n";
    cout << "MOVE RIGHT - " << key_dict[mr] << "\n";
    cout << "MOVE DOWN - " << key_dict[md] << "\n";
    cout << "HOLD - " << key_dict[h] << "\n";
}

void settings_default() {
    h  = KR;
    rr = KE;
    rl = KQ;
    md = KS;
    mr = KD;
    ml = KA;
}

void build () {
    //dict
    //==============================================================================================================================================================
    //{
    dict[LINE][0] = {{-1.5, -0.5}, {-0.5, -0.5}, {0.5, -0.5}, {1.5, -0.5}};
    dict[LINE][1] = {{0.5, -1.5},  {0.5, -0.5},  {0.5, 0.5},  {0.5, 1.5}};
    dict[LINE][2] = {{-1.5, 0.5},  {-0.5, 0.5},  {0.5, 0.5},  {1.5, 0.5}};
    dict[LINE][3] = {{-0.5, -1.5}, {-0.5, -0.5}, {-0.5, 0.5}, {-0.5, 1.5}};

    dict[L_SHAPED1][0] = {{-1, -1}, {-1, 0}, {0, 0}, {1, 0}};
    dict[L_SHAPED1][1] = {{1, -1},  {0, -1}, {0, 0}, {0, 1}};
    dict[L_SHAPED1][2] = {{1, 1},   {1, 0},  {0, 0}, {-1, 0}};
    dict[L_SHAPED1][3] = {{-1, 1},  {0, 1},  {0, 0}, {0, -1}};

    dict[L_SHAPED2][0] = {{-1, 0}, {0, 0},  {1, 0},  {1, -1}};
    dict[L_SHAPED2][1] = {{0, -1}, {0, 0},  {0, 1},  {1, 1}};
    dict[L_SHAPED2][2] = {{-1, 1}, {-1, 0}, {0, 0},  {1, 0}};
    dict[L_SHAPED2][3] = {{0, 1},  {0, 0},  {0, -1}, {-1, -1}};

    dict[SQUARE][0] = {{-0.5, -0.5}, {0.5, -0.5}, {-0.5, 0.5}, {0.5, 0.5}};
    dict[SQUARE][1] = {{-0.5, -0.5}, {0.5, -0.5}, {-0.5, 0.5}, {0.5, 0.5}};
    dict[SQUARE][2] = {{-0.5, -0.5}, {0.5, -0.5}, {-0.5, 0.5}, {0.5, 0.5}};
    dict[SQUARE][3] = {{-0.5, -0.5}, {0.5, -0.5}, {-0.5, 0.5}, {0.5, 0.5}};

    dict[Z_SHAPED1][0] = {{-1, 0},  {0, 0},  {0, -1}, {1, -1}};
    dict[Z_SHAPED1][1] = {{0, -1},  {0, 0},  {1, 0},  {1, 1}};
    dict[Z_SHAPED1][2] = {{-1, 1},  {0, 1},  {0, 0},  {1, 0}};
    dict[Z_SHAPED1][3] = {{-1, -1}, {-1, 0}, {0, 0},  {0, 1}};

    dict[T_SHAPED][0] = {{-1, 0}, {0, 0}, {0, -1}, {1, 0}};
    dict[T_SHAPED][1] = {{0, -1}, {0, 0}, {1, 0},  {0, 1}};
    dict[T_SHAPED][2] = {{-1, 0}, {0, 0}, {0, 1},  {1, 0}};
    dict[T_SHAPED][3] = {{0, -1}, {0, 0}, {-1, 0}, {0, 1}};

    dict[Z_SHAPED2][0] = {{1, 0},  {0, 0},  {0, -1}, {-1, -1}};
    dict[Z_SHAPED2][1] = {{0, 1},  {0, 0},  {1, 0},  {1, -1}};
    dict[Z_SHAPED2][2] = {{1, 1},  {0, 1},  {0, 0},  {-1, 0}};
    dict[Z_SHAPED2][3] = {{-1, 1}, {-1, 0}, {0, 0},  {0, -1}};
    //}
    //==============================================================================================================================================================

    //useful_colors
    //==============================================================================================================================================================
    //{
    useful_colors.push_back(RGB(255, 60, 60));
    useful_colors.push_back(RGB(206, 112, 112));

    useful_colors.push_back(RGB(255, 140, 30));
    useful_colors.push_back(RGB(245, 162, 80));

    useful_colors.push_back(RGB(115, 255, 80));
    useful_colors.push_back(RGB(119, 210, 96));

    useful_colors.push_back(RGB(50, 255, 255));
    useful_colors.push_back(RGB(60, 208, 208));

    useful_colors.push_back(RGB(50, 50, 255));
    useful_colors.push_back(RGB(77, 77, 228));

    useful_colors.push_back(RGB(255, 0, 255));
    useful_colors.push_back(RGB(219, 64, 219));

    useful_colors.push_back(RGB(255, 0, 128));
    useful_colors.push_back(RGB(202, 27, 114));
    //}
    //==============================================================================================================================================================

    //{
    //static_arr
    //==============================================================================================================================================================
    //{
    for (int i = 0; i < 20; i++) {
        for (int j = (AREA_X_SIZE - 10) / 2; j < (AREA_X_SIZE + 10) / 2 ; j++) {
            static_arr[i][j] = {0, RGB(255, 0, 0)};
        }
    }
    //}
    //==============================================================================================================================================================

    //figure_type_arr
    //==============================================================================================================================================================
    //{
    figure_type_arr.push_back(LINE);
    figure_type_arr.push_back(L_SHAPED1);
    figure_type_arr.push_back(L_SHAPED2);
    figure_type_arr.push_back(SQUARE);
    figure_type_arr.push_back(Z_SHAPED1);
    figure_type_arr.push_back(Z_SHAPED2);
    figure_type_arr.push_back(T_SHAPED);
    //}
    //==============================================================================================================================================================

    //start_pos
    //==============================================================================================================================================================
    //{
    start_pos[LINE] = {5, 0};
    start_pos[L_SHAPED1] = {5.5, -0.5};
    start_pos[L_SHAPED2] = {4.5, -0.5};
    start_pos[SQUARE] = {5, -1};
    start_pos[Z_SHAPED1] = {5.5, -0.5};
    start_pos[Z_SHAPED2] = {4.5, -0.5};
    start_pos[T_SHAPED] = {4.5, -0.5};
    //==============================================================================================================================================================
    //}

    //}
    //Этот код написал Плотников Владимир, электронной подписью является число - 750792
    //Открытый ключ: {1919282723, 7}
    //Зашифрованная подпись - 1144560595
}

//{
void sqr_draw(Point p, COLORREF cl, double s = 1) {
    txSetFillColor(cl);
    txSetColor(TX_BLACK);
    txRectangle(p.x + BLOCK_SIZE * s / 2, p.y + BLOCK_SIZE * s / 2, p.x - BLOCK_SIZE * s / 2, p.y - BLOCK_SIZE * s / 2);
}
//}
//Этот код написал Плотников Владимир, электронной подписью является число - 951357
//Открытый ключ: {3465700307, 7}
//Зашифрованная подпись - 808670938

void static_draw() {
    for (int i = 0; i < 20; i++) {
        for (int j = (AREA_X_SIZE - 10) / 2; j < (AREA_X_SIZE + 10) / 2 ; j++) {
            if (static_arr[i][j].first) {
                sqr_draw({(double) j * BLOCK_SIZE + BLOCK_SIZE / 2 + X_LEFT - BLOCK_SIZE * (AREA_X_SIZE - 10) / 2,
                          (double) i * BLOCK_SIZE + BLOCK_SIZE / 2 + Y_UP},
                           static_arr[i][j].second);
            }
        }
    }
    txSetColor(RGB(255, 255, 255), 3);
    txSetFillColor(TX_NULL);
    txRectangle(X_LEFT, Y_UP, X_LEFT + WIDTH, Y_UP + HEIGHT) ;
    txSetColor(RGB(255, 255, 255), 2);
    for (int i = 1; i <= 9; i++)
        txLine(X_LEFT + BLOCK_SIZE * i, Y_UP, X_LEFT + BLOCK_SIZE * i, Y_UP + HEIGHT);
    for (int i = 1; i <= 19; i++)
        txLine(X_LEFT, Y_UP + BLOCK_SIZE * i, X_LEFT + WIDTH, Y_UP + BLOCK_SIZE * i);
}
#endif
