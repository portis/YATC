#include "types.h"
#include <string.h>

#define GET_INPUT(intab, i) ((input *)g_ptr_array_index(intab, i))
#define GET_OUTPUT(outtab, i) ((output *)g_ptr_array_index(outtab, i))
#define GET_PAR(partab, i) ((automaton *)g_ptr_array_index(partab, i))
#define GET_STATE(sttab, i) ((state *)g_ptr_array_index(sttab, i))

extern GPtrArray *intab;
extern GPtrArray *outtab;
extern GPtrArray *partab;

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
