#ifndef MISC_H_INCLUDED
#define MISC_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

int dif;
int li;
char letters[30];
char answer[20];
char guess;
char nick[20];

extern void hangman(int);
extern int single();
extern int rdm(int*);
extern int digsum(int);
extern void continuare(int);

#endif // MISC_H_INCLUDED
