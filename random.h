//TETRIS_2022

#ifndef _RANDGEN_
#define _RANDGEN_

//==============================================================================================================================================================
COLORREF rand_color();
Figure_type rand_type();
Figure rand_figure();
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

Figure rand_figure() {
    COLORREF cl = rand_color();
    Figure_type ft = rand_type();
    Point pos = start_pos[ft];
    Figure ans(pos.x, pos.y, ft, cl, rand() % 4);
    return ans;
}
//==============================================================================================================================================================
#endif
