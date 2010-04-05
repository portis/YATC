
CC = clang -O2 -std=c99 -D_POSIX_SOURCE
#CC = gcc
CFLAGS = `pkg-config --cflags glib-2.0`
LIBS = `pkg-config --libs glib-2.0` 

all :   funcs.o types.h z3zOut4.o parser3.tab.o lex.yy.o
	$(CC) $(CFLAGS) $(LIBS) -o yatc funcs.o z3zOut4.o parser3.tab.o lex.yy.o -lfl

lex.yy.c : scanner.flex
	flex scanner.flex

lex.yy.o : lex.yy.c
	$(CC) $(CFLAGS) $(LIBS) -c lex.yy.c

parser3.tab.c :  parser3.y
	bison -d -t -v parser3.y

parser3.tab.o : parser3.tab.c
	$(CC) $(CFLAGS) $(LIBS) -c parser3.tab.c

funcs.o : funcs.c types.h
	$(CC) $(CFLAGS) $(LIBS) -c funcs.c

z3zOut.o : z3zOut4.c types.h
	$(CC) $(CFLAGS) $(LIBS) -c z3zOut4.c