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

#define QUESTIONMENUHEIGHT 7
#define QUESTIONMENUWIDTH 35

#define NAMEHEIGHT 7
#define NAMEWIDTH 19

/* rysujemy menu z odpowiednim podswietleniem (backlit) */
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

/* rysujemy menu z odpowiednim podswietleniem (backlit) */
void PrintMenuDuringGame(WINDOW *menu,int backlit)
{
    int x=2;
    int y=4;

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

/* rysujemy menu z odpowiednim podswietleniem (backlit) */
void PrintQuestionMenu(WINDOW *menu, short int backlit)
{
    int x1=(QUESTIONMENUWIDTH/2-13)/2;
    int x2=QUESTIONMENUWIDTH/2+(QUESTIONMENUWIDTH/2-12)/2;
    int y=4;

    wattron(menu, A_BOLD);

    box(menu, 0, 0);

    mvwprintw(menu, 1, 2, "DO YOU WANT TO SAVE YOUR SCORE?");

    if(backlit==0)
    {
        wattron(menu, A_REVERSE);
        mvwprintw(menu, y, x1, "      YES      ");
        wattroff(menu, A_REVERSE);

        mvwprintw(menu, y, x2, "      NO      ");
    }

    else
    {
        mvwprintw(menu, y, x1, "      YES      ");

        wattron(menu, A_REVERSE);
        mvwprintw(menu, y, x2, "      NO      ");
        wattroff(menu, A_REVERSE);
    }

    wattroff(menu, A_BOLD);
    wrefresh(menu);
}

short int ShowMenu()
{
    WINDOW *menu=CreateWindow(HEIGHT, WIDTH, (getmaxy(stdscr)-HEIGHT)/2, (getmaxx(stdscr)-WIDTH)/2);
    int backlit=1;                              /* poswietlona opcja */
    int key;


    keypad(menu, TRUE);
    wattron(menu, COLOR_PAIR(9));

    ClearWindow(menu, ' ');

    PrintMenu(menu, backlit);                   /* rysujemy menu */

    while(1)
    {
        key=getch();

        switch (key)
        {
            case KEY_UP:                       /* zmiana podswietlonej opcji */
            {
                if(backlit==1)backlit=3;
                else --backlit;
                PrintMenu(menu,backlit);
                break;
            }
            case KEY_DOWN:                     /* zmiana podswietlonej opcji */
            {
                if(backlit==3)backlit=1;
                else ++backlit;
                PrintMenu(menu,backlit);
                break;
            }
            case 10:                           /* wybor podswietlonej opcji */
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
    int backlit=0;                                          /* poswietlona opcja */
    int key;

    keypad(menu, TRUE);
    wattron(menu, COLOR_PAIR(8));

    ClearWindow(menu, ' ');                                 /* rysujemy menu */

    PrintMenuDuringGame(menu, backlit);

    while(1)
    {
        key=getch();

        switch (key)
        {
            case KEY_UP:                                    /* zmiana podswietlonej opcji */
            {
                ++backlit;
                backlit=backlit%2;
                PrintMenuDuringGame(menu,backlit);
                break;
            }
            case KEY_DOWN:                                  /* zmiana podswietlonej opcji */
            {
                ++backlit;
                backlit=backlit%2;
                PrintMenuDuringGame(menu,backlit);
                break;
            }
            case 10:                                        /* wybor podswietlonej opcji */
            {
                switch (backlit)
                {
                    case 0:
                    {
                        DestroyWindow(menu);
                        return 1;
                        break;
                    }
                    case 1:
                    {
                        DestroyWindow(menu);
                        return 2;
                        break;
                    }
                }
                break;
            }
        }
    }
}

short int QuestionMenu()
{
    WINDOW *menu=CreateWindow(QUESTIONMENUHEIGHT, QUESTIONMENUWIDTH, (getmaxy(stdscr)-QUESTIONMENUHEIGHT)/2, (getmaxx(stdscr)-QUESTIONMENUWIDTH)/2);
    short int backlit=0;                                                   /* poswietlona opcja */
    int key;

    keypad(menu, TRUE);
    nodelay(stdscr, FALSE);
    wattron(menu, COLOR_PAIR(8));

    ClearWindow(stdscr, ACS_DIAMOND);
    refresh();

    ClearWindow(menu, ' ');                                                 /* rysujemy menu */

    PrintQuestionMenu(menu, backlit);

    while(1)
    {
        key=getch();

        if(key==10)                                                         /* wybor podswietlonej opcji */
        {
            DestroyWindow(menu);
            return backlit;
        }

        ++backlit;                                                          /* zmiana podswietlonej opcji */
        backlit=backlit%2;
        PrintQuestionMenu(menu,backlit);
    }
}

char *NameMenu()
{
    WINDOW *menu=CreateWindow(NAMEHEIGHT, NAMEWIDTH, (getmaxy(stdscr)-NAMEHEIGHT)/2, (getmaxx(stdscr)-NAMEWIDTH)/2);
    char *name;
    name=(char *)malloc(20*sizeof(char));

    wattron(menu, COLOR_PAIR(8));
    wattron(menu, A_BOLD);

    ClearWindow(stdscr, ACS_DIAMOND);
    ClearWindow(menu, ' ');

    box(menu, 0, 0);

    mvwprintw(menu, 1, 1, " ENTER YOUR NAME ");
    wrefresh(menu);

    echo();
    nocbreak();
    wmove(menu, 4, 6);
    wgetstr(menu, name);

    DestroyWindow(menu);
    noecho();
    cbreak();
    return name;

}