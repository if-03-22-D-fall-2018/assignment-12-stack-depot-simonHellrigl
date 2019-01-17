# Stack Depot
In a production line workers are creating intermediate products.
These are then deposited in a storage area from where other workers retrieve them once they are ready.

The intermediate products are placed into boxes and stacked in the storage area.
Safety rules allow for a maximum of three boxes to be placed on top of each other.
If more products need to be stored the workers start a new stack in the storage area.

Those workers who use the intermediate products to continue goods production always take the topmost box from the most recently created stack (no matter how many stacks there are).

## Implement a Stack
You might have already guessed it: your task is to implement a stack.
A stack is basically just a list which follows the **last** in, **first** out pattern (in contrast to a queue which is last in, last out).
You already know about stacks, because all our function local variables are also placed on a stack.
Surprisingly, stacks are not only used in computer science but in the real world as well! :)

## Implement the storage area logic
As mentioned before, we can only put at most three boxes on top of each other before starting a new stack.
The stack you implemented is quite stupid and would accept any number of items.

So we need logic for the storage area which enforces that each stack contains only three items at most.
Also the order in which products are removed from the storage area has to be controlled: always the topmost of the most recent stack first.

We are lucky: thanks to this rule the storage area is nothing else but a big stack of stacks! 
Thus, we can reuse our previous implementation with a bit of extra logic on top.

## Take care of your memory
As usual, in addition to implementing the logic required for the unit tests make sure you haven't created any memory leaks!
An easy way to ensure this and **required for passing the unit tests** is to use **`smalloc`** instead of `malloc` and **`sfree`** instead of `free`.
Those two wrappers will keep track of your allocations and tell you if you have properly cleaned everything you should have.
