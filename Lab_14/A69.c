/*69. Write a menu driven program to implement following operations on the circular
linked list.
• Insert a node at the front of the linked list.
• Delete a node from specified position.
• Insert a node at the end of the linked list.
• Display all nodes.*/

#include <stdio.h>
#include <stdlib.h>

struct node{
    int info;
    struct node *link;
};

struct node * insertAtFirst(int x,struct node *first,struct node *last)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->info = x;
    if(first == NULL)
    {
        newnode->link= newnode;
        first = newnode;
        last = newnode;
    }
    else
    {
        newnode->link = first;
        last->link = newnode;
    }
    return newnode;
}

void display(struct node *first,struct node *last)
{
    struct node *save = first;
    save = save->link;
    printf("[");
    while(save != first)
    {
        printf("%d ",save->info);
        save = save->link;
    }
    printf("] \n");
}

int main()
{
    struct node *first = NULL;
    struct node *last = NULL;
    int choice;
    while(1)
    {
        printf("Enter 1 for INSERTION AT FIRST POSIION\n Enter 2 for DISPLAY\n Enter your choice:\n");
        scanf("%d",&choice);
        
        switch(choice)
        {
            case 1:
            {
                int x;
                printf("Enter a number to be inserted:");
                scanf("%d",&x);
                first = insertAtFirst(x,first,last);
                break;
            }
            case 2:
            {
                display(first,last);
                break;
            }
            default :
            {
                return 0;
            }
        }
    }
}