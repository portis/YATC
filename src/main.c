#include "types.h"
#include "z3z.h"
#include "ecitf.h"
#include <string.h>

GPtrArray *autotab;  // automaton table;
GPtrArray *partab;  // automaton table for PAR;
GPtrArray *outtab;  // output table;
GPtrArray *intab;  // input table;


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
  outtab_reorder();
  outtab_subout_reorder();
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
