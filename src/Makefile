
CC = clang -O2 -std=c99 -D_POSIX_SOURCE
#CC = gcc
CFLAGS = `pkg-config --cflags glib-2.0`
LIBS = `pkg-config --libs glib-2.0` 
#BISON = bison -d -t -v
BISON = bison -d

SOURCES = main.c lex.yy.c parser.tab.c funcs.c z3z.c ecitf.c
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

parser.tab.o : parser.tab.c types.h
	$(CC) $(CFLAGS) -c $^

parser.tab.c :  parser.y
	$(BISON) parser.y

funcs.o : funcs.c types.h
	$(CC) $(CFLAGS) -c $^

z3z.o : z3z.c z3z.h
	$(CC) $(CFLAGS) -c $^

ecitf.o : ecitf.c types.h
	$(CC) $(CFLAGS) -c $^