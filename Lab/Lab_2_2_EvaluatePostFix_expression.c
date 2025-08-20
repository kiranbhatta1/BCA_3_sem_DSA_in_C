#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

int evaluatePostfix(char *exp);

int main() {
    char exp[MAX];
    printf("Enter a postfix expression: ");
    scanf("%s", exp);

    int result = evaluatePostfix(exp);
    printf("Result: %d\n", result);

    return 0;
}

int evaluatePostfix(char *exp) {
    int stack[MAX];
    int top = -1;
    int length = strlen(exp);

    for (int i = 0; i < length; i++) {
        char ch = exp[i];

        if (isdigit(ch)) {
            stack[++top] = ch - '0';
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            int operand2 = stack[top--];
            int operand1 = stack[top--];

            switch (ch) {
                case '+':
                    stack[++top] = operand1 + operand2;
                    break;
                case '-':
                    stack[++top] = operand1 - operand2;
                    break;
                case '*':
                    stack[++top] = operand1 * operand2;
                    break;
                case '/':
                    stack[++top] = operand1 / operand2;
                    break;
            }
        }
    }

    return stack[top];
}
