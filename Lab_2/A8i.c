//A1(1) Factorial of number
#include<stdio.h>
void main(){
    int num,ans=1;
    printf("Enter an interger:");
    scanf("%d",&num);
    for(int i=1 ; i<=num ; i++){
        ans=ans*i;
    }
    printf("Factorial of %d is %d",num,ans);
}