#include <stdio.h>
int main() {
    int a, b, op;
    printf("ENTER THE VALUE OF A:\n");
    scanf("%d", &a);
    printf("ENTER THE VALUE OF B:\n");
    scanf("%d", &b);
    printf("ENTER THE OPTION TO PERFORM\n");
    printf("1. ADDITION\n2. SUBTRACTION\n3. MULTIPLICATION\n4. DIVISION\n");
    scanf("%d", &op);
    switch (op) {
        case 1: printf("Result = %d\n", a + b); break;
        case 2: printf("Result = %d\n", a - b); break;
        case 3: printf("Result = %d\n", a * b); break;
        case 4:
            if (b != 0) printf("Result = %d\n", a / b);
            else printf("Division by zero is not allowed\n");
            break;
        default: printf("Invalid Option\n");
    }
    return 0;
}
