
#include "depot.h"

struct DepotImplementation{
    Stack stack_of_stacks;

};

static void addToStack(Depot depot, Product *product)
{
  if (get_count(depot->stack_of_stacks) >= 0)
  {
    Stack temp = create_stack();
    push_stack(temp, product);
    push_stack(depot->stack_of_stacks, temp);
  }
}



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

    while(get_count(depot->stack_of_stacks) > 0)
    {
      delete_stack((Stack) pop_stack(depot->stack_of_stacks));
    }
    sfree(depot->stack_of_stacks);
    sfree(depot);



}

/**
 * Adds a product to the depot.
 * @param depot The depot on which to be pushed.
 * @param product The product to be added.
 */
void push_depot(Depot depot, Product *product)
{
  Stack current = (Stack) peek_stack(depot->stack_of_stacks);
  if (depot->stack_of_stacks != 0)
  {
    if (get_count(depot->stack_of_stacks) == 0)
    {
      addToStack(depot, product);
      return;
    }

    else if (get_count(current) == STACK_SIZE_LIMIT)
    {
      addToStack(depot, product);
      return;
    }

    else
    {
      push_stack(current, product);
    }

  }

}

/**
 * @param depot The depot which count to be retrieved.
 * @return The number of item stacks currently in the depot.
 */
int get_count(Depot depot)
{
    return get_count(depot->stack_of_stacks);
}

/**
 * Removes and returns a product from the depot
 * @param depot The depot from which the product to be taken.
 * @return The removed product.
 */
Product* pop_depot(Depot depot)
{
  Stack current = (Stack) peek_stack(depot->stack_of_stacks);
  if (get_count(depot->stack_of_stacks) == 0)
  {
		return 0;
  }

	else if (get_count(current) == 1)
  {
		current = (Stack) pop_stack(depot->stack_of_stacks);
		Product *toPop = (Product*) pop_stack(current);
		delete_stack(current);
		return toPop;
	}

  else
  {
    return (Product*) pop_stack(current);
  }

}
