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
    if (newpath[count - 1] != '/')
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

void caseunaffiche(struct dirent *entry, char *path, struct parse parse, 
    int SL)
{
    if (mystrcmp("..", entry->d_name) != 0 && mystrcmp(".",
        entry->d_name) != 0)
    {
        unsigned char isdir = entry->d_type;
        if (parse.P == 1 && SL == 1)
            return;
        if (isdir == DT_DIR) 
            mymalloc(entry, path, parse);
        else if (isdir == DT_LNK && parse.L == 1)
            mymalloc(entry, path, parse);
        else
        {
            if (path[mystrlen(path) - 1] == '/')
                printf("%s""%s\n", path, entry->d_name);
            else
                printf("%s""/""%s\n", path, entry->d_name);
        }
    }
}

/* Function that list files and directory in the given path */

void list_current_dir(char *path, struct parse parse)
{
    if (path == NULL)
        path = ".";
    DIR *dir = opendir(path);
    int SL = symbolink(path);
    if (dir == NULL)
    {
        if (errno == EACCES)
            printf("%s,\n", path);
        fprintf(stderr, "myfind: cannot do \'%s\': %s\n", path, 
            strerror(errno));
    }
    if (dir != NULL)
    {
        struct dirent *entry = readdir(dir);
        if (parse.d != 1)
            printf("%s\n", path);
        for (; entry; entry = readdir(dir))
            caseunaffiche(entry, path, parse, SL);
        if (parse.d == 1)
            printf("%s\n", path);
        closedir(dir);
    }
}

/* Function which allocate memory for the concat then do recursive if 
necessary */

void mymalloc(struct dirent *entry, char *path, struct parse parse)
{
    char *newpath = malloc(sizeof(char) * (mystrlen(path) +
        mystrlen(entry->d_name) + 2));
    newpath = concat_path(path, entry->d_name, newpath);
    list_current_dir(newpath, parse);
    free(newpath);
}
