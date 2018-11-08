#include "header.h"

void list_current_dir()
{
	DIR *dir = opendir("./");
	struct dirent *entry = readdir(dir);
	for (; entry; entry = readdir(dir))
	{
		printf("%s\n", entry->d_name);
	}
}
