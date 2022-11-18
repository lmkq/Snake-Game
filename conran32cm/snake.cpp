#include<iostream>
#include<Windows.h>
#include"library.h"
#include "snake.h"
using namespace std;

int X[100 * 20], Y[100 * 20];
int len = 2;
int snake[33] = { 4,8,0,7,2,1,1,2,6,1,1,7,2,1,1,2,1,8,6,7,2,1,1,2,9,0,4,7,2,1,1,2 };

void buildsnake() //randautien
{
    int x = 50;
    int y = 18;
    for (int i = 0; i < len; i++)
    {
        X[i] = x;
        Y[i] = y;
        y--;
    }
}
void ranxuathien()
{
    int x = 50;
    int y = 19;
    for (int i = 0; i < len; i++)
    {
        X[i] = x;
        Y[i] = y;
        y++;
    }
}
void xoasuxuathien()
{
    SetColor(11);
    gotoXY(50, 20); cout << char(196);
    for (int y = 21; y <= 21 + len; y++)
    {
        gotoXY(50, y);
        cout << " ";
    }
}
void deletesnake()
{
    for (int i = 0; i < len; i++)
    {
        gotoXY(X[i], Y[i]);
        cout << " ";
    }
}
void snakemove()//lam con ran xuat hien
{
    int k = 0;
    for (int i = 0; i < len; i++)
    {
        if (k % 16 == 0)
        {
            k++;
        }
        SetColor(k);
        gotoXY(X[i], Y[i]);
        cout << snake[i];
        k++;
    }
}
void movee(int x, int y)// di chuyen den toa do (x,y)
{
    for (int i = len; i > 0; i--)
    {
        X[i] = X[i - 1];
        Y[i] = Y[i - 1];
    }
    X[0] = x;
    Y[0] = y;
}
bool ktan(int x, int y)
{
    if (X[0] == x && Y[0] == y)
    {
        PlaySound(TEXT("food.wav"), NULL, SND_APPLICATION | SND_ASYNC);
        return true;
    }
    else return false;
}

bool ktanduoi()
{
    for (int i = 1; i < len; i++)
        if (X[0] == X[i] && Y[0] == Y[i]) return true;
    return false;
}