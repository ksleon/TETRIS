#include "base.h"
#include "line_clear.h"
#include "figure_class.h"
#include "random.h"
#include "score.h"
#include "button.h"
#include "key.h"
#include "record.h"
#include "tutorial.h"

//Типы фигур:
//Линия - LINE
//Г-образная - L_SHAPED1
//Отраженная Г-образная - L_SHAPED2
//Квадрат - SQUARE
//Z-образная - Z_SHAPED2
//Отраженная Z-оразная - Z_SHAPED1
//Т-образная T_SHAPED

void play();
__attribute__((__noreturn__)) void tetris_exit();

int main() {
    //{
    build();
    key_build();
    settings_load();
    records_load();
    txCreateWindow(1080, 720);
    txClear();
    play();
    //}
    //Этот код написал Плотников Владимир, электронной подписью является число - 456709
    //Открытый ключ: {506477, 7}
    //Зашифрованная подпись - 267686
    txSetFillColor(RGB(150, 150, 150));
    txSetColor(TX_WHITE);
    txClear();
    open_records();
    open_tutorial();
    tetris_exit();
}

__attribute__((__noreturn__)) void tetris_exit() {
    settings_save();
    records_save();
    txDisableAutoPause();
    exit(0);
}

void play() {
    Figure test;
    Score score;
    test = rand_figure();
    while (!GetAsyncKeyState(VK_ESCAPE)) {
        while(true) {
            for(int i = 0; i < 3 && !GetAsyncKeyState(VK_ESCAPE); i++) {
                if (GetAsyncKeyState(to_char(ml))) {
                    test.m_left();
                    //cout << "MOVE LEFT\n";
                }
                if (GetAsyncKeyState(to_char(mr))) {
                    test.m_right();
                    //cout << "MOVE RIGHT\n";
                }
                if (GetAsyncKeyState(to_char(md))) {
                    score.update(test.m_down());
                    //cout << "MOVE DOWN\n";
                }
                if (GetAsyncKeyState(to_char(rl))) {
                    //while(GetAsyncKeyState('Q'));
                    test.r_left();
                    //cout << "ROTATE LEFT";
                }
                if (GetAsyncKeyState(to_char(rr))) {
                    //while(GetAsyncKeyState('E'));
                    test.r_right();
                    //cout << "ROTATE RIGHT";
                }
                txSetFillColor(RGB(150, 150, 150));
                txClear();
                if (test.get() == MOVE)
                    test.draw();
                static_draw();
                score.draw({100, 10});
                txSleep(100);
            }
            if(test.get() != MOVE || GetAsyncKeyState(VK_ESCAPE))
                break;
            score.update(test.m_down());
            txSetFillColor(RGB(150, 150, 150));
            txClear();
            if (test.get() == MOVE)
                test.draw();
            static_draw();
            score.draw({100, 10});
            txSleep(100);
            if(test.get() != MOVE || GetAsyncKeyState(VK_ESCAPE))
                break;
        }
        if (test.get() == STATIC)
            test = rand_figure();
        else
            break;
    }
}
