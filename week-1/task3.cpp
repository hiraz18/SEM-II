#include <stdio.h>

int main() {
    char str[100];
    int vowels = 0, cons = 0, digits = 0, spaces = 0;
    int i;
    
    printf("Enter the string: ");
    gets(str);
    
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' ||
            str[i] == 'o' || str[i] == 'u' ||
            str[i] == 'A' || str[i] == 'E' || str[i] == 'I' ||
            str[i] == 'O' || str[i] == 'U')
            vowels++;
        
        else if ((str[i] >= 'a' && str[i] <= 'z') ||
                 (str[i] >= 'A' && str[i] <= 'Z'))
            cons++;
        
        else if (str[i] >= '0' && str[i] <= '9')
            digits++;
        
        else if (str[i] == ' ' || str[i] == '\t')
            spaces++;
    }
    
    printf("\nVowels = %d\n", vowels);
    printf("Consonants = %d\n", cons);
    printf("Digits = %d\n", digits);
    printf("White spaces = %d\n", spaces);
    
    return 0;
}
