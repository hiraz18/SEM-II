#include <stdio.h>
#include <ctype.h>   

#define MAX 100

int stack[MAX];
int top = -1;

void push(int x) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = x;
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return 0;     
    }
    return stack[top--];
}

int main() {
    char postfix[MAX];
    int i;
    char ch;
    int a, b, result;

    printf("Enter postfix expression (operands 0-9, operators + - * /): ");
    scanf("%s", postfix);         

    for (i = 0; postfix[i] != '\0'; i++) {
        ch = postfix[i];

        if (isdigit(ch)) {
           
            push(ch - '0');
        } else {
          
            a = pop();    
            b = pop();     

            switch (ch) {
            case '+': result = b + a; break;
            case '-': result = b - a; break;
            case '*': result = b * a; break;
            case '/': result = b / a; break;
            default:
                printf("Invalid operator %c\n", ch);
                return 0;
            }
            push(result);
        }
    }

    result = pop();
    printf("Result = %d\n", result);

    return 0;
}
