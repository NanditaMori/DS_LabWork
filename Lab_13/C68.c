/*
    68. Write a program to swap two consecutive nodes in the linked list. Don’t change 
the values of nodes, implement by changing the link of the nodes.
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

struct node * swapConsecutive(struct node *first)
{
    if(first == NULL)
    {
        printf("Your list is Empty!!");
        return first;
    }
    else
    {
        struct node *save = (struct node *)malloc(sizeof(struct node));
        struct node *prev = first;
        struct node *next = prev->link;
        
        prev->link = next->link;
        next->link = prev;
        first = next;
        
        while(prev != NULL && next!= NULL)
        {
        
            save = prev;
            prev = prev->link;
            next = prev->link;
            
            save->link = next;
            prev->link = next->link;
            next->link = prev;
            
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
                first = swapConsecutive(first);
                break;
            }
            default:
            {
                return 0;
            }
        }
    }
    
}