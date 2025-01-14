#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAX 100

typedef struct Stack {
    int top;
    double items[MAX];
} Stack;

void push(Stack *s, double item) {
    if (s->top >= MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        s->items[++(s->top)] = item;
    }
}

double pop(Stack *s) {
    if (s->top < 0) {
        printf("Stack Underflow\n");
        return 0;
    } else {
        return s->items[(s->top)--];
    }
}

int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

double evaluateOperation(double a, double b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        case '^': return pow(a, b);
        default: return 0;
    }
}

double evaluatePostfix(char* postfix) {
    Stack s;
    s.top = -1;
    int i = 0;
    double a, b, result;
    
    while (postfix[i] != '\0') {
        if (isdigit(postfix[i])) {
            double num = 0;
            while (isdigit(postfix[i])) {
                num = num * 10 + (postfix[i] - '0');
                i++;
            }
            i--; // Adjust for the loop increment
            push(&s, num);
        } else if (isOperator(postfix[i])) {
            b = pop(&s);
            a = pop(&s);
            result = evaluateOperation(a, b, postfix[i]);
            push(&s, result);
        }
        i++;
    }
    
    return pop(&s);
}

int main() {
    char postfix[MAX];
    
    printf("Enter a postfix expression: ");
    scanf("%s", postfix);
    
    double result = evaluatePostfix(postfix);
    
    printf("Result of the postfix expression: %.2f\n", result);
    
    return 0;
}
