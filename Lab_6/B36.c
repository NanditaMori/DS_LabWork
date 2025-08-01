/*
    B 36.
    Write a program to determine if an input character string is of the form aibi where i >= 1 i.e., Number of ‘a’ should be equal to number of ‘b’.
*/

#include <stdio.h>
char stack[10];
int top = -1;

void push(char x)
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
    int i = 0;
    int countB = 0;
    while (str[i] != '\0')
    {
        if (str[i] == 'a')
        {
            push('a');
        }
        else if (str[i] == 'b')
        {
            countB++;
        }
        i++;
    }
    if(countB == (top+1))
    {
        printf("Valid String");
    }
    else{
        printf("Invalid String!!");
    }
}

int main()
{
    char str[10];
    printf("Enter a string: ");
    scanf("%s", str);
    Recognize(str);
}
