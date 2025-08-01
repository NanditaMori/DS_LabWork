//A1(2) Factorial of number
#include <stdio.h>
int fact(int n);
void main(){
    int num;
    printf("Enter an integer");
    scanf("%d",&num);
printf("Ans is: %d",fact(num));

}
int fact(int n){
    if(n<=1){
        return 1;
    }
    else{
        return n*fact(n-1);
    }
}