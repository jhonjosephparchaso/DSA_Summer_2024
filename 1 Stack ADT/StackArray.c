#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

#include "StackArray.h"

void initStack(StackArrayList *s) {
    s->top = -1;
}

StackArrayList createStack() {
    StackArrayList stack;
    stack.top = -1;
    return stack;
}

bool isEmpty(StackArrayList s) {
    return s.top == -1;
}

bool isFull(StackArrayList s) {
    return s.top >= MAX - 1;
}

bool stack_push(StackArrayList *s, int elem) {
    bool retVal = false;
    if (!isFull(*s)) {
        s->top++;
        s->data[s->top] = elem;
        retVal = true;
    }
    return retVal;
}

bool stack_pop(StackArrayList *s) {
    bool retVal = false;
    if (!isEmpty(*s)) {
        s->top--;
        retVal = true;
    }
    return retVal;
}

int stack_peek(StackArrayList s) {
    return (!isEmpty(s)) ? s.data[s.top] : -1;
}

void display(StackArrayList s) {
    StackArrayList tempStack;
    initStack(&tempStack);
    printf("Stack elements: ");
    while (!isEmpty(s)) {
        int elem = stack_peek(s);
        stack_pop(&s);
        printf("%d ", elem);
        stack_push(&tempStack, elem);
    }
    printf("\n");

//    while (!isEmpty(tempStack)) {
//        int elem = stack_peek(tempStack);
//        stack_pop(&tempStack);
//        stack_push(&s, elem);
//    }
}

void visualize(StackArrayList s) {
	int i;
    for (i=s.top;i >= 0; i--) {
        printf("| %d |\n", s.data[i]);
    }
    printf(" ----- \n");
}

StackArrayList getEven(StackArrayList *s) {
	int i;
    StackArrayList evenStack = createStack();
    for (i=0;i <= s->top; i++) {
        if (s->data[i] % 2 == 0) {
            stack_push(&evenStack, s->data[i]);
        }
    }
    return evenStack;
}

