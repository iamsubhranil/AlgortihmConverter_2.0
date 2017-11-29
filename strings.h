#pragma once

#include <stdint.h>

uint64_t str_insert(const char *value);
const char* str_get(uint64_t key);

void str_ref_incr(uint64_t key);
void str_ref_decr(uint64_t key);