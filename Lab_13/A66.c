// 66. Write a program to sort elements of a linked list.

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

struct node *sort(struct node *first)
{
    if (first == NULL)
    {
        printf("Your linked list is empty!!");
        return first;
    }
    else if (first->link == NULL)
    {
        printf("Your list contains only one element!!");
        return first;
    }
    else
    {
        struct node *newnode = NULL;
        struct node *pred = first;
        struct node *save = pred->link;

        while (save != NULL)
        {

            if (pred->info > save->info)
            {
                pred->link = save->link;
                save->link = pred;

                if (newnode == NULL)
                {
                    first = save;
                    newnode = first;
                }
                else
                {
                    newnode->link = save;
                    // newnode = newnode->link;
                }

                // newnode = save;
                // save = pred->link;
                // save = save->link;
                // pred = pred->link;

                // newnode = pred;
                // pred = save;
                // save = save->link;

                save = pred->link;
                if (newnode != NULL)
                    newnode = newnode->link;
            }
            else
            {
                newnode = pred;
                pred = save;
                save = save->link;
            }
        }
        return first;
    }
}

int main()
{
    int choice;
    // struct node *first=(struct node *)malloc(sizeof(struct node));
    struct node *first = NULL;
    while (1)
    {
        printf("\n Enter 1 for INSERTION \n Enter 2 for DSPLAY \n Enter 3 for SORTING \n Select a number from 1-3: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            int x;
            printf("Enter a number to be inserted: ");
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
            first = sort(first);
            break;
        }
        default:
        {
            return 0;
        }
        }
    }
}