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

short int NewGame();

WINDOW *CreateWindow(int height, int width, int starty, int startx);
void DestroyWindow(WINDOW *win);

void InitColors();
void ClearWindow(WINDOW *win, const chtype ch);

struct Blocks* initBlocksCounter();
short int NewBlock(struct Blocks *blocksCounter);

