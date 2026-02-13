#include <stdio.h>
#include <string.h>

int main() {
    char s1[100], s2[100];

    printf("Enter first string: ");
    gets(s1);

    printf("Enter second string: ");
    gets(s2);

    // Addition
    strcat(s1, s2);
    printf("After Addition: %s\n", s1);

    // Copying
    strcpy(s2, s1);
    printf("After Copy: %s\n", s2);

    // Reverse
    strrev(s1);
    printf("Reverse: %s\n", s1);

    // Length
    printf("Length: %d", strlen(s1));

    return 0;
}
