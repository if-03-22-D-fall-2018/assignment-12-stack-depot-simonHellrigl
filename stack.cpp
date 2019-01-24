#include "stack.h"

struct Node {
    struct Node* next;
    void* data;
};

struct StackImplementation {
    struct Node* head;
    int len;
};

/**
 * Used to create a stack structure.
 * @return The newly created stack.
 */
Stack create_stack()
{
    Stack stack = (Stack) smalloc(sizeof(StackImplementation));
    stack->head = 0;
    stack->len = 0;
    return stack;

}

/**
 * Used to free all memory the supplied stack allocated.
 * @param stack The stack to be deleted.
 * @note delete structure, including the struct itself, but not the data!
 */
void delete_stack(Stack stack)
{
    struct Node* current = stack->head;
    while (current != 0)
    {
        Node* temp = current;
        current = current->next;
        sfree(temp);
    }
    sfree(stack);

}

/**
 * Adds a new node with the supplied data to the top of the stack.
 * @param stack The stack onto which data has to be pushed.
 * @param data The data to be pushed.
 */
void push_stack(Stack stack, void *data)
{
    Node* toAdd = (Node*) smalloc(sizeof(Node));
    toAdd->data = data;
    toAdd->next = stack->head;
    stack->head = toAdd;
    stack->len++;
}

/**
 * @param stack The stack which number of elements to be retrieved.
 * @return The number of items currently on the stack.
 */
int get_count(Stack stack)
{
    return stack->len;

}

/**
 * Removes and returns the topmost item of the stack.
 * @param stack The stack from which to take.
 * @return The element returned from the stack.
 */
void* pop_stack(Stack stack)
{
    

}

/**
 * Returns the topmost item of the stack without removing it.
 * @param stack The stack from which to take.
 * @return The element returned from the stack.
*/
void* peek_stack(Stack stack)
{

}
