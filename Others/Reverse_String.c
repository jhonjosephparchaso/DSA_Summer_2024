#include <stdio.h>

void reverseString(char *str) {
	int l, i, n;
	for(l = 0; str[l] != '\0'; l++){}
    n = l;
    for (i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

int main() {
    char str[100];

    printf("Enter a string: ");
    gets(str);

    printf("Before reversing: %s\n", str);

    reverseString(str);

    printf("After reversing: %s\n", str);

    return 0;
}
