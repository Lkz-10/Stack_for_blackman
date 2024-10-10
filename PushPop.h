#ifndef __PUSHPOP_H__
#define __PUSHPOP_H__

#include <stdlib.h>

#include "Globals.h"
#include "OutputColours.h"
#include "DumpErr.h"
#include "CDtor.h"

void StackPush(Stk_t* stk, stk_el_t el);
void StackPop(Stk_t* stk, stk_el_t* var);

#endif
