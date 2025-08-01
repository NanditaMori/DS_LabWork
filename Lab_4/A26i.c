// Write a program to insert a number in an array that is already sorted in an ascending order

#include <stdio.h>

void main() {
    int a[50], size = 10, num, i, j;

    // Input sorted array
    printf("Enter 10 elements in ascending order:\n");
    for (i = 0; i < size; i++) {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }
    printf("Enter the number to insert: ");
    scanf("%d", &num);
    for (i = 0; i < size; i++) {
        if (num < a[i]) {
            break;
        }
    }

    for (j = size; j > i; j--) {
        a[j] = a[j - 1];
    }

    a[i] = num;
    size++;  
    
    printf("Array after insertion:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}







// Write a program to insert a number in an array that is already sorted in an ascending order

// #include <stdio.h>
// void main(){
//     int size,num,location;
    
//     int a[50];
//     for(int i=0 ; i<10 ; i++){
//         printf("Enter value for array:");
//         scanf("%d",&a[i]);
//     }
//     printf("Enter a new number:");
//     scanf("%d",&num);

//     for(int i=11 ; i!=-1 ; i--){
        
//         if(a[i]<=num){
//             a[i]=a[i-1];
//         }
//         if(a[i]<num){
//             a[location]=num;
//             i++;
//             break;
//         }
//     }
//     for(int i=0 ; i<11 ; i++){
//         printf("%d ",a[i]);
//     }
// }


