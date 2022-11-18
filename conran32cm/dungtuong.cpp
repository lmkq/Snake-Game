#include "dungtuong.h"

int X[100 * 20], Y[100 * 20];
bool dungtuong1()
{
    if (X[0] == 100 || X[0] == 0 || Y[0] == 0 || Y[0] == 20) return true;
    else return false;
}
bool dungtuong2()
{
    if (X[0] == 100 || X[0] == 0 || Y[0] == 0 || Y[0] == 20) return true;
    for (int x = 30; x <= 70; x++)
    {
        if (X[0] == x && Y[0] == 10) return true;
    }
    return false;
}
bool dungtuong3()
{
    if (X[0] == 100 || X[0] == 0 || Y[0] == 0 || Y[0] == 20) return true;
    for (int x = 30; x <= 70; x++)
    {
        if (X[0] == x && Y[0] == 8) return true;
        if (X[0] == x && Y[0] == 12) return true;
    }
    return false;
}
bool dungtuong4()
{
    if (X[0] == 100 || X[0] == 0 || Y[0] == 0 || Y[0] == 20) return true;
    for (int x = 30; x <= 44; x++)
    {
        if (X[0] == x && Y[0] == 8) return true;
        if (X[0] == x && Y[0] == 12) return true;
    }
    for (int x = 56; x <= 70; x++)
    {
        if (X[0] == x && Y[0] == 8) return true;
        if (X[0] == x && Y[0] == 12) return true;
    }
    for (int y = 5; y <= 8; y++)
    {
        if (X[0] == 44 && Y[0] == y) return true;
        if (X[0] == 56 && Y[0] == y) return true;
    }
    for (int y = 12; y <= 15; y++)
    {
        if (X[0] == 44 && Y[0] == y) return true;
        if (X[0] == 56 && Y[0] == y) return true;
    }
    return false;
}
bool dungtuong5()
{
    if (X[0] == 100 || X[0] == 0 || Y[0] == 0 || Y[0] == 20) return true;
    for (int x = 30; x <= 44; x++)
    {
        if (X[0] == x && Y[0] == 5) return true;
        if (X[0] == x && Y[0] == 15) return true;
    }
    for (int x = 56; x <= 70; x++)
    {
        if (X[0] == x && Y[0] == 5) return true;
        if (X[0] == x && Y[0] == 15) return true;
    }
    for (int y = 5; y <= 8; y++)
    {
        if (X[0] == 30 && Y[0] == y) return true;
        if (X[0] == 70 && Y[0] == y) return true;
    }
    for (int y = 12; y <= 15; y++)
    {
        if (X[0] == 30 && Y[0] == y) return true;
        if (X[0] == 70 && Y[0] == y) return true;
    }
    for (int x = 44; x <= 56; x++)
    {
        if (X[0] == x && Y[0] == 7) return true;
        if (X[0] == x && Y[0] == 13) return true;
    }
    return false;
}