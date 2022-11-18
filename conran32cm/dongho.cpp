#include<iostream>
#include "dongho.h"
#include"library.h"

using namespace std;
void dongho()
{
    //    //resizeConsole(550, 300);
    //    //gotoXY(120, 1);
    //    cout << "Nhan Phim Bat Ki De Bat Dau\n";
    //    //gotoXY(120, 2);
    //    printf("00 : 00\n");
    //    char x = _getch();
    //    int dem = 1;
    //    int k = 0, f = 0;
    //    int arr[100];
    //    int idx = 0;
    //    int brr[100];
    //    int check = 0;
    //    for (int i = 0; i < 60; i++)
    //    {
    //        for (int j = 0; j <= 60; j++)
    //        {
    //            //gotoXY(120, 3);
    //            //system("cls");
    //            //XoaManHinh();
    //            //gotoXY(120, 3);
    //            printf("%02d : %02d\n", i, j);
    //            //gotoXY(120, 4);
    //            printf("\nKet Qua Luu:\n");
    //            for (int f = 0; f < idx; f++)
    //            {
    //                //gotoXY(120, 3);
    //                printf("%02d : %02d\n", arr[f], brr[f]);
    //            }
    //            //gotoXY(120, 6);
    //            printf("\n\nSpace : Pause\t\tENTER : Save\t\tESC : Exit\n");
    //            Sleep(1000);
    //
    //            if (GetAsyncKeyState(VK_SPACE))
    //            {
    //                dem++;
    //            }
    //            if (dem % 2 == 0)
    //            {
    //                j--;
    //                char a = _getch();
    //            }
    //            if (GetAsyncKeyState(VK_ESCAPE))
    //            {
    //                goto loi;
    //            }
    //            if (GetAsyncKeyState(VK_RETURN))
    //            {
    //                arr[idx] = i;
    //                brr[idx] = j;
    //                idx++;
    //            }
    //
    //        }
    //    }
    //loi:
    int h = 0;
    int p = 0;
    int g = 0;
    gotoXY(101, 5);
    cout << 0 << h << ":" << 0 << p << ":" << 0 << g;
    Sleep(1000);
    for (int i = 0; i < 60; i++)
    {
        p = 0;
        h = i;
        for (int j = 0; j < 60; j++)
        {
            g = 0;
            p = j;
            for (int t = 0; t < 60; t++)
            {
                g = t;
                gotoXY(101, 5);
                if (h < 10) cout << 0 << h;
                else cout << h;
                cout << ":";
                if (p < 10)cout << 0 << p;
                else cout << p;
                cout << ":";
                if (g < 10)cout << 0 << g;
                else cout << g;
                Sleep(1000);
            }
        }
    }
}