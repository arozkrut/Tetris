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
    wborder(win, ' ', ' ', ' ',' ',' ',' ',' ',' ');                     /* czyscimy krawedzie okna */
    ClearWindow(win, ' ');                                               /* czyscimy reszte okna */
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
    wrefresh(win);
}

void SaveWindows(WINDOW *matrix, WINDOW *nextWin, WINDOW *scoreWin)
{
    FILE *matrixFile;                                               /* zapisujemy stan okien do plikow */
    FILE *nextWinFile;
    FILE *scoreWinFile;

    matrixFile=fopen( MATRIXWINFILE, "w");
    nextWinFile=fopen( NEXTWINFILE, "w");
    scoreWinFile= fopen( SCOREWINFILE, "w");

    putwin(matrix, matrixFile);
    putwin(nextWin, nextWinFile);
    putwin(scoreWin, scoreWinFile);

    fclose(matrixFile);
    fclose(nextWinFile);
    fclose(scoreWinFile);

}

void RefreshWindows(WINDOW *matrix, WINDOW *nextWin, WINDOW *scoreWin)
{
    FILE *matrixFile;                                           /* odczytujemy stan okien z pliku i je odswiezamy */
    FILE *nextWinFile;
    FILE *scoreWinFile;

    matrixFile=fopen( MATRIXWINFILE, "r");
    nextWinFile=fopen( NEXTWINFILE, "r");
    scoreWinFile= fopen( SCOREWINFILE, "r");

    ClearWindow(stdscr,' ');
    attron(A_BOLD);
    mvprintw((getmaxy(stdscr)/2)-(MATRIXHEIGHT/2)+NEXTWINDOWHEIGHT+2*DISTANCE+SCOREWINDOWHEIGHT, getmaxx(stdscr)/2+DISTANCE+5, "Press p to pause");
    attroff(A_BOLD);
    refresh();

    matrix=getwin(matrixFile);
    nextWin=getwin(nextWinFile);
    scoreWin=getwin(scoreWinFile);

    wrefresh(matrix);
    wrefresh(nextWin);
    wrefresh(scoreWin);

    fclose(matrixFile);
    fclose(nextWinFile);
    fclose(scoreWinFile);

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
    init_pair(10, COLOR_BLACK, COLOR_BLACK);
    init_pair(11, COLOR_RED, COLOR_RED);
    init_pair(12, COLOR_YELLOW, COLOR_RED);
}