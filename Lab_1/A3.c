//A3
#include <stdio.h>
void main(){
    char ch;
    printf("Enter a character:");
    scanf("%c",&ch);
    if(ch=='A' || ch=='E'|| ch=='I'||ch=='O' || ch=='U'|| ch=='a'||ch=='e' || ch=='i'|| ch=='o'||ch=='u'){
        printf("%c is vowel",ch);
    }
    else{
        printf("%c is not vowel",ch);
    }
}