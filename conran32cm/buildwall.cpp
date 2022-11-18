#include<iostream>
#include"library.h"
#include<Windows.h>
#include "buildwall.h"
using namespace std;

void buildwall1()
{
    SetColor(11);
    for (int x = 0; x <= 100; x++)
    {
        gotoXY(x, 0);
        cout << char(196);
        gotoXY(x, 20);
        cout << char(196);
    }
    for (int y = 0; y <= 20; y++)
    {
        gotoXY(0, y);
        cout << char(179);
        gotoXY(100, y);
        cout << char(179);
    }
    gotoXY(0, 20); cout << char(192);
    gotoXY(100, 0); cout << char(191);
    gotoXY(100, 20); cout << char(217);
    gotoXY(0, 0); cout << char(218);
}
void buildwall2()
{
    SetColor(11);
    for (int x = 0; x <= 100; x++)
    {
        gotoXY(x, 0);
        cout << char(196);
        gotoXY(x, 20);
        cout << char(196);
    }
    for (int y = 0; y <= 20; y++)
    {
        gotoXY(0, y);
        cout << char(179);
        gotoXY(100, y);
        cout << char(179);
    }
    gotoXY(0, 20); cout << char(192);
    gotoXY(100, 0); cout << char(191);
    gotoXY(100, 20); cout << char(217);
    gotoXY(0, 0); cout << char(218);
    for (int x = 30; x <= 70; x++)
    {
        gotoXY(x, 10);
        cout << char(196);
    }
}
void buildwall3()
{
    SetColor(11);
    for (int x = 0; x <= 100; x++)
    {
        gotoXY(x, 0);
        cout << char(196);
        gotoXY(x, 20);
        cout << char(196);
    }
    for (int y = 0; y <= 20; y++)
    {
        gotoXY(0, y);
        cout << char(179);
        gotoXY(100, y);
        cout << char(179);
    }
    gotoXY(0, 20); cout << char(192);
    gotoXY(100, 0); cout << char(191);
    gotoXY(100, 20); cout << char(217);
    gotoXY(0, 0); cout << char(218);
    for (int x = 30; x <= 70; x++)
    {
        gotoXY(x, 8);
        cout << char(196);
        gotoXY(x, 12);
        cout << char(196);
    }
}
void buildwall4()
{
    SetColor(11);
    for (int x = 0; x <= 100; x++)
    {
        gotoXY(x, 0);
        cout << char(196);
        gotoXY(x, 20);
        cout << char(196);
    }
    for (int y = 0; y <= 20; y++)
    {
        gotoXY(0, y);
        cout << char(179);
        gotoXY(100, y);
        cout << char(179);
    }
    gotoXY(0, 20); cout << char(192);
    gotoXY(100, 0); cout << char(191);
    gotoXY(100, 20); cout << char(217);
    gotoXY(0, 0); cout << char(218);
    for (int x = 30; x <= 44; x++)
    {
        gotoXY(x, 8);
        cout << char(196);
        gotoXY(x, 12);
        cout << char(196);
    }
    for (int x = 56; x <= 70; x++)
    {
        gotoXY(x, 8);
        cout << char(196);
        gotoXY(x, 12);
        cout << char(196);
    }
    for (int y = 5; y <= 8; y++)
    {
        gotoXY(44, y);
        cout << char(179);
        gotoXY(56, y);
        cout << char(179);
    }
    for (int y = 12; y <= 15; y++)
    {
        gotoXY(44, y);
        cout << char(179);
        gotoXY(56, y);
        cout << char(179);
    }
    gotoXY(44, 12); cout << char(191);
    gotoXY(56, 8); cout << char(192);
    gotoXY(56, 12); cout << char(218);
    gotoXY(44, 8); cout << char(217);
}
void buildwall5()
{
    SetColor(11);
    for (int x = 0; x <= 100; x++)
    {
        gotoXY(x, 0);
        cout << char(196);
        gotoXY(x, 20);
        cout << char(196);
    }
    for (int y = 0; y <= 20; y++)
    {
        gotoXY(0, y);
        cout << char(179);
        gotoXY(100, y);
        cout << char(179);
    }
    gotoXY(0, 20); cout << char(192);
    gotoXY(100, 0); cout << char(191);
    gotoXY(100, 20); cout << char(217);
    gotoXY(0, 0); cout << char(218);
    for (int x = 30; x <= 44; x++)
    {
        gotoXY(x, 5);
        cout << char(196);
        gotoXY(x, 15);
        cout << char(196);
    }
    for (int x = 56; x <= 70; x++)
    {
        gotoXY(x, 5);
        cout << char(196);
        gotoXY(x, 15);
        cout << char(196);
    }
    for (int y = 5; y <= 8; y++)
    {
        gotoXY(30, y);
        cout << char(179);
        gotoXY(70, y);
        cout << char(179);
    }
    for (int y = 12; y <= 15; y++)
    {
        gotoXY(30, y);
        cout << char(179);
        gotoXY(70, y);
        cout << char(179);
    }
    gotoXY(30, 15); cout << char(192);
    gotoXY(70, 5); cout << char(191);
    gotoXY(70, 15); cout << char(217);
    gotoXY(30, 5); cout << char(218);
    for (int x = 44; x <= 56; x++)
    {
        gotoXY(x, 7); cout << char(196);
        gotoXY(x, 13); cout << char(196);
    }
}
