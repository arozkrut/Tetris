//
// Created by aleksandra on 28.01.18.
//

#include "tetris.h"


/*
 * X
 * X
 * X
 * X
 */

/*
 * XXXX
 */


/*
 * XX
 * X
 * X
 */

/*
 * XXX
 *   X
 */



/*
 *  X
 *  X
 * XX
 */



/*
 * X
 * XXX
 */



/*
 * XX
 *  X
 *  X
 */


/*
 *   X
 * XXX
 */


/*
 * X
 * X
 * XX
 */

/*
 * XXX
 * X
 */


/*
 *  X
 * XXX
 */


/*
 * X
 * XX
 * X
 */


/*
 * XXX
 *  X
 */

/*
 *  X
 * XX
 *  X
 */


/*
 * XX
 * XX
 */



/*
 *  XX
 * XX
 */


/*
 * X
 * XX
 *  X
 */


/*
 * XX
 *  XX
 */

/*
 *  X
 * XX
 * X
 */

int BlockHeight(short int block, int position); /* zwraca wysokosc klocka */

/*
 * Draw rysuje klocki
 * win - okno gdzie rysujemy
 * blockY? blockX? wspolrzedne do rysowania
 * character - jakim znakiem rysujemy
 * color - ktory kolor
 */
void Draw(WINDOW *win, int blockY1, int blockX1, int blockY2, int blockX2, int blockY3, int blockX3, int blockY4, int blockX4, const chtype character, short int color)
{
    --blockX1;
    --blockX2;
    --blockX3;
    --blockX4;

    wattron(win, COLOR_PAIR(color));
    wattron(win, A_BOLD);

    mvwaddch(win,blockY1+1,2*blockX1+1,character);
    mvwaddch(win,blockY1+1,2*blockX1+2,character);

    mvwaddch(win,blockY2+1,2*blockX2+1,character);
    mvwaddch(win,blockY2+1,2*blockX2+2,character);

    mvwaddch(win,blockY3+1,2*blockX3+1,character);
    mvwaddch(win,blockY3+1,2*blockX3+2,character);

    mvwaddch(win,blockY4+1,2*blockX4+1,character);
    mvwaddch(win,blockY4+1,2*blockX4+2,character);

    wrefresh(win);
}



void DrawBlock(WINDOW *win, short int block, int blockY, int blockX, int position, const chtype character, bool shadow)
{
    short int color;

    if(shadow)color=10;                             /* ustawienie koloru do rysowania */
    else color=block+1;

    switch(block)                                   /* wywolujemy odpowiednia funkcje dla kazdego bloku i jego katu */
    {
        case 0:
        {
            switch(position)
            {
                case 1:
                {
                    Draw(win, blockY, blockX, blockY+1, blockX, blockY+2, blockX, blockY+3, blockX, character, color);
                    break;
                }
                case 2:
                {
                    Draw(win, blockY, blockX, blockY, blockX+1, blockY, blockX+2, blockY, blockX+3, character, color);
                    break;
                }
                case 3:
                {
                    Draw(win, blockY, blockX, blockY+1, blockX, blockY+2, blockX, blockY+3, blockX, character, color);
                    break;
                }
                case 4:
                {
                    Draw(win, blockY, blockX, blockY, blockX+1, blockY, blockX+2, blockY, blockX+3, character, color);
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
                    Draw(win, blockY, blockX, blockY, blockX+1, blockY+1, blockX, blockY+2, blockX, character, color);
                    break;
                }
                case 2:
                {
                    Draw(win, blockY, blockX, blockY, blockX+1, blockY, blockX+2, blockY+1, blockX+2, character, color);
                    break;
                }
                case 3:
                {
                    Draw(win, blockY, blockX+1, blockY+1, blockX+1, blockY+2, blockX, blockY+2, blockX+1, character, color);
                    break;
                }
                case 4:
                {
                    Draw(win, blockY, blockX, blockY+1, blockX, blockY+1, blockX+1, blockY+1, blockX+2, character, color);
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
                    Draw(win, blockY, blockX, blockY, blockX+1, blockY+1, blockX+1, blockY+2, blockX+1, character, color);
                    break;
                }
                case 2:
                {
                    Draw(win, blockY, blockX+2, blockY+1, blockX, blockY+1, blockX+1, blockY+1, blockX+2, character, color);
                    break;
                }
                case 3:
                {
                    Draw(win, blockY, blockX, blockY+1, blockX, blockY+2, blockX, blockY+2, blockX+1, character, color);
                    break;
                }
                case 4:
                {
                    Draw(win, blockY, blockX, blockY, blockX+1, blockY, blockX+2, blockY+1, blockX, character, color);
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
                    Draw(win, blockY, blockX+1, blockY+1, blockX, blockY+1, blockX+1, blockY+1, blockX+2, character, color);
                    break;
                }
                case 2:
                {
                    Draw(win, blockY, blockX, blockY+1, blockX, blockY+1, blockX+1, blockY+2, blockX, character, color);
                    break;
                }
                case 3:
                {
                    Draw(win, blockY, blockX, blockY, blockX+1, blockY, blockX+2, blockY+1, blockX+1, character, color);
                    break;
                }
                case 4:
                {
                    Draw(win, blockY, blockX+1, blockY+1, blockX, blockY+1, blockX+1, blockY+2, blockX+1, character, color);
                    break;
                }
            }
            break;
        }
        case 4:
        {
            Draw(win, blockY, blockX, blockY, blockX+1, blockY+1, blockX, blockY+1, blockX+1, character, color);
            break;
        }
        case 5:
        {
            switch(position)
            {
                case 1:
                {
                    Draw(win, blockY, blockX+1, blockY, blockX+2, blockY+1, blockX, blockY+1, blockX+1, character, color);
                    break;
                }
                case 2:
                {
                    Draw(win, blockY, blockX, blockY+1, blockX, blockY+1, blockX+1, blockY+2, blockX+1, character, color);
                    break;
                }
                case 3:
                {
                    Draw(win, blockY, blockX+1, blockY, blockX+2, blockY+1, blockX, blockY+1, blockX+1, character, color);
                    break;
                }
                case 4:
                {
                    Draw(win, blockY, blockX, blockY+1, blockX, blockY+1, blockX+1, blockY+2, blockX+1, character, color);
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
                    Draw(win, blockY, blockX, blockY, blockX+1, blockY+1, blockX+1, blockY+1, blockX+2, character, color);
                    break;
                }
                case 2:
                {
                    Draw(win, blockY, blockX+1, blockY+1, blockX, blockY+1, blockX+1, blockY+2, blockX, character, color);
                    break;
                }
                case 3:
                {
                    Draw(win, blockY, blockX, blockY, blockX+1, blockY+1, blockX+1, blockY+1, blockX+2, character, color);
                    break;
                }
                case 4:
                {
                    Draw(win, blockY, blockX+1, blockY+1, blockX, blockY+1, blockX+1, blockY+2, blockX, character, color);
                    break;
                }
            }
            break;
        }
    }
}



void UpdateNextWin(WINDOW *nextWin, short int nextBlock)
{
    int blockX;
    int blockY=1;
    int position;

    /* czyscimy okno bez krawedzi */
    for(int i=2;i<NEXTWINDOWHEIGHT-1;++i)for(int j=1;j<NEXTWINDOWWIDTH-1;++j)mvwaddch(nextWin,i,j,' ');

    if(nextBlock==0)                  /* obliczamy wspolrzedne do rysowania w zaleznosci od klocka i katu */
    {
        ++blockY;
        blockX=(NEXTWINDOWWIDTH)/4-1;
        position=2;
    }
    else if(nextBlock==3)
    {
        position=2;
        blockX=NEXTWINDOWWIDTH/4;
    }
    else if(nextBlock==5 || nextBlock==6)
    {
        position=2;
        blockX=(NEXTWINDOWWIDTH)/4;
    }
    else if(nextBlock==4)
    {
        ++blockY;
        position=1;
        blockX=(NEXTWINDOWWIDTH)/4;
    }
    else
    {
        position=1;
        blockX=(NEXTWINDOWWIDTH)/4;
    }

    DrawBlock(nextWin, nextBlock, blockY, blockX, position, ACS_CKBOARD, false);
}


void DrawMatrix(WINDOW *matrix,int *tmatrix)
{
    for(int i=0;i<20;++i)
    {
        for(int j=1;j<=10;++j)
        {
            if(*(tmatrix+i*ELINROW+j)==0)
            {
                mvwaddch(matrix, i+1, 2*(j-1)+1, ' ');
                mvwaddch(matrix, i+1, 2*(j-1)+2, ' ');
            }
            else
            {
                wattron(matrix, COLOR_PAIR(*(tmatrix+i*ELINROW+j)));
                mvwaddch(matrix, i+1, 2*(j-1)+1, ACS_CKBOARD);
                mvwaddch(matrix, i+1, 2*(j-1)+2, ACS_CKBOARD);
            }
        }
    }
    wrefresh(matrix);
}

void FindShadow(WINDOW *matrix, short int block, int blockY, int blockX, int position, int *shadowY, int *tmatrix)
{
    bool found=false;

    for(int i=blockY+BlockHeight(block, position)+1; i<=20; ++i)             /* szukamy najwiekszej wspolrzednej Y */
    {                                                                        /* dla ktorej da sie narysowac cien klocka */
        if(CheckIfPossible(block, i, blockX, position, tmatrix))found=true;  /* cien da sie narysowac */
        else
        {
            *shadowY=i-1;                                                    /* i jest juz niedobre wiec i-1 */
            break;                                                           /* jest najwieksza wspolrzedna */
        }
    }

    if(!found)*shadowY=-1;                                                   /* nie mozna narysowac czyli cien nie istnieje */

    /* da sie narysowac i rysujemy */
    else DrawBlock(matrix, block, *shadowY, blockX, position, ACS_CKBOARD, true);
}

int BlockHeight(short int block, int position)
{
    if(block==0 && position%2==1)return 4;
    if(block==0)return 1;
    if((block==1 || block==2) && position%2==1)return 3;
    if(block==1 || block==2 || block==4 || position%2==1)return 2;
    return 3;
}
