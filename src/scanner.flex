%option noyywrap yylineno
%x COMMENT

%{

#include <glib.h>
#include "parser.tab.h"

#define _POSIX_SOURCE 1
#include <stdio.h>


//extern YYSTYPE yylval;
char *p;
%}
%%

TARGOS { return T_TARGOS; }
ENDTARGOS { return T_END_TARGOS; }
AUTOMATON { return T_AUTOMATON; }
STATES { return T_STATES; }
init  { return T_INIT; }
TRANS { return T_TRANS; }
FROM { return T_FROM; }
TO { return T_TO; }
WITH { return T_WITH; }
PAR { return T_PAR; }
RAFF { return T_RAFF; }
ENDPAR { return T_ENDPAR; }
PROCESS { return T_PROCESS; }
system { return T_SYSTEM; }
"=" { return('=');}
";" {return(';');}
":" {return(':'); }
"," { return(','); }
"("  { return('('); }
")"  { return(')'); }
"[" { return('['); }
"]"  { return(']'); }
"*" { return('*'); }
true { return T_TRUE; }
false { return T_FALSE; }
and { return T_AND; }
or { return T_OR; }
not { return T_NOT; }
in { return T_IN; }
out { return T_OUT; }
bool { return T_BOOL; }
pre { return T_PRE; }
"%".*\n

([_a-zA-Z])([_a-zA-Z0-9])* {p=(char *)calloc(strlen(yytext)+1,sizeof(char));
                       strcpy(p,yytext);
                       yylval.text=p;
 return T_ID; }

[ \t\n]

%%

 /*{ p=(char *)calloc(strlen(yytext)+1,sizeof(char)); strcpy(p, yytext); yylval.text=p; return T_AND; }*/


