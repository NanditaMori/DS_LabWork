#include <stdio.h>
void main()
{
    int a, b, count = 0;
    printf("Enter a lowerlimit:");
    scanf("%d", &a);
    printf("Enter a upperlimit:");
    scanf("%d", &b);

    for (int i = a; i <= b; i++)
    {
        for (int j = 2; j <= i; j++)
        {
            if (i % j == 0)
            {
                count++;
            }
        }
        if (count == 1)
        {
            printf("%d Number is prime \n", i);
        }
        count=0;
    }
}