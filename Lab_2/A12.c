#include <stdio.h>
void main(){
    int num,count=0;
    printf("Enter a number:");
    scanf("%d",&num);
    for(int i=1 ; i<num ; i++){
        if(num%i == 0){
            count++;
        }
    }
    if(count==1){
        printf("Number is prime");
    }
    else{
        printf("Number is not prime");
    }
}