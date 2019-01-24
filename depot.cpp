
#include "depot.h"

struct DepotImplementation{
    Stack stack_of_stacks;

};

Depot create_depot()
{
    Depot depot = (Depot) smalloc(sizeof(DepotImplementation));
	depot->stack_of_stacks = create_stack();
    return depot;
}

/**
 * Used to free all memory the supplied depot allocated.
 * @param depot The depot to be deleted.
 */
void delete_depot(Depot depot)
{
    /*counter = 0;
    while (counter <= depot->stack_of_stacks->len)
    {
        /* code */
    }*/


}

/**
 * Adds a product to the depot.
 * @param depot The depot on which to be pushed.
 * @param product The product to be added.
 */
void push_depot(Depot depot, Product *product)
{

}

/**
 * @param depot The depot which count to be retrieved.
 * @return The number of item stacks currently in the depot.
 */
int get_count(Depot depot)
{
    return 0;

}

/**
 * Removes and returns a product from the depot
 * @param depot The depot from which the product to be taken.
 * @return The removed product.
 */
Product* pop_depot(Depot depot)
{

}
