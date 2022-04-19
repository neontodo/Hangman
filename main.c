#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include "printing.h"
#include "statistics.h"
#include "scoring.h"
#include "misc.h"

int main()
{
    //system("Song.mp3&");
    printf("\n\n\n\n\t\t\tPlease enter your name: ");
    scanf("%s", &nick);
    system("cls");
    printf("\n\n\tInstructions:\n --------------------------------\n");
    printf(" ->The computer / Another person will introduce a word which the player will try to guess\n");
    printf(" ->Have the player select a letter of the alphabet\n");
    printf(" ->If the letter selected by the player is included in the word, the letter will be revealed,\n   otherwise a portion of the hangman will appear\n");
    printf(" ->The game will end when the word is guessed (WIN) or all the parts of the hangman will be displayed (LOSE)\n");
    printf("\n\n\t Press any key to continue...");
    getch();
    system("cls");
    option();

    return 0;
}
