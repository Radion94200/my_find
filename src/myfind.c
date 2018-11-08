#include "header.h"

void list_current_dir(char *path)
{
	DIR *dir = opendir("path");
	struct dirent *entry = readdir(dir);
	for (; entry; entry = readdir(dir))
	{
		unsigned char isdir = entry->d_type;
		if (isdir == 4) 
		{
			printf("%s\n", entry->d_name);
			list_current_dir();
		}
		else 
			printf("%s\n", entry->d_name);
	}
}

char concat_path(char *dirparent, char *dirchild)
{
	
}	
		
