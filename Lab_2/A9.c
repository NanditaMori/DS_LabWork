#include<stdio.h>
void main(){
    int num,power,ans=1;
    printf("Enetr a number:");
    scanf("%d",&num);
    printf("Enetr a power:");
    scanf("%d",&power);
    for(int i=1 ; i<=power ;i++){
        ans=num*ans;
    }
    printf("Answer is:%d",ans);
}