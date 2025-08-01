// Anagram programm

#include <stdio.h>
#include <stdlib.h>
void main(){
    int size;
    printf("Enter size of array: ");
    scanf("%d",&size);
    char a[size][10];

    for(int i=0 ; i<size ; i++){
        printf("Enter a word: ");
        scanf("%s",&a[size]);
    }

    printf("Entered array is: ");
    for(int i=0 ; i<size ; i++){
        for(int j=0 ; j<size ; j++ ){
            printf("%c",a[i][j]);
        }
    }

    

}