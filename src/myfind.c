#include "header.h"

/* Function which concat the path of the current and child dir */

char *concat_path(char *dirparent, char *dirchild)
{
    char *path = malloc(sizeof(char) * (mystrlen(dirparent) +
                mystrlen(dirchild)) + 2);
    int count = 0;
    for (int i = 0; i != '\0'; i++)
    {
        path[count] = dirparent[i];
        count++;
    }
    path[count + 1] = '/';
    for (int j = 0; j != '\0'; j++)
    {
        path[count] = dirchild[j];
        count++;
    }
    return path;
}

/* Function to unaffiche . & .. */

void caseunaffiche(struct dirent *entry, char *path)
{
    int valueone = mystrlen("..");
    int valuetwo = mystrlen(entry->d_name);
    int valuecurrent = mystrlen(".");
    if (valueone != valuetwo && valuecurrent != valuetwo)
    {
        /*unsigned char isdir = entry->d_type;
        if (isdir == 4) 
        {
            printf("%s\n", entry->d_name);
            list_current_dir(path);
        }
        else*/ 
            printf("%s""/""%s\n", path, entry->d_name);
    }
}

/* Function that list files and directory in the given path */

void list_current_dir(char *path)
{
    DIR *dir = opendir(path);
	struct dirent *entry = readdir(dir);
	printf("%s\n", path);
    for (; entry; entry = readdir(dir))
	{
        caseunaffiche(entry, path);
	}
    closedir(dir);
}
