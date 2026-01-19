#include <stdio.h>

int main() {
    int a[10][10], b[10][10], res[10][10];
    int r1, c1, r2, c2, i, j, k, ch;
    
    printf("Enter rows and columns for matrix A: ");
    scanf("%d %d", &r1, &c1);
    printf("Enter rows and columns for matrix B: ");
    scanf("%d %d", &r2, &c2);
    
    printf("\nEnter elements of matrix A:\n");
    for(i=0; i<r1; i++)
        for(j=0; j<c1; j++)
            scanf("%d", &a[i][j]);
    
    printf("\nEnter elements of matrix B:\n");
    for(i=0; i<r2; i++)
        for(j=0; j<c2; j++)
            scanf("%d", &b[i][j]);
    
    printf("\n--- MENU ---\n");
    printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Transpose\n");
    printf("Enter your choice: ");
    scanf("%d", &ch);
    
    switch(ch) {
        case 1: // Addition
            if(r1==r2 && c1==c2) {
                printf("\nAddition Result:\n");
                for(i=0; i<r1; i++) {
                    for(j=0; j<c1; j++) {
                        res[i][j] = a[i][j] + b[i][j];
                        printf("%4d ", res[i][j]);
                    }
                    printf("\n");
                }
            }
            break;
            
        case 2: // Subtraction
            if(r1==r2 && c1==c2) {
                printf("\nSubtraction Result:\n");
                for(i=0; i<r1; i++) {
                    for(j=0; j<c1; j++) {
                        res[i][j] = a[i][j] - b[i][j];
                        printf("%4d ", res[i][j]);
                    }
                    printf("\n");
                }
            }
            break;
            
        case 3: // Multiplication
            if(c1==r2) {
                printf("\nMultiplication Result:\n");
                for(i=0; i<r1; i++) {
                    for(j=0; j<c2; j++) {
                        res[i][j] = 0;
                        for(k=0; k<c1; k++)
                            res[i][j] += a[i][k] * b[k][j];
                        printf("%4d ", res[i][j]);
                    }
                    printf("\n");
                }
            }
            break;
            
        case 4: // Transpose
        	int ab;
        	printf("1.Transpose of Matrix A: \n2. Transpose of Matrix B: \n");
    		printf("Enter your choice: ");
    		scanf("%d", &ab);
        	switch(ab) {
        		case 1:
        			printf("\nTranspose of Matrix A:\n");
        			for(i=0; i<c1; i++) {
                		for(j=0; j<r1; j++)
                    		printf("%4d ", a[j][i]);
                		printf("\n");
            		}
            		break;
            	case 2:
            		printf("\nTranspose of Matrix B:\n");
            		for(i=0; i<c2; i++) {
               			for(j=0; j<r2; j++)
                    		printf("%4d ", b[j][i]);
                		printf("\n");
                	}
                	break;
            }
            break;
    }
    return 0;
}
