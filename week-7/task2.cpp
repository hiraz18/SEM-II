#include <stdio.h>
#include <ctype.h>

char stack[100];
int top = -1;

void push(char x) { stack[++top] = x; }

char pop() { return (top == -1) ? -1 : stack[top--]; }

int prec(char x) {
    if (x == '(') return 0;
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/') return 2;
    if (x == '^') return 3;
    return -1;
}

int main() {
    char exp[] = "a+b*(c^d-e)"; // Example input
    char *e, x;
    e = exp;

    printf("Postfix: ");
    while (*e != '\0') {
        if (isalnum(*e)) {
            printf("%c", *e);
        } else if (*e == '(') {
            push(*e);
        } else if (*e == ')') {
            while ((x = pop()) != '(') printf("%c", x);
        } else {
            while (top != -1 && prec(stack[top]) >= prec(*e))
                printf("%c", pop());
            push(*e);
        }
        e++;
    }

    while (top != -1) printf("%c", pop());
    printf("\n");
    return 0;
}
