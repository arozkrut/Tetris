//
// Created by aleksandra on 28.01.18.
//

#include "tetris.h"

void DrawI1(WINDOW *win, int blockY, int blockX, const chtype character);
void DrawI2(WINDOW *win, int blockY, int blockX, const chtype character);

void DrawJ1(WINDOW *win, int blockY, int blockX, const chtype character);
void DrawJ2(WINDOW *win, int blockY, int blockX, const chtype character);
void DrawJ3(WINDOW *win, int blockY, int blockX, const chtype character);
void DrawJ4(WINDOW *win, int blockY, int blockX, const chtype character);

void DrawL1(WINDOW *win, int blockY, int blockX, const chtype character);
void DrawL2(WINDOW *win, int blockY, int blockX, const chtype character);
void DrawL3(WINDOW *win, int blockY, int blockX, const chtype character);
void DrawL4(WINDOW *win, int blockY, int blockX, const chtype character);

void DrawT1(WINDOW *win, int blockY, int blockX, const chtype character);
void DrawT2(WINDOW *win, int blockY, int blockX, const chtype character);
void DrawT3(WINDOW *win, int blockY, int blockX, const chtype character);
void DrawT4(WINDOW *win, int blockY, int blockX, const chtype character);

void DrawO1(WINDOW *win, int blockY, int blockX, const chtype character);

void DrawS1(WINDOW *win, int blockY, int blockX, const chtype character);
void DrawS2(WINDOW *win, int blockY, int blockX, const chtype character);

void DrawZ1(WINDOW *win, int blockY, int blockX, const chtype character);
void DrawZ2(WINDOW *win, int blockY, int blockX, const chtype character);



void DrawBlock(WINDOW *win, short int block, int blockY, int blockX, int position, const chtype character)
{
    switch(block)
    {
        case 0:
        {
            switch(position)
            {
                case 1:
                {
                    DrawI1(win, blockY, blockX, character);
                    break;
                }
                case 2:
                {
                    DrawI2(win, blockY, blockX, character);
                    break;
                }
                case 3:
                {
                    DrawI1(win, blockY, blockX, character);
                    break;
                }
                case 4:
                {
                    DrawI2(win, blockY, blockX, character);
                    break;
                }
            }
            break;
        }
        case 1:
        {
            switch(position)
            {
                case 1:
                {
                    DrawJ1(win, blockY, blockX, character);
                    break;
                }
                case 2:
                {
                    DrawJ2(win, blockY, blockX, character);
                    break;
                }
                case 3:
                {
                    DrawJ3(win, blockY, blockX, character);
                    break;
                }
                case 4:
                {
                    DrawJ4(win, blockY, blockX, character);
                    break;
                }
            }
            break;
        }
        case 2:
        {
            switch(position)
            {
                case 1:
                {
                    DrawL1(win, blockY, blockX, character);
                    break;
                }
                case 2:
                {
                    DrawL2(win, blockY, blockX, character);
                    break;
                }
                case 3:
                {
                    DrawL3(win, blockY, blockX, character);
                    break;
                }
                case 4:
                {
                    DrawL4(win, blockY, blockX, character);
                    break;
                }
            }
            break;
        }
        case 3:
        {
            switch(position)
            {
                case 1:
                {
                    DrawT1(win, blockY, blockX, character);
                    break;
                }
                case 2:
                {
                    DrawT2(win, blockY, blockX, character);
                    break;
                }
                case 3:
                {
                    DrawT3(win, blockY, blockX, character);
                    break;
                }
                case 4:
                {
                    DrawT4(win, blockY, blockX, character);
                    break;
                }
            }
            break;
        }
        case 4:
        {
            switch(position)
            {
                case 1:
                {
                    DrawO1(win, blockY, blockX, character);
                    break;
                }
                case 2:
                {
                    DrawO1(win, blockY, blockX, character);
                    break;
                }
                case 3:
                {
                    DrawO1(win, blockY, blockX, character);
                    break;
                }
                case 4:
                {
                    DrawO1(win, blockY, blockX, character);
                    break;
                }
            }
            break;
        }
        case 5:
        {
            switch(position)
            {
                case 1:
                {
                    DrawS1(win, blockY, blockX, character);
                    break;
                }
                case 2:
                {
                    DrawS2(win, blockY, blockX, character);
                    break;
                }
                case 3:
                {
                    DrawS1(win, blockY, blockX, character);
                    break;
                }
                case 4:
                {
                    DrawS2(win, blockY, blockX, character);
                    break;
                }
            }
            break;
        }
        case 6:
        {
            switch(position)
            {
                case 1:
                {
                    DrawZ1(win, blockY, blockX, character);
                    break;
                }
                case 2:
                {
                    DrawZ2(win, blockY, blockX, character);
                    break;
                }
                case 3:
                {
                    DrawZ1(win, blockY, blockX, character);
                    break;
                }
                case 4:
                {
                    DrawZ2(win, blockY, blockX, character);
                    break;
                }
            }
            break;
        }
    }
}

/*
 * X
 * X
 * X
 * X
 */
void DrawI1(WINDOW *win, int blockY, int blockX, const chtype character)
{
    wattron(win, COLOR_PAIR(1));

    mvwaddch(win,blockY+1,2*blockX,character);
    mvwaddch(win,blockY+1,2*blockX+1,character);

    mvwaddch(win,blockY+2,2*blockX,character);
    mvwaddch(win,blockY+2,2*blockX+1,character);

    mvwaddch(win,blockY+3,2*blockX,character);
    mvwaddch(win,blockY+3,2*blockX+1,character);

    mvwaddch(win,blockY+4,2*blockX,character);
    mvwaddch(win,blockY+4,2*blockX+1,character);

    wrefresh(win);
}


/*
 * XXXX
 */
void DrawI2(WINDOW *win, int blockY, int blockX, const chtype character)
{
    wattron(win, COLOR_PAIR(1));

    mvwaddch(win,blockY+1,2*blockX,character);
    mvwaddch(win,blockY+1,2*blockX+1,character);

    mvwaddch(win,blockY+1,2*blockX+2,character);
    mvwaddch(win,blockY+1,2*blockX+3,character);

    mvwaddch(win,blockY+1,2*blockX+4,character);
    mvwaddch(win,blockY+1,2*blockX+5,character);

    mvwaddch(win,blockY+1,2*blockX+6,character);
    mvwaddch(win,blockY+1,2*blockX+7,character);

    wrefresh(win);
}


/*
 * XX
 * X
 * X
 */
void DrawJ1(WINDOW *win, int blockY, int blockX, const chtype character)
{
    wattron(win, COLOR_PAIR(2));

    mvwaddch(win,blockY+1,2*blockX,character);
    mvwaddch(win,blockY+1,2*blockX+1,character);

    mvwaddch(win,blockY+1,2*blockX+2,character);
    mvwaddch(win,blockY+1,2*blockX+3,character);

    mvwaddch(win,blockY+2,2*blockX,character);
    mvwaddch(win,blockY+2,2*blockX+1,character);

    mvwaddch(win,blockY+3,2*blockX,character);
    mvwaddch(win,blockY+3,2*blockX+1,character);

    wrefresh(win);
}

/*
 * XXX
 *   X
 */
void DrawJ2(WINDOW *win, int blockY, int blockX, const chtype character)
{
    wattron(win, COLOR_PAIR(2));

    mvwaddch(win,blockY+1,2*blockX,character);
    mvwaddch(win,blockY+1,2*blockX+1,character);

    mvwaddch(win,blockY+1,2*blockX+2,character);
    mvwaddch(win,blockY+1,2*blockX+3,character);

    mvwaddch(win,blockY+1,2*blockX+4,character);
    mvwaddch(win,blockY+1,2*blockX+5,character);

    mvwaddch(win,blockY+2,2*blockX+4,character);
    mvwaddch(win,blockY+2,2*blockX+5,character);

    wrefresh(win);
}

/*
 *  X
 *  X
 * XX
 */
void DrawJ3(WINDOW *win, int blockY, int blockX, const chtype character)
{
    wattron(win, COLOR_PAIR(2));

    mvwaddch(win,blockY+1,2*blockX+2,character);
    mvwaddch(win,blockY+1,2*blockX+3,character);

    mvwaddch(win,blockY+2,2*blockX+2,character);
    mvwaddch(win,blockY+2,2*blockX+3,character);

    mvwaddch(win,blockY+3,2*blockX,character);
    mvwaddch(win,blockY+3,2*blockX+1,character);

    mvwaddch(win,blockY+3,2*blockX+2,character);
    mvwaddch(win,blockY+3,2*blockX+3,character);

    wrefresh(win);
}

/*
 * X
 * XXX
 */
void DrawJ4(WINDOW *win, int blockY, int blockX, const chtype character)
{
    wattron(win, COLOR_PAIR(2));

    mvwaddch(win,blockY+1,2*blockX,character);
    mvwaddch(win,blockY+1,2*blockX+1,character);

    mvwaddch(win,blockY+2,2*blockX,character);
    mvwaddch(win,blockY+2,2*blockX+1,character);

    mvwaddch(win,blockY+2,2*blockX+2,character);
    mvwaddch(win,blockY+2,2*blockX+3,character);

    mvwaddch(win,blockY+2,2*blockX+4,character);
    mvwaddch(win,blockY+2,2*blockX+5,character);

    wrefresh(win);
}


/*
 * XX
 *  X
 *  X
 */

void DrawL1(WINDOW *win, int blockY, int blockX, const chtype character)
{
    wattron(win, COLOR_PAIR(3));

    mvwaddch(win,blockY+1,2*blockX,character);
    mvwaddch(win,blockY+1,2*blockX+1,character);

    mvwaddch(win,blockY+1,2*blockX+2,character);
    mvwaddch(win,blockY+1,2*blockX+3,character);

    mvwaddch(win,blockY+2,2*blockX+2,character);
    mvwaddch(win,blockY+2,2*blockX+3,character);

    mvwaddch(win,blockY+3,2*blockX+2,character);
    mvwaddch(win,blockY+3,2*blockX+3,character);

    wrefresh(win);
}

/*
 *   X
 * XXX
 */

void DrawL2(WINDOW *win, int blockY, int blockX, const chtype character)
{
    wattron(win, COLOR_PAIR(3));

    mvwaddch(win,blockY+1,2*blockX+4,character);
    mvwaddch(win,blockY+1,2*blockX+5,character);

    mvwaddch(win,blockY+2,2*blockX,character);
    mvwaddch(win,blockY+2,2*blockX+1,character);

    mvwaddch(win,blockY+2,2*blockX+2,character);
    mvwaddch(win,blockY+2,2*blockX+3,character);

    mvwaddch(win,blockY+2,2*blockX+4,character);
    mvwaddch(win,blockY+2,2*blockX+5,character);

    wrefresh(win);
}


/*
 * X
 * X
 * XX
 */

void DrawL3(WINDOW *win, int blockY, int blockX, const chtype character)
{
    wattron(win, COLOR_PAIR(3));

    mvwaddch(win,blockY+1,2*blockX,character);
    mvwaddch(win,blockY+1,2*blockX+1,character);

    mvwaddch(win,blockY+2,2*blockX,character);
    mvwaddch(win,blockY+2,2*blockX+1,character);

    mvwaddch(win,blockY+3,2*blockX,character);
    mvwaddch(win,blockY+3,2*blockX+1,character);

    mvwaddch(win,blockY+3,2*blockX+2,character);
    mvwaddch(win,blockY+3,2*blockX+3,character);

    wrefresh(win);
}


/*
 * XXX
 * X
 */

void DrawL4(WINDOW *win, int blockY, int blockX, const chtype character)
{
    wattron(win, COLOR_PAIR(3));

    mvwaddch(win,blockY+1,2*blockX,character);
    mvwaddch(win,blockY+1,2*blockX+1,character);

    mvwaddch(win,blockY+1,2*blockX+2,character);
    mvwaddch(win,blockY+1,2*blockX+3,character);

    mvwaddch(win,blockY+1,2*blockX+4,character);
    mvwaddch(win,blockY+1,2*blockX+5,character);

    mvwaddch(win,blockY+2,2*blockX,character);
    mvwaddch(win,blockY+2,2*blockX+1,character);

    wrefresh(win);
}

/*
 *  X
 * XXX
 */

void DrawT1(WINDOW *win, int blockY, int blockX, const chtype character)
{
    wattron(win, COLOR_PAIR(4));

    mvwaddch(win,blockY+1,2*blockX+2,character);
    mvwaddch(win,blockY+1,2*blockX+3,character);

    mvwaddch(win,blockY+2,2*blockX,character);
    mvwaddch(win,blockY+2,2*blockX+1,character);

    mvwaddch(win,blockY+2,2*blockX+2,character);
    mvwaddch(win,blockY+2,2*blockX+3,character);

    mvwaddch(win,blockY+2,2*blockX+4,character);
    mvwaddch(win,blockY+2,2*blockX+5,character);

    wrefresh(win);
}


/*
 * X
 * XX
 * X
 */

void DrawT2(WINDOW *win, int blockY, int blockX, const chtype character)
{
    wattron(win, COLOR_PAIR(4));

    mvwaddch(win,blockY+1,2*blockX,character);
    mvwaddch(win,blockY+1,2*blockX+1,character);

    mvwaddch(win,blockY+2,2*blockX,character);
    mvwaddch(win,blockY+2,2*blockX+1,character);

    mvwaddch(win,blockY+2,2*blockX+2,character);
    mvwaddch(win,blockY+2,2*blockX+3,character);

    mvwaddch(win,blockY+3,2*blockX,character);
    mvwaddch(win,blockY+3,2*blockX+1,character);

    wrefresh(win);
}


/*
 * XXX
 *  X
 */

void DrawT3(WINDOW *win, int blockY, int blockX, const chtype character)
{
    wattron(win, COLOR_PAIR(4));

    mvwaddch(win,blockY+1,2*blockX,character);
    mvwaddch(win,blockY+1,2*blockX+1,character);

    mvwaddch(win,blockY+1,2*blockX+2,character);
    mvwaddch(win,blockY+1,2*blockX+3,character);

    mvwaddch(win,blockY+1,2*blockX+4,character);
    mvwaddch(win,blockY+1,2*blockX+5,character);

    mvwaddch(win,blockY+2,2*blockX+2,character);
    mvwaddch(win,blockY+2,2*blockX+3,character);

    wrefresh(win);
}


/*
 *  X
 * XX
 *  X
 */

void DrawT4(WINDOW *win, int blockY, int blockX, const chtype character)
{
    wattron(win, COLOR_PAIR(4));

    mvwaddch(win,blockY+1,2*blockX+2,character);
    mvwaddch(win,blockY+1,2*blockX+3,character);

    mvwaddch(win,blockY+2,2*blockX,character);
    mvwaddch(win,blockY+2,2*blockX+1,character);

    mvwaddch(win,blockY+2,2*blockX+2,character);
    mvwaddch(win,blockY+2,2*blockX+3,character);

    mvwaddch(win,blockY+3,2*blockX+2,character);
    mvwaddch(win,blockY+3,2*blockX+3,character);

    wrefresh(win);
}


/*
 * XX
 * XX
 */

void DrawO1(WINDOW *win, int blockY, int blockX, const chtype character)
{
    wattron(win, COLOR_PAIR(5));

    mvwaddch(win,blockY+1,2*blockX,character);
    mvwaddch(win,blockY+1,2*blockX+1,character);

    mvwaddch(win,blockY+2,2*blockX,character);
    mvwaddch(win,blockY+2,2*blockX+1,character);

    mvwaddch(win,blockY+1,2*blockX+2,character);
    mvwaddch(win,blockY+1,2*blockX+3,character);

    mvwaddch(win,blockY+2,2*blockX+2,character);
    mvwaddch(win,blockY+2,2*blockX+3,character);

    wrefresh(win);
}


/*
 *  XX
 * XX
 */

void DrawS1(WINDOW *win, int blockY, int blockX, const chtype character)
{
    wattron(win, COLOR_PAIR(6));

    mvwaddch(win,blockY+1,2*blockX+2,character);
    mvwaddch(win,blockY+1,2*blockX+3,character);

    mvwaddch(win,blockY+1,2*blockX+4,character);
    mvwaddch(win,blockY+1,2*blockX+5,character);

    mvwaddch(win,blockY+2,2*blockX,character);
    mvwaddch(win,blockY+2,2*blockX+1,character);

    mvwaddch(win,blockY+2,2*blockX+2,character);
    mvwaddch(win,blockY+2,2*blockX+3,character);

    wrefresh(win);
}


/*
 * X
 * XX
 *  X
 */

void DrawS2(WINDOW *win, int blockY, int blockX, const chtype character)
{
    wattron(win, COLOR_PAIR(6));

    mvwaddch(win,blockY+1,2*blockX,character);
    mvwaddch(win,blockY+1,2*blockX+1,character);

    mvwaddch(win,blockY+2,2*blockX,character);
    mvwaddch(win,blockY+2,2*blockX+1,character);

    mvwaddch(win,blockY+2,2*blockX+2,character);
    mvwaddch(win,blockY+2,2*blockX+3,character);

    mvwaddch(win,blockY+3,2*blockX+2,character);
    mvwaddch(win,blockY+3,2*blockX+3,character);

    wrefresh(win);
}


/*
 * XX
 *  XX
 */

void DrawZ1(WINDOW *win, int blockY, int blockX, const chtype character)
{
    wattron(win, COLOR_PAIR(7));

    mvwaddch(win,blockY+1,2*blockX,character);
    mvwaddch(win,blockY+1,2*blockX+1,character);

    mvwaddch(win,blockY+1,2*blockX+2,character);
    mvwaddch(win,blockY+1,2*blockX+3,character);

    mvwaddch(win,blockY+2,2*blockX+2,character);
    mvwaddch(win,blockY+2,2*blockX+3,character);

    mvwaddch(win,blockY+2,2*blockX+4,character);
    mvwaddch(win,blockY+2,2*blockX+5,character);

    wrefresh(win);
}

/*
 *  X
 * XX
 * X
 */
void DrawZ2(WINDOW *win, int blockY, int blockX, const chtype character)
{
    wattron(win, COLOR_PAIR(7));

    mvwaddch(win,blockY+1,2*blockX+2,character);
    mvwaddch(win,blockY+1,2*blockX+3,character);

    mvwaddch(win,blockY+2,2*blockX,character);
    mvwaddch(win,blockY+2,2*blockX+1,character);

    mvwaddch(win,blockY+2,2*blockX+2,character);
    mvwaddch(win,blockY+2,2*blockX+3,character);

    mvwaddch(win,blockY+3,2*blockX,character);
    mvwaddch(win,blockY+3,2*blockX+1,character);

    wrefresh(win);
}

