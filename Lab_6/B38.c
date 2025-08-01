/*
    B 38.
    Removing starts from a string Problem
    You are given a string s, which contains stars *. In one operation, you can: Choose a star in s. Remove the closest non-star character to its left, as well as remove the star itself. Return the string after all stars have been removed.
    Note :
•The input will be generated such that the operation is always possible.
•It can be shown that the resulting string will always be unique.
Sample Example-1:
Input: s = "leet**cod*e".
Output: "lecoe"

Sample Example-2:
Input: s = "erase*****"
Output: ""

*/

#include <stdio.h>
#define size 20

char stack[size];
int top = -1;

void push(char x)
{
    if (top >= size)
    {
        printf("Stack Overflow!!");
        return;
    }
    top++;
    stack[top] = x;
}

char pop()
{
    if (top < 0)
    {
        printf("Stack underflow!!");
        return 0;
    }
    top--;
    return (stack[top + 1]);
}

void display()
{
    printf("New string is:");
    for (int i = 0; i <= top; i++)
    {
        printf("%c", stack[i]);
    }
    printf("\n");
}

void Remove(char *str)
{
    int i=0;
    while(str[i]!= '\0')
    {
        if(str[i]=='*')
        {
            pop();
        }
        else{
            push(str[i]);
        }
        i++;
    }
    display();
}

void main()
{
    char str[20];
    printf("Enter a string:\n");
    scanf("%s",str);
    Remove(str);
}