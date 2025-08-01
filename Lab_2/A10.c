#include<stdio.h>
void main(){
    int num,sum=0,ans=0;
    printf("Enetr a number:");
    scanf("%d",&num);
    while(num!=0){
        ans = num%10;
        sum=sum*10+ans;
        num = num/10;
    }
    printf("Answer is:%d",sum);
}