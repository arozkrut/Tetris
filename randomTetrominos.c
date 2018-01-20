//
// Created by aleksandra on 20.01.18.
//


#include "tetris.h"

void NewBlocks(short int *tab)
{
    time_t t;
    srand((unsigned) time(&t));
    for(int i=0;i<14;++i)(*(tab+i))=rand()%7;
}