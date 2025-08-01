// WAP to allocate and de-allocate memory for int, char and float variable at runtime.

#include <stdio.h>
#include<stdlib.h>
void main()
{
    int *iptr = (int *)malloc(sizeof(int));
    char *cptr = (char *)malloc(sizeof(char));
    float *fptr = (float *)malloc(sizeof(float));

    if (iptr && cptr && fptr)
    {
        *iptr = 10;
        *cptr = 'a';
        *fptr = 10.25;

        printf("Integer: %d\n",*iptr);
        printf("Character : %c\n",*cptr);
        printf("Float: %f\n",*fptr);

        free(iptr);
        free(cptr);
        free(fptr);
    }
    else{
        printf("Memory allocation failed!!");
    }
}
