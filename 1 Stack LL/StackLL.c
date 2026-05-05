#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "StackLL.h"

void initStack(StackLinkedList *s) {
    s->top = NULL;
}

StackLinkedList createStack() {
    StackLinkedList stack;
    stack.top = NULL;
    return stack;
}

bool isEmpty(StackLinkedList s) {
    return s.top == NULL;
}

bool stack_push(StackLinkedList *s, int elem) {
	bool retVal = false;
    StackNode *newNode = (StackNode *)malloc(sizeof(StackNode));
    if (!newNode);
    newNode->data = elem;
    newNode->next = s->top;
    s->top = newNode;
    retVal = true;
    return retVal;
}

bool stack_pop(StackLinkedList *s) {
	bool retVal = false;
    if (isEmpty(*s));
    StackNode *temp = s->top;
    s->top = s->top->next;
    free(temp);
    retVal = true;
    return retVal;
}

int stack_peek(StackLinkedList s) {
    return (isEmpty(s))? -1 : s.top->data;
}

void display(StackLinkedList s) {
    StackLinkedList tempStack = createStack();
    printf("Stack elements: ");
    while (!isEmpty(s)) {
        int elem = stack_peek(s);
        stack_pop(&s);
        printf("%d ", elem);
        stack_push(&tempStack, elem);
    }
    printf("\n");

    while (!isEmpty(tempStack)) {
        int elem = stack_peek(tempStack);
        stack_pop(&tempStack);
        stack_push(&s, elem);
    }
}

void visualize(StackLinkedList s) {
    printf("Stack visualization:\n");
    StackNode *trav;
    for (trav = s.top; trav != NULL; trav = trav->next) {
        printf("| %d |\n", trav->data);
    }
    printf(" ----- \n");
}
StackLinkedList getEven(StackLinkedList *s) {
    StackLinkedList evenStack = createStack();
    StackNode *trav;
    for (trav = s->top; trav != NULL; trav = trav->next) {
        if (trav->data % 2 == 0) {
            stack_push(&evenStack, trav->data);
        }
    }
    return evenStack;
}
