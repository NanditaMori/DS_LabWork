// Write a program to insert a number in an array that is already sorted in an ascending order
#include <stdio.h>
void main()
{
    int size;
    printf("Enter size of array: ");
    scanf("%d",&size);
    int a[size];
    // for (int i = 0; i < a.length-1; i++)
    // {
    //     printf("Enter value for array:");
    //     scanf("%d", &a[i]);
    // }

    for (int i = 0; i < 5; i++)
    {
        int min=a[i];
        int minIndex=i;
        for (int j = (i + 1) ; j < 5; j++)
        {
            if(min>a[j]){
                min=a[j];
                minIndex=j;
            }
        }
        if(minIndex!=i){
            a[min]=a[i];
            minIndex=i;
        }
    }
    printf("Sorted Array:");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", a[i]);
    }
}