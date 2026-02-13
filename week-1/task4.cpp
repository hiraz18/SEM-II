#include <stdio.h>

int main() {
    int a[3][3], b[3][3], c[3][3], i, j, k;

    printf("Enter Matrix A:\n");
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            scanf("%d",&a[i][j]);

    printf("Enter Matrix B:\n");
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            scanf("%d",&b[i][j]);

    // Addition
    printf("\nAddition:\n");
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            c[i][j]=a[i][j]+b[i][j];
            printf("%d ",c[i][j]);
        }
        printf("\n");
    }

    // Subtraction
    printf("\nSubtraction:\n");
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            c[i][j]=a[i][j]-b[i][j];
            printf("%d ",c[i][j]);
        }
        printf("\n");
    }

    // Multiplication
    printf("\nMultiplication:\n");
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            c[i][j]=0;
            for(k=0;k<3;k++)
                c[i][j]+=a[i][k]*b[k][j];
            printf("%d ",c[i][j]);
        }
        printf("\n");
    }

    // Transpose of A
    printf("\nTranspose of A:\n");
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            printf("%d ",a[j][i]);
        }
        printf("\n");
    }

    return 0;
}
