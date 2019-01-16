#ifndef SPL_STACK_H
#define SPL_STACK_H

typedef struct _node Node;

typedef struct _stack Stack;

/**
 * Used to create a stack structure
 */
Stack* stack_create();

/**
 * Used to free all memory the supplied stack allocated
 * (hint: struct structure, including the struct itself, but not the data!)
 */
void stack_delete(Stack *stack);

/**
 * Adds a new node with the supplied data to the top of the stack
 */
void stack_push(Stack *stack, void *data);

/**
 * Returns the number of items currently on the stack
 */
int stack_get_count(Stack *stack);

/**
 * Removes and returns the topmost item of the stack
 */
void* stack_pop(Stack *stack);

/**
 * Returns the topmost item of the stack without removing it
 */
void* stack_peek(Stack *stack);

#endif //SPL_STACK_H
