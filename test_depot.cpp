#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "shortcut.h"
#include "test_depot.h"
#include "depot.h"

// Stack Tests
TEST(create_stack)
{
	Stack *stack = stack_create();
	ASSERT_FALSE(stack == 0, "Stack has to be created");
	stack_delete(stack);
}

TEST(add_items_to_stack)
{
	Stack *stack = stack_create();

	Product products[] = {
        {1},
        {2},
        {3}
    };
	stack_push(stack, &products[0]);
	stack_push(stack, &products[1]);
	stack_push(stack, &products[2]);

	ASSERT_EQUALS(stack_get_count(stack), 3);

	stack_delete(stack);
}

TEST(get_items_from_stack)
{
	Stack *stack = stack_create();

	Product products[] = {
        {1},
        {2},
        {3}
    };
	stack_push(stack, &products[0]);
	stack_push(stack, &products[1]);
	stack_push(stack, &products[2]);

	ASSERT_EQUALS(((Product*)stack_pop(stack))->serial_no, 3);
	ASSERT_EQUALS(((Product*)stack_pop(stack))->serial_no, 2);
	
	ASSERT_EQUALS(((Product*)stack_peek(stack))->serial_no, 1);
	ASSERT_EQUALS(stack_get_count(stack), 1);

	ASSERT_EQUALS(((Product*)stack_pop(stack))->serial_no, 1);
	ASSERT_EQUALS(stack_get_count(stack), 0);

	stack_delete(stack);
}

TEST(create_depot)
{
	Depot *depot = depot_create();
	ASSERT_FALSE(depot == 0, "Depot has to be created");
	depot_delete(depot);
}

TEST(fill_depot)
{
	Depot *depot = depot_create();
	
	Product products[] = {
        {1},
        {2},
        {3},
		{4}
    };

	ASSERT_EQUALS(depot_get_stack_count(depot), 0);

	depot_push(depot, &products[0]);
	ASSERT_EQUALS(depot_get_stack_count(depot), 1);
	depot_push(depot, &products[1]);
	ASSERT_EQUALS(depot_get_stack_count(depot), 1);
	depot_push(depot, &products[2]);
	ASSERT_EQUALS(depot_get_stack_count(depot), 1);
	depot_push(depot, &products[3]);
	ASSERT_EQUALS(depot_get_stack_count(depot), 2);

	depot_delete(depot);
}

TEST(use_depot)
{
	Depot *depot = depot_create();
	
	Product products[] = {
        {1},
        {2},
        {3},
		{4},
		{5},
		{6},
		{7}
    };

	for (int i = 0; i < 7; i++){
		depot_push(depot, &products[i]);
	}
	ASSERT_EQUALS(depot_get_stack_count(depot), 3);

	for (int j = 6; j >= 0; j--){
		Product *p = depot_pop(depot);
		ASSERT_EQUALS(p->serial_no, j+1);
		if (j == 4){
			ASSERT_EQUALS(depot_get_stack_count(depot), 2);
		}
		if (j == 2){
			ASSERT_EQUALS(depot_get_stack_count(depot), 1);
		}
	}
	ASSERT_EQUALS(depot_get_stack_count(depot), 0);

	depot_push(depot, &products[0]);
	depot_push(depot, &products[1]);
	depot_push(depot, &products[2]);
	depot_push(depot, &products[3]);
	depot_pop(depot);
	depot_push(depot, &products[4]);
	ASSERT_EQUALS(depot_get_stack_count(depot), 2);
	ASSERT_EQUALS(((Product*)depot_pop(depot))->serial_no, 5);
	ASSERT_EQUALS(depot_get_stack_count(depot), 1);

	depot_delete(depot);
}
