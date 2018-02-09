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
    initscr();                /* rozpoczecie trybu ncurses */
    start_color();            /* zmiana opcji ncurses */
    clear();
    noecho();
    cbreak();
    curs_set(0);
    keypad(stdscr, TRUE);

    InitColors();             /* funcja deklarujaca pary kolorow */
    attron(COLOR_PAIR(9));

    ClearWindow(stdscr, ACS_DIAMOND);
    refresh();

    short int option=1;
    while(option!=-1)                         /* kiedy option przyjmie wartosc -1 konczymy program */
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
                attron(COLOR_PAIR(8));        /* zmiana kolorow */
                ClearWindow(stdscr, ' ');     /* i wywolanie funkcji NewGame() */
                option=NewGame();
                attron(COLOR_PAIR(9));        /* powrot do standardowych kolorow */

                break;
            }
            case 3:
            {
                attron(COLOR_PAIR(12));       /* zmiana kolorow */
                ClearWindow(stdscr, ACS_DIAMOND);
                WriteRanking();
                option=1;
                attron(COLOR_PAIR(9));        /* powrot do standardowych kolorow */
            }
        }

        ClearWindow(stdscr, ACS_DIAMOND);
        refresh();
    }

    refresh();
    endwin();

}