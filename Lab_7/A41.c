/*
    41.Write a program to convert infix notation to postfix notation using stack.
*/

#include <stdio.h>
#include <string.h>
# define size 20

int stack[size];
int top = -1;

void push(char x)
{
    if (top >= 20)
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
        printf("Stack underflow!! \n");
        return 0;
    }
    top--;
    return (stack[top + 1]);
}

int InputPre(char next)
{
    if(next == '+' || next == '-')
    {
        return 1;
    }
    else if(next == '*' || next == '/' || next == '%')
    {
        return 3;
    }
    else if(next == '^')
    {
        return 6;
    }
    else if(next == '(')
    {
        return 9;
    }
    else if(next == ')')
    {
        return 0;
    }
    else{
        return 7;
    }
}

int StackPre(char next)
{
    if(next == '+' || next == '-')
    {
        return 2;
    }
    else if(next == '*' || next == '/' || next == '%')
    {
        return 4;
    }
    else if(next == '^')
    {
        return 5;
    }
    else if(next == '(')
    {
        return 0;
    }
    else{
        return 8;
    }
}

int rankof(char next)
{
    if(next == '+' || next == '-' || next == '*'||next == '/' || next == '^' || next == '%')
    {
        return -1;
    }
    else{
        return 1;
    }
}

void revpol(char * infix)
{
    
    top++;
    stack[top] = '(';
    char polish[20];
    int rank = 0;
    int i = -1;
    int j = -1;
    char next = infix[++j];
    while (next != '\0')
    {
        if(top < 0)
        {
            printf("Inavlid String !! Stack empty \n");
            return;
        }
        while(StackPre(stack[top]) > InputPre(next))
        {
            char temp = pop();
            polish[++i] = temp;
            rank = rank + rankof(temp);
            if(rank < 1)
            {
                printf("Invalid String!! rank is low \n");
                break;
            }
        }
        if(StackPre(stack[top]) != InputPre(next))
        {
            push(next);
        }
        else{
            pop();
        }
        next = infix[++j];
    }
    polish[++i] = '\0';
    if(top != -1 || rank !=1)
    {
        printf("Invalid String!! top or Rank invalid");
    }
    else{
        printf("Valid String!!");
        printf("Postfix string is :%s",polish);
    }

}

void main()
{
    char infix[20];
    printf("Enter a string:");
    scanf("%s",infix);
    strcat(infix,")");
    revpol(infix);
}