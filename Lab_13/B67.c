/*
    67. WAP to perform given operation in the linked list. There exist a Linked List. Add 
a node that contains the GCD of that two nodes between every pair adjacent 
node of Linked List.
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *link;
};

struct node *insertAtFirst(int x,struct node *first)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->info = x;
    newnode->link = first;
    first = newnode;
    return first;
}

void display(struct node *first)
{
    if(first == NULL)
    {
        printf("Your List is empty!! \n");
        return;
    }
    struct node *save= first;
    printf("[");
    do
    {
        printf("%d ",save->info);
        save = save->link;
    }while(save != NULL);
    printf("] \n");
}

struct node * insertGCD(struct node *first)
{
    if(first == NULL)
    {
        printf("Your List is empty!! \n");
        return first;
    }
    else
    {
        struct node *prev = first;
        struct node *next = prev->link;
        int gcd;
        while(next != NULL)
        {
            int a,b;
            a =  prev->info;
            b = next->info;
            
            for(int i=0 ; i<a || i<b ; i++)
            {
                if(a%i==0 && b%i==0)
                {
                    gcd = i;
                }
            }
            struct node *insert = (struct node *)malloc(sizeof(struct node));
            insert->info = gcd;
            insert->link = next;
            prev->link = insert;
            
            prev = next;
            next = prev->link;
        }
        return first;
    }
}



int main()
{
    struct node *first = NULL;
    int choice;
    while(1)
    {
        printf("Enter your choice: \n");
        scanf("%d",&choice);
        
        switch (choice)
        {
            case 1:
            {
                int x;
                printf("Enter value to be inserted: \n");
                scanf("%d",&x);
                first = insertAtFirst(x,first);
                break;
            }
            case 2:
            {
                display(first);
                break;
            }
            case 3:
            {
                first = insertGCD(first);
                break;
            }
            default:
            {
                return 0;
            }
        }
    }
    
}