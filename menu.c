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

#define HEIGHT 10
#define WIDTH 26
void PrintMenu(WINDOW *menu, int backlit)
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

void PrintMenuDuringGame(WINDOW *menu,int backlit)
{
    int x=2;
    int y=3;
    box(menu, 0, 0);

    wattron(menu, A_BOLD);
    mvwaddch(menu,1,8,ACS_DIAMOND);
    mvwprintw(menu,1,10,"TETRIS");
    mvwaddch(menu,1,17,ACS_DIAMOND);
    wattroff(menu, A_BOLD);

    if(backlit==0)
    {
        wattron(menu, A_REVERSE);
        mvwprintw(menu, y, x, "        RESUME        ");
        wattroff(menu, A_REVERSE);

        mvwprintw(menu, y+2, x, "    RETURN TO MENU    ");
    }

    else
    {
        mvwprintw(menu, y, x, "        RESUME        ");

        wattron(menu, A_REVERSE);
        mvwprintw(menu, y+2, x, "    RETURN TO MENU    ");
        wattroff(menu, A_REVERSE);
    }

    wrefresh(menu);
}

short int ShowMenu()
{
    WINDOW *menu=CreateWindow(HEIGHT, WIDTH, (24-HEIGHT)/2, (80-WIDTH)/2);
    int backlit=1;
    int key;

    keypad(menu, TRUE);
    refresh();

    PrintMenu(menu, backlit);

    while(1)
    {
        key=getch();

        switch (key)
        {
            case KEY_UP:
            {
                if(backlit==1)backlit=3;
                else --backlit;
                PrintMenu(menu,backlit);
                break;
            }
            case KEY_DOWN:
            {
                if(backlit==3)backlit=1;
                else ++backlit;
                PrintMenu(menu,backlit);
                break;
            }
            case 10:
            {
                switch (backlit)
                {
                    case 1:
                    {
                        DestroyWindow(menu);
                        return 4;
                        break;
                    }
                    case 2:
                    {
                        DestroyWindow(menu);
                        return 6;
                        break;
                    }
                    case 3:
                    {
                        DestroyWindow(menu);
                        return -1;
                        break;
                    }
                }
                break;
            }
        }
    }
}

short int ShowMenuDuringGame()
{
    WINDOW *menu=CreateWindow(HEIGHT, WIDTH, (24-HEIGHT)/2, (80-WIDTH)/2);
    int backlit=0;
    int key;

    keypad(menu, TRUE);
    refresh();

    PrintMenuDuringGame(menu, backlit);

    while(1)
    {
        key=getch();

        switch (key)
        {
            case KEY_UP:
            {
                ++backlit;
                backlit=backlit%2;
                PrintMenuDuringGame(menu,backlit);
                break;
            }
            case KEY_DOWN:
            {
                ++backlit;
                backlit=backlit%2;
                PrintMenuDuringGame(menu,backlit);
                break;
            }
            case 10:
            {
                switch (backlit)
                {
                    case 0:
                    {
                        DestroyWindow(menu);
                        return 5;
                        break;
                    }
                    case 1:
                    {
                        DestroyWindow(menu);
                        //////////////////////////////////////TODO: tu jeszcze cos niszcze!!!!!!!!!!!!!!!
                        return 1;
                        break;
                    }
                }
                break;
            }
        }
    }
}