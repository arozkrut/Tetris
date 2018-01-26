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

short int NewBlock(struct Blocks *blocksCounter)
{
    if(blocksCounter->betweenI==12)
    {
        blocksCounter->betweenI=0;
        blocksCounter->successiveSZ=0;
        return 0;
    }

    short int block;

    if(blocksCounter->successiveSZ==4)block=rand()%4;
    else block=rand()%7;

    if(block!=0)blocksCounter->betweenI+=1;
    if(block==5 || block==6)blocksCounter->successiveSZ+=1;
    else blocksCounter->successiveSZ=0;

    return block;
}

struct Blocks* initBlocksCounter()
{
    struct Blocks *blocksCounter;
    blocksCounter=(struct Blocks *)malloc(sizeof(struct Blocks));
    blocksCounter->betweenI=0;
    blocksCounter->successiveSZ=4;
    return blocksCounter;
}