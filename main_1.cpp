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

void play();                                     ///Запуск игры
__attribute__((__noreturn__)) void tetris_exit();///Выход из игры (с сохранением всего)
__attribute__((__noreturn__)) void menu();       ///Открытие основного меню

int main() {
    //{
    build();
    key_build();
    settings_load();
    records_load();
    txCreateWindow(1080, 720);
    menu();
    //}
    //Этот код написал Плотников Владимир, электронной подписью является число - 456709
    //Открытый ключ: {506477, 7}
    //Зашифрованная подпись - 267686
}

__attribute__((__noreturn__)) void menu() {
    Button Play_game({200 + 100, 200}, {400 + 100, 300}, "PLAY",     TX_NULL, TX_BLACK);
    Button Records  ({200 + 100, 400}, {400 + 100, 500}, "RECORDS",  TX_NULL, TX_BLACK);
    Button Settings ({500 + 100, 200}, {700 + 100, 300}, "SETTINGS", TX_NULL, TX_BLACK);
    Button Exit     ({500 + 100, 400}, {700 + 100, 500}, "EXIT",     TX_NULL, TX_BLACK);
    txSelectFont ("Serifiqo 4F Free Capitals", 50, 50 / 3, 1000);
    txSetFillColor(RGB(150, 150, 150));
    txSetColor(TX_BLACK);
    txClear();
    txTextOut(500, 100, "TETRIS");
    Play_game.draw();
    Records.draw();
    Settings.draw();
    Exit.draw();
    while(!Exit.get()) {
        if (Play_game.get())
            play();
        if (Records.get())
            open_records();
        if (Settings.get())
            open_tutorial();

        txSetFillColor(RGB(150, 150, 150));
        txSetColor(TX_BLACK);
        txClear();
        txSelectFont ("Serifiqo 4F Free Capitals", 50, 50 / 3, 1000);
        txTextOut(500, 100, "TETRIS");
        Play_game.draw();
        Records.draw();
        Settings.draw();
        Exit.draw();
        txSleep(10);
    }
    tetris_exit();
}

__attribute__((__noreturn__)) void tetris_exit() {
    settings_save();
    records_save();
    txDisableAutoPause();
    exit(0);
}

void play() {
    build();
    Figure main_figure;
    Figure next;
    Figure hold;
    Figure hold1;
    Figure hold2;
    Score score;
    main_figure = rand_figure();
    next = rand_figure();
    next.set({900, 180});
    //double xh = 900, yh = 396;
    //int t = 0;
    while (!GetAsyncKeyState(VK_ESCAPE)) {
        while(true) {
            for(int i = 0; i < 3 && !GetAsyncKeyState(VK_ESCAPE); i++) {
                if (GetAsyncKeyState(to_char(ml))) {
                    main_figure.m_left();
                }
                if (GetAsyncKeyState(to_char(mr))) {
                    main_figure.m_right();
                }
                if (GetAsyncKeyState(to_char(md))) {
                    score.update(main_figure.m_down());
                }
                if (GetAsyncKeyState(to_char(rl))) {
                    main_figure.r_left();
                }
                if (GetAsyncKeyState(to_char(rr))) {
                    main_figure.r_right();
                }
                /*if (GetAsyncKeyState(to_char(h))) {
                    if (t == 0) {
                        hold = main_figure;
                        hold.set({xh, yh});
                        hold.draw();
                        main_figure = next;
                        main_figure.set_default();
                        next = rand_figure();
                        next.set({900, 180});
                        t += 1;
                    }
                    else {
                        hold1 = hold;
                        hold2 = main_figure;
                        hold = main_figure;
                        hold.set({xh, yh});
                        hold.draw();

                        main_figure = hold1;
                        main_figure.set_default();
                        main_figure.set(hold2.get_pos());
                        //if (type);
                            //main_figure.set({});
                        main_figure.draw();
                    }
                }*/
                txSetFillColor(RGB(150, 150, 150));
                txClear();
                if (main_figure.get() == MOVE)
                    main_figure.draw();
                static_draw();
                txSetColor(TX_BLACK, 2);
                txRectangle(810, 90, 990, 270);
                txRectangle(810, 306, 990, 486);
                next.draw();
                //hold.draw();
                score.draw({100, 10});
                txSleep(100);
            }
            if(main_figure.get() != MOVE || GetAsyncKeyState(VK_ESCAPE))
                break;
            score.update(main_figure.m_down());
            txSetFillColor(RGB(150, 150, 150));
            txClear();
            if (main_figure.get() == MOVE)
                main_figure.draw();
            static_draw();
            txSetColor(TX_BLACK, 2);
            txSetFillColor(RGB(150, 150, 150));
            txRectangle(810, 90, 990, 270);
            txRectangle(810, 306, 990, 486);
            next.draw();
            //hold.draw();
            score.draw({100, 10});
            txSleep(100);
            if(main_figure.get() != MOVE || GetAsyncKeyState(VK_ESCAPE))
                break;
        }
        if (main_figure.get() == STATIC){
            main_figure = next;
            main_figure.set_default();
            next = rand_figure();
            next.set({900, 180});
        }
        else {
            break;
        }
    }
    if (MessageBox(NULL, "Желаете внести себя в список рекордов?","Рекорд?", MB_YESNO) == IDYES) {
        const char* nik = txInputBox("Под каким именем Вы хотите это сделать?", "Рекорд!", "PRO_GAME_MASTER_2010");
        Record r(string(nik), score.get());
        record_add(r);
    }
}
