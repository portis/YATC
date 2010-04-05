%{
#include <stdio.h>
#include "types.h"
  //#define YYSTYPE char *
#define YYDEBUG 1

 static void addTran(char *f, char *t, char *e);

 static void addOutput(char *f, gboolean def);
 static void addOutput2(state *s, automaton *at, char *f, char *e);
 static GPtrArray * findOutput(char *f, char *e);
 static void addOutputFinal(state *st, automaton *at, GPtrArray *arr);
 static void addPar(char *a);


 //extern char yylex();

 /* newly added */
 extern void input_add(gchar *name, gboolean cont);
 extern output *output_find(gchar *name);
 extern void output_add(gchar *name); //, gboolean def);
 extern subout *subout_new(state *st, automaton *at, gchar *expr);
 extern state *state_new(gchar *name, gboolean init);
 extern automaton *automaton_new(gchar *name);
 extern void automaton_add_state(automaton *a, state *s);
 extern void automaton_add_tran(automaton *a, tran *t);
 extern void autotab_add(automaton *a);
 extern tran * tran_new(state *, state *, char *);
 extern void automaton_add_tran(automaton *a, tran *t);
 extern void partab_find_and_add(gchar *aname);
 extern void partab_find_and_add2(char *a);
 automaton* cura;
 state* curs;
 GPtrArray *exprstmp;

 int yylex(void);
 int yyerror(char *s);
%}



%union
{
  char *text;
  GPtrArray *array;
  int  ival;
};


%token T_TARGOS T_END_TARGOS
%token T_AUTOMATON
%token T_STATES T_INIT
%token T_TRANS T_FROM T_TO T_WITH
%token T_AND T_OR T_NOT T_PRE
%token <text> T_ID
%token T_PROCESS T_SYSTEM T_IN T_OUT T_BOOL
%token T_PAR T_ENDPAR T_RAFF
%token T_TRUE T_FALSE

%left T_AND T_OR
%nonassoc T_NOT

%start t_program

%%

t_program : T_TARGOS t_automaton_list t_proc t_par T_END_TARGOS ;

t_automaton_list : t_automaton
| t_automaton_list t_automaton
;

t_automaton : t_autohead t_states t_trans 
;

t_autohead : T_AUTOMATON T_ID { cura = automaton_new($2); autotab_add(cura); } 
;

t_states : T_STATES t_state_list
;

t_state_list : t_state_init t_state_normal_list
;

t_state_init : T_ID T_INIT '[' ']' { curs = state_new($1, TRUE); automaton_add_state(cura, curs); } 
| T_ID T_INIT '[' t_ooo ']' { curs = state_new($1, TRUE); automaton_add_state(cura, curs); addOutputFinal(curs, cura, $<array>4); } 
;

t_state_normal_list :
T_ID '[' ']' { curs = state_new($1, FALSE); automaton_add_state(cura, curs); }
| T_ID '[' t_ooo ']' { curs = state_new($1, FALSE); automaton_add_state(cura, curs); addOutputFinal(curs, cura, $<array>3); }
| T_ID '[' ']' t_state_normal_list { curs = state_new($1, FALSE); automaton_add_state(cura, curs); }
| T_ID '[' t_ooo ']' t_state_normal_list { curs = state_new($1, FALSE); automaton_add_state(cura, curs); addOutputFinal(curs, cura, $<array>3); }
;

t_ooo :  T_ID '=' t_out_expr ';'  { $<array>$ = findOutput($1, $<text>3); } 
| t_ooo T_ID '=' t_out_expr ';'  { $<array>$ = findOutput($2, $<text>4); } 
;

t_out_expr : T_ID 
           | T_TRUE 
{ gchar *ct = "1";
  $<text>$ = ct;
 }   | T_FALSE 
{ gchar *ct = g_strdup("-1");
  $<text>$ = ct;
 }  
           | T_PRE '(' T_ID ')' 
{ char *ct = g_strdup("pre(");
  ct = strcat(ct, $<text>3);
  ct = strcat(ct, ")");
  $<text>$ = ct;
 }  
           | '(' t_out_expr ')'
{ char *ct = g_strdup("(");
  ct = strcat(ct, $<text>2);
  ct = strcat(ct, ")");
  $<text>$ = ct;
 }  
           | T_NOT t_out_expr
{ char *ct = g_strdup("not (");
  ct = strcat(ct, $<text>2);
  ct = strcat(ct, ")");
  $<text>$ = ct;
 }
           | t_out_expr T_AND t_out_expr
	   {
	     char *ct = g_strdup($<text>1);
  ct = strcat(ct, " and ");
  ct = strcat(ct, $<text>3);
  $<text>$ = ct;
 }  
           | t_out_expr T_OR t_out_expr 
	   {
	     char *ct = g_strdup($<text>1);
	     ct = strcat(ct, " or ");
	     ct = strcat(ct, $<text>3);
	     $<text>$ = ct;
	   }  
;

t_trans : T_TRANS t_tran_list 
;

t_tran_list : 
 T_FROM T_ID T_TO T_ID T_WITH T_ID  '[' t_tran_expr ']' { addTran($2, $4, $<text>8); }
| T_FROM T_ID T_TO T_ID T_WITH T_ID '[' t_tran_expr ']' t_tran_list { addTran($2, $4, $<text>8); } 
;

t_tran_expr : T_ID { { gchar *ct = g_strdup($1); $<text>$ = ct; } }
| T_TRUE { $<text>$ = "1"; }
| T_FALSE { $<text>$ = "-1"; }
| T_PRE '(' T_ID ')' { gchar *ct = g_strconcat("pre(", $<text>2, ")", NULL); free($<text>2); $<text>$ = ct;  }
| '(' t_tran_expr ')' { gchar *ct = g_strconcat("(", $<text>2, ")", NULL); free($<text>2); $<text>$ = ct; }
| T_NOT t_tran_expr { gchar *ct = g_strconcat("not (", $<text>2, ")", NULL); free($<text>2); $<text>$ = ct; }
| t_tran_expr T_AND t_tran_expr { gchar *ct = g_strconcat($<text>1, " and ", $<text>3, NULL); free($<text>1); free($<text>3); $<text>$ = ct; }
| t_tran_expr T_OR t_tran_expr  { gchar *ct = g_strconcat($<text>1, " or ", $<text>3, NULL); free($<text>1); free($<text>3);  $<text>$ = ct; }
;

t_proc : T_PROCESS T_SYSTEM '[' t_in ',' t_out ']' 
;

t_in : T_IN '(' t_inlist ':' T_BOOL ')' 
;

t_inlist : T_ID { input_add($1, FALSE); } 
         | '*' T_ID { input_add($2, TRUE); }
         | T_ID ',' t_inlist { input_add($1, FALSE); } 
         | '*' T_ID ',' t_inlist { input_add($2, TRUE); }
;

t_out : T_OUT '(' t_outlist ':' T_BOOL ')' 
;

t_outlist : T_ID '=' T_TRUE { addOutput($1, TRUE); }
| T_ID '=' T_FALSE { addOutput($1, FALSE); }
| T_ID '=' T_TRUE ',' t_outlist { addOutput($1, TRUE); }
| T_ID '=' T_FALSE ',' t_outlist { addOutput($1, FALSE); } 
;

t_par : T_PAR t_raff T_ENDPAR 
;

t_raff : T_RAFF T_ID { addPar($2); }
       | T_RAFF T_ID t_raff { addPar($2); } 
;

%%

void addTran(char *f, char *t, char *e)
{ 

  state *from;
  state *to;

  for (int i = 0; i < cura->sttab->len; i++)
    {
      state* stmp = (state *)g_ptr_array_index(cura->sttab, i);
      if (!strcmp(f, stmp->name))
	{
	  from = stmp;
	}

      if (!strcmp(t, stmp->name))
	{
	  to = stmp;
	}
    }

  if (from && to)
    {
      tran *trtmp = tran_new(from, to, e);
      automaton_add_tran(cura, trtmp);
    }
  else if (!from)
    {
      fprintf(stderr, "no such state, %s\n", f);
      abort();
    }
  else if (!to)
    {
      fprintf(stderr, "no such state, %s\n", t);
      abort();
    }
    
}


static void addOutput(char *f, gboolean def)
{
  //  output_add(f, def);
  output_add(f);
}

static GPtrArray *findOutput(char*outname, char *exp)
{

  GPtrArray * tmp = g_ptr_array_new();

  //  subout *subtmp = subout_new(st, exp);
  output *otmp = output_find(outname);
  if (otmp == NULL)
    {
      output_add(outname);
      otmp = output_find(outname);
    }

  subouttmp *subtmp = (subouttmp *)malloc(sizeof(subouttmp));
  subtmp->expr = g_strdup(exp);

  if (otmp != NULL)  /* output already defined */
    {
      subtmp->outname = otmp;
      g_ptr_array_add(tmp, (gpointer)subtmp);
    }
  else  /* else: output not defined yet */
    {
      output_add(outname);
      output *otmp2 = output_find(outname);
      subtmp->outname = otmp;
      g_ptr_array_add(tmp, (gpointer)subtmp);
   }

  return tmp;

}

static void addOutputFinal(state *st, automaton *at, GPtrArray *arr)
{
  if (arr == NULL)
    {
      
    }

  subouttmp *tmp;
  for (int i = 0; i < arr->len; i++)  // or use a g_ptr_array_foreach
    {
      tmp = (subouttmp *)g_ptr_array_index(arr, i);
      if (tmp != NULL)
	{
	  addOutput2(st, at, tmp->outname->name, tmp->expr);	
	}
      //      g_ptr_array_remove_index(exprstmp, i);
    }
  //g_ptr_array_remove_range(exprstmp, 0, exprstmp->len-1);
  g_ptr_array_free(arr, FALSE);
  //exprstmp = NULL;
}


static void addOutput2(state *st, automaton *a, char *outname, char *exp)
{
  if (!st)
    {
      fprintf(stderr, "no state!");
    }

  subout *subtmp = subout_new(st, a, exp);

  output *otmp = output_find(outname);
  if (otmp != NULL)  /* output already defined */
    {
      g_ptr_array_add(otmp->exprs, (gpointer)subtmp);
    }
  else  /* else: output not defined yet */
    {
      output_add(outname);
      output *otmp2 = output_find(outname);
      g_ptr_array_add(otmp2->exprs, (gpointer)subtmp);
    }
}





static void addPar(char *a)
{
  partab_find_and_add2(a);
}


/* SHOULD VERIFY ONLY ONE STATE FOR EACH AUTOMATON IS INIT */

int yyerror(char *s)
 {
   fprintf(stderr, "error: %s\n", s);
   return 1;
 }
