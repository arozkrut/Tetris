//
// Created by aleksandra on 27.01.18.
//

#include "tetris.h"
#define MATRIXWIDTH 20
#define MATRIXHEIGHT 20

#define NEXTWINDOWWIDTH 8
#define NEXTWINDOWHEIGHT 6

#define SCOREWINDOWWIDTH 26
#define SCOREWINDOWHEIGHT 5

#define DISTANCE 3

void PrepareNewGame(WINDOW *matrix, WINDOW *nextWin, WINDOW *scoreWin);
void CalculateCoordinates(int *matrixX, int *matrixY, int *nextX, int *nextY, int *scoreX, int *scoreY);

short int NewGame()
{
    WINDOW *matrix;
    WINDOW *nextWin;
    WINDOW *scoreWin;

    PrepareNewGame(matrix, nextWin, scoreWin);

    getch();

    return -1;
}

void PrepareNewGame(WINDOW *matrix, WINDOW *nextWin, WINDOW *scoreWin)
{
    attron(A_BOLD);

    mvprintw(getmaxy(stdscr)/2-1,getmaxx(stdscr)/2-11,"PRESS SOME KEY TO START");
    
    //attron(COLOR_PAIR(8));
    mvprintw(getmaxy(stdscr)/2-1,getmaxx(stdscr)/2-11,"                       ");
    //attron(COLOR_PAIR(9));

    getch();

    int matrixX, matrixY;
    int nextX, nextY;
    int scoreX, scoreY;

    CalculateCoordinates(&matrixX, &matrixY, &nextX, &nextY, &scoreX, &scoreY);

    matrix=CreateWindow(MATRIXHEIGHT, MATRIXWIDTH, matrixY, matrixX);
    nextWin=CreateWindow(NEXTWINDOWHEIGHT, NEXTWINDOWWIDTH, nextY, nextX);
    scoreWin=CreateWindow(SCOREWINDOWHEIGHT, SCOREWINDOWWIDTH, scoreY, scoreX);

    wattron(matrix, COLOR_PAIR(8) | A_BOLD);
    ClearWindow(matrix, ' ');
    box(matrix, 0, 0);
    wrefresh(matrix);

    wattron(nextWin, COLOR_PAIR(8) | A_BOLD);
    ClearWindow(nextWin, ' ');
    box(nextWin, 0, 0);
    wrefresh(nextWin);

    wattron(scoreWin, COLOR_PAIR(8) | A_BOLD);
    ClearWindow(scoreWin, ' ');
    box(scoreWin, 0, 0);
    wrefresh(scoreWin);


    mvprintw(scoreY+DISTANCE+SCOREWINDOWHEIGHT, scoreX, "Press p to pause");
    attroff(A_BOLD);
}

void CalculateCoordinates(int *matrixX, int *matrixY, int *nextX, int *nextY, int *scoreX, int *scoreY)
{
    *matrixY=(getmaxy(stdscr)/2)-(MATRIXHEIGHT/2);
    *matrixX=(getmaxx(stdscr)/2)-DISTANCE-MATRIXWIDTH;

    *nextY=*matrixY;
    *nextX=getmaxx(stdscr)/2+DISTANCE;

    *scoreY=*nextY+NEXTWINDOWHEIGHT+DISTANCE;
    *scoreX=*nextX;
}