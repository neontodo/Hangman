#include "statistics.h"
#include "scoring.h"
#include "misc.h"

void TOP()
{
    int i,aux;
    char oux[20],actual_name[20];
    struct top arr[6];
    FILE *ftop = fopen("top_list.txt", "r");
    for(i=1; i<=5; i++)
    {
        fscanf(ftop, "%s", &arr[i].user);
        fscanf(ftop, "%d", &arr[i].highs);
    }
    strcpy(actual_name, nick);
    fclose(ftop);
    FILE *fto = fopen("top_list.txt", "w");
    for(i=1; i<=5; i++)
    {
        if(arr[i].highs<points)
        {
            aux=arr[i].highs;
            arr[i].highs=points;
            points=aux;
            strcpy(oux,arr[i].user);
            strcpy(arr[i].user, nick);
            strcpy(nick, oux);
        }
    }
    for(i=1; i<=5; i++)
    {
        fprintf(ftop, "%s\n", arr[i].user);
        fprintf(ftop, "%d\n", arr[i].highs);
    }
    fclose(fto);
    strcpy(nick, actual_name);
}
void stats(int match, int word_g, int strk, int points)
{
    int matplay, total_points, g_word, streak;
    FILE *fstats = fopen("stats.txt", "r");
    fscanf(fstats, "%d", &matplay);
    fscanf(fstats, "%d", &total_points);
    fscanf(fstats, "%d", &g_word);
    fscanf(fstats, "%d", &streak);
    fclose(fstats);
    matplay=matplay+match;
    total_points=total_points+points;
    if(word_g==1)
        g_word=g_word+word_g;
    if(strk>streak)
        streak=strk;
    FILE *fstat = fopen("stats.txt", "w");
    fprintf(fstat, "%d", matplay);
    fprintf(fstat, "\n%d", total_points);
    fprintf(fstat, "\n%d", g_word);
    fprintf(fstat, "\n%d", streak);
    word_g=0;
    match=0;
    score=0;
    fclose(fstat);
}
void stots()
{
    int matplay, total_points, g_word, streak,i;
    FILE *fstats = fopen("stats.txt", "r");
    fscanf(fstats, "%d", &matplay);
    fscanf(fstats, "%d", &total_points);
    fscanf(fstats, "%d", &g_word);
    fscanf(fstats, "%d", &streak);
    printf("\n\n\n\t\tTotal number of matches played: %d\n", matplay);
    printf("\t\tTotal number of points earned: %d\n", total_points);
    printf("\t\tTotal number of guessed words: %d\n", g_word);
    printf("\t\tHighest streak: %d\n\n\n\n", streak);
    fclose(fstats);
    struct top arr[6];
    FILE *ftop = fopen("top_list.txt", "r");
    for(i=1; i<=5; i++)
    {
        fscanf(ftop, "%s", &arr[i].user);
        fscanf(ftop, "%d", &arr[i].highs);
    }
    printf("\t\tTOP 5 PLAYERS:\n");
    printf("\t\t\t ==================\n");
    for(i=1; i<=5; i++)
        printf("\t\t\t || %d. %s : %d\n", i, arr[i].user, arr[i].highs);
    printf("\t\t\t ==================\n");
    printf("\n\n\t\tPress any key to return to menu...");
    getch();
    system("cls");
    fclose(ftop);
    option();
}
