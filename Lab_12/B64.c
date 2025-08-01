//64. Write a program to reverse a linked list
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *link;
};

struct node * INSERTAtFirst(int x,struct node *first)
{ // insert at first
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->info = x;
    newnode->link = first;
    first = newnode;
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

struct node *Reverselist(struct node *FIRST) {
    struct node *next = NULL;
    struct node *current = FIRST;
    struct node *prev = NULL;

    while (current != NULL) {
        next = current->link;
        current->link = prev;
        prev = current;
        current = next;
    }
    return prev;
}

int main()
{
    struct node *first = NULL;
    struct node *first1 = NULL;
    while (1)
    {
        int choice;
        printf("\n Enter 1 for INSERTION \n Enter 2 for REVERSE \n Enter 3 for DISPLAY \n Select a number from 1-3: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            int x;
            printf("Enter a number to be inserted: ");
            scanf("%d", &x);
            first = INSERTAtFirst(x,first);
            break;
        }
        case 2:
        {
           first = Reverselist(first);
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