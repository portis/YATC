#include <string.h>
#include <getopt.h>
#include "types.h"
#include "z3z.h"
#include "ecitf.h"
#include "validate.h"
#include "YatcConfig.h"


GPtrArray *autotab;  // automaton table;
GPtrArray *partab;  // automaton table for PAR;
GPtrArray *outtab;  // output table;
GPtrArray *intab;  // input table;


extern void yyparse();
extern int yydebug;
extern FILE* yyin;

static int verbose_flag;
static int outfile_flag = 0;
static int z3z_flag = 0;
static int ec_flag = 0;

void reorder_system();

void print_usage()
{
  printf("Yatc usage:\n");
  printf("    -ecpreuve: output .ec and .ec.itf files\n");
  printf("    -z3z: output .z3z file\n");
  printf("    --verbose: print internal informations\n");
  printf("    -o: output into the specific file\n");
}

/* int main2(int argc, char *argv[]) */
/* { */

/*   gboolean z3zout = 0; */
/*   gboolean ecout = 0; */
/*   int c; */
/*   char *outfilename; */
/*   SysInit(); */
/*   yydebug=1; */

/*   while (1) */
/*     { */
/*       static struct option long_options[] =  */
/* 	{ */
/* 	  {"verbose", no_argument, &verbose_flag, 1}, */
/* 	  {"breif", no_argument, &verbose_flag, 0}, */
/* 	  {"z3z", no_argument, 0, 'z'}, */
/* 	  {"ecpreuve", no_argument, 0, 'e'}, */
/* 	  {"outfile", required_argument, 0, 'o'}, */
/* 	  {0, 0, 0, 0} */
/* 	}; */
      
/*       int option_index = 0; */

/*       c = getopt_long(argc, argv, "zeo:", */
/* 		      long_options, &option_index); */

/*       if (c == -1) */
/* 	{ */
/* 	  break; */
/* 	} */

/*       switch (c) */
/* 	{ */
/* 	case 0: */
/* 	  break; */
/* 	case 'z': */
/* 	  puts("z3z output\n"); */
/* 	  z3z_flag = 1; */
/* 	  break; */
/* 	case 'e': */
/* 	  puts("ec output \n"); */
/* 	  ec_flag = 1; */
/* 	  break; */
/* 	case 'o': */
/* 	  outfile_flag = 1; */
/* 	  outfilename = g_strdup(optarg); */
/* 	  printf("file %s\n", optarg); */
/* 	  break; */
/* 	case '?': */
/* 	  print_usage(); */
/* 	  break; */
/* 	default: */
/* 	  abort(); */
/* 	} */
/*     } */

/*   if (!(yyin = fopen(argv[1], "r"))) */
/*     { */
/*       if (!(yyin = fopen("M1p.targos", "r"))) */
/* 	{ */
/* 	  perror("M1p.targos not found!"); */
/* 	  abort(); */
/* 	} */
/*     } */

/*   yyparse(); */

/*   reorder_system(); */

/*   if ((z3z_flag == 1) && (ec_flag == 1)) */
/*     { */
/*       perror("cannot output z3z and ec files at the same time\n"); */
/*       abort(); */
/*     } */

/*   if (z3z_flag == 1) */
/*     { */
/*       FILE* z3zfile; */
/*       if (outfile_flag == 1) */
/* 	{ */
/* 	  if (!(z3zfile=fopen(outfilename, "w"))) */
/* 	    { */
/* 	      perror("open output file error\n"); */
/* 	      abort(); */
/* 	    } */
/* 	} */
/*       else */
/* 	z3zfile = stdout; */

/*       z3zFileOutput(z3zfile); */
/*     } */

/*   if (ec_flag == 1) */
/*     { */
/*       FILE* ecfile; */
/*       FILE* itffile; */
/*       char *itffilename; */

/*       if (outfile_flag == 1) */
/* 	{ */
/* 	  if (!(ecfile=fopen(outfilename, "w"))) */
/* 	    { */
/* 	      perror("open output file error\n"); */
/* 	      abort(); */
/* 	    } */

/* 	  itffilename = g_strconcat(outfilename, ".itf", NULL); */

/* 	  if (!(itffile=fopen(itffilename, "w"))) */
/* 	    { */
/* 	      perror("open output file error"); */
/* 	      abort(); */
/* 	    } */
/* 	  ecitfInputs(itffile); */
/* 	  ecitfOutputs(itffile); */
/* 	} */
/*       else */
/* 	ecfile = stdout; */
/*       ecNode(ecfile); */
      
/*     } */
/*   return 0; */
/* } */

int main(int argc, char *argv[])
{

  gboolean z3zout = 0;
  gboolean ecout = 0;
  int c;
  char *infilename;
  char *outfilename;

  SysInit();
  //yydebug=1;

  char *ops;

  if (argc < 2)
    {
      perror("Please give an input file name");
    }

  infilename = g_strdup(argv[1]);
  if (infilename == NULL)
    {
      perror("Please give an input file name");
    }

  int i = 2;

  while ((ops=argv[i])!=NULL)
    {

      if (!strcmp(ops, "-z3z"))
	{
	  z3z_flag = 1;
	}
      else if (!strcmp(ops, "-ecpreuve"))
	{
	  ec_flag = 1;
	}
      else if (!strcmp(ops, "-o"))
	{
	  outfile_flag = 1;
	  outfilename = g_strdup(argv[i+1]);
	}
      else if (!strcmp(ops, "?"))
	{
	  print_usage();	  
	}

	i++;
    }

  if (!(yyin = fopen(infilename, "r")))
    {
      fprintf(stderr, "Cannot open input file %s!", infilename);
      exit(EXIT_FAILURE);
    }

  yyparse();

  g_ptr_array_foreach(partab, (GFunc)check_init_state, NULL);

  reorder_system();

  if ((z3z_flag == 1) && (ec_flag == 1))
    {
      perror("cannot output z3z and ec files at the same time\n");
      exit(EXIT_FAILURE);
    }

  if (z3z_flag == 1)
    {
      FILE* z3zfile;
      if (outfile_flag == 1)
	{
	  if (!(z3zfile=fopen(outfilename, "w")))
	    {
	      perror("open output file error\n");
	      exit(EXIT_FAILURE);
	    }
	}
      else
	z3zfile = stdout;

      z3zFileOutput(z3zfile);
    }

  if (ec_flag == 1)
    {
      FILE* ecfile;
      FILE* itffile;
      char *itffilename;

      if (outfile_flag == 1)
	{
	  if (!(ecfile=fopen(outfilename, "w")))
	    {
	      perror("open output file error\n");
	      exit(EXIT_FAILURE);
	    }

	  itffilename = g_strconcat(outfilename, ".itf", NULL);

	  if (!(itffile=fopen(itffilename, "w")))
	    {
	      perror("open output file error");
	      exit(EXIT_FAILURE);
	    }
	  ecitfInputs(itffile);
	  ecitfOutputs(itffile);
	}
      else
	ecfile = stdout;
      ecNode(ecfile);
      
    }

  fprintf(stdout, "%s Version %d.%d\n",
	  argv[0],
	  YATC_VERSION_MAJOR,
	  YATC_VERSION_MINOR);

  return 0;
}


void reorder_system()
{
  autotab_reorder();
  intab_reorder();
  outtab_reorder();
  outtab_subout_reorder();
  partab_reorder();
  partab_add_postfix();
  outtab_update_subexp();

}

void print_system()
{
  autotab_print();
  outtab_print(); 
  intab_print(); 
  partab_print();

}
