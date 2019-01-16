#include <stdlib.h>
#include "stack.h"


struct _node {
    struct _node *next;
    void *data;
};

struct _stack {
    struct _node *head;
    int count;
};

Stack* stack_create() {
    Stack *stack = (Stack*) malloc(sizeof(Stack));
    stack->head = 0;
    stack->count = 0;
    return stack;
}

void stack_delete(Stack *stack) {
    Node *node = (Node*) stack->head;
    while (node) {
        Node *tmp = node;
        node = node->next;
        free(tmp);
    }
    free(stack);
}

void stack_push(Stack *stack, void *data) {
    Node *new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = stack->head;
    stack->head = new_node;
    stack->count++;
}

int stack_get_count(Stack *stack) {
    return stack->count;
}

void* stack_pop(Stack *stack) {
    if (stack_get_count(stack) == 0){
        return 0;
    }
    Node *top = stack->head;
    stack->head = top->next;
    stack->count--;
    void *data = top->data;
    free(top);
    return data;
}

void* stack_peek(Stack *stack) {
    if (stack_get_count(stack) == 0){
        return 0;
    }
    return stack->head->data;
}
