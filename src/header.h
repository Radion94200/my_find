#define _DEFAULT_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

struct parse{
    int d;
    int L;
    int P;
    int H;
};

/* Functions of usefunc.c */
int mystrlen(char *array);
int mystrcmp(char *firstchain, char *secondchain);

/* Functions of myfind.c */
void list_current_dir(char *path, struct parse parse);
char *concat_path(char *dirparent, char *dirchild, char *newpath);
void caseunaffiche(struct dirent *entry, char *path, struct parse parse, 
    int SL);
void mymalloc(struct dirent *entry, char *path, struct parse parse);

/*Functions of parser.c */
void parse_options(int argc, char *argv[], struct parse parse);
void initialize_struct(struct parse *parse);

/* Functions of main.c */
int main(int argc, char *argv[]);

/* Function of specialcases.c */
int symbolink(char *path);
