//
// Created by aleksandra on 26.01.18.
//

/*
 * Options:
 *
 * 1-Menu
 * 2-Menu while playing
 * 3-Game
 * 4-New Game
 * 5-Resume game
 * 6-Ranking
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
    keypad(stdscr, TRUE);

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
                option=ShowMenuDuringGame();
                break;
            }
            case 3:
            {

            }
        }
    }

    //clrtoeol();
    refresh();
    endwin();

}