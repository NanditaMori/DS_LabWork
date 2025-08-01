// 51.WAP to calculate the sum of n numbers using Pointer.
#include<stdio.h>
#include <stdlib.h>
void main(){
    int size;
    printf("Enter size of array:");
    scanf("%d",&size);

    int a[size];
    for(int i=0 ; i<size ; i++){
        printf("Enter array elements: ");
        scanf("%d",&a[i]);
    }
    int *ptr = (int *)malloc(size*sizeof(int));
    ptr=a;
    int sum=0;
    for(int i=0 ; i<size ; i++){
        sum=sum+*(ptr+i);
    }
    printf("Sum is:%d ",sum);
    free(ptr);
}