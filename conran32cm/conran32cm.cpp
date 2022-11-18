// conran32cm.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "library.h"
#include <fstream>
#include <windowsx.h>
#include <mmsystem.h>
#include <stdio.h>
#include "Windows.h"
#include <algorithm>
#include <chrono>
#include<vector>
#include"dongho.h"
#include<string>

#pragma comment(lib, "winmm.lib")
using namespace std;
using namespace std::chrono;
const char* fname = "highscore.txt";
const char* path = "loadgame.txt";

struct BOX      // nút chức năng ở menu
{
    int x, y;   // tọa độ x,y của nút tính theo góc trên cùng bên trái
    int w, h;     // chiều rộng, chiều cao của nút.
    string text;  // nội dung của nút chức năng
    int color, highlight;  // màu chữ, màu highlight.
};

/* vị trí xuất hiện của nút đầu tiên*/
int vitriXbandau = 55;
int vitriYbandau = 10;

int color = 224; // mau cua box
int highlight = 64; // mau highlight

int soluongbox = 8;
int man, xfood, yfood, diem, huong;
char ten[16];

BOX* DanhSachBox = new BOX[soluongbox];

int indexCuaMenuDangDuocChon = 0;
int khoang_cach_giua_2_menu = 2;

int on = 0;
struct hscore
{
    char name[20];
    int highscore;
    int time;
};
int X[100 * 20], Y[100 * 20];
int snake[33] = { 4,8,0,7,2,1,1,2,6,1,1,7,2,1,1,2,1,8,6,7,2,1,1,2,9,0,4,7,2,1,1,2 };
int len = 2;
hscore score, list[5];

void wall_menu();
void printfascii(const char* filename, int color, bool random_color);
void box(BOX B);
void menu();
void endgame();
HANDLE hStdin;
DWORD fdwSaveOldMode;
void playload(const char* path, int& xfood, int& yfood, int& len, int& man, char ten[], int X[], int Y[], int& diem, int& huong);
void luugame(const char* path, int& xfood, int& yfood, int& len, int& man, char ten[], int X[], int Y[], int& diem, int& huong);
void playnew();
void buildsnake();
void ranxuathien();
void xoasuxuathien();
void buildwall1();
void buildwall2();
void buildwall3();
void buildwall4();
void buildwall5();
void deletesnake();
void snakemove();
void movee(int x, int y);
bool dungtuong1();
bool dungtuong2();
bool dungtuong3();
bool dungtuong4();
bool dungtuong5();
void food1(int& xfood, int& yfood);
void food2(int& xfood, int& yfood);
void food3(int& xfood, int& yfood);
void food4(int& xfood, int& yfood);
void food5(int& xfood, int& yfood);
bool ktan(int xfood, int yfood);
bool ktanduoi();
void man1(int& xfood, int& yfood, int& diem, int& huong);
void man2(int& xfood, int& yfood, int& diem, int& huong);
void man3(int& xfood, int& yfood, int& diem, int& huong);
void man4(int& xfood, int& yfood, int& diem, int& huong);
void man5(int& xfood, int& yfood, int& diem, int& huong);
bool checkhighscore();
void gethighscore();
void showhighscore();
void playmusic();
void cachchoi();
void printLoadingBar();
void gameover();
void dongho();
void menu_event();
int main()
{
    menu_event();


    return 0;
}

void playload(const char* path, int& xfood, int& yfood, int& len, int& man, char ten[], int X[], int Y[], int& diem, int& huong)
{
    ifstream f;
    f.open(path, ios::in);
    f >> xfood;
    f >> yfood;
    f >> len;
    f >> man;
    f.ignore();
    f.getline(ten, 16);
    for (int i = 0; i < strlen(ten); i++)
    {
        score.name[i] = ten[i];
    }
    for (int i = 0; i < len; i++)
    {
        f >> X[i] >> Y[i];
    }
    f >> diem;
    f >> huong;
    srand(time(NULL));
    ShowCur(0);
    switch (man)
    {
    case 1:
    {
        buildwall1();
        break;
    }
    case 2:
    {
        buildwall2();
        break;
    }
    case 3:
    {
        buildwall3();
        break;
    }
    case 4:
    {
        buildwall4();
        break;
    }
    case 5:
    {
        buildwall5();
        break;
    }
    }
    cachchoi();
    switch (man)
    {
    case 1:
    {
        man1(xfood, yfood, diem, huong);
        break;
    }
    case 2:
    {
        man2(xfood, yfood, diem, huong);
        break;
    }
    case 3:
    {
        man3(xfood, yfood, diem, huong);
        break;
    }
    case 4:
    {
        man4(xfood, yfood, diem, huong);
        break;
    }
    case 5:
    {
        man5(xfood, yfood, diem, huong);
        break;
    }
    }
    f.close();
}
void luugame(const char* path, int& xfood, int& yfood, int& len, int& man, char ten[], int X[], int Y[], int& diem, int& huong)
{
    ofstream g;
    g.open(path, ios::out);
    g << xfood << " " << yfood << "\n";
    g << len << "\n";
    g << man << "\n";
    g << ten << "\n";
    for (int i = 0; i < len; i++)
    {
        g << X[i] << " " << Y[i] << "\n";
    }
    g << diem << "\n";
    g << huong << "\n";
    g.close();
}
void playnew()
{

    int xfood, yfood;
    SetColor(7);
    gotoXY(51, 12); cout << "NHAP TEN NGUOI CHOI: ";
    cin >> score.name;
    //printLoadingBar();
    system("cls");
    srand(time(NULL));
    ShowCur(0);
    buildwall1();
    buildsnake();
    food1(xfood, yfood);
    int huong = 1;
    man1(xfood, yfood, score.highscore, huong);
    playmusic();
    if (checkhighscore() == true)
    {
        gethighscore();
    };
    cout << endl;
    _getch();
}
void buildwall1()
{
    SetColor(11);
    for (int x = 0; x <= 100; x++)
    {
        Sleep(10);
        gotoXY(x, 0);
        cout << char(220);
        gotoXY(x, 20);
        cout << char(220);
    }
    for (int y = 0; y <= 20; y++)
    {
        Sleep(20);
        gotoXY(0, y);
        cout << char(219);
        gotoXY(100, y);
        cout << char(219);
    }
    gotoXY(0, 20); cout << char(219);
    gotoXY(100, 0); cout << char(220);
    gotoXY(100, 20); cout << char(219);
    gotoXY(0, 0); cout << char(220);
}
void buildwall2()
{
    SetColor(11);
    for (int x = 0; x <= 100; x++)
    {
        Sleep(10);
        gotoXY(x, 0);
        cout << char(220);
        gotoXY(x, 20);
        cout << char(220);
    }
    for (int y = 0; y <= 20; y++)
    {
        Sleep(20);
        gotoXY(0, y);
        cout << char(219);
        gotoXY(100, y);
        cout << char(219);
    }
    gotoXY(0, 20); cout << char(219);
    gotoXY(100, 0); cout << char(220);
    gotoXY(100, 20); cout << char(219);
    gotoXY(0, 0); cout << char(220);
    for (int x = 30; x <= 70; x++)
    {
        Sleep(10);
        gotoXY(x, 10);
        cout << char(220);
    }
}
void buildwall3()
{
    SetColor(11);
    for (int x = 0; x <= 100; x++)
    {
        Sleep(10);
        gotoXY(x, 0);
        cout << char(220);
        gotoXY(x, 20);
        cout << char(220);
    }
    for (int y = 0; y <= 20; y++)
    {
        Sleep(20);
        gotoXY(0, y);
        cout << char(219);
        gotoXY(100, y);
        cout << char(219);
    }
    gotoXY(0, 20); cout << char(219);
    gotoXY(100, 0); cout << char(220);
    gotoXY(100, 20); cout << char(219);
    gotoXY(0, 0); cout << char(220);
    for (int x = 30; x <= 70; x++)
    {
        Sleep(10);
        gotoXY(x, 8);
        cout << char(220);
        gotoXY(x, 12);
        cout << char(220);
    }
}
void buildwall4()
{
    SetColor(11);
    for (int x = 0; x <= 100; x++)
    {
        Sleep(10);
        gotoXY(x, 0);
        cout << char(220);
        gotoXY(x, 20);
        cout << char(220);
    }
    for (int y = 0; y <= 20; y++)
    {
        Sleep(20);
        gotoXY(0, y);
        cout << char(219);
        gotoXY(100, y);
        cout << char(219);
    }
    gotoXY(0, 20); cout << char(219);
    gotoXY(100, 0); cout << char(220);
    gotoXY(100, 20); cout << char(219);
    gotoXY(0, 0); cout << char(220);
    for (int x = 30; x <= 44; x++)
    {
        Sleep(10);
        gotoXY(x, 8);
        cout << char(220);
        gotoXY(x, 12);
        cout << char(220);
    }
    for (int x = 56; x <= 70; x++)
    {
        Sleep(10);
        gotoXY(x, 8);
        cout << char(220);
        gotoXY(x, 12);
        cout << char(220);
    }
    for (int y = 5; y <= 8; y++)
    {
        Sleep(10);
        gotoXY(44, y);
        cout << char(219);
        gotoXY(56, y);
        cout << char(219);
    }
    for (int y = 12; y <= 15; y++)
    {
        Sleep(10);
        gotoXY(44, y);
        cout << char(219);
        gotoXY(56, y);
        cout << char(219);
    }
    gotoXY(44, 12); cout << char(220);
    gotoXY(56, 8); cout << char(219);
    gotoXY(56, 12); cout << char(220);
    gotoXY(44, 8); cout << char(219);
}
void buildwall5()
{
    SetColor(11);
    for (int x = 0; x <= 100; x++)
    {
        Sleep(10);
        gotoXY(x, 0);
        cout << char(220);
        gotoXY(x, 20);
        cout << char(220);
    }
    for (int y = 0; y <= 20; y++)
    {
        Sleep(20);
        gotoXY(0, y);
        cout << char(219);
        gotoXY(100, y);
        cout << char(219);
    }
    gotoXY(0, 20); cout << char(219);
    gotoXY(100, 0); cout << char(220);
    gotoXY(100, 20); cout << char(219);
    gotoXY(0, 0); cout << char(220);
    for (int x = 30; x <= 44; x++)
    {
        Sleep(10);
        gotoXY(x, 5);
        cout << char(220);
        gotoXY(x, 15);
        cout << char(220);
    }
    for (int x = 56; x <= 70; x++)
    {
        Sleep(10);
        gotoXY(x, 5);
        cout << char(220);
        gotoXY(x, 15);
        cout << char(220);
    }
    for (int y = 5; y <= 8; y++)
    {
        Sleep(10);
        gotoXY(30, y);
        cout << char(219);
        gotoXY(70, y);
        cout << char(219);
    }
    for (int y = 12; y <= 15; y++)
    {
        Sleep(10);
        gotoXY(30, y);
        cout << char(219);
        gotoXY(70, y);
        cout << char(219);
    }
    gotoXY(30, 15); cout << char(219);
    gotoXY(70, 5); cout << char(220);
    gotoXY(70, 15); cout << char(219);
    gotoXY(30, 5); cout << char(220);
    for (int x = 44; x <= 56; x++)
    {
        Sleep(10);
        gotoXY(x, 7); cout << char(220);
        gotoXY(x, 13); cout << char(220);
    }
}
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
        if (X[i] > 0 && X[i] < 100 && Y[i]>0 && Y[i] < 20)
        {
            gotoXY(X[i], Y[i]);
            cout << snake[i];
        }
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
void man1(int& xfood, int& yfood, int& diem, int& huong)
{
    PlaySound(TEXT("sound.wav"), NULL, SND_APPLICATION | SND_ASYNC);
    int man = 1;
    if (len % 6 == 1)
    {
        SetColor(6);
        gotoXY(xfood, yfood); cout << "$";
    }
    else if (len % 6 == 2 && len > 2)
    {
        SetColor(11);
        gotoXY(49, 0); cout << char(219);
        gotoXY(50, 0); cout << " ";
        gotoXY(51, 0); cout << char(219);
    }
    else
    {
        SetColor(4);
        gotoXY(xfood, yfood); cout << char(3);
    }
    int x = X[0];
    int y = Y[0];
    score.highscore = diem;
    int check = huong;
    SetColor(11);
    for (int x = 101; x <= 121; x++)
    {
        gotoXY(x, 0);
        cout << char(220);
        gotoXY(x, 20);
        cout << char(220);
        gotoXY(x, 8);
        cout << char(220);
    }
    for (int y = 0; y <= 20; y++)
    {
        gotoXY(121, y);
        cout << char(219);
    }
    gotoXY(121, 0); cout << char(220);
    cachchoi();
    while (true)
    {
        int check_esc = 0;
        gotoXY(50, 21);
        SetColor(14);
        gotoXY(105, 2);
        cout << "PLAYER : " << score.name;
        gotoXY(105, 4);
        cout << "LEVER : " << man;
        gotoXY(105, 6);
        cout << "SCORE : "; cout << score.highscore;
        SetColor(11);
        gotoXY(0, 0); cout << char(220);
        snakemove();
        if (X[len] > 0 && X[len] < 100 && Y[len]>0 && Y[len] < 20)
        {
            gotoXY(X[len], Y[len]);
            cout << " ";
        }
        if (_kbhit())
        {
            char c = _getch();

            if (c == 'l')
            {
                luugame(path, xfood, yfood, len, man, score.name, X, Y, score.highscore, check);
            }
            if (GetAsyncKeyState(VK_ESCAPE))
            {
                system("cls");
                cout << "Enter back to menu";
                len = 2;
                score.highscore = 0;
                break;
            }

            char z;
            if (c == 'p')
            {
                z = _getch();
                while (z != 'p')
                {
                    z = _getch();
                    if (z == 'l')
                    {
                        luugame(path, xfood, yfood, len, man, score.name, X, Y, score.highscore, check);
                    }
                    if (GetAsyncKeyState(VK_ESCAPE))
                    {
                        check_esc = 1;
                        system("cls");
                        cout << "Enter back to menu";
                        len = 2;
                        score.highscore = 0;
                        break;
                    }

                }
                if (check_esc == 1) break;
            }

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
            system("cls");
            buildwall2();
            ranxuathien();
            food2(xfood, yfood);
            int h = 1;
            man2(xfood, yfood, score.highscore, h);
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

            len = 2;
            score.highscore = 0;
            gameover();
            /*  break;*/
            return;
        }
        movee(x, y);
        Sleep(150);
    }

    char e;
    while (true)
    {
        if (_kbhit())
        {
            e = _getch();
            if (e == 13)
            {
                system("cls");
                menu_event();
            }
            else
            {
                return;
            }
        }
    }
}
void man2(int& xfood, int& yfood, int& diem, int& huong)
{
    int man = 2;
    if (len % 6 == 1)
    {
        SetColor(6);
        gotoXY(xfood, yfood); cout << "$";
    }
    else if (len % 6 == 2 && len > 8)
    {
        SetColor(11);
        gotoXY(49, 0); cout << char(219);
        gotoXY(50, 0); cout << " ";
        gotoXY(51, 0); cout << char(219);
    }
    else
    {
        SetColor(4);
        gotoXY(xfood, yfood); cout << char(3);
    }
    int x = X[0];
    int y = Y[0];
    score.highscore = diem;
    int check = huong;
    SetColor(11);
    for (int x = 101; x <= 121; x++)
    {
        gotoXY(x, 0);
        cout << char(220);
        gotoXY(x, 20);
        cout << char(220);
        gotoXY(x, 8);
        cout << char(220);
    }
    for (int y = 0; y <= 20; y++)
    {
        gotoXY(121, y);
        cout << char(219);
    }
    gotoXY(121, 0); cout << char(220);
    cachchoi();
    while (true)
    {
        gotoXY(50, 21);
        SetColor(14);
        gotoXY(105, 2);
        cout << "PLAYER : " << score.name;
        gotoXY(105, 4);
        cout << "LEVER : " << man;
        gotoXY(105, 6);
        cout << "SCORE : "; cout << score.highscore;
        SetColor(11);
        snakemove();
        if (X[len] > 0 && X[len] < 100 && Y[len]>0 && Y[len] < 20)
        {
            gotoXY(X[len], Y[len]);
            cout << " ";
        }

        SetColor(11);
        gotoXY(50, 20);  cout << char(220);
        if (_kbhit())
        {
            char c = _getch();
            if (c == 'l')
            {
                luugame(path, xfood, yfood, len, man, score.name, X, Y, score.highscore, check);
            }
            if (GetAsyncKeyState(VK_ESCAPE))
            {
                system("cls");
                cout << "Enter back to menu";
                len = 2;
                score.highscore = 0;
                break;
            }

            char z;
            if (c == 'p')
            {
                int check_esc = 0;
                z = _getch();
                while (z != 'p')
                {
                    if (_kbhit())
                    {
                        z = _getch();
                        if (z == 'l')
                        {
                            luugame(path, xfood, yfood, len, man, score.name, X, Y, score.highscore, check);
                        }
                        if (GetAsyncKeyState(VK_ESCAPE))
                        {
                            check_esc = 1;
                            system("cls");
                            cout << "Enter back to menu";
                            len = 2;
                            score.highscore = 0;
                            break;
                        }
                    }
                }
                if (check_esc == 1)break;
            }
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
            system("cls");
            buildwall3();
            ranxuathien();
            SetColor(11);
            gotoXY(50, 20);  cout << char(220);
            gotoXY(50, 21);
            food3(xfood, yfood);
            int h = 1;
            man3(xfood, yfood, score.highscore, h);
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

            len = 2;
            score.highscore = 0;
            gameover();
            break;
        }
        movee(x, y);
        Sleep(125);
    }
    char e;
    while (true)
    {
        if (_kbhit())
        {
            e = _getch();
            if (e == 13)
            {
                system("cls");
                menu_event();
            }
            else
            {
                return;
            }
        }
    }
}
void man3(int& xfood, int& yfood, int& diem, int& huong)
{
    int man = 3;
    gotoXY(0, 0); cout << char(220);
    if (len % 6 == 1)
    {
        SetColor(6);
        gotoXY(xfood, yfood); cout << "$";
    }
    else if (len % 6 == 2 && len > 14)
    {
        SetColor(11);
        gotoXY(49, 0); cout << char(219);
        gotoXY(50, 0); cout << " ";
        gotoXY(51, 0); cout << char(219);
    }
    else
    {
        SetColor(4);
        gotoXY(xfood, yfood); cout << char(3);
    }
    int x = X[0];
    int y = Y[0];
    score.highscore = diem;
    int check = huong;
    SetColor(11);
    for (int x = 101; x <= 121; x++)
    {
        gotoXY(x, 0);
        cout << char(220);
        gotoXY(x, 20);
        cout << char(220);
        gotoXY(x, 8);
        cout << char(220);
    }
    for (int y = 0; y <= 20; y++)
    {
        gotoXY(121, y);
        cout << char(219);
    }
    gotoXY(121, 0); cout << char(220);
    cachchoi();
    while (true)
    {
        gotoXY(50, 21);
        SetColor(14);
        gotoXY(105, 2);
        cout << "PLAYER : " << score.name;
        gotoXY(105, 4);
        cout << "LEVER : " << man;
        gotoXY(105, 6);
        cout << "SCORE : "; cout << score.highscore;
        SetColor(11);
        if (X[len] > 0 && X[len] < 100 && Y[len]>0 && Y[len] < 20)
        {
            gotoXY(X[len], Y[len]);
            cout << " ";
        }
        snakemove();
        SetColor(11);
        gotoXY(50, 20);  cout << char(220);
        if (_kbhit())
        {
            char c = _getch();
            if (c == 'l')
            {
                luugame(path, xfood, yfood, len, man, score.name, X, Y, score.highscore, check);
            }
            if (GetAsyncKeyState(VK_ESCAPE))
            {
                system("cls");
                cout << "Enter back to menu";

                break;
            }

            char z;
            if (c == 'p')
            {
                int check_esc = 0;
                z = _getch();
                while (z != 'p')
                {
                    if (_kbhit())
                    {
                        z = _getch();
                        if (z == 'l')
                        {
                            luugame(path, xfood, yfood, len, man, score.name, X, Y, score.highscore, check);
                        }
                        if (GetAsyncKeyState(VK_ESCAPE))
                        {
                            check_esc = 1;
                            system("cls");
                            cout << "Enter back to menu";
                            len = 2;
                            score.highscore = 0;
                            break;
                        }
                    }
                }
                if (check_esc == 1)break;
            }
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
            system("cls");
            /*for (int x = 30; x <= 70; x++)
            {
                gotoXY(x, 8);
                cout << " ";
                gotoXY(x, 12);
                cout << " ";
            }*/
            buildwall4();
            ranxuathien();
            SetColor(11);
            gotoXY(50, 20);  cout << char(220);
            gotoXY(50, 21);
            food4(xfood, yfood);
            int h = 1;
            man4(xfood, yfood, score.highscore, h);
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

            len = 2;
            score.highscore = 0;
            gameover();
            break;
        }
        movee(x, y);
        Sleep(100);

    }
    char e;
    while (true)
    {
        if (_kbhit())
        {
            e = _getch();
            if (e == 13)
            {
                system("cls");
                menu_event();
            }
            else
            {
                return;
            }
        }
    }
}
void man4(int& xfood, int& yfood, int& diem, int& huong)
{
    int man = 4;
    if (len % 6 == 1)
    {
        SetColor(6);
        gotoXY(xfood, yfood); cout << "$";
    }
    else if (len % 6 == 2 && len > 20)
    {
        SetColor(11);
        gotoXY(49, 0); cout << char(219);
        gotoXY(50, 0); cout << " ";
        gotoXY(51, 0); cout << char(219);
    }
    else
    {
        SetColor(4);
        gotoXY(xfood, yfood); cout << char(3);
    }
    int x = X[0];
    int y = Y[0];
    score.highscore = diem;
    int check = huong;
    SetColor(11);
    for (int x = 101; x <= 121; x++)
    {
        gotoXY(x, 0);
        cout << char(220);
        gotoXY(x, 20);
        cout << char(220);
        gotoXY(x, 8);
        cout << char(220);
    }
    for (int y = 0; y <= 20; y++)
    {
        gotoXY(121, y);
        cout << char(219);
    }
    gotoXY(121, 0); cout << char(220);
    cachchoi();
    while (true)
    {
        gotoXY(50, 21);
        SetColor(14);
        gotoXY(105, 2);
        cout << "PLAYER : " << score.name;
        gotoXY(105, 4);
        cout << "LEVER : " << man;
        gotoXY(105, 6);
        cout << "SCORE : "; cout << score.highscore;
        SetColor(11);
        if (X[len] > 0 && X[len] < 100 && Y[len]>0 && Y[len] < 20)
        {
            gotoXY(X[len], Y[len]);
            cout << " ";
        }
        snakemove();
        SetColor(11);
        gotoXY(50, 20);  cout << char(220);
        if (_kbhit())
        {
            char c = _getch();

            if (c == 'l')
            {
                luugame(path, xfood, yfood, len, man, score.name, X, Y, score.highscore, check);
            }
            if (GetAsyncKeyState(VK_ESCAPE))
            {
                system("cls");
                cout << "Enter back to menu";

                break;
            }
            char z;
            if (c == 'p')
            {
                int check_esc = 0;
                z = _getch();
                while (z != 'p')
                {
                    if (_kbhit())
                    {
                        z = _getch();
                        if (z == 'l')
                        {
                            luugame(path, xfood, yfood, len, man, score.name, X, Y, score.highscore, check);
                        }
                        if (GetAsyncKeyState(VK_ESCAPE))
                        {
                            check_esc = 1;
                            system("cls");
                            cout << "Enter back to menu";
                            len = 2;
                            score.highscore = 0;
                            break;
                        }
                    }
                }
                if (check_esc == 1)break;
            }
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
        if ((x == 50 && y == 0) && (len % 6 == 2) && (len > 2))
        {
            deletesnake();
            system("cls");
            /*for (int x = 30; x <= 44; x++)
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
            }*/
            buildwall5();
            ranxuathien();
            SetColor(11);
            gotoXY(50, 20);  cout << char(220);
            gotoXY(50, 21);
            food5(xfood, yfood);
            int h = 1;
            man5(xfood, yfood, score.highscore, h);
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

            len = 2;
            score.highscore = 0;
            gameover();
            break;
        }
        movee(x, y);
        Sleep(75);

    }
    char e;
    while (true)
    {
        if (_kbhit())
        {
            e = _getch();
            if (e == 13)
            {
                system("cls");
                menu_event();
            }
            else
            {
                return;
            }
        }
    }
}
void man5(int& xfood, int& yfood, int& diem, int& huong)
{
    int man = 5;
    if (len % 6 == 1)
    {
        SetColor(6);
        gotoXY(xfood, yfood); cout << "$";
    }
    else if (len % 6 == 2 && len > 26)
    {
        SetColor(11);
        gotoXY(49, 0); cout << char(219);
        gotoXY(50, 0); cout << " ";
        gotoXY(51, 0); cout << char(219);
    }
    else
    {
        SetColor(4);
        gotoXY(xfood, yfood); cout << char(3);
    }
    int x = X[0];
    int y = Y[0];
    score.highscore = diem;
    int check = huong;
    SetColor(11);
    for (int x = 101; x <= 121; x++)
    {
        gotoXY(x, 0);
        cout << char(220);
        gotoXY(x, 20);
        cout << char(220);
        gotoXY(x, 8);
        cout << char(220);
    }
    for (int y = 0; y <= 20; y++)
    {
        gotoXY(121, y);
        cout << char(219);
    }
    gotoXY(121, 0); cout << char(220);
    cachchoi();
    while (true)
    {
        gotoXY(50, 21);
        SetColor(14);
        gotoXY(105, 2);
        cout << "PLAYER : " << score.name;
        gotoXY(105, 4);
        cout << "LEVER : " << man;
        gotoXY(105, 6);
        cout << "SCORE : "; cout << score.highscore;
        SetColor(11);
        if (X[len] > 0 && X[len] < 100 && Y[len]>0 && Y[len] < 20)
        {
            gotoXY(X[len], Y[len]);
            cout << " ";
        }
        snakemove();
        SetColor(11);
        gotoXY(50, 20);  cout << char(220);
        if (_kbhit())
        {
            char c = _getch();

            if (c == 'l')
            {
                luugame(path, xfood, yfood, len, man, score.name, X, Y, score.highscore, check);
            }
            if (GetAsyncKeyState(VK_ESCAPE))
            {
                system("cls");
                cout << "Enter back to menu";

                break;
            }
            char z;
            if (c == 'p')
            {
                int check_esc = 0;
                z = _getch();
                while (z != 'p')
                {
                    if (_kbhit())
                    {
                        z = _getch();
                        if (z == 'l')
                        {
                            luugame(path, xfood, yfood, len, man, score.name, X, Y, score.highscore, check);
                        }
                        if (GetAsyncKeyState(VK_ESCAPE))
                        {
                            check_esc = 1;
                            system("cls");
                            cout << "Enter back to menu";
                            len = 2;
                            score.highscore = 0;
                            break;
                        }
                    }
                }
                if (check_esc == 1)break;
            }
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
            SetColor(14);
            UINT cp = GetConsoleOutputCP();
            SetConsoleOutputCP(CP_UTF8);
            gotoXY(34, 11 + 0); cout << u8" ▄            ▄ ▄▄▄▄▄▄▄ ▄▄   ▄ ▄▄   ▄ ▄▄▄▄▄ ▄▄▄▄▄\n";
            gotoXY(34, 11 + 1); cout << u8" ▀█   █▀▀█   █▀    █    █▀▄  █ █▀▄  █ █     █   █\n";
            gotoXY(34, 11 + 2); cout << u8"  ▀▄ ▄▀  ▀▄ ▄▀     █    █  █ █ █  █ █ █▀▀▀▀ █▀█▀▀\n";
            gotoXY(34, 11 + 3); cout << u8"    █      █    ▄▄▄█▄▄▄ █   ██ █   ██ █▄▄▄▄ █ █▄▄\n";
            SetConsoleOutputCP(cp);

            break;
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

            len = 2;
            score.highscore = 0;
            gameover();
            break;
        }
        movee(x, y);
        Sleep(50);

    }
    char e;
    while (true)
    {
        if (_kbhit())
        {
            e = _getch();
            if (e == 13)
            {
                system("cls");
                menu_event();
            }
            else
            {
                return;
            }
        }
    }
}
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

    FILE* f;
    fopen_s(&f, fname, "rt");
    for (int i = 0; i < 5; i++)
    {
        fscanf_s(f, "%s", list[i].name, 20);
        fscanf_s(f, "  :   %d\n", &list[i].highscore);
    }
    system("cls");

    UINT cp = GetConsoleOutputCP();
    SetConsoleOutputCP(CP_UTF8);        SetColor(rand());
    gotoXY(20, 1 + 0); cout << u8" ▄	    ▄ ▄▄▄▄▄▄▄▄▄ ▄▄▄▄▄▄  ▄      ▄ ▄▄▄▄▄▄▄▄ ▄▄▄▄▄▄▄ ▄▄▄▄▄▄▄ ▄▄▄▄▄ ▄▄▄▄▄▄\n";        SetColor(rand());
    gotoXY(20, 1 + 1); cout << u8" █      █	  █     █       █      █ █        █	▀ █     █ █   █ █	 \n";        SetColor(rand());
    gotoXY(20, 1 + 2); cout << u8" █▀▀▀▀▀▀█	  █     █   ▀▀█ █▀▀▀▀▀▀█ ▀▀▀▀▀▀▀█ █       █     █ █▀█▀▀ █▀▀▀▀▀\n";        SetColor(rand());
    gotoXY(20, 1 + 3); cout << u8" █	    █ ▄▄▄▄█▄▄▄▄ █▄▄▄▄▄█ █      █ ▄▄▄▄▄▄▄█ █▄▄▄▄▄█ █▄▄▄▄▄█ █ █▄▄ █▄▄▄▄▄\n";
    SetConsoleOutputCP(cp);
    for (int i = 0; i < 5; i++)
    {
        SetColor(rand());
        cout << "\t" << list[i].name << "\t:\t" << list[i].highscore << endl;
    }
    fclose(f);
}
void playmusic()
{
    //bool isPlay = PlaySound(L"music.wav", NULL, SND_FILENAME);
    PlaySound(TEXT("music.wav"), NULL, SND_APPLICATION | SND_ASYNC);
}
void cachchoi()
{
    SetColor(14);
    gotoXY(102, 10);
    cout << "D : Right";
    gotoXY(112, 10);
    cout << "W : Up";
    gotoXY(102, 12);
    cout << "A : Left";
    gotoXY(112, 12);
    cout << "S : Down";
    gotoXY(102, 14);
    cout << "P : Pause/Continue";
    gotoXY(102, 16);
    cout << "L : Save";
    gotoXY(102, 18);
    cout << "ESC : Exit";
    SetColor(11);
}
void printLoadingBar()
{
    ShowCur(0);
    SetColor(11);
    gotoXY(7, 19);
    cout << "LOADING..";
    char x = 219;
    int r = 0;
    for (int i = 18; i <= 80; i++)
    {
        gotoXY(16, 19);
        cout << ".";
        Sleep(80);
        gotoXY(16, 19);
        cout << " ";
        gotoXY(i, 19);
        if (i <= 44)
        {
            Sleep(50);
        }
        else
        {
            Sleep(20);
        }
        cout << x;
        gotoXY(82, 19);
        if (i == 80)
        {
            cout << 100 << "%";
            gotoXY(16, 19);
            cout << ".";
            break;
        }
        else
        {
            cout << r << "%";
            r++;
        }
    }
}
void gameover()
{
    UINT cp = GetConsoleOutputCP();
    SetConsoleOutputCP(CP_UTF8);
    //setvbuf(stdout, nullptr, _IOFBF, 1000);
    SetColor(10);
    gotoXY(34, 10 + 0); cout << u8" ▄▄▄▄   ▄▄   ▄▄    ▄▄ ▄▄▄▄▄    ▄▄▄▄▄ ▄     ▄ ▄▄▄▄▄ ▄▄▄▄▄\n";
    gotoXY(34, 10 + 1); cout << u8" █     ▄▀▀▄  █▀▄  ▄▀█ █        █   █ ▀█   █▀ █     █   █\n";
    gotoXY(34, 10 + 2); cout << u8" █ ▀█ ▄█▄▄█▄ █ ▀▄▄▀ █ █▀▀▀▀    █   █  ▀▄ ▄▀  █▀▀▀▀ █▀█▀▀\n";
    gotoXY(34, 10 + 3); cout << u8" ▀▀▀▀ ▀    ▀ ▀  ▀▀  ▀ ▀▀▀▀▀    ▀▀▀▀▀    ▀    ▀▀▀▀▀ ▀  ▀▀\n";
    SetConsoleOutputCP(cp);
    PlaySound(TEXT("gameover.wav"), NULL, SND_APPLICATION | SND_ASYNC);
    Sleep(1500);

    SetColor(14);
    gotoXY(45, 10 + 5); cout << "PRESS ENTER TO GO BACK TO MENU !";
    gotoXY(45, 10 + 6); cout << "PRESS ANY KEY TO EXIT GAME !";
    SetColor(11);

    char x;
    while (true)
    {
        if (_kbhit())
        {
            x = _getch();
            if (x == 13)
            {
                break;
            }
            else
            {
                endgame();
            }
        }

    }
    menu_event();
}
void printfascii(const char* filename, int color, bool random_color)
{
    string line = "";
    ifstream inFile;
    inFile.open(filename);
    if (inFile.is_open())
    {
        while (getline(inFile, line))
        {
            if (random_color == true)
            {
                SetColor(color++);
                if (color > 15)color = 1;
                cout << line << endl;
            }
            else
            {
                SetColor(color);
                cout << line << endl;
            }

        }
    }
    else
    {
        cout << "file is failed";
    }
}
void box(BOX B)
{
    int len = B.text.length();

    gotoXY(B.x, B.y);

    textcolor(B.color);
    cout << " " << B.text;

    for (int i = 1; i <= B.w - len - 1; i++)
    {
        cout << " ";
    }
    textcolor(7);
}
void wall_menu(int color)
{
    int x_max = 125;
    int y_max = 27;
    SetColor(color);
    for (int x = 0; x <= x_max; x++)
    {
        gotoXY(x, 0);
        cout << char(220);
        gotoXY(x, y_max);
        cout << char(220);
    }
    for (int y = 0; y <= y_max; y++)
    {
        gotoXY(0, y);
        cout << char(219);
        gotoXY(x_max, y);
        cout << char(219);
    }
    gotoXY(0, y_max); cout << char(219);
    gotoXY(x_max, 0); cout << char(220);
    gotoXY(x_max, y_max); cout << char(219);
    gotoXY(0, 0); cout << char(220);
}
void wall_menu_mini(int color)
{
    int x_max = 80;
    int y_max = 20;
    SetColor(color);
    for (int x = 42; x <= x_max; x++)
    {
        gotoXY(x, 9);
        cout << char(205);
        gotoXY(x, y_max);
        cout << char(205);
    }

    for (int y = 9; y <= y_max; y++)
    {
        ;
        gotoXY(42, y);
        cout << char(186);
        gotoXY(x_max, y);
        cout << char(186);
    }

    // góc phải trên
    gotoXY(42, y_max); cout << char(200);
    //góc trái trên
    gotoXY(42, 9); cout << char(201);
    // góc trái dưới
    gotoXY(x_max, 9); cout << char(187);
    // góc phải dưới
    gotoXY(x_max, y_max); cout << char(188);

}
void menu()
{

    cout << "\n";
    printfascii("art_snake.txt", 9, true);

    gotoXY(100, 19);
    printfascii("art_snake02.txt", 8, false);


    wall_menu_mini(3);
    wall_menu(11);


    ShowCur(0);

    string TextBox[8];   //string chứa các nội dụng bên trong mỗi nút 

    TextBox[0] = "START GAME";
    TextBox[1] = "OPTIONS";
    TextBox[2] = "HIGH SCORE";
    TextBox[3] = "EXIT";
    TextBox[4] = "NEW GAME";
    TextBox[5] = "LOAD GAME";
    TextBox[6] = "HELP";
    TextBox[7] = "SETTING";

    /*tim o text co noi dung dai nhat de chuan hoa do dai cac nut nhu nhau*/
    int DoDaiLonNhat = TextBox[0].length();

    // chuân hóa ô menu về cùng 1 độ dài
    for (int i = 1; i < soluongbox; ++i)
    {
        int length = TextBox[i].length();

        if (length > DoDaiLonNhat)
            DoDaiLonNhat = length + 3;
    }
    DoDaiLonNhat += 2;

    // gán dữ liệu cho ô đầu tiên
    DanhSachBox[0].text = TextBox[0];
    DanhSachBox[0].color = highlight;
    DanhSachBox[0].highlight = highlight;
    DanhSachBox[0].w = DoDaiLonNhat;
    DanhSachBox[0].h = 2;
    DanhSachBox[0].x = vitriXbandau;
    DanhSachBox[0].y = vitriYbandau;
    box(DanhSachBox[0]);

    for (int i = 1; i < soluongbox; i++)
    {
        DanhSachBox[i].text = TextBox[i];
        DanhSachBox[i].color = color;
        DanhSachBox[i].highlight = highlight;
        DanhSachBox[i].w = DoDaiLonNhat;
        DanhSachBox[i].h = 2;
        DanhSachBox[i].x = vitriXbandau;
        DanhSachBox[i].y = DanhSachBox[i - 1].y + khoang_cach_giua_2_menu + 1;

        if (i == 4 || i == 6)
        {
            DanhSachBox[i].color = highlight;
            DanhSachBox[i].y = DanhSachBox[1].y;
        }
        else if (i == 5 || i == 7)
        {
            DanhSachBox[i].y = DanhSachBox[2].y;
        }

        if (i < 4)
        {
            box(DanhSachBox[i]);
        }
    }
}
void menu_event()
{
    PlaySound(TEXT("sound.wav"), NULL, SND_APPLICATION | SND_ASYNC);
    if (on == 0)
        PlaySound(TEXT("backgroundmusic.wav"), NULL, SND_APPLICATION | SND_ASYNC);
    system("cls");
    menu();
    indexCuaMenuDangDuocChon = 0;

    char c;
    while (true)
    {
        if (_kbhit())
        {
            c = _getch();
            if (c == 13) // enter
                break;
            else if (c == 80) // down
            {
                DanhSachBox[indexCuaMenuDangDuocChon].color = color;
                box(DanhSachBox[indexCuaMenuDangDuocChon]);

                indexCuaMenuDangDuocChon++;

                if (indexCuaMenuDangDuocChon == 4)
                {
                    indexCuaMenuDangDuocChon = 0;
                }

                DanhSachBox[indexCuaMenuDangDuocChon].color = highlight;
                box(DanhSachBox[indexCuaMenuDangDuocChon]);

            }
            else if (c == 72) //up
            {
                DanhSachBox[indexCuaMenuDangDuocChon].color = color;
                box(DanhSachBox[indexCuaMenuDangDuocChon]);

                indexCuaMenuDangDuocChon--;
                if (indexCuaMenuDangDuocChon < 0)
                {
                    indexCuaMenuDangDuocChon = 3;
                }

                DanhSachBox[indexCuaMenuDangDuocChon].color = highlight;
                box(DanhSachBox[indexCuaMenuDangDuocChon]);
            }
        }
    }
    switch (indexCuaMenuDangDuocChon)
    {
    case 0:
    {
        system("cls");
        cout << "\n";
        printfascii("art_snake.txt", 9, true);
        wall_menu_mini(3);


        box(DanhSachBox[4]);
        box(DanhSachBox[5]);

        indexCuaMenuDangDuocChon = 4;

        textcolor(7);
        char x;
        while (true)
        {
            if (_kbhit())
            {
                x = _getch();
                if (x == 13)
                {
                    break;
                }
                else if (x == 72)
                {
                    if (indexCuaMenuDangDuocChon > 0)
                    {
                        DanhSachBox[indexCuaMenuDangDuocChon].color = color; // Reset nút hiện tại trở lại thành màu cũ
                        box(DanhSachBox[indexCuaMenuDangDuocChon]); // Vẽ lại nút để nút có màu cũ

                        indexCuaMenuDangDuocChon--; // Thay đổi index qua nút tiếp theo

                        if (indexCuaMenuDangDuocChon < 4)
                        {
                            indexCuaMenuDangDuocChon = 5;
                        }

                        DanhSachBox[indexCuaMenuDangDuocChon].color = highlight; // Cập nhật nút tiếp theo sẽ có màu highlight
                        box(DanhSachBox[indexCuaMenuDangDuocChon]); // Vẽ lại nút để nút có màu mới
                    }
                }
                else if (x == 80)
                {
                    if (indexCuaMenuDangDuocChon <= 5)
                    {
                        DanhSachBox[indexCuaMenuDangDuocChon].color = color;
                        box(DanhSachBox[indexCuaMenuDangDuocChon]);

                        indexCuaMenuDangDuocChon++;

                        if (indexCuaMenuDangDuocChon > 5)
                        {
                            indexCuaMenuDangDuocChon = 4;
                        }

                        DanhSachBox[indexCuaMenuDangDuocChon].color = highlight;
                        box(DanhSachBox[indexCuaMenuDangDuocChon]);
                    }
                }
            }
        }

        if (indexCuaMenuDangDuocChon == 4)
        {
            system("cls");
            playnew();
        }
        else
        {
            system("cls");
            playload(path, xfood, yfood, len, man, ten, X, Y, diem, huong);
        }
    }break;

    case 1:
    {
        system("cls");
        cout << "\n";
        printfascii("art_snake.txt", 9, true);

        wall_menu_mini(4);

        box(DanhSachBox[6]);
        box(DanhSachBox[7]);

        indexCuaMenuDangDuocChon = 6;

        textcolor(7);
        char x;
        while (true)
        {
            if (_kbhit())
            {
                x = _getch();
                if (x == 13)
                {
                    break;
                }
                else if (x == 72)
                {
                    if (indexCuaMenuDangDuocChon > 0)
                    {
                        DanhSachBox[indexCuaMenuDangDuocChon].color = color; // Reset nút hiện tại trở lại thành màu cũ
                        box(DanhSachBox[indexCuaMenuDangDuocChon]); // Vẽ lại nút để nút có màu cũ

                        indexCuaMenuDangDuocChon--; // Thay đổi index qua nút tiếp theo

                        if (indexCuaMenuDangDuocChon < 6)
                        {
                            indexCuaMenuDangDuocChon = 7;
                        }

                        DanhSachBox[indexCuaMenuDangDuocChon].color = highlight; // Cập nhật nút tiếp theo sẽ có màu highlight
                        box(DanhSachBox[indexCuaMenuDangDuocChon]); // Vẽ lại nút để nút có màu mới
                    }
                }
                else if (x == 80)
                {
                    if (indexCuaMenuDangDuocChon <= 7)
                    {
                        DanhSachBox[indexCuaMenuDangDuocChon].color = color;
                        box(DanhSachBox[indexCuaMenuDangDuocChon]);

                        indexCuaMenuDangDuocChon++;

                        if (indexCuaMenuDangDuocChon > 7)
                        {
                            indexCuaMenuDangDuocChon = 6;
                        }

                        DanhSachBox[indexCuaMenuDangDuocChon].color = highlight;
                        box(DanhSachBox[indexCuaMenuDangDuocChon]);
                    }
                }
            }
        }

        if (indexCuaMenuDangDuocChon == 6)
        {
            system("cls");
            textcolor(7);
            printfascii("help.txt", 1, true);

            char z;
            while (true)
            {
                if (_kbhit())
                {
                    z = _getch();
                    if (z == 27) // esc
                    {
                        system("cls");
                        break;
                    }
                    else if (x == 13) // enter
                    {
                        system("cls");
                        playnew();
                        return;
                    }
                }
            }
            menu_event();
        }
        else // setting ở đây
        {
            system("cls");
            textcolor(13);
            gotoXY(10, 10);
            char yn;
            if (on == 1)
                cout << "DO YOU WANT TO TURN ON MUSIC (Y/N)\n";
            else
                cout << "DO YOU WANT TO TURN OFF MUSIC (Y/N)\n";
            gotoXY(50, 10);
            textcolor(15);
            cin >> yn;

            if (on == 0)
            {
                if (yn == 'y' || yn == 'Y')
                {
                    on = 1;
                }
            }
            else
            {
                if (yn == 'y' || yn == 'Y')
                {
                    on = 0;
                };
            }
            menu_event();
        }

    }break;

    case 2: {
        system("cls");
        showhighscore();
        SetColor(11);
        cout << "\n     Press ENTER to go back to MENU !" << endl;
        cout << "\n     Press ESC to exit game !" << endl;
        char x;
        while (true)
        {
            if (_kbhit())
            {
                x = _getch();
                if (x == 13)
                {
                    system("cls");
                    break;
                }
                else if (x == 27)
                {
                    endgame();
                }
            }
        }
        menu_event();
    }break;

    case 3:
    {
        system("cls");
        endgame();
    }break;
    }
}

void endgame()
{
    system("cls");
    printfascii("endgame.txt", 11, false);
    exit(0);
}