#include <string.h>
#include "z3z.h"

void z3zDeclare(FILE* file)
{
  fprintf(file, "declare(");
    
  for (int i = 0; i < intab->len; i++)
    {
      fprintf(file, "\n      ");
      input *intmp = (input *)g_ptr_array_index(intab, i);
      fprintf(file, "%s", intmp->name);
      fprintf(file, "%s", ",");
    }

  for (int i = 0; i < partab->len; i++)
  {
    automaton *at = (automaton *)g_ptr_array_index(partab, i);

        for (int j = 0; j < at->sttab->len; j++)
	{
	  state *st = (state *)g_ptr_array_index(at->sttab, j);
	  fprintf(file, "\n      ");
	  fprintf(file, "%s", st->name);
	  fprintf(file, ",");
	}
    }

for (int i = 0; i < outtab->len; i++)
  {
    output *ot = (output *)g_ptr_array_index(outtab, i);
      fprintf(file, "\n      memoire_de_");
      fprintf(file, "%s", ot->name);
      fprintf(file, ",");
    }

  fseek(file, -1, SEEK_CUR);
  fprintf(file, "%s", "\n   );\n\n");
    
}


void z3zOutput(FILE* file)
{

  GString *str = g_string_new("");
  GString *stm = g_string_new("");
  for (int i = 0; i < outtab->len; i++)
    {
      output *ot = (output *)g_ptr_array_index(outtab, i);
      fprintf(file, "%s : ", ot->name);

      if (ot->exprs->len > 1)
	{
      g_string_printf(str, "(memoire_de_%s)", ot->name);

      //      for (int j = 0; j < ot->exprs->len; j++)
      for (int j = ot->exprs->len-1; j >= 0; j--)
	{
	  subout *sot=(subout *)g_ptr_array_index(ot->exprs, j);	  
  	  g_string_printf(stm, "%s", str->str);
   	  g_string_printf(str, "("); 
   	  str=g_string_append(str, "(("); 
 	  str=g_string_append(str, sot->expr); 
   	  str=g_string_append(str, ") when "); 
   	  str=g_string_append(str, sot->s->name);
   	  str=g_string_append(str, ") default ");
	  str=g_string_append(str, stm->str);
   	  str=g_string_append(str, ")");
	}

      fprintf(file, "%s", str->str+1);
      fseek(file, -1, SEEK_CUR);
	}
      else
	fprintf(file, "%s", ot->def_val ? "1" : "-1");

      //     fseek(file, -1, SEEK_CUR);
      fprintf(file, ";\n");
    }


  for (int i = 0; i < partab->len; i++)
    {
      automaton *at = (automaton *)g_ptr_array_index(partab, i);

      for (int j = 0; j < at->sttab->len; j++)
	{
	  state *st = (state *)g_ptr_array_index(at->sttab, j);
	  fprintf(file, "%s", st->name);
	  if (st->init)
	    fprintf(file, "%s", "_Choix : 1;\n");
	  else
	    fprintf(file, "%s", "_Choix : -1;\n");
	}

      for (int j = 0; j < at->trtab->len; j++)
	{
	  tran *tt = (tran *)g_ptr_array_index(at->trtab, j);
	  fprintf(file, "%s", tt->name);
	  fprintf(file, ": ((");
	  fprintf(file, "%s", tt->expr);
	  fprintf(file, "%s", ") when ");
	  fprintf(file, "%s", tt->from->name);
	  fprintf(file, "%s", ") ");
	  fprintf(file, "%s", "default (-1);\n");
	}
    }

  fprintf(file, "%s", "\n");
}

void z3zConditions(FILE* file)
{
  fprintf(file, "conditions: [");

  for (int i = 0; i < intab->len; i++)
    {
      input *it = (input *)g_ptr_array_index(intab, i);
      fprintf(file, "\n      ");
      fprintf(file, "%s", it->name);
      fprintf(file, ",");
    }

  fseek(file, -1, SEEK_CUR);
  fprintf(file, "\n    ];\n\n");

}

void z3zEtats(FILE* file)
{

  fprintf(file, "etats: [");
    
  for (int i = 0; i < partab->len; i++)
    {
      automaton *at = (automaton *)g_ptr_array_index(partab, i);

      for (int j = 0; j < at->sttab->len; j++)
	{
	  state *st = (state *)g_ptr_array_index(at->sttab, j);
	  fprintf(file, "%s", "\n      ");
	  fprintf(file, "%s", st->name);
	  fprintf(file, "%s", ",");
	}
    }

for (int i = 0; i < outtab->len; i++)
  {
    output *ot = (output *)g_ptr_array_index(outtab, i);
      fprintf(file, "%s", "\n      memoire_de_");
      fprintf(file, "%s", ot->name);
      fprintf(file, "%s", ",");
    }
  fseek(file, -1, SEEK_CUR);
  fprintf(file, "%s", "\n      ];\n\n");

}

void z3zInit(FILE* file)
{

  fprintf(file, "%s", "initialisations: [");
    
  for (int i = 0; i < partab->len; i++)
    {
      automaton *at = (automaton *)g_ptr_array_index(partab, i);
      for (int j = 0; j < at->sttab->len; j++)
	{
	  state *st = (state *)g_ptr_array_index(at->sttab, j);
	  if (st->init)
	    {
	      fprintf(file, "%s", "\n      ");
	      fprintf(file, "%s", st->name);
	      fprintf(file, "%s", " = 1,");
	    }
	  else
	    {
	      fprintf(file, "%s", "\n      ");
	      fprintf(file, "%s", st->name);
	      fprintf(file, "%s", " = -1,");
	    }
	}
    }

  for (int i = 0; i < outtab->len; i++)
    {
      output *ot = (output *)g_ptr_array_index(outtab, i);
      fprintf(file, "\n      memoire_de_%s = ", ot->name);
      fprintf(file, "%s,", ot->def_val ? "1" : "-1");
    }

  fseek(file, -1, SEEK_CUR);
  fprintf(file, "%s", "\n      ];\n\n");

}

void z3zEvol(FILE* file)
{
  fprintf(file, "%s", "evolutions: [\n\n");

  GString *str1 = g_string_sized_new(1000);
  GString *str2 = g_string_sized_new(1000);

  for (int i = 0; i < partab->len; i++)
    {
      automaton *at = (automaton *)g_ptr_array_index(partab, i);

      for (int j = 0; j < at->sttab->len; j++)
	{
	  state *st1 = (state *)g_ptr_array_index(at->sttab, j);
	  GPtrArray *lien = g_ptr_array_new();

	  g_string_printf(str1, "(%s)", st1->name);

	  for (int k = 0; k < at->sttab->len; k++)
	    {
	      state *st2 = (state *)g_ptr_array_index(at->sttab, k);

	      if (st1 == st2)
		{
		  char *strtmp = (char *)calloc(30000, 1);

		  int numor = 0;
		  
		  for (int l = 0; l < at->trtab->len; l++)
		    {
		      tran *tt = (tran *)g_ptr_array_index(at->trtab, l);

		      if((tt->to != st1) && (tt->from == st1)) // there's a tran from state2 to state1
			{
			  numor++;

			  if (numor > 1)
			    {
			      strtmp = strcat(strtmp, " or ");
			    }

			  strtmp = strcat(strtmp, tt->name);
			}
		    }

		  if (strcmp(strtmp, ""))
		    {
		      gchar *tmp = g_strconcat("(not (", strtmp, "))", NULL);
		      g_ptr_array_add(lien, (gpointer)tmp);
		    }
		  else
		    g_ptr_array_add(lien, NULL);

		  free(strtmp);
		}
	      else
		{
		  char *strtmp = (char *)calloc(30000, 1);
		  //		  strtmp[0] = '\0';

		  for (int l = 0; l < at->trtab->len; l++)
		    {
		      tran *tt = (tran *)g_ptr_array_index(at->trtab, l);

		      if((tt->to == st1) && (tt->from == st2)) // there's a tran from state2 to state1
			{
			  strtmp = strcat(strtmp, tt->name);
			}
		    }

		  if (strcmp(strtmp, ""))
		    {
		      gchar *tmp = g_strconcat("(", strtmp, ")", NULL);
		      g_ptr_array_add(lien, (gpointer)tmp);
		    }
		  else
		    g_ptr_array_add(lien, NULL);
		  
		  free(strtmp);
		}
	    }


	  char *gstr = (char *)calloc(300000, 1);
	  sprintf(gstr, "(%s)", st1->name);

	  for (int i = 0; i < lien->len; i++)
	    {
	      char *stmp = (char *)g_ptr_array_index(lien, i);
	      if (stmp != NULL)
		{
		  char *strtmp = (char *)calloc(300000, 1);
		  state *st = (state *)g_ptr_array_index(at->sttab, i);
		  sprintf(strtmp, "((%s when %s) default %s)", stmp, st->name, gstr);

		  char *kk = gstr;
		  gstr = strtmp;
		  free(kk);
		  free(stmp);
		}
	    }

	  fprintf(file, "      %s,\n", gstr);
	  g_ptr_array_free(lien, TRUE);
	  free(gstr);
	}
    }

  g_string_free(str1, TRUE);
  g_string_free(str2, TRUE);

  fseek(file, -1, SEEK_CUR);

  for (int i = 0; i < outtab->len; i++)
    {
      output *ot = (output *)g_ptr_array_index(outtab, i);
      fprintf(file, "\n      %s,", ot->name);
    }

   fseek(file, -1, SEEK_CUR);
   fprintf(file, "%s", "\n      ];\n\n"); 
}

/* void z3zEvol(FILE* file) */
/* { */
/*   fprintf(file, "%s", "evolutions: [\n"); */

/*   fprintf(file, "%s", "\n      ");  */

/*   GString *str1 = g_string_new(""); */
/*   GString *str2 = g_string_new(""); */

/*   for (int i = 0; i < partab->len; i++) */
/*     { */
/*       automaton *at = (automaton *)g_ptr_array_index(partab, i); */

/*       for (int j = 0; j < at->sttab->len; j++) */
/* 	{ */
/* 	  state *st1 = (state *)g_ptr_array_index(at->sttab, j); */

/* 	  g_string_printf(str1, "(%s)", st1->name); */

/* 	  for (int k = 0; k < at->sttab->len; k++) */
/* 	    { */
/* 	      state *st2 = (state *)g_ptr_array_index(at->sttab, k); */

/* 	      for (int l = 0; l < at->trtab->len; l++) */
/* 		{ */
/* 		  tran *tt = (tran *)g_ptr_array_index(at->trtab, l); */

/* 		  if ( st1 == st2)  */
/* 		    {  */
/* 		      int numor = 0; */

/* 		      GString *strtmp = g_string_new(""); */

/* 		      if((tt->to != st1) && (tt->from == st1)) // there's a tran from state2 to state1 */
/* 			{ */
/* 			  numor++; */

/* 			  if (numor > 1) */
/* 			    { */
/* 			      strtmp = g_string_append(strtmp, " or "); */
/* 			    } */

/* 			  strtmp = g_string_append(strtmp, tt->name); */
/* 			} */

/* 		      if (strcmp(strtmp->str, "")) */
/* 			{ */
/* 			  strtmp = g_string_prepend(strtmp, "(not (");  */
/* 			  strtmp = g_string_append(strtmp, ") when ");  */
/* 			  strtmp = g_string_append(strtmp, st2->name);  */
/* 			} */

/* 		      str1 = g_string_append(str1, strtmp->str); */
/* 		    } */

/* 		  if ( (st1 != st2) && (tt->to == st1) && (tt->from == st2)) // there's a tran from state2 to state1 */
/* 		    { */
/* 		      g_string_printf(str2, str1->str); */
/* 		      g_string_printf(str1, "(");  */
/* 		      str1=g_string_append(str1, "((");  */
/* 		      str1=g_string_append(str1, tt->name); */
/* 		      str1=g_string_append(str1, ") when ");  */
/* 		      str1=g_string_append(str1, st2->name); */
/* 		      str1=g_string_append(str1, ") default "); */
/* 		      str1=g_string_append(str1, str2->str); */
/* 		      str1=g_string_append(str1, ")"); */
/* 		    } */
/* 		} */
/* 	      //	      fprintf(file, "%s     ", str1->str); */
/* 	    } */
/* 	  //	  fseek(file, -1, SEEK_CUR); */
/* 	  fprintf(file, "%s\n     ", str1->str+1); */
/* 	  //	  fseek(file, -1, SEEK_CUR); */
/* 	  //fprintf(file, "\n      "); */
/* 	} */

/*     } */


/*   for (int i = 0; i < outtab->len; i++) */
/*     { */
/*       output *ot = (output *)g_ptr_array_index(outtab, i); */
/*       fprintf(file, "\n      %s,", ot->name); */
/*     } */

/*    fseek(file, -1, SEEK_CUR); */
/*    fprintf(file, "%s", "\n      ];\n\n");  */
/* } */

void z3zCons(FILE* file)
{
  fprintf(file, "%s", "contraintes: [\n");

  /* intput variables */
  for (int i = 0; i < intab->len; i++)
    {
      input *it = (input *)g_ptr_array_index(intab, i);
      fprintf(file, "%s", "\n      ");
      fprintf(file, "%s", it->name);
      fprintf(file, "%s", "^2=1,");
    }

  /* output variables */
  for (int i = 0; i < outtab->len; i++)
    {
      output *ot = (output *)g_ptr_array_index(outtab, i);
      fprintf(file, "%s", "\n      ");
      fprintf(file, "%s", ot->name);
      fprintf(file, "%s", "^2=1,");
    }

  /* _Choix variables and transitions */
  for (int i = 0; i < partab->len; i++)
    {
      automaton *at = (automaton *)g_ptr_array_index(partab, i);

      for (int j = 0; j < at->sttab->len; j++)
	{
	  state *st = (state *)g_ptr_array_index(at->sttab, j);
	  fprintf(file, "%s", "\n      ");
	  fprintf(file, "%s", st->name);
	  fprintf(file, "%s", "_Choix^2=1,");
	}

      for (int j = 0; j < at->trtab->len; j++)
	{
	  tran *tt = (tran *)g_ptr_array_index(at->trtab, j);
	  fprintf(file, "%s", "\n      ");
	  fprintf(file, "%s", tt->name);
	  fprintf(file, "%s", "^2=1,");
	}
    }

  /* state variables */
  for (int i = 0; i < partab->len; i++)
    {
      automaton *at = (automaton *)g_ptr_array_index(partab, i);

      for (int j = 0; j < at->sttab->len; j++)
	{
	  state *st = (state *)g_ptr_array_index(at->sttab, j);
  	  fprintf(file, "%s", "\n      ");
  	  fprintf(file, "%s", st->name);
  	  fprintf(file, "%s", "^2=1,");
  	}
    }

  /* memoire de output variables */
  for (int i = 0; i < outtab->len; i++)
    {
      output *ot = (output *)g_ptr_array_index(outtab, i);
      fprintf(file, "%s", "\n      memoire_de_");
      fprintf(file, "%s", ot->name);
      fprintf(file, "%s", "^2=1,");
    }

  fprintf(file, "\n");

  z3zConsSupplement(file);

  fseek(file, -2, SEEK_CUR);
  fprintf(file, "%s", "\n      ];\n\n");
}

void z3zConsSupplement(FILE* f)
{
  for (int i = 0; i < partab->len; i++)
    {
      automaton *at = GET_PAR(partab, i);
      if (at->sttab->len > 1)
	{
	  state *st = GET_STATE(at->sttab, 0);
	  fprintf(f, "      (%s", st->name);
	  for (int j = 1; j < at->sttab->len; j++)
	    {
	      state *st = GET_STATE(at->sttab, j);
	      fprintf(f, " or %s", st->name);

	    }
	  fprintf(f, ")=1;\n");

	  fprintf(f, "      (");

	  state *st1 = GET_STATE(at->sttab, 0);
	  state *st2 = GET_STATE(at->sttab, 1);

	  fprintf(f, "(%s and %s)", st1->name, st2->name);

	  for (int j = 0; j < at->sttab->len; j++)
	    {
	      state *st1 = GET_STATE(at->sttab, j);

	      for (int k = j+2; k < at->sttab->len; k++)
		{
		  state *st2 = GET_STATE(at->sttab, k);
		  fprintf(f, " or (%s and %s)", st1->name, st2->name);
		}
	    }

	  fprintf(f, ")=-1;\n");
	}
    }

  //  fseek(f, -2, SEEK_CUR);

}

void z3zCont(FILE* file)
{
  fprintf(file, "%s", "controlables: [\n");

  for (int i = 0; i < intab->len; i++)
  {
    input *itmp = (input *)g_ptr_array_index(intab, i);
    if(itmp->controllable) {
	fprintf(file, "%s", "\n      ");
	fprintf(file, "%s", itmp->name);
	fprintf(file, "%s", ",");
      }
    }

  fseek(file, -1, SEEK_CUR);
  fprintf(file, "%s", "\n      ];\n\n");

}

void z3zLibre(FILE* file)
{
  fprintf(file, "%s", "cond_libres: [\n\n\n      ];\n\n");
}

void z3zFileOutput(FILE* file)
{
  z3zDeclare(file);
  z3zOutput(file);
  z3zConditions(file);
  z3zEtats(file); 
  z3zInit(file);
  z3zEvol(file);
  z3zCons(file);
  z3zCont(file);
  z3zLibre(file);
}

