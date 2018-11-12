#include "header.h"

/* Function which concat the path of the current and child dir */

char *concat_path(char *dirparent, char *dirchild, char *newpath)
{
    int count = 0;
    for (int i = 0; i < mystrlen(dirparent); i++)
    {
        newpath[count] = dirparent[i];
        count++;
    }
    if (dirparent[count - 1] != '/')
    {
        newpath[count] = '/';
        count++;
    }
    for (int j = 0; j < mystrlen(dirchild); j++)
    {
        newpath[count] = dirchild[j];
        count++;
    }
    newpath[count] = '\0';
    return newpath;
}

/* Function to unaffiche . & .. */

void caseunaffiche(struct dirent *entry, char *path)
{
    if (mystrcmp("..", entry->d_name) != 0 && mystrcmp(".",
        entry->d_name) != 0)
    {
        unsigned char isdir = entry->d_type;
        if (isdir == 4) 
        {
            char *newpath = malloc(sizeof(char) * (mystrlen(path) +
                mystrlen(entry->d_name) + 2));
            newpath = concat_path(path, entry->d_name, newpath);
            list_current_dir(newpath);
            free(newpath);
        }
        else
            printf("%s""/""%s\n", path, entry->d_name);
    }
}

/* Function that list files and directory in the given path */

void list_current_dir(char *path)
{
    if (path == NULL)
        path = ".";
    DIR *dir = opendir(path);
    if (dir == NULL)
    {
        fprintf(stderr, "myfind: cannot do \'%s\': %s\n", path, 
            strerror(errno));
    }
    if (dir != NULL)
    {
        struct dirent *entry = readdir(dir);
        printf("%s\n", path);
        for (; entry; entry = readdir(dir))
        {
            caseunaffiche(entry, path);
        }
        closedir(dir);
    }
}
