#include <stdio.h>

int fact(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * fact(n - 1);
    }
}

int main() {
    int a;
    printf("Enter the number for factorial: ");
    scanf("%d", &a); 

    int result = fact(a);
    printf("Factorial of %d is %d\n", a, result);

    return 0;
}
