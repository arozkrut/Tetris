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

#define HEIGHT 10
#define WIDTH 26
void PrintMenu(WINDOW *menu, short int backlit)
{
    int x=2;
    int y=3;
    box(menu, 0, 0);

    wattron(menu, A_BOLD);
    mvwaddch(menu,1,8,ACS_DIAMOND);
    mvwprintw(menu,1,10,"TETRIS");
    mvwaddch(menu,1,17,ACS_DIAMOND);
    wattroff(menu, A_BOLD);

    if(backlit==1)
    {
        wattron(menu, A_REVERSE);
        mvwprintw(menu, y, x, "       NEW GAME       ");
        wattroff(menu, A_REVERSE);
        mvwprintw(menu, y+2, x, "      ");
        mvwaddch(menu,y+2,x+6,ACS_DIAMOND);
        mvwprintw(menu, y+2, x+7, " RANKING       ");
        mvwprintw(menu, y+4, x, "         EXIT         ");
    }

    else if(backlit==2)
    {
        mvwprintw(menu, y, x, "       NEW GAME       ");
        wattron(menu, A_REVERSE);
        mvwprintw(menu, y+2, x, "      ");
        mvwaddch(menu,y+2,x+6,ACS_DIAMOND);
        mvwprintw(menu, y+2, x+7, " RANKING       ");
        wattroff(menu, A_REVERSE);
        mvwprintw(menu, y+4, x, "         EXIT         ");
    }

    else
    {
        mvwprintw(menu, y, x, "       NEW GAME       ");
        mvwprintw(menu, y+2, x, "      ");
        mvwaddch(menu,y+2,x+6,ACS_DIAMOND);
        mvwprintw(menu, y+2, x+7, " RANKING       ");
        wattron(menu, A_REVERSE);
        mvwprintw(menu, y+4, x, "         EXIT         ");
        wattroff(menu, A_REVERSE);
    }

    wrefresh(menu);
}

short int ShowMenu()
{
    WINDOW *menu;
    int backlit=1;

    int startx=(80-WIDTH)/2;
    int starty=(24-HEIGHT)/2;

    menu=newwin(HEIGHT, WIDTH, starty, startx);
    keypad(menu, TRUE);
    refresh();

    PrintMenu(menu, backlit);
    getch();

    return -1;
}

