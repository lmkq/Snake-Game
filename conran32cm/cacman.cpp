#include<iostream>
#include<Windows.h>
#include"food.h"
#include"dungtuong.h"
#include"buildwall.h"
#include"library.h"
#include "cacman.h"
#include"snake.h"
#include"highscore.h"
using namespace std;

int X[100 * 20], Y[100 * 20];
int len = 2;
hscore score, list[5];;

void man1()
{
    srand(time(NULL));
    ShowCur(0);
    buildwall1();
    buildsnake();
    int x = X[0];
    int y = Y[0];
    int xfood, yfood;
    food1(xfood, yfood);
    SetColor(4);
    gotoXY(xfood, yfood); cout << char(3);
    int check = 1;
    while (true)
    {
        SetColor(11);
        gotoXY(0, 0); cout << char(218);
        gotoXY(X[len], Y[len]);
        cout << " ";
        snakemove();
        if (_kbhit())
        {
            char c = _getch();
            if (c == 'w' && check != 3)
            {
                check = 1;
            }
            else if (c == 'd' && check != 4)
            {
                check = 2;
            }
            else if (c == 's' && check != 1)
            {
                check = 3;
            }
            else if (c == 'a' && check != 2)
            {
                check = 4;
            }
        }
        if (check == 1)
        {
            y--;
        }
        else if (check == 2)
        {
            x++;
        }
        else if (check == 3)
        {
            y++;
        }
        else if (check == 4)
        {
            x--;
        }

        if ((x == 50 && y == 0) && (len % 6 == 2) && (len > 2)) // chui vao hang 
        {
            deletesnake();
            for (int x = 30; x <= 70; x++)
            {
                gotoXY(x, 10);
                cout << " ";
            }
            man2();
        }
        if (ktan(xfood, yfood))
        {
            len++;
            score.highscore += 10;
            if (len % 6 == 1)
            {
                food1(xfood, yfood);
                SetColor(6);
                gotoXY(xfood, yfood); cout << "$";
            }
            else if (len % 6 == 2)
            {
                SetColor(11);
                gotoXY(49, 0); cout << char(219);
                gotoXY(50, 0); cout << " ";
                gotoXY(51, 0); cout << char(219);
            }
            else
            {
                food1(xfood, yfood);
                SetColor(4);
                gotoXY(xfood, yfood); cout << char(3);
            }
        }
        if (dungtuong1() || ktanduoi())
        {
            system("cls");
            SetColor(15);
            cout << "game over";
            break;
        }
        movee(x, y);
        Sleep(150);

    }
}
void man2()
{
    srand(time(NULL));
    ShowCur(0);
    buildwall2();
    ranxuathien();
    int x = X[0];
    int y = Y[0];
    int xfood, yfood;
    food2(xfood, yfood);
    SetColor(4);
    gotoXY(xfood, yfood); cout << char(3);
    int check = 1;
    while (true)
    {
        gotoXY(X[len], Y[len]);
        cout << " ";
        snakemove();
        xoasuxuathien();
        if (_kbhit())
        {
            char c = _getch();
            if (c == 'w' && check != 3)
            {
                check = 1;
            }
            else if (c == 'd' && check != 4)
            {
                check = 2;
            }
            else if (c == 's' && check != 1)
            {
                check = 3;
            }
            else if (c == 'a' && check != 2)
            {
                check = 4;
            }
        }
        if (check == 1)
        {
            y--;
        }
        else if (check == 2)
        {
            x++;
        }
        else if (check == 3)
        {
            y++;
        }
        else if (check == 4)
        {
            x--;
        }
        if ((x == 50 && y == 0) && (len % 6 == 2) && (len > 2)) {
            deletesnake();
            for (int x = 30; x <= 70; x++)
            {
                gotoXY(x, 10);
                cout << " ";
            }
            man3();
        }
        if (ktan(xfood, yfood))
        {
            len++;
            score.highscore += 10;
            if (len % 6 == 1)
            {
                food2(xfood, yfood);
                SetColor(6);
                gotoXY(xfood, yfood); cout << "$";
            }
            else if (len % 6 == 2)
            {
                SetColor(11);
                gotoXY(49, 0); cout << char(219);
                gotoXY(50, 0); cout << " ";
                gotoXY(51, 0); cout << char(219);
            }
            else
            {
                food2(xfood, yfood);
                SetColor(4);
                gotoXY(xfood, yfood); cout << char(3);
            }
        }
        if (dungtuong2() || ktanduoi())
        {
            system("cls");
            SetColor(15);
            cout << "game over";
            break;
        }
        movee(x, y);
        Sleep(150);
    }

}
void man3()
{
    srand(time(NULL));
    ShowCur(0);
    buildwall3();
    ranxuathien();
    int x = X[0];
    int y = Y[0];
    int xfood, yfood;
    food3(xfood, yfood);
    SetColor(4);
    gotoXY(xfood, yfood); cout << char(3);
    int check = 1;
    while (true)
    {
        gotoXY(X[len], Y[len]);
        cout << " ";
        snakemove();
        xoasuxuathien();
        if (_kbhit())
        {
            char c = _getch();
            if (c == 'w' && check != 3)
            {
                check = 1;
            }
            else if (c == 'd' && check != 4)
            {
                check = 2;
            }
            else if (c == 's' && check != 1)
            {
                check = 3;
            }
            else if (c == 'a' && check != 2)
            {
                check = 4;
            }
        }
        if (check == 1)
        {
            y--;
        }
        else if (check == 2)
        {
            x++;
        }
        else if (check == 3)
        {
            y++;
        }
        else if (check == 4)
        {
            x--;
        }
        if ((x == 50 && y == 0) && (len % 6 == 2) && (len > 2)) {
            deletesnake();
            for (int x = 30; x <= 70; x++)
            {
                gotoXY(x, 8);
                cout << " ";
                gotoXY(x, 12);
                cout << " ";
            }
            man4();
        }
        if (ktan(xfood, yfood))
        {
            len++;
            score.highscore += 10;
            if (len % 6 == 1)
            {
                food3(xfood, yfood);
                SetColor(6);
                gotoXY(xfood, yfood); cout << "$";
            }
            else if (len % 6 == 2)
            {
                SetColor(11);
                gotoXY(49, 0); cout << char(219);
                gotoXY(50, 0); cout << " ";
                gotoXY(51, 0); cout << char(219);
            }
            else
            {
                food3(xfood, yfood);
                SetColor(4);
                gotoXY(xfood, yfood); cout << char(3);
            }
        }
        if (dungtuong3() || ktanduoi())
        {
            system("cls");
            SetColor(15);
            cout << "game over";
            break;
        }
        movee(x, y);
        Sleep(150);

    }
    _getch();
}
void man4()
{
    srand(time(NULL));
    ShowCur(0);
    buildwall4();
    ranxuathien();
    int x = X[0];
    int y = Y[0];
    int xfood, yfood;
    food4(xfood, yfood);
    SetColor(4);
    gotoXY(xfood, yfood); cout << char(3);
    int check = 1;
    while (true)
    {
        gotoXY(X[len], Y[len]);
        cout << " ";
        snakemove();
        xoasuxuathien();
        if (_kbhit())
        {
            char c = _getch();
            if (c == 'w' && check != 3)
            {
                check = 1;
            }
            else if (c == 'd' && check != 4)
            {
                check = 2;
            }
            else if (c == 's' && check != 1)
            {
                check = 3;
            }
            else if (c == 'a' && check != 2)
            {
                check = 4;
            }
        }
        if (check == 1)
        {
            y--;
        }
        else if (check == 2)
        {
            x++;
        }
        else if (check == 3)
        {
            y++;
        }
        else if (check == 4)
        {
            x--;
        }
        if ((x == 50 && y == 0) && (len % 6 == 2) && (len > 2)) {
            deletesnake();
            for (int x = 30; x <= 44; x++)
            {
                gotoXY(x, 8);
                cout << " ";
                gotoXY(x, 12);
                cout << " ";
            }
            for (int x = 56; x <= 70; x++)
            {
                gotoXY(x, 8);
                cout << " ";
                gotoXY(x, 12);
                cout << " ";
            }
            for (int y = 5; y <= 8; y++)
            {
                gotoXY(44, y);
                cout << " ";
                gotoXY(56, y);
                cout << " ";
            }
            for (int y = 12; y <= 15; y++)
            {
                gotoXY(44, y);
                cout << " ";
                gotoXY(56, y);
                cout << " ";
            }
            man5();
        }
        if (ktan(xfood, yfood))
        {
            len++;
            score.highscore += 10;
            if (len % 6 == 1)
            {
                food4(xfood, yfood);
                SetColor(6);
                gotoXY(xfood, yfood); cout << "$";
            }
            else if (len % 6 == 2)
            {
                SetColor(11);
                gotoXY(49, 0); cout << char(219);
                gotoXY(50, 0); cout << " ";
                gotoXY(51, 0); cout << char(219);
            }
            else
            {
                food4(xfood, yfood);
                SetColor(4);
                gotoXY(xfood, yfood); cout << char(3);
            }
        }
        if (dungtuong4() || ktanduoi())
        {
            system("cls");
            SetColor(15);
            cout << "game over";
            break;
        }
        movee(x, y);
        Sleep(150);

    }
    _getch();
}
void man5()
{
    srand(time(NULL));
    ShowCur(0);
    buildwall5();
    ranxuathien();
    int x = X[0];
    int y = Y[0];
    int xfood, yfood;
    food5(xfood, yfood);
    SetColor(4);
    gotoXY(xfood, yfood); cout << char(3);
    int check = 1;
    while (true)
    {
        gotoXY(X[len], Y[len]);
        cout << " ";
        snakemove();
        xoasuxuathien();
        if (_kbhit())
        {
            char c = _getch();
            if (c == 'w' && check != 3)
            {
                check = 1;
            }
            else if (c == 'd' && check != 4)
            {
                check = 2;
            }
            else if (c == 's' && check != 1)
            {
                check = 3;
            }
            else if (c == 'a' && check != 2)
            {
                check = 4;
            }
        }
        if (check == 1)
        {
            y--;
        }
        else if (check == 2)
        {
            x++;
        }
        else if (check == 3)
        {
            y++;
        }
        else if (check == 4)
        {
            x--;
        }
        if ((x == 50 && y == 0) && (len % 6 == 2) && (len > 2)) {
            system("cls");
            cout << "YOU WIN";
        }
        if (ktan(xfood, yfood))
        {
            len++;
            score.highscore += 10;
            if (len % 6 == 1)
            {
                food5(xfood, yfood);
                SetColor(6);
                gotoXY(xfood, yfood); cout << "$";
            }
            else if (len % 6 == 2)
            {
                SetColor(11);
                gotoXY(49, 0); cout << char(219);
                gotoXY(50, 0); cout << " ";
                gotoXY(51, 0); cout << char(219);
            }
            else
            {
                food5(xfood, yfood);
                SetColor(4);
                gotoXY(xfood, yfood); cout << char(3);
            }
        }
        if (dungtuong5() || ktanduoi())
        {
            system("cls");
            SetColor(15);
            cout << "game over";
            break;
        }
        movee(x, y);
        Sleep(150);

    }
    _getch();
}