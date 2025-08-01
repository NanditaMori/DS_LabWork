// 19. Write a program to find position of the smallest number & the largest number from given n numbers.

#include <stdio.h>
void main()
{
    int size;
    printf("Enter size of array: ");
    scanf("%d", &size);
    int a[size];
    for (int i = 0; i < size; i++)
    {
        printf("Enter value for a[%d]: ", i);
        scanf("%d", &a[i]);
    }
    int max = a[0], min = a[0];
    for (int i = 0; i < size; i++)
    {
        if (max < a[i])
        {
            max = a[i];
        }
    }
    for (int i = 0; i < size; i++)
    {
        if (min > a[i])
        {
            min = a[i];
        }
    }
    printf("Maximum = %d\n",max);
    printf("Minimum = %d\n",min);
}