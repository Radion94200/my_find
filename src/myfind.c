#include "header.h"

void list_current_dir(char *path)
{
	DIR *dir = opendir("./");
	struct dirent *entry = readdir(dir);
	for (; entry; entry = readdir(dir))
	{
		unsigned char isdir = entry->d_type;
		if (isdir == 4) 
		{
			printf("%s\n", entry->d_name);
			list_current_dir(path);
		}
		else 
			printf("%s\n", entry->d_name);
	}
}

char concat_path(char *dirparent, char *dirchild)
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
