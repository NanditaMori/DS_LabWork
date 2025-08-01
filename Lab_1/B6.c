//B6
#include <stdio.h>
void main(){
    int sec,min,hour;
    printf("Enter seconds:");
    scanf("%d",&sec);

    hour=sec/3600;
    sec=sec%3600;
    min=sec/60;
    sec=sec%60;

    printf("%d:%d:%d",hour,min,sec);
}