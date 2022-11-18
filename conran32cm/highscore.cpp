#include <iostream>
#include "highscore.h"
#include <fstream>

#pragma comment(lib, "winmm.lib")
const char* fname = "highscore.txt";
hscore score, list[5];;
using namespace std;

bool checkhighscore()
{
    FILE* f;
    fopen_s(&f, fname, "rt");
    for (int i = 0; i < 5; i++)
    {
        fscanf_s(f, "%s", list[i].name, 20);
        fscanf_s(f, "  :   %d\n", &list[i].highscore);
    }
    for (int i = 0; i < 5; i++)
    {
        if (score.highscore > list[i].highscore)
        {
            fclose(f);
            return true;
        }
    }
    fclose(f);
    return false;
}
void gethighscore()
{
    FILE* f;
    fopen_s(&f, fname, "wt");
    for (int i = 0; i < 5; i++)
    {
        if (score.highscore > list[i].highscore)
        {
            for (int j = 4; j > i; j--)
            {
                list[j] = list[j - 1];
            }
            list[i] = score;
            break;
        }
    }
    for (int i = 0; i < 5; i++)
    {
        fprintf(f, "%s   :   %d\n", list[i].name, list[i].highscore);
    }
    fclose(f);
}
void showhighscore()
{
    for (int i = 0; i < 5; i++)
        cout << list[i].name << "    :   " << list[i].highscore << endl;
}