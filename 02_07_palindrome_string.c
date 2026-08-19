#include <stdio.h>
#include <string.h>
int main() {
    char str[100];
    int i, j, palindrome = 1;
    printf("ENTER THE STRING TO CHECK PALINDROME\n");
    scanf("%99s", str);
    i = 0;
    j = strlen(str) - 1;
    while (i < j) {
        if (str[i] != str[j]) {
            palindrome = 0;
            break;
        }
        i++;
        j--;
    }
    if (palindrome)
        printf("%s is a palindrome\n", str);
    else
        printf("%s is not a palindrome\n", str);
    return 0;
}
