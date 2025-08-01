// 32.Read two matrices, first 3x2 and second 2x3, perform multiplication operation and store result in third matrix and print it.

#include <stdio.h>
void main(){
    int a[3][2], b[2][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("Enter value for a[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    printf("\n");

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("Enter value for b[%d][%d]: ", i, j);
            scanf("%d", &b[i][j]);
        }
    }

    int c[3][3];

    for(int i=0 ; i<3 ; i++){
        for(int j=0 ; j<3 ; j++){
            c[i][j]=0;
            for(int k=0 ; k<2 ; k++){
                c[i][j]+=a[i][k]*b[k][j];
            }
        }
    }

     printf("Multiplication of both the arrays is: \n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }




}