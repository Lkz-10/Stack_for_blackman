#ifndef __DUMPERR_H__
#define __DUMPERR_H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "Globals.h"
#include "OutputColours.h"
#include "CDtor.h"

void          StackDump(Stk_t* stk, const char* file_name, const int line, const char* func_name);
int           StackError(Stk_t* stk);
int           HashCheck(Stk_t* stk);
long long int CalculateHash (const char* buffer, size_t size);
void          PrintError(int error_code);

#endif
