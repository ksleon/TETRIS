//TETRIS_2022

#ifndef _TUTORIAL_
#define _TUTORIAL_
#include "base.h"
#include "line_clear.h"
#include "figure_class.h"
#include "random.h"
#include "score.h"
#include "button.h"
#include "key.h"
#include "record.h"

//{
void draw_direct();
void open_tutorial();

void draw_direct(){
    int x = 180 - BLOCK_SIZE;
    for(int i = 0; i < 5;i++){
        txRectangle (x, 400, x + 2 * BLOCK_SIZE, 400 + 2 * BLOCK_SIZE);
        x += 180;
    }
    txSetFillColor(RGB(0, 0, 0));
    txRectangle (360 + 4.5 * BLOCK_SIZE, 100 - BLOCK_SIZE, 360 + 6.5 * BLOCK_SIZE, 100 + BLOCK_SIZE);
    txSetFillColor(RGB(150, 150, 150));
    txRectangle (360 - 5 * BLOCK_SIZE, 100 - BLOCK_SIZE, 360 - 3 * BLOCK_SIZE, 100 + BLOCK_SIZE);
    txDrawText (360 + 4 * BLOCK_SIZE, 40 - BLOCK_SIZE, 360 + 7 * BLOCK_SIZE, 40 + BLOCK_SIZE, "HOLD");
    //txSelectFont ("Serifiqo 4F Free Capitals", 1.6 * BLOCK_SIZE);
    txDrawText (360 + 7 * BLOCK_SIZE, 0, 1080, 2 * BLOCK_SIZE, "Holding a figure and ");
    txDrawText (360 + 7 * BLOCK_SIZE, 2 * BLOCK_SIZE, 1080, 4 * BLOCK_SIZE, "replacing it at the right time.");
    //txSelectFont ("Serifiqo 4F Free Capitals", 1.7 * BLOCK_SIZE);

    txLine(180 - 2 * BLOCK_SIZE, 600, 180 - 4 * BLOCK_SIZE, 600);//стрелочка
    txLine(180 - 4 * BLOCK_SIZE, 600, 180 - 3 * BLOCK_SIZE, 580);//
    txLine(180 - 4 * BLOCK_SIZE, 600, 180 - 3 * BLOCK_SIZE, 620);//влево

    txLine(900 + 2 * BLOCK_SIZE, 600, 900 + 4 * BLOCK_SIZE, 600);//стрелочка
    txLine(900 + 4 * BLOCK_SIZE, 600, 900 + 3 * BLOCK_SIZE, 580);//
    txLine(900 + 4 * BLOCK_SIZE, 600, 900 + 3 * BLOCK_SIZE, 620);//вправо

    txLine(540, 600 + BLOCK_SIZE, 540, 600 + 3 * BLOCK_SIZE);//стрелочка
    txLine(540, 600 + 3 * BLOCK_SIZE, 520, 600 + 2 * BLOCK_SIZE);//
    txLine(540, 600 + 3 * BLOCK_SIZE, 560, 600 + 2 * BLOCK_SIZE);//вниз

    txLine(360 + 2 * BLOCK_SIZE, 100, 360 + 4 * BLOCK_SIZE, 100);//стрелочка
    txLine(360 + 4 * BLOCK_SIZE, 100, 360 + 3 * BLOCK_SIZE, 80);//в
    txLine(360 + 4 * BLOCK_SIZE, 100, 360 + 3 * BLOCK_SIZE, 120);//hold

    txLine(360 - BLOCK_SIZE, 600 - 2 * BLOCK_SIZE, 360 - 2 * BLOCK_SIZE, 600 - 2 * BLOCK_SIZE);//стрелочка
    txLine(360 - 2 * BLOCK_SIZE, 600 - 2 * BLOCK_SIZE, 360 - 2 * BLOCK_SIZE, 600 - BLOCK_SIZE);//поворот
    txLine(360 - 2 * BLOCK_SIZE, 600 - BLOCK_SIZE, 350 - 2 * BLOCK_SIZE, 600 - 1.5 * BLOCK_SIZE);//влево
    txLine(360 - 2 * BLOCK_SIZE, 600 - BLOCK_SIZE, 370 - 2 * BLOCK_SIZE, 600 - 1.5 * BLOCK_SIZE);//

    txLine(720 + BLOCK_SIZE, 600 - 2 * BLOCK_SIZE, 720 + 2 * BLOCK_SIZE, 600 - 2 * BLOCK_SIZE);//стрелочка
    txLine(720 + 2 * BLOCK_SIZE, 600 - 2 * BLOCK_SIZE, 720 + 2 * BLOCK_SIZE, 600 - BLOCK_SIZE);//поворот
    txLine(720 + 2 * BLOCK_SIZE, 600 - BLOCK_SIZE, 710 + 2 * BLOCK_SIZE, 600 - 1.5 * BLOCK_SIZE);//вправо
    txLine(720 + 2 * BLOCK_SIZE, 600 - BLOCK_SIZE, 730 + 2 * BLOCK_SIZE, 600 - 1.5 * BLOCK_SIZE);//
}

void open_tutorial(){
    build();
    key_build();
    txSelectFont ("Serifiqo 4F Free Capitals", 35, 10, 1000);

    Figure tut1(180, 600, T_SHAPED, RGB(65, 105, 225), 0);
    Figure tut2(360, 600, T_SHAPED, RGB(65, 105, 225), 0);
    Figure tut3(540, 600, T_SHAPED, RGB(65, 105, 225), 0);
    Figure tut4(720, 600, T_SHAPED, RGB(65, 105, 225), 0);
    Figure tut5(900, 600, T_SHAPED, RGB(65, 105, 225), 0);
    Figure tut6(360, 100, T_SHAPED, RGB(65, 105, 225), 0);
    Button hold({180 - 3 , 64 - 3}, {252 + 5, 136 + 5},
                "", TX_NULL, TX_NULL);
    Button mleft({144 - 3 , 400 - 3}, {216 + 5, 472 + 5},
                 "", TX_NULL, TX_NULL);
    Button mdown({504 - 3 , 400 - 3}, {576 + 5, 472 + 5},
                 "", TX_NULL, TX_NULL);
    Button mright({864 - 3 , 400 - 3}, {936 + 5, 472 + 5},
                 "", TX_NULL, TX_NULL);
    Button rleft({324 - 3 , 400 - 3}, {396 + 5, 472 + 5},
                 "", TX_NULL, TX_NULL);
    Button rright({684 - 3 , 400 - 3}, {756 + 5, 472 + 5},
                 "", TX_NULL, TX_NULL);
    Button Default({500, 300},
                   "Default", RGB(0, 255, 0), TX_BLACK);
    Button Exit({1011 - 3 , 3 - 3}, {1075 + 5, 67 + 5},
                    "Menu", TX_NULL, TX_NULL);
    txSetFillColor(RGB(150, 150, 150));
    txSetColor(RGB(255, 255, 255), 5);
    draw_direct();
    tut1.draw();
    tut2.draw();
    tut3.draw();
    tut4.draw();
    tut5.draw();
    tut6.draw();
    //settings_print();
    Default.draw();
    Exit.draw();
    draw(h, 180, 64, 252, 136);
    draw(rl, 324, 400, 396, 472);
    draw(ml, 144, 400, 216, 472);
    draw(md, 504, 400, 576, 472);
    draw(mr, 864, 400, 936, 472);
    draw(rr, 684, 400, 756, 472);
    txBegin();
    int f = 0;
    while(f == 0){

        if (hold.get()) {
            while(hold.get());
            //cout << "HOLD\n";
            h = KNULL;
            while ((h = get()) == KNULL);
            while(GetAsyncKeyState(VK_RBUTTON) || GetAsyncKeyState(VK_LBUTTON));
            //settings_print();
        }
        if (Exit.get()) {
            //cout << "Exit\n";
            f = 1;
        }
        if (mleft.get()) {
            while(mleft.get());
            //cout << "MOVE LEFT\n";
            ml = KNULL;
            while ((ml = get()) == KNULL);
            while(GetAsyncKeyState(VK_RBUTTON) || GetAsyncKeyState(VK_LBUTTON));
            //settings_print();
        }
        if (mright.get()) {
            while(mright.get());
            //cout << "MOVE RIGHT\n";
            mr = KNULL;
            while ((mr = get()) == KNULL);
            while(GetAsyncKeyState(VK_RBUTTON) || GetAsyncKeyState(VK_LBUTTON));
            //settings_print();
        }
        if (mdown.get()) {
            while(mdown.get());
            //cout << "MOVE DOWN\n";
            md = KNULL;
            while ((md = get()) == KNULL);
            while(GetAsyncKeyState(VK_RBUTTON) || GetAsyncKeyState(VK_LBUTTON));
            //settings_print();
        }
        if (rright.get()) {
            while(rright.get());
            //cout << "ROTATE RIGHT\n";
            rr = KNULL;
            while ((rr = get()) == KNULL);
            while(GetAsyncKeyState(VK_RBUTTON) || GetAsyncKeyState(VK_LBUTTON));
            //settings_print();
        }
        if (rleft.get()) {
            while(rleft.get());
            //cout << "ROTATE LEFT\n";
            rl = KNULL;
            while ((rl = get()) == KNULL);
            while(GetAsyncKeyState(VK_RBUTTON) || GetAsyncKeyState(VK_LBUTTON));
            //settings_print();
        }
        if (Default.get()) {
            while(Default.get());
            settings_default();
            //settings_print();
        }
        txSetFillColor(RGB(150, 150, 150));
        txClear();
        txSetFillColor(RGB(150, 150, 150));
        txSetColor(RGB(255, 255, 255), 5);
        draw_direct();
        tut1.draw();
        tut2.draw();
        tut3.draw();
        tut4.draw();
        tut5.draw();
        tut6.draw();
        Default.draw();
        Exit.draw();
        draw(h, 180, 64, 252, 136);
        draw(rl, 324, 400, 396, 472);
        draw(ml, 144, 400, 216, 472);
        draw(md, 504, 400, 576, 472);
        draw(mr, 864, 400, 936, 472);
        draw(rr, 684, 400, 756, 472);
        txSleep(10);
    }
    txEnd();
}
//}
//Этот код написал Венгеров Кирилл, электронной подписью является число - 1948
//Открытый ключ: {61534471, 11}
//Зашифрованная подпись - 41637548
#endif
