// 53.WAP to sort the array elements using Pointer.
#include <stdio.h>
#include <stdlib.h>
void main()
{
    int size;
    printf("Enter size of array:");
    scanf("%d", &size);

    int a[size];
    for (int i = 0; i < size; i++)
    {
        printf("Enter array elements: ");
        scanf("%d", &a[i]);
    }
    int *ptr = (int *)malloc(size * sizeof(int));
    ptr = a;

    for (int i = 0; i < size; i++)
    {
        for (int j = 1 + i; j < i; j++)
        {
            if((*ptr+i)>(*ptr+j)){
                int temp = *ptr+i;
                *(ptr+i) = *ptr+j;
                *(ptr+j) = temp;
            }
        }
    }
    printf("Sorted array is: ");
    for(int i=0 ; i<size ; i++){
        printf("%d, ",*(ptr+i));
    }

    free(ptr);
}