//
// Created by aleksandra on 26.01.18.
//

/*
 * Options:
 *
 * 1-Menu
 * 2-Menu while playing
 * 3-Ranking
 *-1-Exit
 */

#include "tetris.h"

void Display()
{
    initscr();
    clear();
    noecho();
    cbreak();
    curs_set(0);

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

            }
            case 3:
            {

            }
        }
    }

    clrtoeol();
    refresh();
    endwin();

}