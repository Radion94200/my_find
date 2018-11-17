#include "header.h"

/* Function check if it's a Symbolink */

int symbolink(char *path)
{
    struct stat buf;
    lstat(path, &buf);
    if (buf.st_mode == S_IFLNK)
        return 1;
    return 0;    
}
