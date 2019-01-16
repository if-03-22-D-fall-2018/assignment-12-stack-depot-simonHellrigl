#ifndef SPL_DEPOT_H
#define SPL_DEPOT_H

#include "stack.h"

#define STACK_SIZE_LIMIT 3

typedef struct _depot Depot;

struct Product {
    int serial_no;
};

/**
 * Used to create a depot
 */
Depot* depot_create();

/**
 * Used to free all memory the supplied depot allocated
 */
void depot_delete(Depot *depot);

/**
 * Adds a product to the depot
 */
void depot_push(Depot *depot, Product *product);

/**
 * Returns the number of item stacks currently in the depot
 */
int depot_get_stack_count(Depot *depot);

/**
 * Removes and returns a product from the depot
 */
Product* depot_pop(Depot *depot);

#endif //SPL_DEPOT_H
