#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

/*struct parse{
	
}*/

/* Functions of usefunc.c */
int mystrlen(char *array);
int mystrcmp(char *firstchain, char *secondchain);

/* Functions of myfind.c */
void list_current_dir(char *path);
char *concat_path(char *dirparent, char *dirchild);
void caseunaffiche(struct dirent *entry, char *path);

/*Functions of parser.c */

/* Functions of main.c */
int main(int argc, char *argv[]);

/* Function of specialcases.c */
