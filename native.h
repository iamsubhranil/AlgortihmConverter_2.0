#ifndef NATIVE_H
#define NATIVE_H

#include "env.h"
#include "interpreter.h"

Data handle_native(uint32_t name, Environment *env);
void register_native(Environment *env);
void register_native_routines();
void unload_all();
#endif
