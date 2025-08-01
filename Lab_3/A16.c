// 16. Write a program to read and display n numbers using an array.
#include <stdio.h>
void main(){
    int size;
    printf("Enter size of arrray: ");
    scanf("%d",&size);
    int a[size];
    for( int i=0 ; i<size ; i++){
        printf("Enter value for a[%d]: ",(i+1));
        scanf("%d",&a[i]);
    }
    for( int i=0 ; i<size ; i++){
        printf("Value of a[%d] = %d \n",(i+1),a[i]);
    }

}