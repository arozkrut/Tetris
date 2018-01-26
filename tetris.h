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

void Display();

short int ShowMenu();
short int ShowMenuDuringGame();

WINDOW *CreateWindow(int height, int width, int starty, int startx);
void DestroyWindow(WINDOW *win);

struct Blocks* initBlocksCounter();
short int NewBlock(struct Blocks *blocksCounter);

