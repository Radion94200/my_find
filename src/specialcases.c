#include "header.h"

/* Function check if it's a Symbolink */

int symbolink(char *path)
{
    struct stat buf;
    lstat(path, &buf);
    if (S_ISLNK(buf.st_mode))
        return 1;
    return 0;    
}

/* Function to compare args and path */

int functocomp(char *path, int argc, char *argv[])
{
    for (int i = 0; i < argc; i++)
    {
        int retval = mystrcmp(path, argv[i]);
        if (retval == 0)
            return 0;
        else
            return 1;
    }
    return 0;
}
