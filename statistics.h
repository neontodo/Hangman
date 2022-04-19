#ifndef STATISTICS_H_INCLUDED
#define STATISTICS_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>

struct top
{
    char user[20];
    int highs;
};

int word_g;
int strk;
int match;

extern void TOP();
extern void stats(int, int, int, int);
extern void stots();

#endif // STATISTICS_H_INCLUDED
