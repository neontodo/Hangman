#include "scoring.h"
#include "misc.h"

void hs()
{
    FILE *f = fopen("hs.txt", "r+");
    fscanf(f, "%d", &highscore);
    if(points>highscore)
    {
        printf("\n\n\t\t================================\n");
        printf("\t\t======= New Highscore !!!=======\n");
        printf("\t\t================================\n");
        getch();
        highscore=points;
        fprintf(f, "%d", highscore);
    }
    fclose(f);
}
void scor()
{
    switch(dif)
    {
    case 0:
    {
        score=score+5;
        break;
    }
    case 1:
    {
        score=score+(5*1.25);
        break;
    }
    case 2:
    {
        score=score+(5*1.5);
        break;
    }
    case 3:
    {
        score=score+(5*1.75);
        break;
    }
    }
}
