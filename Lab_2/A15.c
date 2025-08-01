#include <stdio.h>
void main()
{
    int num, sum = 0, rem, count = 0;
    printf("Enter a number:");
    scanf("%d", &num);
    int n=num;
    int number=num;
    for (int i = 0; i <= num; i++)
    {
        rem = num % 10;
        sum = sum * 10 + rem;
        num = num / 10;
        count++;
    }
    sum=0;rem=0;
    int finalAns=0;
    int res=1;
    for (int i = 0; i < count; i++)
    {
        rem=n%10;
        sum=sum*10+rem;
        for(int j=0 ; j<count ; j++)
        {
            res=sum*res;
        }
        finalAns=finalAns+res;
    }
    if(number==finalAns){
        printf("%d is Amstrong number",number);
    }
    else{
        printf("%d is not Armstrong number");
    }
}