#include "header.h"

int mystrlen(char *array)
{
    int count = 0;
    while (array[count] != '\0')
        count ++;
    return count;
}

int mystrcmp(char *firstchain, char *secondchain)
{
    int nbcharfirst = mystrlen(firstchain);
    int nbcharsec = mystrlen(secondchain);
    if (nbcharfirst == nbcharsec)
    {
        int i = 0;
        for (; i < nbcharfirst; i++)
        {
            if (firstchain[i] != secondchain[i])
                return 1;
        }
        if (i == nbcharsec)
            return 0;
    }
    else 
        return 1;
    return 0;
}
