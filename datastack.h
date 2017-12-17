#pragma once

#include "allocator.h"
#include "values.h"
#include "env.h"

static Data *dataStack = NULL;
static uint32_t sp = 0, stackSize = 0;
static int32_t stackLastIncremented = 0;

#define dStackInit() {stackSize = 10; dataStack = (Data *)mallocate(sizeof(Data)*stackSize);}
#define dStackFree() {memfree(dataStack);}

#define incr() if(sp >= stackSize){\
        stackSize *= 2; \
        stackLastIncremented = 0; \
        dataStack = (Data *)reallocate(dataStack, sizeof(Data)*stackSize);}

#define dpush(x) {incr(); dataStack[sp++] = x;}
#define dpushi(x) {incr(); dataStack[sp++] = new_int(x);}
#define dpushf(x) {incr(); dataStack[sp++] = new_float(x);}
#define dpushs(x) {incr(); dataStack[sp++] = new_str(x);}
#define dpushsk(x) {incr(); dataStack[sp++] = new_strk(x);}
#define dpushl(x) {incr(); dataStack[sp++] = new_logical(x);}
#define dpushid(x) {incr(); dataStack[sp++] = new_identifer(x);}
#define dpushidk(x) {incr(); dataStack[sp++] = new_identiferk(x);}
#define dpushins(x) {incr(); dataStack[sp++] = new_ins(x);}
#define dpushn() {incr(); dataStack[sp++] = new_null();}

#define binpopv() (Data d1, d2; dpopv(d1, env); dpopv(d2, env);)

#define dpeek() dataStack[sp - 1]
#define dpop() dataStack[--sp]
#define dpopv(x, frame) {x = dataStack[--sp]; x = isidentifer(x)?env_get(tstrk(x), &(frame.env), 0):x; }
#define dpopi() tint(dataStack[--sp])
#define dpopf() tfloat(dataStack[--sp])
#define dpops() tstr(dataStack[--sp])
#define dpopsk() tstrk(dataStack[--sp])
#define dpopins() tins(dataStack[--sp])
