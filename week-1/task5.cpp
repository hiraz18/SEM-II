#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100], result[200];
    int choice, length;
    
    printf("Enter first string: ");
    gets(str1);
    
    printf("Enter second string: ");
    gets(str2);
    
    printf("\nMENU:\n");
    printf("1. Addition (Concatenation)\n");
    printf("2. Copying\n");
    printf("3. Reverse\n");
    printf("4. Length\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch(choice) {
        case 1:
            strcpy(result, str1);
            strcat(result, " ");
            strcat(result, str2);
            printf("Addition result: %s\n", result);
            break;
            
        case 2:
            strcpy(result, str1);
            printf("Original: %s\n", str1);
            printf("Copied: %s\n", result);
            break;
            
        case 3:
            printf("Reverse of '%s': ", str1);
            for(length = strlen(str1) - 1; length >= 0; length--)
                printf("%c", str1[length]);
            printf("\n");
            break;
            
        case 4:
            length = strlen(str1);
            printf("Length of string: %d\n", length);
            break;
            
        default:
            printf("Invalid choice!\n");
    }
    
    return 0;
}
