#include "tetris.h"

int main()
{
    short int *blocks;
    blocks=(short int *)malloc(100*sizeof(short int));
    struct Blocks *blocksCounter;
    blocksCounter=initBlocksCounter();


    NewBlocks(blocksCounter,blocks);
    
    return 0;
}