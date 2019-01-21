#ifndef SPL_DEPOT_H
#define SPL_DEPOT_H

#include "stack.h"

#define STACK_SIZE_LIMIT 3

typedef struct DepotImplementation* Depot;

struct Product {
    int serial_no;
};

/**
 * Used to create a depot
 * @return The newly created depot
 */
Depot create_depot();

/**
 * Used to free all memory the supplied depot allocated
 */
void delete_depot(Depot depot);

/**
 * Adds a product to the depot
 */
void push_depot(Depot depot, Product *product);

/**
 * Returns the number of item stacks currently in the depot
 */
int get_count(Depot depot);

/**
 * Removes and returns a product from the depot
 */
Product* pop_depot(Depot depot);

#endif //SPL_DEPOT_H
