#include <stdio.h>
int main() {
    int n, remainder, rnum = 0;
    printf("ENTER THE NUMBER\n");
    scanf("%d", &n);
    while (n != 0) {
        remainder = n % 10;
        rnum = rnum * 10 + remainder;
        n /= 10;
    }
    printf("REVERSE OF THE NUMBER IS %d\n", rnum);
    return 0;
}
