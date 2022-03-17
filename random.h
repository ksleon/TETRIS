//TETRIS_2022

#ifndef _RANDGEN_
#define _RANDGEN_

//==============================================================================================================================================================
COLORREF rand_color();            ///��������� ���� �� ������ ���������
Figure_type rand_type();          ///��������� ��� ������
Figure rand_figure(Figure_type t);///��������� ������
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
//���� ��� ������� ��������� ��������, ����������� �������� �������� ����� - 908437
//�������� ����: {190082983, 7}
//������������� ������� - 75993834
//==============================================================================================================================================================
#endif
