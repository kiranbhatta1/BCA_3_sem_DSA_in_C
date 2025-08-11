#include <stdio.h>

int stack[100], top = -1, n;

void push();
void pop();
void display();

int main() {
    int choice;

    printf("Enter the number of elements in the stack: ");
    scanf("%d", &n);

    printf("Stack operations using array\n");
    printf("--------------------------------\n");

    while (1) {
        printf("\nChoose one from the below options:\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Please enter a valid choice.\n");
        }
    }

    return 0;
}

void push() {
    int val;
    if (top == n - 1) {
        printf("Stack Overflow\n");
    } else {
        printf("Enter the value to push: ");
        scanf("%d", &val);
        top++;
        stack[top] = val;
    }
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
    } else {
        printf("Popped element: %d\n", stack[top]);
        top--;
    }
}

void display() {
    int i;
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements are:\n");
        for (i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

