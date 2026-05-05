#ifndef STACK_LINKEDLIST
#define STACK_LINKEDLIST
#include <stdbool.h>

typedef struct node {
    int data;
    struct node *next;
}StackNode;

typedef struct {
    StackNode *top;
} StackLinkedList;

void initStack(StackLinkedList *s);
StackLinkedList createStack();

bool isEmpty(StackLinkedList s);

bool stack_push(StackLinkedList *s, int elem);
bool stack_pop(StackLinkedList *s);
int stack_peek(StackLinkedList s);

void display(StackLinkedList s);
void visualize(StackLinkedList s);

StackLinkedList getEven(StackLinkedList *s);

#endif

