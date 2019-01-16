#include <stdlib.h>
#include "depot.h"

struct _depot {
    Stack *stack_of_stacks;
};

Depot* depot_create() {
    Depot *depot = (Depot*) malloc(sizeof(Depot));
	depot->stack_of_stacks = stack_create();
    return depot;
}

void depot_delete(Depot *depot) {
	while(stack_get_count(depot->stack_of_stacks) != 0){
		stack_delete((Stack*) stack_pop(depot->stack_of_stacks));
	}
	free(depot->stack_of_stacks);
	free(depot);
}

void _add_to_new_stack(Depot *depot, Product *product) {
	Stack *new_stack = stack_create();
	stack_push(new_stack, product);
	stack_push(depot->stack_of_stacks, new_stack);
}

void depot_push(Depot *depot, Product *product) {
    if (stack_get_count(depot->stack_of_stacks) == 0){
		_add_to_new_stack(depot, product);
		return;  
    }
	Stack *curr_stack = (Stack*) stack_peek(depot->stack_of_stacks);
	if (stack_get_count(curr_stack) == STACK_SIZE_LIMIT){
		_add_to_new_stack(depot, product);
		return;
	}
	stack_push(curr_stack, product);
}

int depot_get_stack_count(Depot *depot) {
    return stack_get_count(depot->stack_of_stacks);
}

Product* depot_pop(Depot *depot) {
	if (stack_get_count(depot->stack_of_stacks) == 0){
		return 0;  
    }
	Stack *curr_stack = (Stack*) stack_peek(depot->stack_of_stacks);
	if (stack_get_count(curr_stack) == 1) {
		curr_stack = (Stack*) stack_pop(depot->stack_of_stacks);
		Product *prod = (Product*) stack_pop(curr_stack);
		stack_delete(curr_stack);
		return prod;
	}
	return (Product*) stack_pop(curr_stack);
}
