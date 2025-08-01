// 62.WAP to remove duplicate elements from a singly linked list.

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
        printf("Your linked list is already empty!!\n");
        return first;
    }
    else
    {
        struct node *prev = first;

        while (prev != NULL)
        {
            struct node *current = prev;
            struct node *next = prev->link;

            while (next != NULL)
            {
                if (prev->info == next->info)  
                {
                    current->link = next->link;
                    free(next);
                    next = current->link;
                }
                else
                {
                    current = next;
                    next = next->link;
                }
            }
            prev = prev->link;
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
            first = deleteDuplicate(first);
            break;
        }
        default:
        {
            return 0;
        }
        }
    }
}