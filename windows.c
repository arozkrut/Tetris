//
// Created by aleksandra on 26.01.18.
//
#include "tetris.h"


void DestroyWindow(WINDOW *win)
{
    wborder(win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
    wclear(win);
    wrefresh(win);
    delwin(win);
}

WINDOW *CreateWindow(int height, int width, int starty, int startx)
{
    WINDOW *win;
    win=newwin(height, width, starty, startx);
    return win;
}