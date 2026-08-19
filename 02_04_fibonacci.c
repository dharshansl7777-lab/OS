#include <stdio.h>
int main() {
    int n, i;
    long long p = -1, q = 1, r;
    printf("ENTER THE LIMIT:\n");
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        r = p + q;
        p = q;
        q = r;
        printf("%lld\n", r);
    }
    return 0;
}
