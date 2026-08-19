#include <stdio.h>
int main() {
    int n, x, sum = 0;
    printf("ENTER THE RANGE:\n");
    scanf("%d", &n);
    for (x = 1; x <= n; x += 2)
        sum += x;
    printf("SUM = %d\n", sum);
    return 0;
}
