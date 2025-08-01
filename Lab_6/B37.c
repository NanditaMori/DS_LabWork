/*

B 37.Valid Parenthesis Problem
Chef has a string which contains only the characters '{', '}', '[', ']', '(' and ')'.
Now Chef wants to know if the given string is balanced or not.
If is balanced then print 1, otherwise print 0.
A balanced parenthesis string is defined as follows:
•The empty string is balanced
•If P is balanced then (P), {P}, [P] is also balanced
•if P and Q are balanced PQ is also balanced
•"([])", "({})[()]" are balanced parenthesis strings
•"([{]})", "())" are not balanced.

*/
#include <stdio.h>
char stack[20];
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

int pop()
{
    if (top < 0)
    {
        printf("Stack underflow!! \n");
        return 0;
    }
    top--;
    return (stack[top + 1]);
}

int Balanced(char *str)
{
    int i=0;
    // if(str == "")
    // {
    //     return 1;
    // }
    
    while(str[i] != '\0')
    {
        if(str[i]=='(' || str[i]=='[' || str[i]=='{')
        {
            push(str[i]);
            
        }
        else if(str[i]==')' || str[i]==']' || str[i]=='}')
        {
            // if(top == -1){
            //     printf("Stack is empty");
            //     return 0;
            // }
            char ch = pop();
            
           if(!( (str[i]==')' && ch == '(') || (str[i]==']' && ch == '[') || (str[i]=='}' && ch == '{') )){
                printf("check");
                return 0;
            }
        }
        i++;
    }
    return 1;
}

int main()
{
    int testCase;
    printf("Enter number of test cases: ");
    scanf("%d",&testCase);

    for(int i=0 ; i<testCase ; i++)
    {
        char str[20];
        printf("Enter the string: \n");
        scanf("%s",str);
        int isBalanced = Balanced(str) ;
        printf("%d \n",isBalanced);
    }
}