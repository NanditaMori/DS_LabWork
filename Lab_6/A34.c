/* 34.
    Write a menu driven program to implement following operations on the Stack using an Array
    i)PUSH, POP, DISPLAY
    ii)PEEP, CHANGE
*/

#include <stdio.h>

int stack[10];
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
        printf("Stack underflow!!");
        return 0;
    }
    top--;
    return (stack[top + 1]);
}

int peep(int i)
{
    if (top - i + 1 <= -1)
    {
        printf("Stack underflow!!");
        return 0;
    }
    return stack[top - i + 1];
}

void change(int i, int x)
{
    if (top - i + 1 <= -1)
    {
        printf("Stack underflow!!");
        return;
    }
    stack[top - i + 1] = x;
    return;
}

void display()
{
    if (top < 0)
    {
        printf("Stack underflow");
        return;
    }
    printf("[ ");
    for (int i = top; i >= 0; i--)
    {
        printf("%d ", stack[i]);
    }
    printf("] \n");
}

int main()
{
    while (1)
    {
        int choice;
        printf("Enter 1 to push an element \nEnter 2 to POP an element \nEnter 3 to DISPLAY the stack \nEnter 4 to PEEP an element \nEnter 5 to CHANGE an element \n  Enter your choice: \n");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
            {
                int x;
                printf("Enter the element to be pushed: ");
                scanf("%d", &x);
                push(x);
                break;
            }
            case 2:
            {
                int poppedElement = pop();
                printf("Popped element: %d\n", poppedElement);
                break;
            }
            case 3:
            {
                display();
                break;
            }
            case 4:
            {
                int i;
                printf("Enter the address of the element to be peeped: ");
                scanf("%d",&i);
                int peepedElement = peep(i);
                printf("The element on %dth position is %d \n\n",i,peepedElement);
                break;
            }
            case 5:
            {
                int i,x;
                printf("Enter position on which the number is to be changed: ");
                scanf("%d",&i);
                printf("Enter the new number:");
                scanf("%d",&x);
                change(i,x);
                break;
            }
            default:
            {
                return 0;
            }
        }
    }
}