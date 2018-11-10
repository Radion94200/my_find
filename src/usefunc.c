#include "header.h"

int mystrlen(char *array)
{
    int count = 0;
    for (; array[count]; count++);
    return count;
}

int mystrcmp(char *firstchain, char *secondchain)
{
    int nbcharfirst = mystrlen(firstchain);
    int nbcharsec = mystrlen(secondchain);
    if (nbcharfirst == nbcharsec)
    {
        for (int i = 0; i != '\0'; i++)
        {
            if (firstchain[i] != secondchain[i])
                return 1;
        }
    }
    return 0;
}
