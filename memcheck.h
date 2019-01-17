#include <stdlib.h>
#include <stdbool.h>

#ifndef ___MEMCHECK_H
#define ___MEMCHECK_H

#define MAX_ALLOCS 64

void* smalloc(size_t size);
void sfree(void *address);
bool memcheck_validate();

#endif
