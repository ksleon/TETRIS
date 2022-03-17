//TETRIS_2022

#ifndef _BUTTON_
#define _BUTTON_

class Button {
private:
    Point p1;         ///���������� ������ �� ����� ������
    Point p2;         ///���������� ���������������� ���� ������
    const char* str;  ///����� �� ������
    COLORREF back_col;///���� ���� ������
    COLORREF text_col;///���� ������ ������
public:
    Button(): p1({0, 0}), p2({0, 0}), str(nullptr), back_col(TX_NULL), text_col(TX_NULL) {}           ///������� �����������
    Button(Point _p1, const char* _str, COLORREF _back_col, COLORREF _text_col):p1(_p1),              ///����������� � ������� 2-� ����������� (����������� �� ����� ������)
                                                                                p2({0, 0}),
                                                                                str(_str),
                                                                                back_col(_back_col),
                                                                                text_col(_text_col)  {
        p2.x = (p1.x + 20 + txGetTextExtentX(str));
        p2.y = (p1.y + 20 + txGetTextExtentY(str));
    }
    Button(Point _p1, Point _p2, const char* _str, COLORREF _back_col, COLORREF _text_col):p1(_p1),   ///����������� � ����� 2-� �����������
                                                                                           p2(_p2),
                                                                                           str(_str),
                                                                                           back_col(_back_col),
                                                                                           text_col(_text_col) {}
    bool get()  { ///���������� ������ ������ ��� ���
        double mx = txMouseX();
        double my = txMouseY();
        return (GetAsyncKeyState(VK_LBUTTON) &&
               (mx <= max(p1.x, p2.x) && mx >= min(p1.x, p2.x)) &&
               (my <= max(p1.y, p2.y) && my >= min(p1.y, p2.y)) );
    }

    void draw() { ///������ ������
        txSetColor(TX_BLACK, 2);
        txSetFillColor(back_col);
        txRectangle(p1.x, p1.y, p2.x, p2.y);
        txSetColor(text_col);
        txSetFillColor(text_col);
        double dx = txGetTextExtentX(str) / 2;
        double dy = txGetTextExtentY(str) / 2;
        double mx = (p1.x + p2.x) / 2;
        double my = (p1.y + p2.y) / 2;
        txTextOut(mx - dx, my - dy, str);

    }
};

/*int main() {
    txCreateWindow(1080, 720);
    txClear();
    txSelectFont ("Serifiqo 4F Free Capitals", 100);
    Button test({100, 100}, "�������� ����", RGB(0, 255, 0), TX_BLACK);
    test.draw();
    while(!test.get());
    cout << getchar();
} */

#endif
