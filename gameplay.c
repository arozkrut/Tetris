//
// Created by aleksandra on 27.01.18.
//

#include "tetris.h"

#define MATRIXWIDTH 24
#define MATRIXHEIGHT 22

#define NEXTWINDOWWIDTH 12
#define NEXTWINDOWHEIGHT 6

#define SCOREWINDOWWIDTH 26
#define SCOREWINDOWHEIGHT 5

#define DISTANCE 3


bool GoDown(short int block, int *blockY, int blockX, int position, int *tmatrix, WINDOW *matrix);
WINDOW *PrepareWinMatrix();
WINDOW *PrepareWinNext();
WINDOW *PrepareWinScore();
void PrepareNewGame();
int *PrepareMatrix();
int FirstPosition(short int block);

short int NewGame()
{
    halfdelay(255);

    int *tmatrix;
    int key;
    bool needNew=true;
    bool possible;

    PrepareNewGame();
    tmatrix=PrepareMatrix();

    WINDOW *matrix=PrepareWinMatrix();
    WINDOW *nextWin=PrepareWinNext();
    WINDOW *scoreWin=PrepareWinScore();
    
    struct Blocks *blocksCounter;
    blocksCounter=initBlocksCounter();

    short int block;
    short int nextBlock=NewBlock(blocksCounter);

    int blockX;
    int blockY;
    int position;

    while(1)
    {
        if(needNew)
        {
            block=nextBlock;
            nextBlock=NewBlock(blocksCounter);

            blockY=0;
            blockX=FirstPosition(block);
            position=1;

            possible=CheckIfPossible(block, blockY, blockX, position, tmatrix);

            if(possible==false)return 1;//////////////////TODO zmienic opcje na zapis punktow

            DrawBlock(matrix, block, blockY, blockX, position, ACS_CKBOARD);

            needNew=false;
        }

        key=getch();

        switch (key)
        {
            case ERR:
            {
                needNew=GoDown(block, &blockY, blockX, position, tmatrix, matrix);
                break;
            }
            case KEY_DOWN:
            {
                needNew=GoDown(block, &blockY, blockX, position, tmatrix, matrix);
                break;
            }
            case KEY_UP:
            {

                break;
            }
            case KEY_LEFT:
            {
                possible=CheckIfPossible(block, blockY, blockX-1, position, tmatrix);
                if(possible)
                {
                    DrawBlock(matrix, block, blockY, blockX, position, ' ');

                    --blockX;

                    DrawBlock(matrix, block, blockY, blockX, position, ACS_CKBOARD);
                }
                else
                {
                    needNew=GoDown(block, &blockY, blockX, position, tmatrix, matrix);
                }
                break;
            }
            case KEY_RIGHT:
            {
                possible=CheckIfPossible(block, blockY, blockX+1, position, tmatrix);
                if(possible)
                {
                    DrawBlock(matrix, block, blockY, blockX, position, ' ');

                    ++blockX;

                    DrawBlock(matrix, block, blockY, blockX, position, ACS_CKBOARD);
                }
                else
                {
                    needNew=GoDown(block, &blockY, blockX, position, tmatrix, matrix);
                }

                break;
            }
            case 'p':
            {

                break;
            }
        }
    }


}

bool GoDown(short int block, int *blockY, int blockX, int position, int *tmatrix, WINDOW *matrix)
{
    bool possible;
    possible=CheckIfPossible(block, *blockY+1, blockX, position, tmatrix);

    if(possible)
    {
        DrawBlock(matrix, block, *blockY, blockX, position, ' ');

        ++(*blockY);

        DrawBlock(matrix, block, *blockY, blockX, position, ACS_CKBOARD);

        return false;
    }
    Changetmatrix(block, *blockY, blockX, position, tmatrix, 1);
    return true;
}

int *PrepareMatrix()
{
    int *tmatrix;
    tmatrix=(int *)calloc(12*21,sizeof(int));


    for(int i=0;i<20;++i)
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

    matrixY=(getmaxy(stdscr)/2)-(MATRIXHEIGHT/2);
    matrixX=(getmaxx(stdscr)/2)-DISTANCE-MATRIXWIDTH;

    matrix=CreateWindow(MATRIXHEIGHT, MATRIXWIDTH, matrixY, matrixX);

    refresh();

    wattron(matrix, COLOR_PAIR(8) | A_BOLD);
    ClearWindow(matrix, ' ');
    box(matrix, 0, 0);
    wrefresh(matrix);

    return matrix;
}
WINDOW *PrepareWinNext()
{
    WINDOW *nextWin;

    int nextX, nextY;

    nextY=(getmaxy(stdscr)/2)-(MATRIXHEIGHT/2);
    nextX=getmaxx(stdscr)/2+DISTANCE;

    nextWin=CreateWindow(NEXTWINDOWHEIGHT, NEXTWINDOWWIDTH, nextY, nextX);

    wattron(nextWin, COLOR_PAIR(8) | A_BOLD);
    ClearWindow(nextWin, ' ');
    box(nextWin, 0, 0);
    wrefresh(nextWin);

    return nextWin;
}
WINDOW *PrepareWinScore()
{
    WINDOW *scoreWin;

    int scoreX, scoreY;

    scoreY=(getmaxy(stdscr)/2)-(MATRIXHEIGHT/2)+NEXTWINDOWHEIGHT+DISTANCE;
    scoreX=getmaxx(stdscr)/2+DISTANCE;

    scoreWin=CreateWindow(SCOREWINDOWHEIGHT, SCOREWINDOWWIDTH, scoreY, scoreX);

    wattron(scoreWin, COLOR_PAIR(8) | A_BOLD);
    ClearWindow(scoreWin, ' ');
    box(scoreWin, 0, 0);
    wrefresh(scoreWin);

    return scoreWin;
}

void PrepareNewGame()
{
    attron(A_BOLD);

    mvprintw(getmaxy(stdscr)/2-1,getmaxx(stdscr)/2-11,"PRESS ANY KEY TO START");
    getch();
    mvprintw(getmaxy(stdscr)/2-1,getmaxx(stdscr)/2-11,"                       ");
    refresh();


    mvprintw((getmaxy(stdscr)/2)-(MATRIXHEIGHT/2)+NEXTWINDOWHEIGHT+2*DISTANCE+SCOREWINDOWHEIGHT, getmaxx(stdscr)/2+DISTANCE+5, "Press p to pause");
    attroff(A_BOLD);

    refresh();
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