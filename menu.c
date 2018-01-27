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

#define HEIGHT 9
#define WIDTH 26
void PrintMenu(WINDOW *menu, int backlit)
{
    int x=2;
    int y=3;

    wattron(menu, A_BOLD);

    box(menu, 0, 0);

    mvwaddch(menu,1,8,ACS_DIAMOND);
    wattron(menu, A_UNDERLINE);
    mvwprintw(menu,1,10,"TETRIS");
    wattroff(menu, A_UNDERLINE);
    mvwaddch(menu,1,17,ACS_DIAMOND);


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

    wattroff(menu, A_BOLD);
    wrefresh(menu);
}

void PrintMenuDuringGame(WINDOW *menu,int backlit)
{
    int x=2;
    int y=3;

    wattron(menu, A_BOLD);

    box(menu, 0, 0);

    mvwaddch(menu,1,8,ACS_DIAMOND);
    wattron(menu, A_UNDERLINE);
    mvwprintw(menu,1,10,"TETRIS");
    wattroff(menu, A_UNDERLINE);
    mvwaddch(menu,1,17,ACS_DIAMOND);

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

    wattroff(menu, A_BOLD);
    wrefresh(menu);
}

short int ShowMenu()
{
    WINDOW *menu=CreateWindow(HEIGHT, WIDTH, (getmaxy(stdscr)-HEIGHT)/2, (getmaxx(stdscr)-WIDTH)/2);
    int backlit=1;
    int key;


    keypad(menu, TRUE);
    wattron(menu, COLOR_PAIR(9));

    ClearWindow(menu, ' ');

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
                        return 2;
                    }
                    case 2:
                    {
                        DestroyWindow(menu);
                        return 3;
                    }
                    case 3:
                    {
                        DestroyWindow(menu);
                        return -1;
                    }
                }
                break;
            }
        }
    }
}

short int ShowMenuDuringGame()
{
    WINDOW *menu=CreateWindow(HEIGHT, WIDTH, (getmaxy(stdscr)-HEIGHT)/2, (getmaxx(stdscr)-WIDTH)/2);
    int backlit=0;
    int key;

    keypad(menu, TRUE);
    wattron(menu, COLOR_PAIR(9));

    ClearWindow(menu, ' ');

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