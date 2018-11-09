#include "header.h"

int mystrlen(char *array)
{
    int count = 0;
    for (; array[count]; count++);
    return count;
}
