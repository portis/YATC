#include "types.h"
#include <string.h>

#define GET_INPUT(intab, i) ((input *)g_ptr_array_index(intab, i))
#define GET_OUTPUT(outtab, i) ((output *)g_ptr_array_index(outtab, i))
#define GET_PAR(partab, i) ((automaton *)g_ptr_array_index(partab, i))
#define GET_STATE(sttab, i) ((state *)g_ptr_array_index(sttab, i))
#define GET_TRAN(trtab, i) ((tran *)g_ptr_array_index(trtab, i))

extern GPtrArray *intab;
extern GPtrArray *outtab;
extern GPtrArray *partab;


void ecNode(FILE* f)
{
  fprintf(f, "%s", "node system(");

  for (int i = 0; i < intab->len; i++)
    {
      input *it = GET_INPUT(intab, i);

      fprintf(f, "%s : bool;\n", it->name);
    }

  fseek(f, -2, SEEK_CUR);

  fprintf(f, "%s", ") returns (");

  for (int i = 0; i < outtab->len; i++)
    {
      output *ot = GET_OUTPUT(outtab, i);

      fprintf(f, "%s : bool;\n", ot->name);
    }

  for (int i = 0; i < partab->len; i++)
    {
      automaton *at = GET_PAR(partab, i);

      for (int j = 0; j < at->sttab->len; j++)
	{
	  state *st = GET_STATE(at->sttab, j);
	  fprintf(f, "suiv_%s : bool;\n", st->name);
	}
    }

  for (int i = 0; i < outtab->len; i++)
    {
      output *ot = GET_OUTPUT(outtab, i);

      fprintf(f, "suiv_memoire_de_%s : bool;\n", ot->name);
    }

  fseek(f, -2, SEEK_CUR);
  fprintf(f, "%s", ");\n");

  fprintf(f, "%s", "var\n");


  for (int i = 0; i < partab->len; i++)
    {
      automaton *at = GET_PAR(partab, i);
      for (int j = 0; j < at->sttab->len; j++)
	{
	  state *st = GET_STATE(at->sttab, j);
	  fprintf(f, "   %s_Choix : bool;\n", st->name);
	}

      for (int j = 0; j < at->trtab->len; j++)
	{
	  tran *tt = GET_TRAN(at->trtab, j);
	  fprintf(f, "   %s : bool;\n", tt->name);
	}
    }

  for (int i = 0; i < partab->len; i++)
    {
      automaton *at = GET_PAR(partab, i);
      for (int j = 0; j < at->sttab->len; j++)
	{
	  state *st = GET_STATE(at->sttab, j);
	  fprintf(f, "   %s : bool;\n", st->name);
	}
      
    }

  for (int i = 0; i < outtab->len; i++)
    {
      output *ot = GET_OUTPUT(outtab, i);
      fprintf(f, "   memoire_de_%s : bool;\n", ot->name);
    }

  /* let */
  fprintf(f, "\nlet\n");

  for (int i = 0; i < partab->len; i++)
    {
      automaton *at = GET_PAR(partab, i);
      for (int j = 0; j < at->sttab->len; j++)
	{
	  state *st = GET_STATE(at->sttab, j);
	  fprintf(f, "   %s_Choix=%s;\n", st->name, st->init ? "true":"false");
	}

      for (int j = 0; j < at->trtab->len; j++)
	{
	  tran *tt = GET_TRAN(at->trtab, j);
	  fprintf(f, "   %s=if (%s) then (%s) else false;\n", tt->name, tt->from->name, tt->expr);
	}
    }

  for (int i = 0; i < partab->len; i++)
    {
      automaton *at = GET_PAR(partab, i);
      for (int j = 0; j < at->sttab->len; j++)
	{
	  state *st = GET_STATE(at->sttab, j);
	  fprintf(f, "   %s=%s->pre(suiv_%s);\n", st->name, st->init ? "true":"false", st->name);
	}
      
    }

  for (int i = 0; i < outtab->len; i++)
    {
      output *ot = (output *)g_ptr_array_index(outtab, i);
      fprintf(f, "   %s=", ot->name);

      for (int j = 0; j < ot->exprs->len; j++)
      //for (int j = ot->exprs->len-1; j >= 0; j--)
	{
	  subout *sot=(subout *)g_ptr_array_index(ot->exprs, j);	  
	  fprintf(f, "if (%s) then ", sot->s->name); 
	  if (!strcmp(sot->expr, "1"))
	    {
	      fprintf(f, "%s", "true");
	    }
	  else if (!strcmp(sot->expr, "-1"))
	    {
	      fprintf(f, "%s", "false");
	    }
	  else
	    {
	      fprintf(f, "(%s)", sot->expr);
	    }
	  fprintf(f, " else ");

	}

      fprintf(f, "memoire_de_%s", ot->name);

      fprintf(f, ";\n");
    }

  /* suiv_ */
  for (int i = 0; i < partab->len; i++)
    {
      automaton *at = GET_PAR(partab, i);
  
      for (int j = 0; j < at->sttab->len; j++)
	{
	  state *st1 = GET_STATE(at->sttab, j);
	  fprintf(f, "   suiv_%s=", st1->name);
	  GPtrArray *lien = g_ptr_array_new();
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
	      else  // st1 != st2
		{
		  char *strtmp = (char *)calloc(30000, 1);

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

	  /* construct output string */
	  //	  char *gstr = (char *)calloc(300000, 1);
	  //	  sprintf(gstr, "%s", st1->name);

	  for (int i = 0; i < lien->len; i++)
	    {
	      char *stmp = (char *)g_ptr_array_index(lien, i);
	      if (stmp != NULL)
		{
		  state *st = (state *)g_ptr_array_index(at->sttab, i);
		  fprintf(f, "if (%s) then %s else ", st->name, stmp);
		}

	      fprintf(f, "%s,\n", st1->name);
	      g_ptr_array_free(lien, TRUE);
	    }
	}
    }


  /* suiv_memoire_ */
  for (int i = 0; i < outtab->len; i++)
    {
      output *ot = GET_OUTPUT(outtab, i);

      fprintf(f, "   suiv_memoire_de_%s=%s;\n", ot->name, ot->name);
    }

  /* memoire_ */

  for (int i = 0; i < outtab->len; i++)
    {
      output *ot = GET_OUTPUT(outtab, i);

      fprintf(f, "   memoire_de_%s=%s->pre(suiv_memoire_de_%s);\n", ot->name, ot->def_val ? "true":"false", ot->name);
    }

  /* tel; */
  fprintf(f, "\ntel;\n\n");

}


void ecitfInputs(FILE* f)
{
  fprintf(f, "%s", "Inputs:\n");

  for (int i = 0; i < intab->len; i++)
    {
      input *it = GET_INPUT(intab, i);

      fprintf(f, "%s\n", it->name);
    }

  fprintf(f, "\n");
}

void ecitfOutputs(FILE* f)
{
  fprintf(f, "%s", "Outputs:\n");

  for (int i = 0; i < outtab->len; i++)
    {
      output *ot = GET_OUTPUT(outtab, i);

      fprintf(f, "%s\n", ot->name);
    }

  for (int i = 0; i < partab->len; i++)
    {
      automaton *at = GET_PAR(partab, i);

      for (int j = 0; j < at->sttab->len; j++)
	{
	  state *st = GET_STATE(at->sttab, j);
	  fprintf(f, "%s : ", st->name);
	  fprintf(f, "%s\n", st->init ? "true" : "false");
	}
    }

  for (int i = 0; i < outtab->len; i++)
    {
      output *ot = GET_OUTPUT(outtab, i);

      fprintf(f, "memoire_de_%s : ", ot->name);
      fprintf(f, "%s\n", ot->def_val ? "true" : "false");
    }


}
