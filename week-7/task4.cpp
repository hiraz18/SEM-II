#include <stdio.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char x) {
    if (top == MAX - 1) return;
    stack[++top] = x;
}

char pop() {
    if (top == -1) return -1;
    return stack[top--];
}

int priority(char x) {
    if (x == '(') return 0;
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/') return 2;
    return 0;
}

int main() {
    char infix[] = "(A+B)*(C+B)*(E/F)"; 
    char postfix[MAX];
    int i = 0, j = 0;
    char ch, x;

    printf("Infix: %s\n", infix);

    while ((ch = infix[i++]) != '\0') {
        if (isalnum(ch)) {
            postfix[j++] = ch;
        } else if (ch == '(') {
            push(ch);
        } else if (ch == ')') {
            while ((x = pop()) != '(')
                postfix[j++] = x;
        } else {
            while (top != -1 && priority(stack[top]) >= priority(ch))
                postfix[j++] = pop();
            push(ch);
        }
    }

    while (top != -1)
        postfix[j++] = pop();

    postfix[j] = '\0';
    printf("Postfix: %s\n", postfix);  

    return 0;
}
