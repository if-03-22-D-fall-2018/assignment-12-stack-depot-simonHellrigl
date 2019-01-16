#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "depot.h"

#include "shortcut.h"
#include "test_depot.h"

int main(int argc, char *argv[])
{
	ADD_TEST(create_stack);

	run_tests();
	return 0;
}
