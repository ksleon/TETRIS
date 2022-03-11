#include "base.h"
#include "figure_class.h"
#include "random.h"
#include "line_clear.h"
#include "score.h"
//Типы фигур:
//Линия - LINE
//Г-образная - L_SHAPED1
//Отраженная Г-образная - L_SHAPED2
//Квадрат - SQUARE
//Z-образная - Z_SHAPED2
//Отраженная Z-оразная - Z_SHAPED1
//Т-образная T_SHAPED

int main() {
    /*Figure test(X_LEFT + BLOCK_SIZE * 3,
                Y_UP + BLOCK_SIZE * 3,
                SQUARE, RGB(255, 0, 0), 0); */
    txCreateWindow(1080, 720);
    build();
    txClear();
    /*for (int i = 0 ; i < 5; i++) {
        txSetFillColor(TX_WHITE);
        txClear();
        test.r_right();
        test.draw();
        txSleep(1000);
    }   */
    //{
    static_arr[19][3] = {1, RGB(255, 60, 60)};
    static_arr[18][3] = {1, RGB(255, 60, 60)};
    static_arr[19][4] = {1, RGB(255, 60, 60)};

    static_arr[17][3] = {1, RGB(119, 210, 96)};
    static_arr[16][3] = {1, RGB(119, 210, 96)};
    static_arr[15][3] = {1, RGB(119, 210, 96)};
    static_arr[14][3] = {1, RGB(119, 210, 96)};

    static_arr[19][5] = {1, RGB(50, 50, 255)};
    static_arr[19][6] = {1, RGB(50, 50, 255)};

    static_arr[18][5] = {1, RGB(206, 112, 112)};
    static_arr[17][5] = {1, RGB(206, 112, 112)};
    static_arr[18][6] = {1, RGB(206, 112, 112)};
    static_arr[17][6] = {1, RGB(206, 112, 112)};

    static_arr[15][5] = {1, RGB(245, 162, 80)};
    static_arr[16][5] = {1, RGB(245, 162, 80)};
    static_arr[16][6] = {1, RGB(245, 162, 80)};
    static_arr[16][7] = {1, RGB(245, 162, 80)};

    static_arr[19][7] = {1, RGB(219, 64, 219)};
    static_arr[19][8] = {1, RGB(219, 64, 219)};
    static_arr[18][7] = {1, RGB(219, 64, 219)};
    static_arr[17][7] = {1, RGB(219, 64, 219)};

    static_arr[15][6] = {1, RGB(50, 255, 255)};
    static_arr[15][7] = {1, RGB(50, 255, 255)};
    static_arr[15][8] = {1, RGB(50, 255, 255)};
    static_arr[16][8] = {1, RGB(50, 255, 255)};

    static_arr[18][8]  = {1, RGB(60, 208, 208)};
    static_arr[18][9]  = {1, RGB(60, 208, 208)};
    static_arr[18][10] = {1, RGB(60, 208, 208)};
    static_arr[19][9]  = {1, RGB(60, 208, 208)};

    static_arr[17][8] = {1, RGB(115, 255, 80)};
    static_arr[17][9] = {1, RGB(115, 255, 80)};
    static_arr[16][9] = {1, RGB(115, 255, 80)};
    static_arr[15][9] = {1, RGB(115, 255, 80)};

    static_arr[19][12] = {1, RGB(202, 27, 114)};
    static_arr[19][11] = {1, RGB(202, 27, 114)};
    static_arr[18][11] = {1, RGB(202, 27, 114)};
    static_arr[17][11] = {1, RGB(202, 27, 114)};

    static_arr[17][10] = {1, RGB(77, 77, 228)};
    static_arr[16][10] = {1, RGB(77, 77, 228)};
    static_arr[16][11] = {1, RGB(77, 77, 228)};
    static_arr[15][11] = {1, RGB(77, 77, 228)};

    static_arr[15][10] = {1, RGB(255, 140, 30)};
    static_arr[14][10] = {1, RGB(255, 140, 30)};
    static_arr[14][9]  = {1, RGB(255, 140, 30)};
    static_arr[13][9]  = {1, RGB(255, 140, 30)};

    static_arr[15][12] = {1, RGB(50, 255, 255)};
    static_arr[16][12] = {1, RGB(50, 255, 255)};
    static_arr[17][12] = {1, RGB(50, 255, 255)};
    static_arr[18][12] = {1, RGB(50, 255, 255)};

    static_arr[10][4] = {1, RGB(255, 0, 255)};
    static_arr[9][4]  = {1, RGB(255, 0, 255)};
    static_arr[8][4]  = {1, RGB(255, 0, 255)};
    static_arr[7][4]  = {1, RGB(255, 0, 255)};

    static_draw();
    //}
    //Этот код написал Плотников Владимир, электронной подписью является число - 456709
    //Открытый ключ: {506477, 7}
    //Зашифрованная подпись - 267686

    Score s(13000);
    s.draw({100, 10});

    txRectangle(800, 100, 1000, 300);
    txTextOut(830, 10, "Next");
    txRectangle(800, 100 + 300, 1000, 300 + 300);
    txTextOut(830, 10 + 300, "Hold");
}
