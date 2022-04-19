#include "misc.h"
#include "scoring.h"
#include "statistics.h"


void hangman(int cont)
{
    li=0;
    word_g=0;
    if(cont==2)
    {
        printf("\n\n\n\tEnter word to guess: ");
        hide_word();
        dif=0;
    }
    else
        single();
    // Set the mask array - mask[i] is true if the
    // character s[i] has been guessed.  The mask
    // must be allocated, and initialized to all false
    int N = strlen(answer), greseli=1,ok;
    int mask[N];
    for (int i=0; i < N; ++i)
        mask[i] = 0;

    // Loop over each round of guessing
    int gameover = 0;
    while (! gameover)
    {
        system("cls");
        ok=0;
        // Print word with *s for unguessed letters
        printf("\n\n\tThe word is: ");
        for(int j=0; j < N; ++j)
        {
            if (mask[j])
                printf("%c", answer[j]);
            else
                printf("*");
        }
        printf("\n");
        spanzurare(greseli);

        // Get player's next guess
        printf("\n\tChoose letter: ");
        scanf(" %c", &guess);

        // Mark true all mask positions corresponding to guess
        for(int k=0; k < N; ++k)
        {
            if (answer[k] == guess)
            {
                mask[k] = 1;
                ok=1;
                scor();
            }
        }
        if(ok==0)
        {
            greseli=greseli+1;
            if(strchr(letters,guess)==0)
                letters[li++]=guess;
        }


        // Determine whether the player has won!
        gameover = 1;
        for(int m = 0; m < N; ++m)
        {
            if (!mask[m] && greseli!=7)
            {
                gameover = 0;
                break;
            }
        }

    }
    if(greseli!=7)
    {
        printf("\n\n\t\tCongratulations %s, you got it! The word is \"%s\".\n", nick, answer);
        word_g=1;
        strk=strk+1;
    }
    else
    {
        system("cls");
        spanzurare(greseli);
        printf("\n\n\t\tToo bad %s, the luck was not on your side today. The word was \"%s\".\n", nick,answer);
    }
    match=1;
    points=points+score;
    memset(letters, 0, sizeof(letters));
    stats(match,word_g,strk,points);
    printf("\n\t\tWhat would you like to do now chief?\n\n");
    printf("\t\t\t1.Play again\n\n");
    printf("\t\t\t2.Return to menu\n");
    continuare(cont);
    system("cls");
}
int single()
{
    printf("\n\n\n\t\t\t\tChoose the difficulty of the word:\n\n");
    printf("\t\t\t\t\t1.Easy\n\n");
    printf("\t\t\t\t\t2.Medium\n\n");
    printf("\t\t\t\t\t3.Hard\n\n");
    scanf("%d", &dif);
    int which=rdm(which);
    FILE *file1;
    file1=fopen("words.txt","r");
    if (dif==2)
        for (int i=1; i<=9; i++)
            fscanf(file1,"%s", answer);
    if (dif==3)
        for (int i=1; i<=18; i++)
            fscanf(file1,"%s", answer);
    while (which!=0)
    {
        fscanf(file1,"%s", answer);
        which--;
    }
    fclose(file1);
}
int rdm (int *x)
{
    srand(time(NULL));
    x=digsum(rand());
}
int digsum(int nr)
{
    int sum = 0;
    while (nr > 0 || sum > 9)
    {
        if (nr == 0)
        {
            nr = sum;
            sum = 0;
        }
        sum += nr % 10;
        nr /= 10;
    }
    return sum;
}
void continuare(int cont)
{
    scanf("%d", &cont);
    if(cont==1)
    {
        system("cls");
        hangman(cont);
    }
    else
    {
        TOP();
        hs();
        strk=0;
        points=0;
        system("cls");
        option();
    }
}
