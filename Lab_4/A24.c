//Write a program to insert a number at a given location in an array.
#include <stdio.h>
void main(){
    int size,num,location;
    
    int a[50];
    for(int i=0 ; i<10 ; i++){
        printf("Enter value for array:");
        scanf("%d",&a[i]);
    }
    printf("Enter a new number:");
    scanf("%d",&num);
    printf("Enter the location where the number is to be changed:");
    scanf("%d",&location);

    for(int i=11 ; i!=-1 ; i--){
        
        if(i!=location){
            a[i]=a[i-1];
        }
        if(i==location){
            a[location]=num;
            i++;
            break;
        }
    }
    for(int i=0 ; i<11 ; i++){
        printf("%d ",a[i]);
    }
}