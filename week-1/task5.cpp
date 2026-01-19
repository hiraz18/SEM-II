#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100], result[200];
    int choice, length, length2;
    
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
        	int ab;
        	printf("1. Reverse of first string.\n");
    		printf("2. Reverse of second string.\n");
    		printf("Enter your choice: ");
    		scanf("%d", &ab);
    		switch(ab) {
    			case 1:
    				printf("Reverse of '%s': ", str1);
            		for(length = strlen(str1) - 1; length >= 0; length--)
                		printf("%c", str1[length]);
            		printf("\n");
            		break;
            	case 2:
            		printf("Reverse of '%s': ", str2);
            		for(length = strlen(str2) - 1; length >= 0; length--)
                		printf("%c", str2[length]);
            		printf("\n");
            		break;
			}
            break;
            
        case 4:
        	int cd;
        	printf("1. Length of first string.\n");
    		printf("2. Length of second string.\n");
    		printf("Enter your choice: ");
    		scanf("%d", &cd);
    		switch(cd) {
    			case 1:
    				length = strlen(str1);
            		printf("Length of string: %d\n", length);
            		break;
				case 2:
					length2 = strlen(str2);
            		printf("Length of string: %d\n", length2);
            		break;
			}
            break;
            
        default:
            printf("Invalid choice!\n");
    }
    
    return 0;
}
