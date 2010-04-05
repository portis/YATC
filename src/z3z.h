#ifndef _Z3Z_H_
#define _Z3Z_H_

#include <glib.h>
#include "types.h"

extern GPtrArray *intab;
extern GPtrArray *outtab;
extern GPtrArray *partab;

void z3zDeclare(FILE* file);
void z3zOutput(FILE* file);
void z3zConditions(FILE* file);
void z3zEtats(FILE* file);
void z3zInit(FILE* file);
void z3zEvol(FILE* file);
void z3zCons(FILE* file);
void z3zCont(FILE* file);
void z3zLibre(FILE* file);
void z3zFileOutput(FILE* file);

#endif /* _Z3Z_H_ */
