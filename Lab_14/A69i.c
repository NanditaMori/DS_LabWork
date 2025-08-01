/*69. Write a menu driven program to implement following operations on the circular
linked list.
• Insert a node at the front of the linked list.
• Delete a node from specified position.
• Insert a node at the end of the linked list.
• Display all nodes.*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};

void insertAtFirst(int x, struct node **first, struct node **last)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->info = x;
    if (*first == NULL)
    {
        newnode->link = newnode;
        *first = newnode;
        *last = newnode;
    }
    else
    {
        newnode->link = *first;
        (*last)->link = newnode;
        *first = newnode;
    }
}

void display(struct node *first)
{
    if(first == NULL)
    {
        printf("Your linked list is empty:");
        return;
    }
    struct node *save = first;
    printf("[");

    do {
        printf("%d ", save->info);
        save = save->link;
    } while (save != first);

    printf("]\n");
}

void insertAtEnd(int x, struct node **first, struct node **last)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->info = x;
    if (*first == NULL)
    {
        newnode->link = newnode;
        *first = newnode;
        *last = newnode;
    }
    else
    {
        newnode->link = *first;
        (*last)->link = newnode;
        *last = newnode;
    }
}

// below written code is also correct
/*
void display(struct node *first,struct node *last)
{
    struct node *save = first;
    // save = save->link;
    printf("[");
    while(save != last)
    {
        printf("%d ",save->info);
        save = save->link;
    }
    printf("%d ",save->info);
    printf("] \n");
}
    */

void deleteAtPosition(int index, struct node **first)
{
    if (*first == NULL)
    {
        printf("Your linked list is already empty!!");
    }
    else if (index == 0)
    {
        struct node *temp = (*first);
        *first = (*first)->link;
        free(temp); 
    }
    else
    {
        struct node *pred = *first;
        struct node *save = pred->link;
        int count = 1;
        
        while (count < index || save != *first)
        {
            save = save->link;
            pred = pred->link;
            count++;
        }
        pred->link = save->link;
        free(save);
    }
}

int main()
{
    struct node *first = NULL;
    struct node *last = NULL;
    int choice;
    while (1)
    {
        printf("Enter 1 for INSERTION AT FIRST POSIION\n Enter 2 for DISPLAY\n Enter 1 for INSERTION AT LAST POSIION\n  Enter 4 FOR DELETION\n Enter your choice:\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            int x;
            printf("Enter a number to be inserted:");
            scanf("%d", &x);
            insertAtFirst(x, &first, &last);
            break;
        }
        case 2:
        {
            display(first);
            break;
        }

        case 3:
        {
            int x;
            printf("Enter a number to be inserted:");
            scanf("%d", &x);
            insertAtEnd(x, &first, &last);
            break;
        }
        case 4:
        {
            int index;
            printf("Enter index of the element to be deleted:");
            scanf("%d", &index);
            deleteAtPosition(index, &first);
            break;
        }
        default:
        {
            return 0;
        }
        }
    }
}