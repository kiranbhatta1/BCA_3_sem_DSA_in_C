#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

int evaluatePrefix(char* exp) {
    int stack[MAX];
    int top = -1;
    int length = strlen(exp);

    for (int i = length - 1; i >= 0; i--) {
        char ch = exp[i];

        if (ch == ' ')
            continue;

        if (isdigit(ch)) {
          
            stack[++top] = ch - '0';
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            if (top < 1) {
                printf("Invalid expression.\n");
                exit(1);
            }

            int operand1 = stack[top--];
            int operand2 = stack[top--];
            int result;

            switch (ch) {
                case '+': result = operand1 + operand2; break;
                case '-': result = operand1 - operand2; break;
                case '*': result = operand1 * operand2; break;
                case '/': result = operand1 / operand2; break;
            }

            stack[++top] = result;
        }
    }

    return stack[top];
}

int main() {
    char exp[MAX];

    printf("Enter a prefix expression: ");
    fgets(exp, MAX, stdin);
    exp[strcspn(exp, "\n")] = '\0'; 

    int result = evaluatePrefix(exp);
    printf("Result: %d\n", result);

    return 0;
}

