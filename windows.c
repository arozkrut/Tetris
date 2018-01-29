//
// Created by aleksandra on 26.01.18.
//
#include "tetris.h"

/* I XXXX    0
 *
 * J X       1
 *   XXX
 *
 * L   X     2
 *   XXX
 *
 * O XX      4
 *   XX
 *
 * S  XX     5
 *   XX
 *
 * Z XX      6
 *    XX
 *
 * T  X      3
 *   XXX
 *
 * NORMAL    7
*/

void DestroyWindow(WINDOW *win)
{
    wborder(win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
    ClearWindow(win, ' ');
    wrefresh(win);
    delwin(win);
}

WINDOW *CreateWindow(int height, int width, int starty, int startx)
{
    WINDOW *win;
    win=newwin(height, width, starty, startx);
    return win;
}

void ClearWindow(WINDOW *win, const chtype character)
{
    int maxx;
    int maxy;
    getmaxyx(win, maxy, maxx);

    for(int i=0;i<=maxy;++i)
    {
        for(int j=0;j<=maxx;++j)
        {
            mvwaddch(win,i,j,character);
        }
    }

}

void InitColors()
{
    init_pair(1, COLOR_BLUE, COLOR_BLACK);
    init_pair(2, COLOR_WHITE, COLOR_BLACK);
    init_pair(3, COLOR_CYAN, COLOR_BLACK);
    init_pair(4, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(5, COLOR_YELLOW, COLOR_BLACK);
    init_pair(6, COLOR_RED, COLOR_BLACK);
    init_pair(7, COLOR_GREEN, COLOR_BLACK);
    init_pair(8, COLOR_WHITE, COLOR_BLACK);
    init_pair(9, COLOR_CYAN, COLOR_BLUE);
}