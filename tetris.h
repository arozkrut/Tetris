//
// Created by aleksandra on 20.01.18.
//
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ncurses.h>
#include <stdbool.h>

#define ELINROW 12

struct Blocks
{
    short int betweenI;
    short int successiveSZ;
};

void Display();

short int ShowMenu();
short int ShowMenuDuringGame();

short int NewGame();
bool CheckIfPossible(short int block, int blockY, int blockX, int position, int *tmatrix);
void DrawBlock(WINDOW *win, short int block, int blockY, int blockX, int position, const chtype character);
void Changetmatrix(short int block, int blockY, int blockX, int position, int *tmatrix, int value);

WINDOW *CreateWindow(int height, int width, int starty, int startx);
void DestroyWindow(WINDOW *win);

void InitColors();
void ClearWindow(WINDOW *win, const chtype character);

struct Blocks* initBlocksCounter();
short int NewBlock(struct Blocks *blocksCounter);

