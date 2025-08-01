// 18.Write a program to calculate average of first n numbers.
#include <stdio.h>
void main(){
    int size;
    printf("Enter size of array: ");
    scanf("%d",&size);

    int a[size];
    for(int i=0 ; i<size ; i++){
        printf("Enter value for a[%d]: ",i);
        scanf("%d",&a[i]);
    }
    int n;
    printf("Enter value for n: ");
    scanf("%d",&n);
    int sum=0;
    printf("%d\n",sum);
    for(int i=0 ; i<=n ; i++){
        sum=sum+a[i];
    }
    int avg = sum/n;
    printf("Average = %d",avg);
}