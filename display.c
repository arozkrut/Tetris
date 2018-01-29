//
// Created by aleksandra on 26.01.18.
//

/*
 * Options:
 *
 * 1-Menu
 * 2-New Game
 * 3-Ranking
 *-1-Exit
 */

#include "tetris.h"

void Display()
{
    initscr();
    start_color();
    clear();
    noecho();
    cbreak();
    curs_set(0);
    keypad(stdscr, TRUE);

    InitColors();
    attron(COLOR_PAIR(9));

    ClearWindow(stdscr, ACS_DIAMOND);
    refresh();

    short int option=1;
    while(option!=-1)
    {
        switch(option)
        {
            case 1:
            {
                option=ShowMenu();
                break;
            }
            case 2:
            {
                attron(COLOR_PAIR(8));
                ClearWindow(stdscr, ' ');
                option=NewGame();
                attron(COLOR_PAIR(9));
                cbreak();
                break;
            }
            case 3:
            {

            }
        }

        ClearWindow(stdscr, ACS_DIAMOND);

    }

    //mvaddch(i,j,ACS_CKBOARD);

    //clrtoeol();
    refresh();
    endwin();

}