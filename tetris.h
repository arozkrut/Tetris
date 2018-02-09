//
// Created by aleksandra on 20.01.18.
//
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ncurses.h>
#include <stdbool.h>
#include <string.h>

#define ELINROW 12

#define MATRIXWIDTH 22
#define MATRIXHEIGHT 22

#define NEXTWINDOWWIDTH 10
#define NEXTWINDOWHEIGHT 6

#define SCOREWINDOWWIDTH 26
#define SCOREWINDOWHEIGHT 5

#define DISTANCE 3

#define WAITING 1700
#define LESSTIME 50

#define SCORESINRANKING 15

#define BLINK 100

#define MATRIXWINFILE "matrix.txt"
#define NEXTWINFILE "nextWin.txt"
#define SCOREWINFILE "scoreWin.txt"
#define RANKINGFILE "ranking.txt"


struct Blocks                /* struktura przechowywujaca informacje o wylosowanych klockach */
{
    short int betweenI;      /* kiedy ostatnio wylosowano klocek I */
    short int successiveSZ;  /* ile wylsowano pod rzad klockow S lub Z */
};

struct Ranking               /* lista uporzadkowana przechowywujaca informacje o rankingu */
{
    char name[20];           /* imie gracza */
    long score;              /* wynik gracza */
    struct Ranking *next;
};
struct Ranking *ranking;     /* pierwszy element listy */

void ReadRanking();          /* stworzenie listy Ranking */
void WriteRanking();         /* wypisanie rankingu */

void Display();              /* funkcja przechodzaca miedzy menu, gra, rankingiem i koncem programu */

short int ShowMenu();        /* fukcja obslugujaca menu */
short int ShowMenuDuringGame();/* funcja obslugujaca drugie menu */
short int QuestionMenu();    /* funkcja obslugujaca manu z pytaniem czy chcemy zapisac wynik */
char *NameMenu();            /* funkcja wczytujaca imie gracza */

short int NewGame();         /* funkcja obslugujaca rozgrywke */



/*
 * CheckIfPossible - sprawdzenie czy klocek moze poruszyc sie w zadane miejsce
 * block - typ klocka
 * blockY - wspolrzedna Y w matrixie
 * blockX - wspolrzedna X w matrixie
 * position - kat klocka
 * tmatrix - tablica przechowywujaca wyglad matrixa
 * zwraca true jesli mozliwe, false wpp
 */
bool CheckIfPossible(short int block, int blockY, int blockX, int position, int *tmatrix);


/*
 * DrawBlock Rysuje klocki na ekranie
 * block - typ klocka
 * blockY - wspolrzedna Y w matrixie
 * blockX - wspolrzedna X w matrixie
 * position - kat klocka
 * win - okno w ktorym rysujemy matrixa
 * character - jakim znakiem rysujemy klocek
 * shadow - true to cien, false zwykly klocek
 */
void DrawBlock(WINDOW *win, short int block, int blockY, int blockX, int position, const chtype character, bool shadow);


/*
 * Changetmatrix aktualizuje wyglad tablicy tmatrix
 * block - typ klocka
 * blockY - wspolrzedna Y w matrixie
 * blockX - wspolrzedna X w matrixie
 * position - kat klocka
 * tmatrix - tablica przechowywujaca wyglad matrixa
 * value - jaki to klocek
 */
void Changetmatrix(short int block, int blockY, int blockX, int position, int *tmatrix, int value);


/*
 * Rotation obraca klocek jesli mozliwe
 * block - typ klocka
 * blockY - wspolrzedna Y w matrixie
 * blockX - wspolrzedna X w matrixie
 * position - kat klocka
 * tmatrix - tablica przechowywujaca wyglad matrixa
 * matrix - okno w ktorym rysujemy matrixa
 */
void Rotation(short int block, int *blockY, int *blockX, int *position, int *tmatrix, WINDOW *matrix);

/*
 * AddBlocksToSum aktualizuje tablice blocksInRow, usuwa wypelnione rzedy i liczy zdobyte punkty
 * block - typ klocka
 * blockY - wspolrzedna Y w matrixie
 * blockX - wspolrzedna X w matrixie
 * position - kat klocka
 * tmatrix - tablica przechowywujaca wyglad matrixa
 * matrix - okno w ktorym rysujemy matrixa
 * blocksInRow - przechowuje informacje o liczbie zajetych wspolrzednych w kazdym rzedzie matrixa
 * points - liczba punktow
 */
void AddBlocksToSum(WINDOW *matrix, short int block, int blockY, int blockX, int position, int *tmatrix, int *blocksInRow, long *points);

/*
 * FindShadow znajduje cien klocka jesli mozliwe
 * block - typ klocka
 * blockY - wspolrzedna Y w matrixie
 * blockX - wspolrzedna X w matrixie
 * position - kat klocka
 * tmatrix - tablica przechowywujaca wyglad matrixa
 * matrix - okno w ktorym rysujemy matrixa
 */
void FindShadow(WINDOW *matrix, short int block, int blockY, int blockX, int position, int *shadowY, int *tmatrix);



void UpdateNextWin(WINDOW *nextWin, short int nextBlock);                   /* aktualizuje okno z nastepnym klockiem */
void DrawMatrix(WINDOW *matrix,int *tmatrix);                               /* rysuje od caly matrix na ekranie */
void UpdateScoreWin(WINDOW *scoreWin, long points);                         /* aktualizuje okno z punktami */
void ReadBestScore(WINDOW *scoreWin);                                       /* wczytuje najlepszy wynik i go wypisuje */

void SaveScore(long points);                                                /* funkcja obslugujaca zapisywanie wyniku */


void SaveWindows(WINDOW *matrix, WINDOW *nextWin, WINDOW *scoreWin);        /* zapisanie stanu okien */
void RefreshWindows(WINDOW *matrix, WINDOW *nextWin, WINDOW *scoreWin);     /* odwiezenie okien */

WINDOW *CreateWindow(int height, int width, int starty, int startx);        /* tworzenie okna */
void DestroyWindow(WINDOW *win);                                            /* niszczenie okna */

void InitColors();                                                          /* deklaracja par kolorow */
void ClearWindow(WINDOW *win, const chtype character);                      /* czyszenie okien */

struct Blocks* initBlocksCounter();                                         /* przypisanie wartosci poczatkowych BlocksCounter */
short int NewBlock(struct Blocks *blocksCounter);                           /* funkcja losuje nowe bloki */

