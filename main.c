#include "tetris.h"

int main()
{
    short int *blocks;
    blocks=malloc(14*sizeof(short int));
    NewBlocks(blocks);
    for(int i=0;i<14;++i)printf("%d ", *(blocks+i));
    return 0;
}