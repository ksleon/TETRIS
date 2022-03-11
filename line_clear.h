//TETRIS_2022

#ifndef _LINE_CLEAR_
#define _LINE_CLEAR_

//functions
//==============================================================================================================================================================
//{
bool check_line (unsigned int n);   ///ѕроверка на заполненность линии
int update ();                      ///ќбновление массива, возвращает кол-во стертых линий
void delete_line (unsigned int n);  ///”даление линии из массива
//}
//==============================================================================================================================================================

//initialization
//==============================================================================================================================================================
//{
bool check_line (unsigned int n) {
    bool ans = 1;
    for (auto x : static_arr[n])  {
        ans = min(ans, x.first);
    }
    return ans;
}
int update () {
    int ans = 0;
    for (unsigned int i = 0; i < static_arr.size(); i++) {
        if (check_line(i)) {
            delete_line(i);
            ans++;
        }
    }
    return ans;
}

void delete_line (unsigned int n) {
    for (int i = n; i > 0; i++)
        static_arr[i] = static_arr[i - 1];
    static_arr[0].clear();
    static_arr[0].resize(AREA_X_SIZE, {1, TX_BLACK});
    for (int j = (AREA_X_SIZE - 10) / 2; j < (AREA_X_SIZE + 10) / 2 ; j++) {
        static_arr[0][j] = {0, RGB(255, 0, 0)};
    }
}
//}
//==============================================================================================================================================================
#endif
