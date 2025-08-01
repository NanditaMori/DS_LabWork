//Write a program to delete a number from a given location in an array.
#include <stdio.h>
void main(){
    int location;
    int a[50];
    for(int i=0 ; i<5 ; i++){
        printf("Enter value for array:");
        scanf("%d",&a[i]);
    }
    printf("Enter location from where the number is to be deleted:");
    scanf("%d",&location);

    for(int i=0 ; i<5 ; i++){
        if(i>=location){
            a[i]=a[i+1];
        }
    }
    for(int i=0 ; i<4 ; i++){
        printf("%d ",a[i]);
    }

}