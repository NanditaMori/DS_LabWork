// 20.Write a program to find whether the array contains a duplicate number or not.

#include <stdio.h>
void main(){
    int size;
    printf("Enter size of array: ");
    scanf("%d",&size);
    int a[size];
    for (int i = 0; i < size; i++)
    {
        printf("Enter value for a[%d]: ", i);
        scanf("%d", &a[i]);
    }
    
    int duplicate;
    for(int i=0 ; i<size ; i++){
        duplicate=a[i];
        for(int j=0 ; j>i ; j++){
            if(a[j]==duplicate){
                printf("%d is duplicate \n",duplicate);
            }
        }
    }
}