#ifndef DEF_H
#define DEF_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <glib.h>

/* #define NSTATE 1000 */
/* #define NTRAN 1000 */
/* #define NAUTO 1000 */
/* #define NSYM 9997 */
/* #define NIN 1000 */
/* #define NOUT 1000 */

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

/* typedef struct lien { */
/*   state *s; */
/*   tran *from[1000]; */
/*   tran *to[1000]; */
/* } lien; */


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


#define GET_INPUT(intab, i) ((input *)g_ptr_array_index(intab, i))
#define GET_OUTPUT(outtab, i) ((output *)g_ptr_array_index(outtab, i))
#define GET_PAR(partab, i) ((automaton *)g_ptr_array_index(partab, i))
#define GET_STATE(sttab, i) ((state *)g_ptr_array_index(sttab, i))
#define GET_TRAN(trtab, i) ((tran *)g_ptr_array_index(trtab, i))


input *input_find(gchar *name);
void input_add(gchar *name, gboolean cont);
void input_print(input *i);
void intab_reorder();
void intab_print();

subout *subout_new(state *st, automaton *at, gchar *expr);
void subout_print(subout *so);
output *output_find(gchar *name);
void output_add(gchar *name);
void output_add2(gchar *name, gboolean val);
void outtab_subout_reorder();
void output_print(output *o);
void outtab_reorder();
void outtab_update_subexp();
void outtab_print();

state *state_new(gchar *name, gboolean init);
state *state_dup2(state *s);
void state_add_postfix(state *s, gchar *p);
void state_print(state* s);

tran *tran_new(state *from, state *to, gchar* expr);
tran *tran_dup2(tran *t, automaton *a);
void tran_print(tran* t);

automaton *automaton_new(gchar *name);
void automaton_add_state(automaton *a, state *s);
void automaton_add_tran(automaton *a, tran *t);
state *automaton_find_state(automaton *a, gchar *sname);
automaton *automaton_dup2(automaton *a);
static void automaton_reorder_states(automaton *a);
static void automaton_reorder_trans(automaton *a);
void tran_add_postfix(tran *t, int i);
static void automaton_add_postfix(automaton *a, int i);
void automaton_print(automaton *a);

void autotab_add(automaton *a);
automaton *autotab_find(gchar *aname);
void autotab_reorder();
void autotab_print();

void partab_add(automaton *a);
void partab_find_and_add2(gchar *aname);
void partab_add_postfix();
void partab_reorder();
void partab_print();

void SysInit();


//struct symbol symtab[NSYM];

//struct symbol *lookup(char *);


#endif
