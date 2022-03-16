//TETRIS_2022

#ifndef _KEYS_
#define _KEYS_

//{
void draw(Key_type test, double x, double y, double x1, double y1);
Key_type get();
void key_build();
char to_char(Key_type key);

void draw(Key_type test, double x, double y, double x1, double y1) {
    txSetColor (TX_BLACK, 5);
    //txSelectFont ("Serifiqo 4F Free Capitals", 1.7*BLOCK_SIZE);
    if(test == KUP){
        //txRectangle (x, y, x + 72, y + 72);
        txLine (x + 36, y + 10, x + 36, y + 62);
        txLine (x + 36, y + 5,  x + 18, y + 36);
        txLine (x + 36, y + 5,  x + 54, y + 36);
    }
    else if(test == KDOWN){
        //txRectangle (x, y, x + 72, y + 72);
        txLine (x + 36, y + 10, x + 36, y + 60);
        txLine (x + 36, y + 66, x + 18, y + 36);
        txLine (x + 36, y + 66, x + 54, y + 36);
    }
    else if(test == KLEFT){
        //txRectangle (x, y, x + 72, y + 72);
        txLine (x + 10, y + 36, x + 62, y + 36);
        txLine (x + 5, y + 36, x + 41, y + 18);
        txLine (x + 5, y + 36, x + 41, y + 54);
    }
    else if(test == KRIGHT){
        //txRectangle (x, y, x + 72, y + 72);
        txLine (x + 10, y + 36, x + 72, y + 36);
        txLine (x + 67, y + 36, x + 36, y + 18);
        txLine (x + 67, y + 36, x + 36, y + 54);
    }
    else if(test == KRMB){
        txSetFillColor(TX_NULL);
        txEllipse (x + 12, y + 5, x + 60, y + 67);
        txLine (x + 60, y + 36, x + 12, y + 36);
        txLine (x + 36, y + 36, x + 36, y + 5);
        txSetFillColor(TX_BLACK);
        txPie (x + 12, y + 5, x + 60, y + 67, 360, 90);
    }
    else if(test == KLMB){
        txSetFillColor(TX_NULL);
        txEllipse (x + 12, y + 5, x + 60, y + 67);
        txLine (x + 60, y + 36, x + 12, y + 36);
        txLine (x + 36, y + 36, x + 36, y + 5);
        txSetFillColor(TX_BLACK);
        txPie (x + 12, y + 5, x + 60, y + 67, 90, 90);
    }
    else{
        //txRectangle (x, y, x + 72, y + 72);
        double mx = (x1 + x) / 2;
        double lx = txGetTextExtentX(key_dict[test].c_str()) / 2;
        double my = (y1 + y) / 2;
        double ly = txGetTextExtentY(key_dict[test].c_str()) / 2;
        //txDrawText (x, y, x1, y1, key_dict[test].c_str(), DT_WORDBREAK);
        txTextOut(mx - lx, my - ly, key_dict[test].c_str());
    }
}

Key_type get() {
    if (GetAsyncKeyState('A'))
        return KA;
    if (GetAsyncKeyState('B'))
        return KB;
    if (GetAsyncKeyState('C'))
        return KC;
    if (GetAsyncKeyState('D'))
        return KD;
    if (GetAsyncKeyState('E'))
        return KE;
    if (GetAsyncKeyState('F'))
        return KF;
    if (GetAsyncKeyState('G'))
        return KG;
    if (GetAsyncKeyState('H'))
        return KH;
    if (GetAsyncKeyState('I'))
        return KI;
    if (GetAsyncKeyState('J'))
        return KJ;
    if (GetAsyncKeyState('K'))
        return KK;
    if (GetAsyncKeyState('L'))
        return KL;
    if (GetAsyncKeyState('M'))
        return KM;
    if (GetAsyncKeyState('N'))
        return KN;
    if (GetAsyncKeyState('O'))
        return KO;
    if (GetAsyncKeyState('P'))
        return KP;
    if (GetAsyncKeyState('Q'))
        return KQ;
    if (GetAsyncKeyState('R'))
        return KR;
    if (GetAsyncKeyState('S'))
        return KS;
    if (GetAsyncKeyState('T'))
        return KT;
    if (GetAsyncKeyState('U'))
        return KU;
    if (GetAsyncKeyState('V'))
        return KV;
    if (GetAsyncKeyState('W'))
        return KW;
    if (GetAsyncKeyState('X'))
        return KX;
    if (GetAsyncKeyState('Y'))
        return KY;
    if (GetAsyncKeyState('Z'))
        return KZ;
    if (GetAsyncKeyState(VK_UP))
        return KUP;
    if (GetAsyncKeyState(VK_DOWN))
        return KDOWN;
    if (GetAsyncKeyState(VK_LEFT))
        return KLEFT;
    if (GetAsyncKeyState(VK_RIGHT))
        return KRIGHT;
    if (GetAsyncKeyState(VK_RBUTTON))
        return KRMB;
    if (GetAsyncKeyState(VK_LBUTTON))
        return KLMB;
    if (GetAsyncKeyState(VK_MENU))
        return KALT;
    if (GetAsyncKeyState(VK_SHIFT))
        return KSHIFT;
    if (GetAsyncKeyState(VK_CONTROL))
        return KCTRL;
    if (GetAsyncKeyState(VK_SPACE))
        return KSPACE;
    return KNULL;
}

void key_build() {
    key_dict[KA] = "A";
    key_dict[KB] = "B";
    key_dict[KC] = "C";
    key_dict[KD] = "D";
    key_dict[KE] = "E";
    key_dict[KF] = "F";
    key_dict[KG] = "G";
    key_dict[KH] = "H";
    key_dict[KI] = "I";
    key_dict[KJ] = "J";
    key_dict[KK] = "K";
    key_dict[KL] = "L";
    key_dict[KM] = "M";
    key_dict[KN] = "N";
    key_dict[KO] = "O";
    key_dict[KP] = "P";
    key_dict[KQ] = "Q";
    key_dict[KR] = "R";
    key_dict[KS] = "S";
    key_dict[KT] = "T";
    key_dict[KU] = "U";
    key_dict[KV] = "V";
    key_dict[KW] = "W";
    key_dict[KX] = "X";
    key_dict[KY] = "Y";
    key_dict[KZ] = "Z";
    key_dict[KUP]    = "UP ARROW";
    key_dict[KDOWN]  = "DOWN ARROW";
    key_dict[KLEFT]  = "LEFT ARROW";
    key_dict[KRIGHT] = "RIGHT ARROW";
    key_dict[KRMB] = "RIGHT MOSE BUTTON";
    key_dict[KLMB] = "LEFT MOSE BUTTON";
    key_dict[KALT]   = "ALT";
    key_dict[KSHIFT] = "SHIFT";
    key_dict[KCTRL]  = "CTRL";
    key_dict[KSPACE] = "SPACE";
    key_dict[KNULL] = "NULL";

    auto it = key_dict.begin();
    for (int i = 0; it != key_dict.end(); it++, i++) {
        reverse_key_dict[it->second] = it->first;
    }
}

char to_char(Key_type key) {
    char ans = 'k';
    if (key == KUP)
        ans = VK_UP;
    else if (key == KLEFT)
        ans = VK_LEFT;
    else if (key == KRIGHT)
        ans = VK_RIGHT;
    else if (key == KDOWN)
        ans = VK_DOWN;
    else if (key == KRMB)
        ans = VK_RBUTTON;
    else if (key == KLMB)
        ans = VK_LBUTTON;
    else if (key == KSHIFT)
        ans = VK_SHIFT;
    else if (key == KALT)
        ans = VK_MENU;
    else if (key == KCTRL)
        ans = VK_CONTROL;
    else if (key == KSPACE)
        ans = VK_SPACE;
    else
        ans = char((int) key + 'A');
    return ans;
}
//}
//Этот код написал Венгеров Кирилл, электронной подписью является число - 1948
//Открытый ключ: {61534471, 11}
//Зашифрованная подпись - 41637548
/*int main() {
    txCreateWindow(1080, 720);
    Key_type test = KNULL;
    key_build();
    cout << "Dict had built\n";
    while ((test = get()) == KNULL);
    draw(test);
    //cout << key_dict[test] << "\n";
    //cout << char((int) test + 'A');
}  */
#endif
