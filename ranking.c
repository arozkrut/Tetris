//
// Created by aleksandra on 30.01.18.
//

#include "tetris.h"

#define RANKINGWIDTH 35
#define RANKINGHEIGHT 21

void ReadRanking()
{
    char string[20];                                           /* lokalna zmienna uzywana do wczytywania z pliku */

    FILE *rankingFile;                                         /* wskaznik na plik z rankingiem */
    rankingFile=fopen(RANKINGFILE, "r");

    struct Ranking *profile;                                   /* lokalna zmienna pomocnicza do tworzenia listy */
    ranking=(struct Ranking *)malloc(sizeof(struct Ranking));  /* przypisujemy zmiennej globalnej ranking pamiec */

    ranking->next=NULL;                                        /* i przypisujemy jej wartosci poczatkowe */
    ranking->score=-1;

    if(rankingFile==NULL)return;                               /* jesli pliku nie otwarto wroc */

    if(fscanf(rankingFile, "%s", string)==EOF)return;          /* jesli plik jest pusty wroc */

    strcpy(ranking->name,string);
    fscanf(rankingFile, "%s", string);
    ranking->score=strtol(string,NULL,10);                     /* zamiana stringa na typ int */

    profile=ranking;                                           /* przypisanie zmiennej profile pierwszego elementu listy */
    while(fscanf(rankingFile, "%s", string)!=EOF)              /* dopoki nie trafimy na koniec pliku wykonuj: */
    {
        struct Ranking *new;                                   /* wczytalismy cos co nie jest EOF */
        new=(struct Ranking *)malloc(sizeof(struct Ranking));  /* wiec tworzymy nowy element listy */
                                                               /* i przypisujemy mu wczytane wartosci */
        strcat(new->name, string);
        fscanf(rankingFile, "%s", string);
        new->score=strtol(string,NULL,10);
        new->next=NULL;

        profile->next=new;
        profile=new;
    }

    fclose(rankingFile);
}

void UpdateRankingFile()
{
    FILE *rankingFile;
    rankingFile=fopen(RANKINGFILE, "w");

    struct Ranking *profile;
    profile=ranking;

    for(int i=0;i<SCORESINRANKING;++i)
    {
        if(profile==NULL)break;
        fprintf(rankingFile, "%s %ld\n", profile->name, profile->score);
        profile=profile->next;
    }

    fclose(rankingFile);
}



void ReadBestScore(WINDOW *scoreWin)
{
    if(ranking->score==-1)mvwprintw(scoreWin, 1, 14, "         0");
    else mvwprintw(scoreWin, 1, 14, "%10d", ranking->score);
    wrefresh(scoreWin);

}

void AddScore(long points, char *playerName)
{
    if(ranking->score==-1)
    {
        ranking->score=points;
        strcpy(ranking->name, playerName);
    }
    else if(points>ranking->score)
    {
        struct Ranking *new;
        new=(struct Ranking *)malloc(sizeof(struct Ranking));

        new->score=points;
        strcpy(new->name, playerName);
        new->next=ranking;
        ranking=new;
    }
    else
    {
        struct Ranking *profile=ranking;

        while(profile->next!=NULL && profile->next->score>=points)
        {
            profile=profile->next;
        }

        struct Ranking *new;
        new=(struct Ranking *)malloc(sizeof(struct Ranking));

        new->score=points;
        strcpy(new->name, playerName);
        new->next=profile->next;
        profile->next=new;
    }
}

void SaveScore(long points)
{
    short int option;
    option=QuestionMenu();

    if(option==1)return;

    char *playerName=NameMenu();

    AddScore(points, playerName);

    free(playerName);
    playerName=NULL;

    UpdateRankingFile();
}

void WriteRanking()
{
    WINDOW *rankingWin=CreateWindow(RANKINGHEIGHT, RANKINGWIDTH, (getmaxy(stdscr)-RANKINGHEIGHT)/2, (getmaxx(stdscr)-RANKINGWIDTH)/2);

    keypad(rankingWin, TRUE);
    wattron(rankingWin, COLOR_PAIR(12));
    wattron(rankingWin, A_BOLD);

    ClearWindow(rankingWin, ' ');
    box(rankingWin, 0, 0);

    mvwaddch(rankingWin,1,(RANKINGWIDTH-7)/2-2,ACS_DIAMOND);
    wattron(rankingWin, A_UNDERLINE);
    mvwprintw(rankingWin, 1, (RANKINGWIDTH-7)/2, "RANKING");
    wattroff(rankingWin, A_UNDERLINE);
    mvwaddch(rankingWin,1,(RANKINGWIDTH-7)/2+8,ACS_DIAMOND);

    struct Ranking *profile;
    profile=ranking;

    wattron(rankingWin, A_REVERSE);

    for(int i=1;i<=SCORESINRANKING;++i)
    {
        if(profile==NULL || ranking->score==-1)
        {
            mvwprintw(rankingWin, i+2, 2, "%2d. ----------      ----------", i);
        }
        else
        {
            mvwprintw(rankingWin, i+2, 2, "%2d. %10s      %10ld", i, profile->name, profile->score);
            profile=profile->next;
        }
        wattroff(rankingWin, A_REVERSE);
    }

    mvwprintw(rankingWin,19,(RANKINGWIDTH-23)/2, "PRESS ANY KEY TO RETURN");
    wrefresh(rankingWin);

    getch();
    DestroyWindow(rankingWin);
}