/*
    A 46.Write a menu driven program to implement following operations on the Queue using an Array
•ENQUEUE
•DEQUEUE
•DISPLAY
*/

#include <stdio.h>
# define size 10

int q[size];
int f=-1;
int r=-1;

void Enqueue(int y)
{
    if(r >= size)
    {
        printf("Queue Overflow!! \n");
        return;
    }
    r++;
    q[r] = y;
    if(f == -1)
    {
        f=1;
    }
    return;
    
}

int Dequeue()
{
    if(f==-1)
    {
        printf("Stack Underflow!! \n");
        return 0;
    }
    int y = q[f];
    if(f == r)
    {
        f =0 ;
        r = 0;
        f = f+1;
    }
    return y;
}

void Display()
{
    if(f == -1)
    {
        printf("Stack Underflow!! \n");
        return;
    }
    printf("[ ");
    for(int i=f ; i<=r ; i++)
    {
        printf("%d ",q[i]);
    }
    printf("] \n");
}

int main()
{
    while (1)
    {
        int choice;
        printf("Enter your choice: \n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
            {
                int y;
                printf("Enter a value to be INSERTED in queue: \n");
                scanf("%d",&y);
                Enqueue(y);
                break;
            }
            case 2:
            {
                int y = Dequeue();
                printf("Dequeued element is %d \n",y);
                break;
            }
            case 3:
            {
                Display();
                break;
            }
            default:
            {
                return 0;
            }
        }
    }
    
}
