#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
char infix[MAX], prefix[MAX];
int top = -1;

void push(char c) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
    } else {
        stack[++top] = c;
    }
}

char pop() {
    if (top == -1) {
        return '\0';
    } else {
        return stack[top--];
    }
}

int precedence(char ch) {
    switch (ch) {
        case '$': return 3; 
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default:  return 0;
    }
}

// Reverse a string
void reverse(char str[]) {
    int i, j;
    char temp;
    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}
void intopre() {
    int i, j = 0;
    char ch, next;

    reverse(infix);

    for (i = 0; i < strlen(infix); i++) {
        ch = infix[i];

        if (isalnum(ch)) { 
            prefix[j++] = ch;
        } else if (ch == ')') {
            push(ch);
        } else if (ch == '(') {
            while ((next = pop()) != ')' && next != '\0') {
                prefix[j++] = next;
            }
        } else { 
            while (top != -1 && precedence(stack[top]) >= precedence(ch)) {
                prefix[j++] = pop();
            }
            push(ch);
        }
    }

    while (top != -1) {
        prefix[j++] = pop();
    }

    prefix[j] = '\0';
    reverse(prefix);
}

int main() {
    printf("Enter the infix expression: ");
    scanf("%s", infix);

    intopre();
    printf("Prefix expression: %s\n", prefix);

    return 0;
}
