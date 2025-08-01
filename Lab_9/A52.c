// 52.WAP to find the largest element in the array using Pointer.
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
    int max=*ptr;
    for(int i=0 ; i<size ; i++){
       if(max < *(ptr+i)){
            max=*(ptr+i);
       }
    }
    printf("Largest is: %d",max);
    free(ptr);
}