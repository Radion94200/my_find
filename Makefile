cc = gcc
CFLAGS = -g -Wall -Wextra -Wall -pedantic -std=c99

SRCS = src/myfind.c src/main.c src/parser.c src/usefunc.c src/specialcases.c
OBJS = ${SRCS:.c=.o}

myfind : ${OBJS}
	 ${CC} -o myfind ${OBJS} ${CFLAGS}

.PHONY: all check clean

all : myfind

check : tests/test.sh myfind
	tests/test.sh | column -t

clean :
	${RM} src/*.o
	${RM} myfind
	${RM} *.txt
	${RM} src/.*.swp #pour supprimer les fichiers de l editeur
	${RM} .*.swp
	${RM} tests/.*.swp
