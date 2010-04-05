
CC = clang -O2 -std=c99 -D_POSIX_SOURCE
#CC = gcc
CFLAGS = `pkg-config --cflags glib-2.0`
LIBS = `pkg-config --libs glib-2.0` 

SOURCES = main.c lex.yy.c parser3.tab.c funcs.c z3zOut4.c ecitf.c
HEADERS = *.h

BIN = yatc

all :   types.h $(SOURCES)
	$(CC) $(CFLAGS) $(LIBS) -o yatc $(SOURCES) -lfl

main.o : main.c
	$(CC) $(CFLAGS) -c main.c

lex.yy.o : lex.yy.c
	$(CC) $(CFLAGS) -c lex.yy.c

lex.yy.c : scanner.flex
	flex scanner.flex

parser3.tab.o : parser3.tab.c types.h
	$(CC) $(CFLAGS) -c $^

parser3.tab.c :  parser3.y
	bison -d -t -v parser3.y

funcs.o : funcs.c types.h
	$(CC) $(CFLAGS) -c $^

z3zOut.o : z3zOut4.c types.h
	$(CC) $(CFLAGS) -c $^

ecitf.o : ecitf.c types.h
	$(CC) $(CFLAGS) -c $^