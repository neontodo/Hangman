#include "printing.h"
#include "misc.h"
#include "scoring.h"
#include "statistics.h"


void spanzurare(int g)
{
    switch(g)
    {
    case 1:
    {
        printf("\n\t\t+---+\n");
        printf("  \t\t|   |");
        printf("\t\t\t\t Score: %d \n", score);
        printf("  \t\t|\n");
        printf("  \t\t|\n");
        printf("  \t\t|\n");
        printf("  \t\t|\n");
        printf("\t\t-------\n\n");
        printf("\tWrong letters: %s\n", letters);
        break;
    }
    case 2:
    {
        printf("\n\t\t+---+\n");
        printf(" \t\t|   |");
        printf("\t\t\t\t Score: %d \n", score);
        printf(" \t\t|   0\n");
        printf(" \t\t|\n");
        printf(" \t\t|\n");
        printf(" \t\t|\n");
        printf("\t\t-------\n\n");
        printf("\tWrong letters: %s\n", letters);
        break;
    }
    case 3:
    {
        printf("\n\t\t+---+\n");
        printf(" \t\t|   |");
        printf("\t\t\t\t Score: %d \n", score);
        printf(" \t\t|   0\n");
        printf(" \t\t|   |\n");
        printf(" \t\t|\n");
        printf(" \t\t|\n");
        printf("\t\t-------\n\n");
        printf("\tWrong letters: %s\n", letters);
        break;
    }
    case 4:
    {
        printf("\n\t\t+---+\n");
        printf(" \t\t|   |");
        printf("\t\t\t\t Score: %d \n", score);
        printf(" \t\t|   0\n");
        printf(" \t\t|  /|\n");
        printf(" \t\t|\n");
        printf(" \t\t|\n");
        printf("\t\t-------\n\n");
        printf("\tWrong letters: %s\n", letters);
        break;
    }
    case 5:
    {
        printf("\n\t\t+---+\n");
        printf(" \t\t|   |");
        printf("\t\t\t\t Score: %d \n", score);
        printf(" \t\t|   0\n");
        printf(" \t\t|  /|\\ \n");
        printf(" \t\t|\n");
        printf(" \t\t|\n");
        printf("\t\t-------\n\n");
        printf("\tWrong letters: %s\n", letters);
        break;
    }
    case 6:
    {
        printf("\n\t\t+---+\n");
        printf(" \t\t|   |");
        printf("\t\t\t\t Score: %d \n", score);
        printf(" \t\t|   0          Please don't kill me.\n");
        printf(" \t\t|  /|\\ \n");
        printf(" \t\t|  / \n");
        printf(" \t\t|\n");
        printf("\t\t-------\n\n");
        printf("\tWrong letters: %s\n", letters);
        break;
    }
    case 7:
    {
        printf("\n\t\t+---+\n");
        printf(" \t\t|   |");
        printf("\t\t\t\t Score: %d \n", score);
        printf(" \t\t|   x\n");
        printf(" \t\t|  /|\\ \n");
        printf(" \t\t|  / \\\n");
        printf(" \t\t|\n");
        printf("\t\t-------\n\n");
        break;
    }
    }
}
void hide_word()
{
    char c=' ';
    int i=0;
    while (i<=20)
    {
        answer[i]=getch();
        c=answer[i];
        if(c==13)
            break;
        else
            printf("*");
        i++;
    }
    answer[i]='\0';
    i=0;
}
int option()
{
    int cont=1;
    while(cont==1 || cont==2 || cont==3 || cont==4)
    {
        printf(" \n\n\n\n\t\t\tSelect option:\n\n");
        printf("\t\t\t\t1.Singleplayer\n\n");
        printf("\t\t\t\t2.Multiplayer\n\n");
        printf("\t\t\t\t3.Stats\n\n");
        printf("\t\t\t\t4.Quit\n\n");
        scanf("%d", &cont);
        system("cls");
        switch(cont)
        {
        case 1:
        {
            hangman(cont);
            strk=0;
            break;
        }
        case 2:
        {
            hangman(cont);
            strk=0;
            break;
        }
        case 3:
        {
            stots();
            break;
        }
        case 4:
            exit(0);
        }
    }
    return 0;
}
