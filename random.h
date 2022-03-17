//TETRIS_2022

#ifndef _RANDGEN_
#define _RANDGEN_

//==============================================================================================================================================================
COLORREF rand_color();            ///Случайный цвет из списка возможных
Figure_type rand_type();          ///Случайный тип фигуры
Figure rand_figure(Figure_type t);///Случайная фигура
//////////////////////////////////////

COLORREF rand_color() {
    srand (time (NULL));
    int num = rand() % useful_colors.size();
    return useful_colors[num];
}

Figure_type rand_type() {
    int num = rand() % figure_type_arr.size();
    return figure_type_arr[num];
}

//{
Figure rand_figure(Figure_type t = NOT_FIGURE) {

    Figure_type ft;
    if (t == NOT_FIGURE)
        ft = rand_type();
    else
        ft = t;
    COLORREF cl = rand_color();
    Point pos = start_pos[ft];
    Figure ans(pos.x * BLOCK_SIZE + X_LEFT,
               pos.y * BLOCK_SIZE + Y_UP,
               ft, cl, 0);
    return ans;

}
//}
//Этот код написал Плотников Владимир, электронной подписью является число - 908437
//Открытый ключ: {190082983, 7}
//Зашифрованная подпись - 75993834
//==============================================================================================================================================================
#endif
