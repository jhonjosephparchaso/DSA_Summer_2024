#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

typedef struct {
    int top;
    char items[MAX];
} Stack;

void initialize(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, char item) {
    if (s->top == MAX - 1) {
        exit(1);
    } else {
        s->items[++(s->top)] = item;
    }
}

char pop(Stack *s) {
    if (isEmpty(s)) {
        exit(1);
    } else {
        return s->items[(s->top)--];
    }
}

char peek(Stack *s) {
    if (isEmpty(s)) {
        exit(1);
    } else {
        return s->items[s->top];
    }
}

int isOperand(char ch) {
    return isalnum(ch);
}

int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return 0;
}

void infixToPostfix(char* infix, char* postfix) {
    Stack s;
    initialize(&s);
    int k = 0, i;

    for (i = 0; infix[i]; i++) {
        if (isOperand(infix[i])) {
            postfix[k++] = infix[i];
        } else if (infix[i] == '(') {
            push(&s, infix[i]);
        } else if (infix[i] == ')') {
            while (!isEmpty(&s) && peek(&s) != '(') {
                postfix[k++] = pop(&s);
            }
            if (!isEmpty(&s) && peek(&s) != '(') {
                printf("Invalid expression\n");
                exit(1);
            } else {
                pop(&s);
            }
        } else {
            while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(infix[i])) {
                postfix[k++] = pop(&s);
            }
            push(&s, infix[i]);
        }
    }

    while (!isEmpty(&s)) {
        postfix[k++] = pop(&s);
    }
    postfix[k] = '\0';
}

int main() {
    char infix[] = "a*b+c/d-e";
    char postfix[MAX];

    infixToPostfix(infix, postfix);

    printf("Infix Expression: %s\n", infix);
    printf("Postfix Expression: %s\n", postfix);

    return 0;
}

