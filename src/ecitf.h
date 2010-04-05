#ifndef _ECITF_H_
#define _ECITF_H_

#include "types.h"
#include <string.h>

extern GPtrArray *intab;
extern GPtrArray *outtab;
extern GPtrArray *partab;

void ecNode(FILE* f);
void ecitfInputs(FILE* f);
void ecitfOutputs(FILE* f);

#endif /* _ECITF_H_ */
