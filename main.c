#include "tetris.h"

int main()
{
    /*
     * Losowanie funkcją rand() od czasu
     */
    time_t t;
    srand((unsigned) time(&t));

    /*
     * Wczytanie informacji o rankingu
     * do listy uporzadkowanej
     * o pierwszym elemencie ranking
     */
    struct Ranking *ranking;
    ReadRanking();


    Display();

    return 0;
}
