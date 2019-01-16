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
