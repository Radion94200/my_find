#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

/*struct parse{
	
}*/

int mystrlen(char *array);

void list_current_dir(char *path);

char *concat_path(char *dirparent, char *dirchild);

int main(int argc, char *argv[]);
