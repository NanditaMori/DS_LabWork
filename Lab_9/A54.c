// 54. WAP to check whether the string is Palindrome or not using Pointer.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void main(){
    char str[20],newStr[20];
    printf("Enter a string:");
    scanf("%s",str);
    char *ptr = str;
    char *ptr1 = newStr;
    for(int i=strlen(str)-1; i>=0 ; i--){
        for(int j=0 ; j<strlen(str) ; j++){
            *(ptr1+j)=*(ptr+i);
        }
    }
    if(*ptr1 == *ptr){
        printf("string is pallindrome");
    }
    else{
        printf("String is not pallindrome");
    }
}