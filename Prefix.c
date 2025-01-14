#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
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

double evaluatePrefix(char* prefix) {
    Stack s;
    s.top = -1;
    int length = strlen(prefix);
    
    // Loop through the prefix expression from right to left
    for (int i = length - 1; i >= 0; i--) {
        if (isdigit(prefix[i])) {
            double num = 0;
            int power = 1;
            
            while (i >= 0 && isdigit(prefix[i])) {
                num += (prefix[i] - '0') * power;
                power *= 10;
                i--;
            }
            i++; // Adjust for the loop decrement
            push(&s, num);
        } else if (isOperator(prefix[i])) {
            double a = pop(&s);
            double b = pop(&s);
            double result = evaluateOperation(a, b, prefix[i]);
            push(&s, result);
        }
    }
    
    return pop(&s);
}

int main() {
    char prefix[MAX];
    
    printf("Enter a prefix expression: ");
    scanf("%s", prefix);
    
    double result = evaluatePrefix(prefix);
    
    printf("Result of the prefix expression: %.2f\n", result);
    
    return 0;
}
