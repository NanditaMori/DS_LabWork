/*
72.Write a menu driven program to implement following operations on the doubly linked list.
•Insert a node at the front of the linked list.
•Delete a node from specified position.
•Insert a node at the end of the linked list. (Home Work)
•Display all nodes. (Home Work)
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *lptr;
    struct node *rptr;
};

void insertAtFirst(int x, struct node **left, struct node **right)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->info = x;
    newnode->lptr = NULL;
    newnode->rptr = *left;
    if (*left != NULL)
    {
        (*left)->lptr = newnode;
    }
    else
    {
        *right = newnode;
    }
    *left = newnode;
}

void display(struct node *left)
{
    if (left == NULL)
    {
        printf("Your list is empty!!");
    }
    else
    {
        struct node *save = left;
        printf("[");
        do
        {
            printf("%d ", save->info);
            save = save->rptr;
        } while (save != NULL);
        printf("] \n");
    }
}

void insertAtEnd(int x, struct node **left, struct node **right)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->info = x;
    newnode->rptr = NULL;
    if (*left == NULL)
    {
        newnode->lptr = NULL;
    }
    else
    {
        (*right)->rptr = newnode;
        newnode->lptr = *right;
        *right = newnode;
    }
}

void deleteAtPosition(int index, struct node **left, struct node **right)
{
    if (left == NULL)
    {
        printf("Your list is already empty!!");
    }
    else
    {
        int count = 0;
        struct node *save = *left;
        struct node *next = save->rptr;
        struct node *pred = NULL;
        while (save != NULL || count < index)
        {
            pred = save;
            save = save->rptr;
            next = next->rptr;
            count++;
        }
        next->lptr = pred->rptr;
        pred->rptr = next;
        free(save);
    }
}

int main()
{
    struct node *left = NULL;
    struct node *right = NULL;
    int choice;
    while (1)
    {
        printf("Enter 1 for INSERTION AT FIRST POSIION \nEnter 2 for DISPLAY \nEnter 3 for INSERTION AT LAST POSIION \nEnter 4 FOR DELETION\n Enter your choice: \n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            int x;
            printf("Enter a number to be inserted:");
            scanf("%d", &x);
            insertAtFirst(x, &left, &right);
            break;
        }
        case 2:
        {
            display(left);
            break;
        }
        case 3:
        {
            int x;
            printf("Enter a number to be inserted:");
            scanf("%d", &x);
            insertAtEnd(x, &left, &right);
            break;
        }
        case 4:
        {
            int index;
            printf("Enter index of the element to be deleted:");
            scanf("%d", &index);
            deleteAtPosition(index, &left, &right);
            break;
        }
        default:
        {
            return 0;
        }
        }
    }
}