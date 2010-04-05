#ifndef DEF_H
#define DEF_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <glib.h>

#define NSTATE 1000
#define NTRAN 1000
#define NAUTO 1000
#define NSYM 9997
#define NIN 1000
#define NOUT 1000

enum symtype { AUTOMATON, STATE, INPUT, OUTPUT };
enum valtype { BOOL };

struct tran;

typedef struct state {
  char *name;
  gboolean init;
  //  GPtrArray *frtr;
  //  GPtrArray *totr;
} state;

typedef struct tran {
  gchar *name;
  state *from;
  state *to;
  gchar *expr;
} tran;

typedef struct lien {
  state *s;
  tran *from[1000];
  tran *to[1000];
} lien;


typedef struct automaton {
  gchar *name;
  GPtrArray *sttab;  // state table
  GPtrArray *trtab;  // transition table
} automaton;

typedef struct input {
  gchar *name;
  gboolean controllable;
} input;

typedef struct subout {
  gchar *expr;
  state *s;
  automaton *a;  // to simplify rename precedure
} subout;


typedef struct output {
  gchar *name;
  gboolean def_val;
  GPtrArray *exprs;  // element type: subout
} output;

typedef struct subouttmp {
  gchar *expr;
  output *outname;
} subouttmp;


struct symbol {
  char *name;
  enum symtype type;
};

struct symbol symtab[NSYM];

struct symbol *lookup(char *);
void addstate();
void createParName();
void createTranName();
void createTotrFrtr();
void reorderStates();
//void renameStateName();

void printStat();

void z3zDeclare(FILE* file);
void z3zOutput(FILE* file);
void z3zConditions(FILE* file);
void z3zEtats(FILE* file);
void z3zInit(FILE* file);
void z3zEvol(FILE* file);
void z3zEvol1(FILE* file);
void z3zCons(FILE* file);
void z3zCont(FILE* file);
void z3zLibre(FILE* file);

#endif
