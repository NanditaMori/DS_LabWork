/*
    A35.
    How stack can be used to recognize strings aca, bcb, abcba, abbcbba? Write a program to solve the above problem.
*/

#include<stdio.h>
int stack[20];
int top = -1;

void push(int x)
{
    if (top >= 10)
    {
        printf("Stack Overflow!!");
        return;
    }
    top++;
    stack[top] = x;
}

int pop()
{
    if (top < 0)
    {
        printf("Stack underflow");
        return 0;
    }
    top--;
    return (stack[top + 1]);
}


void Recognize(char *str)
{
    int i=0;
    top=0;
    stack[top] = 'c';
    char next = str[i];
    while(next != 'c')
    {
        if (next == ' ')
        {
            printf("Invalid String");
            return;
        }
        else{
            push(next);
            next = str[++i];        
        }
    }
    i++;
    while(stack[top] != 'c' && str[i]!= '\0')
    {
        int x;
        next = str[i];
        x = pop();

        if(next != x)
        {
            printf("Invalid String!!");
            return;
        }
        i++;
    }
    if(str[i] == '\0')
    {
        printf("Valid String \n");
    }
    else{
        printf("Invalid String \n");
    }
    return;
    
}

int main()
{
    char str[20];
    printf("Enter a string: ");
    scanf("%s",str);
    Recognize(str);
}