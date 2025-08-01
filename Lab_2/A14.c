#include <stdio.h>
void main()
{
    int num, ans, sum = 0;
    printf("Enter a number:");
    scanf("%d", &num);

    for (int i = 1; i <= num; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            
            sum = sum + j;
        }
        ans = ans + sum;
    }
    printf("Answer is: %d \n", ans);
}