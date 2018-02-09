//
// Created by aleksandra on 27.01.18.
//


#include "tetris.h"

/* funkcja GoDown obluguje spadanie klocka i jego ladowanie
 * block - typ klocka
 * blockY - wspolrzedna Y w matrixie
 * blockX - wspolrzedna X w matrixie
 * position - kat klocka
 * tmatrix - tablica przechowywujaca wyglad matrixa
 * matrix - okno w ktorym rysujemy matrixa
 * blocksInRow - przechowuje informacje o liczbie zajetych wspolrzednych w kazdym rzedzie matrixa
 * points - liczba punktow
 * zwraca wartosc true jesli klocek wyladowal
 * i false jesli wciaz spada
 */
bool GoDown(short int block, int *blockY, int blockX, int position, int *tmatrix, WINDOW *matrix, int *blocksInRow, long *points);
WINDOW *PrepareWinMatrix();                         /* przygotowuje okno gdzie wysujemy matrixa */
WINDOW *PrepareWinNext();                           /* przygotowuje okno gdzie rysujemy nastepny klocek ktory sie pojawi */
WINDOW *PrepareWinScore();                          /* przygotowuje okno gdzie wypisujemy aktualne punkty i nasjlepszy wynik */
void PrepareNewGame();                              /* przygotowujemy ekran do gry */
int *PrepareMatrix();                               /* przygotowanie tmatrix */
bool TimeToGoDown(clock_t *time, int timeWaiting);  /* sprawdzanie czy klocek ma opasc */
int FirstPosition(short int block);                 /* zwraca wspolrzedna X swiezego klocka ktory ma sie pojawic na ekranie */

short int NewGame()
{
    nodelay(stdscr, TRUE);

    int *tmatrix;                                   /* tablica przechowywujaca wyglad matrixa */
    int *blocksInRow;                               /* przechowuje informacje o liczbie zajetych wspolrzednych w kazdym rzedzie matrixa */

    int key;

    long points=0;                                  /* liczba punktow */
    long ppoints=0;                                 /* pomocnicza zmienna uzywana do sprawdzenia czy zdobylismy jakies punkty */

    bool needNew=true;                              /* true - potrzebujemy nowego klocka, false - jeszcze nie */
    bool possible;                                  /* true - mozliwe, false - niemozliwe */

    short int option;

    PrepareNewGame();
    tmatrix=PrepareMatrix();
    blocksInRow=(int *)calloc(20, sizeof(int));

    WINDOW *matrix=PrepareWinMatrix();
    WINDOW *nextWin=PrepareWinNext();
    WINDOW *scoreWin=PrepareWinScore();

    struct Blocks *blocksCounter;
    blocksCounter=initBlocksCounter();

    short int block;
    short int nextBlock=NewBlock(blocksCounter);

    int blockX;                                     /* wspolrzedna X klocka */
    int blockY;                                     /* wspolrzedna Y klocka */
    int position;                                   /* kat klocka */

    int shadowY;                                    /* wspolrzedna Y cienia klocka */

    clock_t time=clock();
    int  timeWaiting=WAITING;                       /* czas miedzy kolejnymi opadaniamu klocka */

    while(1)
    {
        if(needNew)                                 /* jesli potrzebujemy nowego klocka */
        {
            if(points!=ppoints)                     /* jesli zdobylismy jakies punkty */
            {
                UpdateScoreWin(scoreWin,points);

                timeWaiting-=(points-ppoints)/100*LESSTIME; /* zmniejszamy czas pomiedzy kolejnymi opadaniami klocka */
                                                            /* wspoliniowo do zdobytych punktow */
                ppoints=points;
            }


            block=nextBlock;                        /* losowanie nowego klocka */
            nextBlock=NewBlock(blocksCounter);

            UpdateNextWin(nextWin,nextBlock);

            blockY=0;                               /* ustawienie wartosci poczatkowych */
            blockX=FirstPosition(block);
            position=1;

            /* sprawdzenie czy nowy klocek moze sie pojawic */
            possible=CheckIfPossible(block, blockY, blockX, position, tmatrix);

            if(possible==false)
            {                                       /* jesli niemozliwe zapisz wynik i zakoncz gre */
                SaveScore(points);

                DestroyWindow(matrix);
                DestroyWindow(nextWin);
                DestroyWindow(scoreWin);

                free(tmatrix);
                free(blocksInRow);
                free(blocksCounter);

                return 1;
            }

                                                    /* jesli mozliwe */
            DrawBlock(matrix, block, blockY, blockX, position, ACS_CKBOARD, false);

            shadowY=-1;                             /* na poczatku nie ma cienia bo jeszcze go nie znalezlismy */
            FindShadow(matrix, block, blockY, blockX, position, &shadowY, tmatrix);

            needNew=false;                          /* wylosowany klocek ma spadac dalej */
        }


        if(TimeToGoDown(&time, timeWaiting))        /* klocek spada albo laduje i szukamy jego cienia jesli istnieje */
        {
            if(shadowY!=-1)DrawBlock(matrix, block, shadowY, blockX, position, ' ', false); /* czyscimy stary cien */
            needNew=GoDown(block, &blockY, blockX, position, tmatrix, matrix, blocksInRow, &points);
            FindShadow(matrix, block, blockY, blockX, position, &shadowY, tmatrix);
        }


        key=getch();                                /* wczytanie wciskanych przyciskow */

        switch (key)
        {
            case KEY_DOWN:                          /* klocek spada albo laduje i szukamy jego cienia jesli istnieje */
            {
                if(shadowY!=-1)DrawBlock(matrix, block, shadowY, blockX, position, ' ', false); /* czyscimy stary cien */
                needNew=GoDown(block, &blockY, blockX, position, tmatrix, matrix, blocksInRow, &points);
                FindShadow(matrix, block, blockY, blockX, position, &shadowY, tmatrix);
                break;
            }
            case KEY_UP:                            /* klocek obraca sie jesli moze i szuamy jego nowego cienia jesli istnieje */
            {
                if(shadowY!=-1)DrawBlock(matrix, block, shadowY, blockX, position, ' ', false); /* czyscimy stary cien */
                Rotation(block, &blockY, &blockX, &position, tmatrix, matrix);
                FindShadow(matrix, block, blockY, blockX, position, &shadowY, tmatrix);
                break;
            }
            case KEY_LEFT:                          /* klocek porusza sie w lewo jesli moze i szukamy nowego cienia */
            {
                possible=CheckIfPossible(block, blockY, blockX-1, position, tmatrix);
                if(possible)
                {
                    if(shadowY!=-1)DrawBlock(matrix, block, shadowY, blockX, position, ' ', false); /* czyscimy stary cien */
                    DrawBlock(matrix, block, blockY, blockX, position, ' ', false);
                    --blockX;                                                                       /* przsuwamy klocek */
                    DrawBlock(matrix, block, blockY, blockX, position, ACS_CKBOARD, false);
                    FindShadow(matrix, block, blockY, blockX, position, &shadowY, tmatrix);
                }

                break;
            }
            case KEY_RIGHT:                         /* klocek porusza sie w prawo jesli moze i szukamy nowego cienia */
            {
                possible=CheckIfPossible(block, blockY, blockX+1, position, tmatrix);
                if(possible)
                {
                    if(shadowY!=-1)DrawBlock(matrix, block, shadowY, blockX, position, ' ', false); /* czyscimy stary cien */
                    DrawBlock(matrix, block, blockY, blockX, position, ' ', false);
                    ++blockX;                                                                       /* przsuwamy klocek */
                    DrawBlock(matrix, block, blockY, blockX, position, ACS_CKBOARD, false);
                    FindShadow(matrix, block, blockY, blockX, position, &shadowY, tmatrix);
                }

                break;
            }
            case 'p':
            {
                nodelay(stdscr, FALSE);

                SaveWindows(matrix, nextWin, scoreWin);             /* zapisujemy wyglad okien */

                ClearWindow(stdscr, ACS_DIAMOND);
                refresh();
                option=ShowMenuDuringGame();
                if(option==1)                                       /* resume game */
                {
                    RefreshWindows(matrix, nextWin, scoreWin);      /* odswiezamy okna */
                    nodelay(stdscr, TRUE);
                }
                else
                {
                    SaveScore(points);                              /* return to menu */

                    DestroyWindow(matrix);
                    DestroyWindow(nextWin);
                    DestroyWindow(scoreWin);

                    free(tmatrix);
                    free(blocksInRow);
                    free(blocksCounter);

                    return 1;
                }
                break;
            }
        }


    }


}

bool GoDown(short int block, int *blockY, int blockX, int position, int *tmatrix, WINDOW *matrix, int *blocksInRow, long *points)
{
    bool possible;
    possible=CheckIfPossible(block, *blockY+1, blockX, position, tmatrix);

    /* jezeli klocek moze opasc */
    if(possible)
    {
        /* czyscimy poprzednia pozycje na ekranie */
        DrawBlock(matrix, block, *blockY, blockX, position, ' ', false);

        ++(*blockY);     /* klocek opada */

        /* rysujemy nowy klocek na ekranie */
        DrawBlock(matrix, block, *blockY, blockX, position, ACS_CKBOARD, false);

        return false;    /* nie wyladowal */
    }

    /* klocek laduje */
    Changetmatrix(block, *blockY, blockX, position, tmatrix, block+1);
    AddBlocksToSum(matrix, block, *blockY, blockX, position, tmatrix, blocksInRow, points);

    return true;        /* klocek wyladowal */
}



int *PrepareMatrix()
{
    int *tmatrix;                                               /* 0 - wolne miejsce */
    tmatrix=(int *)calloc(12*21,sizeof(int));                   /* wpp zajete przez jakis klocek*/


    for(int i=0;i<20;++i)                                       /* wypelniamy dodatkowe wymiry tmatrix klockami */
    {
        *(tmatrix+(i*ELINROW))=1;

        *(tmatrix+(i*ELINROW)+11)=1;
    }

    for(int i=0;i<12;++i)*(tmatrix+(20*ELINROW)+i)=1;

    return tmatrix;
}

WINDOW *PrepareWinMatrix()
{
    WINDOW *matrix;
    int matrixX, matrixY;

    matrixY=(getmaxy(stdscr)/2)-(MATRIXHEIGHT/2);                       /* wyliczamy wspolrzedne okna */
    matrixX=(getmaxx(stdscr)/2)-DISTANCE-MATRIXWIDTH;

    matrix=CreateWindow(MATRIXHEIGHT, MATRIXWIDTH, matrixY, matrixX);

    refresh();

    wattron(matrix, COLOR_PAIR(8) | A_BOLD);                            /* rysujemy okno */
    ClearWindow(matrix, ' ');
    box(matrix, 0, 0);
    wrefresh(matrix);

    return matrix;
}
WINDOW *PrepareWinNext()
{
    WINDOW *nextWin;

    int nextX, nextY;

    nextY=(getmaxy(stdscr)/2)-(MATRIXHEIGHT/2);                         /* wyliczamy wspolrzedne okna */
    nextX=getmaxx(stdscr)/2+DISTANCE;

    nextWin=CreateWindow( NEXTWINDOWHEIGHT, NEXTWINDOWWIDTH, nextY, nextX);

    wattron(nextWin, COLOR_PAIR(8) | A_BOLD);                           /* rysujemy okno */
    ClearWindow(nextWin, ' ');
    box(nextWin, 0, 0);

    mvwprintw(nextWin, 1, NEXTWINDOWWIDTH/2-2, "NEXT");

    wrefresh(nextWin);

    return nextWin;
}
WINDOW *PrepareWinScore()
{
    WINDOW *scoreWin;

    int scoreX, scoreY;

    scoreY=(getmaxy(stdscr)/2)-(MATRIXHEIGHT/2)+NEXTWINDOWHEIGHT+DISTANCE;  /* wyliczamy wspolrzedne okna */
    scoreX=getmaxx(stdscr)/2+DISTANCE;

    scoreWin=CreateWindow(SCOREWINDOWHEIGHT, SCOREWINDOWWIDTH, scoreY, scoreX);

    wattron(scoreWin, COLOR_PAIR(8) | A_BOLD);                              /* rysujemy okno */
    ClearWindow(scoreWin, ' ');
    box(scoreWin, 0, 0);

    wattron(scoreWin, COLOR_PAIR(5));
    mvwprintw(scoreWin, 1, 2, "BEST SCORE:");
    ReadBestScore(scoreWin);


    wattron(scoreWin, COLOR_PAIR(8));
    mvwprintw(scoreWin, 3, 2, "YOUR SCORE:");
    mvwprintw(scoreWin, 3, 14, "         0");

    wrefresh(scoreWin);

    return scoreWin;
}

void PrepareNewGame()
{
    attron(A_BOLD);

    nodelay(stdscr, FALSE);
    mvprintw(getmaxy(stdscr)/2-1,getmaxx(stdscr)/2-11,"PRESS ANY KEY TO START");
    getch();
    nodelay(stdscr, TRUE);

    mvprintw(getmaxy(stdscr)/2-1,getmaxx(stdscr)/2-11,"                       ");
    refresh();


    mvprintw((getmaxy(stdscr)/2)-(MATRIXHEIGHT/2)+NEXTWINDOWHEIGHT+2*DISTANCE+SCOREWINDOWHEIGHT, getmaxx(stdscr)/2+DISTANCE+5, "Press p to pause");
    attroff(A_BOLD);

    refresh();
}

bool TimeToGoDown(clock_t *time, int timeWaiting)
{
    if(clock()>=*time+timeWaiting*CLOCKS_PER_SEC/1000.0)
    {
        *time=clock();
        return true;
    }
    return false;
}

int FirstPosition(short int block)
{
    switch(block)
    {
        case 0:
            return 6;
        case 1:
            return 5;
        case 2:
            return 5;
        case 3:
            return 4;
        case 4:
            return 5;
        case 5:
            return 4;
        case 6:
            return 5;
    }
}