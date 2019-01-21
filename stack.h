#include "memcheck.h"

#ifndef SPL_STACK_H
#define SPL_STACK_H

typedef struct StackImplementation* Stack;

/**
 * Used to create a stack structure
 */
Stack create_stack();

/**
 * Used to free all memory the supplied stack allocated
 * (hint: struct structure, including the struct itself, but not the data!)
 */
void delete_stack(Stack stack);

/**
 * Adds a new node with the supplied data to the top of the stack
 */
void push_stack(Stack stack, void *data);

/**
 * Returns the number of items currently on the stack
 */
int get_count(Stack stack);

/**
 * Removes and returns the topmost item of the stack
 */
void* pop_stack(Stack stack);

/**
 * Returns the topmost item of the stack without removing it
 */
void* peek_stack(Stack stack);

#endif //SPL_STACK_H
