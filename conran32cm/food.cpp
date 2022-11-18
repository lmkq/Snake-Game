#include "food.h"
#include<Windows.h>

int X[100 * 20], Y[100 * 20];
int len = 2;

void food1(int& xfood, int& yfood)
{
    xfood = rand() % (99) + 1;
    yfood = rand() % (19) + 1;
    for (int i = 0; i < len; i++)
    {
        if (xfood == X[i] && yfood == Y[i]) food1(xfood, yfood);
    }
}
void food2(int& xfood, int& yfood)
{
    xfood = rand() % (99) + 1;
    yfood = rand() % (19) + 1;
    for (int x = 30; x <= 70; x++)
    {
        if (xfood == x && yfood == 10) food2(xfood, yfood);
    }
    for (int i = 0; i < len; i++)
    {
        if (xfood == X[i] && yfood == Y[i]) food2(xfood, yfood);
    }
}
void food3(int& xfood, int& yfood)
{
    xfood = rand() % (99) + 1;
    yfood = rand() % (19) + 1;
    for (int x = 30; x <= 70; x++)
    {
        if (xfood == x && yfood == 8) food3(xfood, yfood);
        if (xfood == x && yfood == 12) food3(xfood, yfood);
    }
    for (int i = 0; i < len; i++)
    {
        if (xfood == X[i] && yfood == Y[i]) food3(xfood, yfood);
    }
}
void food4(int& xfood, int& yfood)
{
    xfood = rand() % (99) + 1;
    yfood = rand() % (19) + 1;

    for (int x = 30; x <= 44; x++)
    {
        if (xfood == x && yfood == 8) food4(xfood, yfood);
        if (xfood == x && yfood == 12) food4(xfood, yfood);
    }
    for (int x = 56; x <= 70; x++)
    {
        if (xfood == x && yfood == 8) food4(xfood, yfood);
        if (xfood == x && yfood == 12) food4(xfood, yfood);
    }
    for (int y = 5; y <= 8; y++)
    {
        if (xfood == 44 && yfood == y) food4(xfood, yfood);
        if (xfood == 56 && yfood == y) food4(xfood, yfood);
    }
    for (int y = 12; y <= 15; y++)
    {
        if (xfood == 44 && yfood == y) food4(xfood, yfood);
        if (xfood == 56 && yfood == y) food4(xfood, yfood);
    }
    for (int i = 0; i < len; i++)
    {
        if (xfood == X[i] && yfood == Y[i]) food4(xfood, yfood);
    }
}
void food5(int& xfood, int& yfood)
{
    xfood = rand() % (99) + 1;
    yfood = rand() % (19) + 1;
    for (int x = 30; x <= 44; x++)
    {
        if (xfood == x && yfood == 5) food5(xfood, yfood);
        if (xfood == x && yfood == 15) food5(xfood, yfood);
    }
    for (int x = 56; x <= 70; x++)
    {
        if (xfood == x && yfood == 5) food5(xfood, yfood);
        if (xfood == x && yfood == 15) food5(xfood, yfood);
    }
    for (int y = 5; y <= 8; y++)
    {
        if (xfood == 30 && yfood == y) food5(xfood, yfood);
        if (xfood == 70 && yfood == y) food5(xfood, yfood);
    }
    for (int y = 12; y <= 15; y++)
    {
        if (xfood == 30 && yfood == y) food5(xfood, yfood);
        if (xfood == 70 && yfood == y) food5(xfood, yfood);
    }
    for (int x = 44; x <= 56; x++)
    {
        if (xfood == x && yfood == 7) food5(xfood, yfood);
        if (xfood == x && yfood == 13) food5(xfood, yfood);
    }
    for (int i = 0; i < len; i++)
    {
        if (xfood == X[i] && yfood == Y[i]) food4(xfood, yfood);
    }
}