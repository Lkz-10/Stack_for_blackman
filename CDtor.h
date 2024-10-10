#ifndef __CDTOR_H__
#define __CDTOR_H__

#include <stdlib.h>
#include <assert.h>
#include "Globals.h"
#include "DumpErr.h"

void StackCtor(Stk_t* stk);
int FillPoison (Stk_t* stk);
void StackDtor(Stk_t* stk);

#endif
