// 60.Write a program to implement stack using singly linked list.

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *link;
};

struct node *push(int x, struct node *first)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->info = x;
    newNode->link = first;
    first = newNode;
    
    return first;
}

struct node *pop(struct node *first)
{
    if(first == NULL){
        printf("Your linked list is empty!!");
    }
    else{
        struct node *save = first;
        first = first->link;
        return first;
        free(save);
    }
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
        printf("%d",save->info);
        printf("]\n");
        
    }
}
int main()
{
    struct node *first = (struct node *)malloc(sizeof(struct node));
    first = NULL;

    while (1)
    {
        int choice;
        printf("Enter 1 to push an element in the stack \nEnter 2 to pop an element from the stack \nEnter 3 to peep elements in the stack \n Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            int x;
            printf("\nEnter a number to be inserted: ");
            scanf("%d", &x);
            first = push(x, first);
            break;
        }
        case 2:
        {
            first = pop(first);
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