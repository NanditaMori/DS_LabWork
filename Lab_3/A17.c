// 17.Write a program to calculate sum of numbers from m to n.

#include <stdio.h>
void main(){
    int size;
    printf("Enter size of array: ");
    scanf("%d",&size);
    int a[size];
    
    for(int i=0 ; i<size ; i++){
        printf("Enter value for array[%d]: ",(i));
        scanf("%d",&a[i]);
    }
    int low,high;
    printf("Enter lower limit: ");
    scanf("%d",&low);

    printf("Enter upper limit: ");
    scanf("%d",&high);
    int sum=0;

    for(int i=low ; i<=high ; i++){
        sum=sum+a[i];
    }
    printf("Sum of number= %d",sum);
}