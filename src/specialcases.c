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
