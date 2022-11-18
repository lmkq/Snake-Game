#pragma once

struct hscore
{
    char name[20];
    int highscore;
};

bool checkhighscore();
void gethighscore();
void showhighscore();
