// 27. Write a program to delete a number from an array that is already sorted in an ascending order.

#include <stdio.h>
void main(){
     int size;
    printf("Enter size of array: ");
    scanf("%d",&size);
    int a[size];

    printf("Enter elements in ascending order:\n");
    for (int i = 0; i < size; i++) {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }
    int num;
    printf("Enter the number to delete: ");
    scanf("%d", &num);

    for(int i=0 ; i<size ; i++){
        if(a[i]>num){
            a[i]=a[i-1];
        }
    }
    
    for(int i=0 ; i<size-1 ; i++){
        printf("%d ",a[i]);
    }
}