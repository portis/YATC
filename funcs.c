#include "types.h"
#include <string.h>

GPtrArray *autotab;  // automaton table;
GPtrArray *partab;  // automaton table for PAR;
GPtrArray *outtab;  // output table;
GPtrArray *intab;  // input table;

extern void ecNode(FILE *f);
extern void ecitfInputs(FILE *f);
extern void ecitfOutputs(FILE *f);

state *automaton_find_state(automaton *a, gchar *sname);

/* input manipulations */
input *input_find(gchar *name)
{

  for (int i = 0; i < intab->len; i++)
    {
      input * intmp = (input *)g_ptr_array_index(intab, i);
      if (!strcmp(intmp->name, name))
	{
	  return intmp;
	}
    }

  return NULL;
}


void input_add(gchar *name, gboolean cont)
{
  input *itmp = input_find(name);

  if (itmp==NULL)
    {
      itmp = (input *)calloc(sizeof(input), 1);
      itmp->name = g_strdup(name);
      itmp->controllable = cont;
    }

  g_ptr_array_add(intab, itmp);
}


void input_print(input *i)
{
  printf("Input: %s, controllable? %d\n", i->name, i->controllable);
}

void intab_reorder()
{
  for (int i = 0; i < intab->len/2; i++)
    {
      gpointer p = g_ptr_array_index(intab, i);
      g_ptr_array_index(intab, i) = g_ptr_array_index(intab, intab->len-i-1);
      g_ptr_array_index(intab, intab->len-i-1) = p;
    }
}

void intab_print()
{
  g_ptr_array_foreach(intab, (GFunc)input_print, NULL);
}

/* subout manipulations */
subout *subout_new(state *st, automaton *at, gchar *expr)
{
  subout *subtmp = (subout *)calloc(sizeof(subout), 1);
  subtmp->s = st;
  subtmp->a = at;
  subtmp->expr = g_strdup(expr);
  return subtmp;
}

void subout_print(subout *so)
{
  printf("subexp: %s at state %s\n", so->expr, so->s->name);
}

/* output manipulations */
output *output_find(gchar *name)
{
  output *outtmp;

  for (int i = 0; i < outtab->len; i++)
    {
      outtmp = (output *)g_ptr_array_index(outtab, i);
      if (!strcmp(outtmp->name, name))
	{
	  return outtmp;  // already defined
	}
    }

  return NULL;
}

void output_add(gchar *name)
{

  if (output_find(name)==NULL)
    {
      output * outtmp = (output *)calloc(sizeof(output), 1);
      outtmp->name = g_strdup(name);
      outtmp->exprs = g_ptr_array_new();
      
      g_ptr_array_add(outtab, outtmp);
    }
}

void output_add2(gchar *name, gboolean val)
{

  if (output_find(name)==NULL)
    {
      output * outtmp = (output *)calloc(sizeof(output), 1);
      outtmp->name = g_strdup(name);
      outtmp->exprs = g_ptr_array_new();
      outtmp->def_val = val;
      g_ptr_array_add(outtab, outtmp);
    }
}


void output_print(output *o)
{
  printf("Output: %s\n", o->name);
  g_ptr_array_foreach(o->exprs, (GFunc)subout_print, NULL);
}

void outtab_update_subexp()
{
  for (int i = 0; i < outtab->len; i++)
    {
      output *ot = (output *)g_ptr_array_index(outtab, i);
      for (int j = 0; j < ot->exprs->len; j++)
	{
	  subout *so = (subout *)g_ptr_array_index(ot->exprs, j);
	  for (int k = 0; k < partab->len; k++)
	    {
	      automaton *at = (automaton *)g_ptr_array_index(partab, k);
	      gchar *anm = g_strdup(at->name);
	      if (!(strcmp(strtok(anm, "_"), so->a->name)))
		{
		  so->a = at;
		  for (int l = 0; l < at->sttab->len; l++)
		    {
		      state *st = (state *)g_ptr_array_index(at->sttab, l);
		      gchar *snm = g_strdup(st->name);
		      if (!strcmp(strtok(snm, "_"), so->s->name))
			{
			  so->s = st;
			  break;
			}
		    }
		  break;
		}
	    }
	}
    }

}

void outtab_print()
{
  g_ptr_array_foreach(outtab, (GFunc)output_print, NULL);
}


/* state manipulations */
state *state_new(gchar *name, gboolean init)
{
  state *tmp = (state *)calloc(sizeof(state), 1);
  tmp->name = g_strdup(name);
  tmp->init = init;
  //  tmp->frtr = g_ptr_array_new();
  //  tmp->totr = g_ptr_array_new();

  return tmp;
}

/* state *state_dup(state *s, gchar *postfix) */
/* { */
/*   state *tmp = (state *)malloc(sizeof(state)); */
/*   gchar *newname = g_strdup(s->name); */
/*   newname = strcat(newname, postfix); */
/*   tmp->name = newname; */
/*   tmp->init = s->init; */
/*   tmp->frtr = g_ptr_array_new(); */
/*   tmp->totr = g_ptr_array_new(); */

/*   return tmp; */

/* } */

state *state_dup2(state *s)
{
  state *tmp = (state *)calloc(sizeof(state), 1);
  tmp->name = (char *)calloc(sizeof(char), strlen(s->name)+1);
  tmp->name = strcpy(tmp->name, s->name);
  //  tmp->name = g_strdup(s->name);
  //   tmp->name = strcpy(tmp->name, s->name);
  tmp->init = s->init;
  //  tmp->frtr = NULL; //g_ptr_array_new();
  //  tmp->totr = NULL; //g_ptr_array_new();

  return tmp;

}

void state_add_postfix(state *s, gchar *p)
{
  s->name = strcat(s->name, p);
}

void state_print(state* s)
{
  printf("State: %s\n", s->name);
}


/* transition manipulations */
tran *tran_new(state *from, state *to, gchar* expr)
{
  tran *tmp = (tran *)calloc(sizeof(tran), 1);
  tmp->from = from;
  tmp->to = to;
  tmp->expr = g_strdup(expr);
  gchar *n = g_strdup("from ");
  n = strcat(n, from->name);
  n = strcat(n, " to ");
  n = strcat(n, to->name);
  tmp->name = g_strdup(n);
  g_free(n);
  return tmp;
}

tran *tran_dup2(tran *t, automaton *a)
{
  tran *tmp = (tran *)calloc(sizeof(tran), 1);
  tmp->name = g_strdup(t->name);
  tmp->from = automaton_find_state(a, t->from->name);
  tmp->to = automaton_find_state(a, t->to->name);
  tmp->expr = g_strdup(t->expr);

  if (tmp->from == NULL || tmp->to == NULL)
    {
      fprintf(stderr, "state not valid!\n");
      abort();
    }

  return tmp;
}

void tran_print(tran* t)
{
  printf("Tran: %s\t %s\n", t->name, t->expr);
}

/* automaton minipulations */
automaton *automaton_new(gchar *name)
{
  automaton *atmp = (automaton *)calloc(sizeof(automaton), 1);
  atmp->name = g_strdup(name);
  atmp->sttab = g_ptr_array_new();
  atmp->trtab = g_ptr_array_new();

  return atmp;
}

void automaton_add_state(automaton *a, state *s)
{
  g_ptr_array_add(a->sttab, (gpointer) s);
}

void automaton_add_tran(automaton *a, tran *t)
{
  g_ptr_array_add(a->trtab, (gpointer) t);
}

state *automaton_find_state(automaton *a, gchar *sname)
{
  for (int i = 0; i < a->sttab->len; i++)
    {
      state *st = (state *)g_ptr_array_index(a->sttab, i);
      if (!strcmp(st->name, sname))
	{
	  return st;
	}
    }

  return NULL;
}

automaton *automaton_dup2(automaton *a)
{
  automaton *atmp = (automaton *)calloc(sizeof(automaton), 1);
  atmp->name = g_strdup(a->name);

  atmp->sttab = g_ptr_array_new();

  for (int i = 0; i < a->sttab->len; i++)
    {
      state *st = (state *)g_ptr_array_index(a->sttab, i);
      state *nst = state_dup2(st);
      g_ptr_array_add(atmp->sttab, (gpointer)nst);
    }

  atmp->trtab = g_ptr_array_new();

  for (int i = 0; i < a->trtab->len; i++)
    {
      tran *t = (tran *)g_ptr_array_index(a->trtab, i);
      tran *nt = tran_dup2(t, atmp);
      g_ptr_array_add(atmp->trtab, (gpointer)nt);
    }
  return atmp;
}

static void automaton_reorder_states(automaton *a)
{
  gpointer *sttmp;

  for (int i = 1; i < a->sttab->len/2; i++)
  {
    sttmp = g_ptr_array_index(a->sttab, i);
    g_ptr_array_index(a->sttab, i) = g_ptr_array_index(a->sttab, a->sttab->len - i);
    g_ptr_array_index(a->sttab, a->sttab->len - i) = sttmp;
  }

}

static void automaton_reorder_trans(automaton *a)
{
  gpointer *trtmp;

  for (int i = 0; i < a->trtab->len/2; i++)
  {
    trtmp = g_ptr_array_index(a->trtab, i);
    g_ptr_array_index(a->trtab, i) = g_ptr_array_index(a->trtab, a->trtab->len - i - 1);
    g_ptr_array_index(a->trtab, a->trtab->len - i -1) = trtmp;
  }
}

void tran_add_postfix(tran *t, int i)
{
  //  GString *str = g_string_new("condition_de_");
  char *str = (char *)calloc(1000, 1);

  sprintf(str, "%s", t->from->name);
  str = strcat(str, "_vers_");
  str = strcat(str, t->to->name);

  str = strcat(str, "_");

  char *str2 = (char *)calloc(50, 1);
  sprintf(str2, "%d", i);
  str = strcat(str, str2);

  free(t->name);
  t->name = g_strdup(str);
  //  printf("%s\n", t->name);
  free(str);
  free(str2);

}

static void automaton_add_postfix(automaton *a, int i)
{
  gchar *str1 = (char *)calloc(1000,1);
  str1 = strcpy(str1, "_");
  gchar *tmp = (gchar *)calloc(100,1);
  sprintf(tmp, "%d", i);
  str1 = strcat(str1, tmp);
  //gchar *str1 = (char *)malloc(1000);
  //  str1 = g_strconcat("_", tmp);

  /* add postfix to automaton */
  a->name = strcat(a->name, str1);

  /* add postfix to states */
  gchar *str2 = (char *)calloc(sizeof(char), 1000);
  //  str2 = g_strdup("_de_");
  sprintf(str2, "_de_");
  //  str2 = g_strconcat(str2, a->name);
  str2 = strcat(str2, a->name);

  //gchar *str2 = g_strconcat("_de_", a->name);

  for (int i = 0; i < a->sttab->len; i++)
    {
      state *st = (state *)g_ptr_array_index(a->sttab, i);
      state_add_postfix(st, str2); 
    }

  /* add postfix to trans */
  for (int i = 0; i < a->trtab->len; i++)
    {
      tran *t = (tran *)g_ptr_array_index(a->trtab, i);
      tran_add_postfix(t, i);
    }

  free(str1);
  free(tmp);
  free(str2);

}

void automaton_print(automaton *a)
{
  printf("Automaton: %s\n", a->name);
  
  g_ptr_array_foreach(a->sttab, (GFunc)state_print, NULL);
  g_ptr_array_foreach(a->trtab, (GFunc)tran_print, NULL);
}

/* autotab minipulations */
void autotab_add(automaton *a)
{
  g_ptr_array_add(autotab, (gpointer)a);
}

automaton *autotab_find(gchar *aname)
{
  for (int i = 0; i < autotab->len; i++)
    {
      automaton *atmp = (automaton *)g_ptr_array_index(autotab, i);
      if (!strcmp(aname, atmp->name))
	{
	  return atmp;
	}
    }

  return NULL;
}

void autotab_reorder()
{
  g_ptr_array_foreach(autotab, (GFunc)automaton_reorder_states, NULL);
  g_ptr_array_foreach(autotab, (GFunc)automaton_reorder_trans, NULL);
}
void autotab_print()
{
  g_ptr_array_foreach(autotab, (GFunc)automaton_print, NULL);
}

/* partab minipulations */
void partab_add(automaton *a)
{
  g_ptr_array_add(partab, (gpointer)a);
}


void partab_find_and_add2(gchar *aname)
{
  automaton *atmp = autotab_find(aname);
  if (atmp == NULL)
    {
      fprintf(stderr, "No automaton %s in PAR section\n", aname);
      abort();
    }
  else
    {
      partab_add(automaton_dup2(atmp));
    }
}

void partab_add_postfix()
{
  for (int i = 0; i < partab->len; i++)
    {
      automaton *a = (automaton *)g_ptr_array_index(partab, i);
      automaton_add_postfix(a, i);
    }
}

void partab_reorder()
{
for (int i = 0; i < partab->len/2; i++)
  {
    gpointer *p = g_ptr_array_index(partab, i);
    g_ptr_array_index(partab, i) = g_ptr_array_index(partab, partab->len - i -1);
    g_ptr_array_index(partab, partab->len - i -1) = p;
  }
  g_ptr_array_foreach(partab, (GFunc)automaton_reorder_states, NULL);
  g_ptr_array_foreach(partab, (GFunc)automaton_reorder_trans, NULL);
}

void partab_print()
{
  g_ptr_array_foreach(partab, (GFunc)automaton_print, NULL);
}


void SysInit()
{
  intab = g_ptr_array_new();
  outtab = g_ptr_array_new();
  autotab = g_ptr_array_new();
  partab = g_ptr_array_new();
}


void z3zFileOutput(FILE* file)
{

  z3zDeclare(file);
  z3zOutput(file);
  z3zConditions(file);
  z3zEtats(file); 
  z3zInit(file);
  z3zEvol1(file);
  z3zCons(file);
  z3zCont(file);
  z3zLibre(file);
}

extern void yyparse();
extern int yydebug;
extern FILE* yyin;

int main(int argc, char *argv[])
{

  SysInit();
  //    yydebug=1;

  if (!(yyin = fopen(argv[1], "r")))
    {
      if (!(yyin = fopen("M1p.targos", "r")))
	{
	  perror("M1p.targos not found!");
	  return(1);
	}
    }

  yyparse();

  autotab_reorder();
  //      autotab_print();
  //      outtab_print(); 
  intab_reorder();
  //      intab_print(); 

  partab_reorder();
  partab_add_postfix();

  outtab_update_subexp();

  //      partab_print();

  FILE* z3zfile;
  if (!(z3zfile = fopen(argv[2], "w")))
    {
      if (!(z3zfile=fopen("out.z3z", "w")))
	{
	  perror("open output file error\n");
	  return(1);
	}
    }

  z3zFileOutput(z3zfile);

  FILE* ecfile;
  //  if (!(itffile = fopen(argv[3], "w")))
  //    {
      if (!(ecfile=fopen("out.ec", "w")))
	{
	  perror("open output file error\n");
	  return(1);
	}
      //    }

      ecNode(ecfile);


  FILE* itffile;
  //  if (!(itffile = fopen(argv[3], "w")))
  //    {
      if (!(itffile=fopen("out.ec.itf", "w")))
	{
	  perror("open output file error\n");
	  return(1);
	}
      //    }

  ecitfInputs(itffile);
  ecitfOutputs(itffile);

  return 0;
}

