//
// Created by aleksandra on 29.01.18.
//

#include "tetris.h"

/*
 * CheckRows sprawdza czy rzedy zostaly wypelnione i mozna je skasowac
 * from - odkad sprawdzamy
 * numberOfRows - ile rzedow sprawdzamy
 * tmatrix - tablica przechowywujaca wyglad matrixa
 * matrix - okno w ktorym rysujemy matrixa
 * blocksInRow - przechowuje informacje o liczbie zajetych wspolrzednych w kazdym rzedzie matrixa
 * zwraca liczbe usunietych rzedow
 */
int CheckRows(int from, int numberOfRows, int *tmatrix, int *blocksInRow, WINDOW *matrix);



/*
 * aktualizuje tablice blocksInRow
 * blockY - od ktorego rzedu zaczynamy dodawanie
 * row1 - tyle dodajemy do rzedu pierwszego
 * row2 - tyle dodajemy do rzedu drugiego
 * row3 - tyle dodajemy do rzedu trzeciego
 * row4 - tyle dodajemy do rzedu czwartego
 */
void AddToRow(int *blocksInRow, int blockY, int row1, int row2, int row3, int row4);


void AddBlocksToSum(WINDOW *matrix, short int block, int blockY, int blockX, int position, int *tmatrix, int *blocksInRow, long *points)
{
    int rows;

    switch(block)                          /* wywolujemy odpowiednia funkcje dla kazdego bloku i jego katu */
    {
        case 0:
        {
            switch(position)
            {
                case 1:
                {
                    AddToRow(blocksInRow, blockY, 1, 1, 1, 1);
                    rows=CheckRows(blockY,4,tmatrix,blocksInRow, matrix);
                    break;
                }
                case 2:
                {
                    AddToRow(blocksInRow, blockY, 4, 0, 0, 0);
                    rows=CheckRows(blockY,1,tmatrix,blocksInRow, matrix);
                    break;
                }
                case 3:
                {
                    AddToRow(blocksInRow, blockY, 1, 1, 1, 1);
                    rows=CheckRows(blockY,4,tmatrix,blocksInRow, matrix);
                    break;
                }
                case 4:
                {
                    AddToRow(blocksInRow, blockY, 4, 0, 0, 0);
                    rows=CheckRows(blockY,1,tmatrix,blocksInRow, matrix);
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
                    AddToRow(blocksInRow, blockY, 2, 1, 1, 0);
                    rows=CheckRows(blockY,3,tmatrix,blocksInRow, matrix);
                    break;
                }
                case 2:
                {
                    AddToRow(blocksInRow, blockY, 3, 1, 0, 0);
                    rows=CheckRows(blockY,2,tmatrix,blocksInRow, matrix);
                    break;
                }
                case 3:
                {
                    AddToRow(blocksInRow, blockY, 1, 1, 2, 0);
                    rows=CheckRows(blockY,3,tmatrix,blocksInRow, matrix);
                    break;
                }
                case 4:
                {
                    AddToRow(blocksInRow, blockY, 1, 3, 0, 0);
                    rows=CheckRows(blockY,2,tmatrix,blocksInRow, matrix);
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
                    AddToRow(blocksInRow, blockY, 2, 1, 1, 0);
                    rows=CheckRows(blockY,3,tmatrix,blocksInRow, matrix);
                    break;
                }
                case 2:
                {
                    AddToRow(blocksInRow, blockY, 1, 3, 0, 0);
                    rows=CheckRows(blockY,2,tmatrix,blocksInRow, matrix);
                    break;
                }
                case 3:
                {
                    AddToRow(blocksInRow, blockY, 1, 1, 2, 0);
                    rows=CheckRows(blockY,3,tmatrix,blocksInRow, matrix);
                    break;
                }
                case 4:
                {
                    AddToRow(blocksInRow, blockY, 3, 1, 0, 0);
                    rows=CheckRows(blockY,2,tmatrix,blocksInRow, matrix);
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
                    AddToRow(blocksInRow, blockY, 1, 3, 0, 0);
                    rows=CheckRows(blockY,2,tmatrix,blocksInRow, matrix);
                    break;
                }
                case 2:
                {
                    AddToRow(blocksInRow, blockY, 1, 2, 1, 0);
                    rows=CheckRows(blockY,3,tmatrix,blocksInRow, matrix);
                    break;
                }
                case 3:
                {
                    AddToRow(blocksInRow, blockY, 3, 1, 0, 0);
                    rows=CheckRows(blockY,2,tmatrix,blocksInRow, matrix);
                    break;
                }
                case 4:
                {
                    AddToRow(blocksInRow, blockY, 1, 2, 1, 0);
                    rows=CheckRows(blockY,3,tmatrix,blocksInRow, matrix);
                    break;
                }
            }
            break;
        }
        case 4:
        {
            AddToRow(blocksInRow, blockY, 2, 2, 0, 0);
            rows=CheckRows(blockY,2,tmatrix,blocksInRow, matrix);
            break;
        }
        case 5:
        {
            switch(position)
            {
                case 1:
                {
                    AddToRow(blocksInRow, blockY, 2, 2, 0, 0);
                    rows=CheckRows(blockY,2,tmatrix,blocksInRow, matrix);
                    break;
                }
                case 2:
                {
                    AddToRow(blocksInRow, blockY, 1, 2, 1, 0);
                    rows=CheckRows(blockY,3,tmatrix,blocksInRow, matrix);
                    break;
                }
                case 3:
                {
                    AddToRow(blocksInRow, blockY, 2, 2, 0, 0);
                    rows=CheckRows(blockY,2,tmatrix,blocksInRow, matrix);
                    break;
                }
                case 4:
                {
                    AddToRow(blocksInRow, blockY, 1, 2, 1, 0);
                    rows=CheckRows(blockY,3,tmatrix,blocksInRow, matrix);
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
                    AddToRow(blocksInRow, blockY, 2, 2, 0, 0);
                    rows=CheckRows(blockY,2,tmatrix,blocksInRow, matrix);
                    break;
                }
                case 2:
                {
                    AddToRow(blocksInRow, blockY, 1, 2, 1, 0);
                    rows=CheckRows(blockY,3,tmatrix,blocksInRow, matrix);
                    break;
                }
                case 3:
                {
                    AddToRow(blocksInRow, blockY, 2, 2, 0, 0);
                    rows=CheckRows(blockY,2,tmatrix,blocksInRow, matrix);
                    break;
                }
                case 4:
                {
                    AddToRow(blocksInRow, blockY, 1, 2, 1, 0);
                    rows=CheckRows(blockY,3,tmatrix,blocksInRow, matrix);
                    break;
                }
            }
            break;
        }
    }


    if(rows>0)                          /* liczymy punkty */
    {
        *points+=100*rows;              /* 100 za kazdy usuniety rzad */
        *points+=50*(rows-1);           /* plus 50 za drugi i kolejne */
        if(rows==4)*points+=50;         /* plus 50 za cztery */
    }
}

void AddToRow(int *blocksInRow, int blockY, int row1, int row2, int row3, int row4)
{
    *(blocksInRow+blockY)+=row1;
    *(blocksInRow+blockY+1)+=row2;
    *(blocksInRow+blockY+2)+=row3;
    *(blocksInRow+blockY+3)+=row4;
}
void Wait()                                            /* czekamy BLINK milisekund */
{
    clock_t time=clock();
    while(clock()<=time+BLINK*CLOCKS_PER_SEC/1000.0);
}

int CheckRows(int from, int numberOfRows, int *tmatrix, int *blocksInRow, WINDOW *matrix)
{
    int rows=0;                                      /* liczba usunietych rzedow */

    for(int i=0;i<numberOfRows;++i)                  /* czyscimy pelne rzedy oraz liczymy ile ich jest */
    {
        if(*(blocksInRow+from+i)==10)
        {
            ++rows;
            for(int c=1;c<=10;++c)*(tmatrix+((from+i)*ELINROW)+c)=0;
            *(blocksInRow+from+i)=0;
        }
    }

    if(rows!=0)                                      /* jezeli cos wyczyscilismy */
    {
        DrawMatrix(matrix,tmatrix);
        Wait();

        for(int l=0;l<rows;++l)                      /* opadanie rzedow klockow nad usunietymi rzedami */
        {
            for(int i=numberOfRows-1;i>=0;--i)
            {
                if(*(blocksInRow+from+i)==0)
                {
                    for(int r=from+i;r>0;--r)
                    {
                        for(int c=1;c<=10;++c)*(tmatrix+(r*ELINROW)+c)=*(tmatrix+((r-1)*ELINROW)+c);
                        *(blocksInRow+r)=*(blocksInRow+r-1);
                    }
                    DrawMatrix(matrix,tmatrix);
                    Wait();
                }
            }
        }

        for(int c=1;c<=10;++c)*(tmatrix+c)=0;       /* czyscimy sama gore bo jesli cos spadlo to tam na pewno nic nie ma */
        *blocksInRow=0;
    }

    return rows;
}


void UpdateScoreWin(WINDOW *scoreWin, long points)
{
    mvwprintw(scoreWin, 3, 14, "          ");
    mvwprintw(scoreWin, 3, 14, "%10d", points);
    wrefresh(scoreWin);
}