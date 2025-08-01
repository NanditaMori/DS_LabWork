//61. Write a program to implement queue using singly linked list.

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *link;
};

struct node * insertNode(int x,struct node *first)
{ // insert at end
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->info = x;
    newnode->link = NULL;
    if (first == NULL)
    {
        first = newnode;
    }
    else
    {
        struct node *save;
        save = first;
        while (save->link != NULL)
        {
            save = save->link;
        }
        save->link = newnode;
    }
    return first;
}

struct node * deleteNode(struct node *first)
{
    if (first == NULL)
    {
        printf("Your linked list is already empty!!\n");
    }
    else
    {
        struct node *newnode = first;
        first = first->link;
        free(newnode);
        printf("First node deleted.\n");
    }
    return first;
}

void display(struct node *first)
{
    struct node *save;
    save = first;
    if (save == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    printf("[");
    while (save != NULL)
    {
        printf("%d ", save->info);
        save = save->link;
    }
    printf("] \n");
}

 
int main()
{
    struct node *first = NULL;
    while (1)
    {
        int choice;
        printf("\n Enter 1 for INSERTION OF NODE \n Enter 2 for DELETION OF NODE \n Enter 3 for DISPLAY OF ELEMENTS \n Select a number from 1-8: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            int x;
            printf("Enter a number to be inserted: ");
            scanf("%d", &x);
            first = insertNode(x,first);
            break;
        }
        case 2:
        {
            first = deleteNode(first);
            break;
        }
        case 3:
        {
            display(first);
            break;
        }
       
        default:
        {
           return 0;
        }
    }
    }
   
}