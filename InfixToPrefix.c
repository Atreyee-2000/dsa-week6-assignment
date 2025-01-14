#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

typedef struct Stack {
    int top;
    char items[MAX];
} Stack;

void push(Stack *s, char item) {
    if (s->top >= MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        s->items[++(s->top)] = item;
    }
}

char pop(Stack *s) {
    if (s->top < 0) {
        printf("Stack Underflow\n");
        return '\0';
    } else {
        return s->items[(s->top)--];
    }
}

char peek(Stack *s) {
    return s->items[s->top];
}

int isEmpty(Stack *s) {
    return s->top == -1;
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
        default:
            return 0;
    }
}

int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

void reverse(char* str) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

void infixToPrefix(char* infix, char* prefix) {
    Stack s;
    s.top = -1;
    int i, j = 0;
    
    // Reverse the infix expression
    reverse(infix);
    
    for (i = 0; infix[i] != '\0'; i++) {
        if (isalnum(infix[i])) {
            prefix[j++] = infix[i];
        } else if (infix[i] == ')') {
            push(&s, infix[i]);
        } else if (infix[i] == '(') {
            while (!isEmpty(&s) && peek(&s) != ')') {
                prefix[j++] = pop(&s);
            }
            if (!isEmpty(&s) && peek(&s) != ')') {
                printf("Invalid expression\n");
                return;
            } else {
                pop(&s);
            }
        } else if (isOperator(infix[i])) {
            while (!isEmpty(&s) && precedence(peek(&s)) > precedence(infix[i])) {
                prefix[j++] = pop(&s);
            }
            push(&s, infix[i]);
        }
    }
    
    while (!isEmpty(&s)) {
        prefix[j++] = pop(&s);
    }
    
    prefix[j] = '\0';
    
    // Reverse the prefix expression
    reverse(prefix);
}

int main() {
    char infix[MAX], prefix[MAX];
    
    printf("Enter an infix expression: ");
    scanf("%s", infix);
    
    infixToPrefix(infix, prefix);
    
    printf("Prefix expression: %s\n", prefix);
    
    return 0;
}
