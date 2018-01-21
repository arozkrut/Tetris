//
// Created by aleksandra on 20.01.18.
//
/* I XXXX    0
 *
 * J X       1
 *   XXX
 *
 * L   X     2
 *   XXX
 *
 * O XX      4
 *   XX
 *
 * S  XX     5
 *   XX
 *
 * Z XX      6
 *    XX
 *
 * T  X      3
 *   XXX
 *
 * Pomiedzy I a I max 12 blokow
 * S i Z max 4 pod rzad
 * I, J, L, lub T na poczatku
 */

#include "tetris.h"

void NewBlocks(struct Blocks *blocksCounter, short int *blocks)
{
    time_t t;
    srand((unsigned) time(&t));

    for(int i=0;i<100;++i)
    {
        if(blocksCounter->betweenI==12)
        {
            blocksCounter->betweenI=0;
            blocksCounter->successiveSZ=0;
            printf("0 ");
            *(blocks+i)=0;
        }

        if(blocksCounter->successiveSZ==4)*(blocks+i)=rand()%4;
        else *(blocks+i)=rand()%7;

        if(*(blocks+i)!=0)blocksCounter->betweenI+=1;
        if(*(blocks+i)==5 || *(blocks+i)==6)blocksCounter->successiveSZ+=1;
        else blocksCounter->successiveSZ=0;

        printf("%d ", *(blocks+i));
    }

}

struct Blocks* initBlocksCounter()
{
    struct Blocks *blocksCounter;
    blocksCounter=(struct Blocks *)malloc(sizeof(struct Blocks));
    blocksCounter->betweenI=0;
    blocksCounter->successiveSZ=4;
    return blocksCounter;
}