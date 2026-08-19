#include <stdio.h>
int main() {
    int n, i;
    long long fact = 1;
    printf("ENTER THE NUMBER:\n");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        fact *= i;
    printf("FACTORIAL OF THE GIVEN NUMBER IS %lld\n", fact);
    return 0;
}
