/*
59.Write a program to remove the duplicates nodes from given sorted Linked List.
•Input: 1 → 1 → 6 → 13 → 13 → 13 → 27 → 27
•Output: 1 → 6 → 13 → 27
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};

struct node *insertAtFirst(int x, struct node *first)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->info = x;
    newNode->link = first;
    first = newNode;

    return first;
}

void display(struct node *first)
{
    if (first == NULL)
    {
        printf("Your linked list is empty!! \n");
    }
    else
    {
        struct node *save = first;
        printf("[");
        while (save->link != NULL)
        {
            printf("%d ", save->info);
            save = save->link;
        }
        printf("%d", save->info);
        printf("]\n");
    }
}

struct node *deleteDuplicate(struct node *first)
{
    if (first == NULL)
    {
        printf("your linked list is already empty!!");
        return first;
    }

    else
    {
        struct node *prev = first;
        struct node *next = prev->link;
        while (next != NULL)
        {
            if (prev->info == next->info)
            {
                prev->link = next->link;
                struct node *temp = next;
                next = next->link;
                free(temp);
            }
            else{
                prev = next;
                next = next->link;  
            }
        }
    }
    return first;
}

int main()
{
    struct node *first = NULL;

    while (1)
    {
        int choice;
        printf("Enter 1 for INSERT AT FIRST POSITION \nEnter 2 to DISPLAY \nEnter 3 to DELETE DUPLICATE \n Enter your choice:");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            int x;
            printf("Enter a number to be inserted:");
            scanf("%d", &x);
            first = insertAtFirst(x, first);
            break;
        }
        case 2:
        {
            display(first);
            break;
        }
        case 3:
        {
            deleteDuplicate(first);
            break;
        }
        default:
        {
            return 0;
        }
        }
    }
}