//
// Created by aleksandra on 20.01.18.
//
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ncurses.h>

struct Blocks
{
    short int betweenI;
    short int successiveSZ;
};

struct Blocks* initBlocksCounter();
void NewBlocks(struct Blocks *blocksCounter, short int *blocks);
