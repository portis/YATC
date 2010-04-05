
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "parser3.y"

#include <stdio.h>
#include <glib.h>
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
 extern void output_add(gchar *name); 
 extern void output_add2(gchar *name, gboolean def);
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


/* Line 189 of yacc.c  */
#line 115 "parser3.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     T_TARGOS = 258,
     T_END_TARGOS = 259,
     T_AUTOMATON = 260,
     T_STATES = 261,
     T_INIT = 262,
     T_TRANS = 263,
     T_FROM = 264,
     T_TO = 265,
     T_WITH = 266,
     T_AND = 267,
     T_OR = 268,
     T_NOT = 269,
     T_PRE = 270,
     T_ID = 271,
     T_PROCESS = 272,
     T_SYSTEM = 273,
     T_IN = 274,
     T_OUT = 275,
     T_BOOL = 276,
     T_PAR = 277,
     T_ENDPAR = 278,
     T_RAFF = 279,
     T_TRUE = 280,
     T_FALSE = 281
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 44 "parser3.y"

  char *text;
  GPtrArray *array;
  int  ival;



/* Line 214 of yacc.c  */
#line 185 "parser3.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 197 "parser3.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   120

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  21
/* YYNRULES -- Number of rules.  */
#define YYNRULES  49
/* YYNRULES -- Number of states.  */
#define YYNSTATES  124

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   281

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      31,    32,    35,     2,    33,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    34,    30,
       2,    29,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    27,     2,    28,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     9,    11,    14,    18,    21,    24,    27,
      32,    38,    42,    47,    52,    58,    63,    69,    71,    73,
      75,    80,    84,    87,    91,    95,    98,   108,   119,   121,
     123,   125,   130,   134,   137,   141,   145,   153,   160,   162,
     165,   169,   174,   181,   185,   189,   195,   201,   205,   208
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      37,     0,    -1,     3,    38,    50,    55,     4,    -1,    39,
      -1,    38,    39,    -1,    40,    41,    47,    -1,     5,    16,
      -1,     6,    42,    -1,    43,    44,    -1,    16,     7,    27,
      28,    -1,    16,     7,    27,    45,    28,    -1,    16,    27,
      28,    -1,    16,    27,    45,    28,    -1,    16,    27,    28,
      44,    -1,    16,    27,    45,    28,    44,    -1,    16,    29,
      46,    30,    -1,    45,    16,    29,    46,    30,    -1,    16,
      -1,    25,    -1,    26,    -1,    15,    31,    16,    32,    -1,
      31,    46,    32,    -1,    14,    46,    -1,    46,    12,    46,
      -1,    46,    13,    46,    -1,     8,    48,    -1,     9,    16,
      10,    16,    11,    16,    27,    49,    28,    -1,     9,    16,
      10,    16,    11,    16,    27,    49,    28,    48,    -1,    16,
      -1,    25,    -1,    26,    -1,    15,    31,    16,    32,    -1,
      31,    49,    32,    -1,    14,    49,    -1,    49,    12,    49,
      -1,    49,    13,    49,    -1,    17,    18,    27,    51,    33,
      53,    28,    -1,    19,    31,    52,    34,    21,    32,    -1,
      16,    -1,    35,    16,    -1,    16,    33,    52,    -1,    35,
      16,    33,    52,    -1,    20,    31,    54,    34,    21,    32,
      -1,    16,    29,    25,    -1,    16,    29,    26,    -1,    16,
      29,    25,    33,    54,    -1,    16,    29,    26,    33,    54,
      -1,    22,    56,    23,    -1,    24,    16,    -1,    24,    16,
      56,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    68,    68,    70,    71,    74,    77,    80,    83,    86,
      87,    91,    92,    93,    94,    97,    98,   101,   102,   105,
     109,   115,   121,   127,   134,   143,   147,   148,   151,   152,
     153,   154,   155,   156,   157,   158,   161,   164,   167,   168,
     169,   170,   173,   176,   177,   178,   179,   182,   185,   186
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_TARGOS", "T_END_TARGOS",
  "T_AUTOMATON", "T_STATES", "T_INIT", "T_TRANS", "T_FROM", "T_TO",
  "T_WITH", "T_AND", "T_OR", "T_NOT", "T_PRE", "T_ID", "T_PROCESS",
  "T_SYSTEM", "T_IN", "T_OUT", "T_BOOL", "T_PAR", "T_ENDPAR", "T_RAFF",
  "T_TRUE", "T_FALSE", "'['", "']'", "'='", "';'", "'('", "')'", "','",
  "':'", "'*'", "$accept", "t_program", "t_automaton_list", "t_automaton",
  "t_autohead", "t_states", "t_state_list", "t_state_init",
  "t_state_normal_list", "t_ooo", "t_out_expr", "t_trans", "t_tran_list",
  "t_tran_expr", "t_proc", "t_in", "t_inlist", "t_out", "t_outlist",
  "t_par", "t_raff", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,    91,    93,    61,
      59,    40,    41,    44,    58,    42
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    36,    37,    38,    38,    39,    40,    41,    42,    43,
      43,    44,    44,    44,    44,    45,    45,    46,    46,    46,
      46,    46,    46,    46,    46,    47,    48,    48,    49,    49,
      49,    49,    49,    49,    49,    49,    50,    51,    52,    52,
      52,    52,    53,    54,    54,    54,    54,    55,    56,    56
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     1,     2,     3,     2,     2,     2,     4,
       5,     3,     4,     4,     5,     4,     5,     1,     1,     1,
       4,     3,     2,     3,     3,     2,     9,    10,     1,     1,
       1,     4,     3,     2,     3,     3,     7,     6,     1,     2,
       3,     4,     6,     3,     3,     5,     5,     3,     2,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     3,     0,     1,     6,     0,
       4,     0,     0,     0,     0,     0,     0,     0,     7,     0,
       0,     5,     0,     0,     0,     2,     0,     0,     8,     0,
      25,     0,     0,    48,    47,     0,     0,     0,     0,     0,
      49,     0,     9,     0,    11,     0,     0,    38,     0,     0,
       0,     0,     0,     0,    10,    13,    12,     0,     0,    39,
       0,     0,    36,     0,     0,    17,    18,    19,     0,     0,
       0,    14,     0,    40,     0,     0,     0,     0,    22,     0,
       0,     0,     0,    15,     0,     0,    41,    37,     0,     0,
       0,    21,    23,    24,    16,     0,    43,    44,     0,    20,
       0,     0,    28,    29,    30,     0,     0,     0,     0,    42,
      33,     0,     0,     0,     0,    26,    45,    46,     0,    32,
      34,    35,    27,    31
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     4,     5,     6,    13,    18,    19,    28,    43,
      69,    21,    30,   106,    11,    32,    49,    51,    77,    16,
      24
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -59
static const yytype_int8 yypact[] =
{
       5,    -1,    11,    16,    25,   -59,    15,   -59,   -59,    30,
     -59,    -5,    38,    51,    -8,    42,    63,    61,   -59,    53,
      62,   -59,    54,    56,    47,   -59,    48,    49,   -59,    58,
     -59,    46,    45,    42,   -59,    21,    27,    69,    -9,    60,
     -59,    52,   -59,    34,    53,    37,    66,    50,    68,    55,
      57,    59,    13,    64,   -59,   -59,    53,    74,    -9,    65,
      70,    76,   -59,    13,    71,   -59,   -59,   -59,    13,     1,
      13,   -59,    78,   -59,    -9,    67,    72,    73,   -59,    79,
     -12,    13,    13,   -59,     3,    77,   -59,   -59,    32,    75,
      80,   -59,   -59,   -59,   -59,    20,    81,    82,    84,   -59,
      20,    86,   -59,   -59,   -59,    20,    28,    76,    76,   -59,
     -59,    87,   -10,    20,    20,    62,   -59,   -59,    88,   -59,
     -59,   -59,   -59,   -59
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -59,   -59,   -59,    93,   -59,   -59,   -59,   -59,   -38,    83,
     -58,   -59,   -29,   -53,   -59,   -59,   -49,   -59,   -44,   -59,
      85
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      81,    82,   113,   114,     3,    78,    55,    47,     1,    73,
      80,     7,    84,    81,    82,    81,    82,    15,    71,    22,
      91,    12,   119,    92,    93,    86,    48,    63,    64,    65,
       3,    83,     8,    94,   100,   101,   102,    41,    66,    67,
     113,   114,     9,    41,    68,   103,   104,   110,    14,    42,
      53,   105,   112,    53,    17,    44,   115,    96,    97,    20,
     120,   121,    54,   116,   117,    56,    23,    25,    26,    27,
      34,    29,    33,    31,    37,    35,    36,    38,    39,    46,
      50,    52,    57,    58,    59,    72,   122,    62,    61,    60,
       0,    75,    76,    70,    85,    90,    98,    10,    74,    87,
       0,    88,    79,   118,    95,     0,     0,    89,     0,     0,
       0,     0,    99,     0,   107,   108,   109,   111,    40,    45,
     123
};

static const yytype_int8 yycheck[] =
{
      12,    13,    12,    13,     5,    63,    44,    16,     3,    58,
      68,     0,    70,    12,    13,    12,    13,    22,    56,    27,
      32,     6,    32,    81,    82,    74,    35,    14,    15,    16,
       5,    30,    16,    30,    14,    15,    16,    16,    25,    26,
      12,    13,    17,    16,    31,    25,    26,   100,    18,    28,
      16,    31,   105,    16,    16,    28,    28,    25,    26,     8,
     113,   114,    28,   107,   108,    28,    24,     4,     7,    16,
      23,     9,    16,    19,    16,    27,    27,    31,    33,    10,
      20,    29,    16,    33,    16,    11,   115,    28,    31,    34,
      -1,    21,    16,    29,    16,    16,    21,     4,    33,    32,
      -1,    29,    31,    16,    27,    -1,    -1,    34,    -1,    -1,
      -1,    -1,    32,    -1,    33,    33,    32,    31,    33,    36,
      32
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    37,     5,    38,    39,    40,     0,    16,    17,
      39,    50,     6,    41,    18,    22,    55,    16,    42,    43,
       8,    47,    27,    24,    56,     4,     7,    16,    44,     9,
      48,    19,    51,    16,    23,    27,    27,    16,    31,    33,
      56,    16,    28,    45,    28,    45,    10,    16,    35,    52,
      20,    53,    29,    16,    28,    44,    28,    16,    33,    16,
      34,    31,    28,    14,    15,    16,    25,    26,    31,    46,
      29,    44,    11,    52,    33,    21,    16,    54,    46,    31,
      46,    12,    13,    30,    46,    16,    52,    32,    29,    34,
      16,    32,    46,    46,    30,    27,    25,    26,    21,    32,
      14,    15,    16,    25,    26,    31,    49,    33,    33,    32,
      49,    31,    49,    12,    13,    28,    54,    54,    16,    32,
      49,    49,    48,    32
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 6:

/* Line 1455 of yacc.c  */
#line 77 "parser3.y"
    { cura = automaton_new((yyvsp[(2) - (2)].text)); autotab_add(cura); ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 86 "parser3.y"
    { curs = state_new((yyvsp[(1) - (4)].text), TRUE); automaton_add_state(cura, curs); ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 87 "parser3.y"
    { curs = state_new((yyvsp[(1) - (5)].text), TRUE); automaton_add_state(cura, curs); addOutputFinal(curs, cura, (yyvsp[(4) - (5)].array)); ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 91 "parser3.y"
    { curs = state_new((yyvsp[(1) - (3)].text), FALSE); automaton_add_state(cura, curs); ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 92 "parser3.y"
    { curs = state_new((yyvsp[(1) - (4)].text), FALSE); automaton_add_state(cura, curs); addOutputFinal(curs, cura, (yyvsp[(3) - (4)].array)); ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 93 "parser3.y"
    { curs = state_new((yyvsp[(1) - (4)].text), FALSE); automaton_add_state(cura, curs); ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 94 "parser3.y"
    { curs = state_new((yyvsp[(1) - (5)].text), FALSE); automaton_add_state(cura, curs); addOutputFinal(curs, cura, (yyvsp[(3) - (5)].array)); ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 97 "parser3.y"
    { (yyval.array) = findOutput((yyvsp[(1) - (4)].text), (yyvsp[(3) - (4)].text)); ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 98 "parser3.y"
    { (yyval.array) = findOutput((yyvsp[(2) - (5)].text), (yyvsp[(4) - (5)].text)); ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 103 "parser3.y"
    { gchar *ct = "1";
  (yyval.text) = ct;
 ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 106 "parser3.y"
    { gchar *ct = g_strdup("-1");
  (yyval.text) = ct;
 ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 110 "parser3.y"
    { char *ct = g_strdup("pre(");
  ct = strcat(ct, (yyvsp[(3) - (4)].text));
  ct = strcat(ct, ")");
  (yyval.text) = ct;
 ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 116 "parser3.y"
    { char *ct = g_strdup("(");
  ct = strcat(ct, (yyvsp[(2) - (3)].text));
  ct = strcat(ct, ")");
  (yyval.text) = ct;
 ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 122 "parser3.y"
    { char *ct = g_strdup("not (");
  ct = strcat(ct, (yyvsp[(2) - (2)].text));
  ct = strcat(ct, ")");
  (yyval.text) = ct;
 ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 128 "parser3.y"
    {
	     char *ct = g_strdup((yyvsp[(1) - (3)].text));
  ct = strcat(ct, " and ");
  ct = strcat(ct, (yyvsp[(3) - (3)].text));
  (yyval.text) = ct;
 ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 135 "parser3.y"
    {
	     char *ct = g_strdup((yyvsp[(1) - (3)].text));
	     ct = strcat(ct, " or ");
	     ct = strcat(ct, (yyvsp[(3) - (3)].text));
	     (yyval.text) = ct;
	   ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 147 "parser3.y"
    { addTran((yyvsp[(2) - (9)].text), (yyvsp[(4) - (9)].text), (yyvsp[(8) - (9)].text)); ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 148 "parser3.y"
    { addTran((yyvsp[(2) - (10)].text), (yyvsp[(4) - (10)].text), (yyvsp[(8) - (10)].text)); ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 151 "parser3.y"
    { { gchar *ct = g_strdup((yyvsp[(1) - (1)].text)); (yyval.text) = ct; } ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 152 "parser3.y"
    { (yyval.text) = "1"; ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 153 "parser3.y"
    { (yyval.text) = "-1"; ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 154 "parser3.y"
    { gchar *ct = g_strconcat("pre(", (yyvsp[(2) - (4)].text), ")", NULL); free((yyvsp[(2) - (4)].text)); (yyval.text) = ct;  ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 155 "parser3.y"
    { gchar *ct = g_strconcat("(", (yyvsp[(2) - (3)].text), ")", NULL); free((yyvsp[(2) - (3)].text)); (yyval.text) = ct; ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 156 "parser3.y"
    { gchar *ct = g_strconcat("not (", (yyvsp[(2) - (2)].text), ")", NULL); free((yyvsp[(2) - (2)].text)); (yyval.text) = ct; ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 157 "parser3.y"
    { gchar *ct = g_strconcat((yyvsp[(1) - (3)].text), " and ", (yyvsp[(3) - (3)].text), NULL); free((yyvsp[(1) - (3)].text)); free((yyvsp[(3) - (3)].text)); (yyval.text) = ct; ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 158 "parser3.y"
    { gchar *ct = g_strconcat((yyvsp[(1) - (3)].text), " or ", (yyvsp[(3) - (3)].text), NULL); free((yyvsp[(1) - (3)].text)); free((yyvsp[(3) - (3)].text));  (yyval.text) = ct; ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 167 "parser3.y"
    { input_add((yyvsp[(1) - (1)].text), FALSE); ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 168 "parser3.y"
    { input_add((yyvsp[(2) - (2)].text), TRUE); ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 169 "parser3.y"
    { input_add((yyvsp[(1) - (3)].text), FALSE); ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 170 "parser3.y"
    { input_add((yyvsp[(2) - (4)].text), TRUE); ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 176 "parser3.y"
    { addOutput((yyvsp[(1) - (3)].text), TRUE); ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 177 "parser3.y"
    { addOutput((yyvsp[(1) - (3)].text), FALSE); ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 178 "parser3.y"
    { addOutput((yyvsp[(1) - (5)].text), TRUE); ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 179 "parser3.y"
    { addOutput((yyvsp[(1) - (5)].text), FALSE); ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 185 "parser3.y"
    { addPar((yyvsp[(2) - (2)].text)); ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 186 "parser3.y"
    { addPar((yyvsp[(2) - (3)].text)); ;}
    break;



/* Line 1455 of yacc.c  */
#line 1767 "parser3.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 189 "parser3.y"


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
  output_add2(f, def);
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

