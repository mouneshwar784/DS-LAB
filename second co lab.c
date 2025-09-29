#include <stdio.h>
#include <string.h>
#define SIZE 100

char stack[SIZE];
int top = -1;

void push(char c) {
    if (top == SIZE - 1)
        printf("Stack Overflow!");
    else
        stack[++top] = c;
}

char pop() {
    if (top == -1) {
        printf("Stack Underflow!");
        return -1;
    } else
        return stack[top--];
}

int precedence(char c) {
    switch (c) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3;
        default: return 0;
    }
}

void infixtopostfix(char inf[], char post[]) {
    int i, R = 0;
    char c;
    int len = strlen(inf);
    for (i = 0; i < len; i++) {
        c = inf[i];
        switch (c) {
            case '(': push(c); break;
            case ')':
                while (top != -1 && stack[top] != '(') {
                    post[R++] = pop();
                }
                pop();
                break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
                while (top != -1 && precedence(stack[top]) >= precedence(c)) {
                    post[R++] = pop();
                }
                push(c);
                break;
            default:
                post[R++] = c;
        }
    }
    while (top != -1) {
        post[R++] = pop();
    }
    post[R] = '\0';
}

int main() {
    char infi[100], post[100];
    printf("Enter the infix Expression: ");
    scanf("%s", infi);
    printf("Infix expression is %s\n", infi);
    infixtopostfix(infi, post);
    printf("Postfix expression is %s\n", post);
    return 0;
}
