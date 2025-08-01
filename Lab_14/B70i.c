//70.WAP to split a circular linked list into two halves.

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

    printf("]\n\n");
}


void splitList(struct node **first,struct node **last,struct node **first1,struct node **last1)
{
    struct node *ptr1 = *first;
    struct node *ptr2 = *first;

    while(ptr1->link != *first)
    {
        if(ptr2->link == *first)    //for odd number of elements
        {
            *first1 = ptr1->link;
            ptr1->link = *first;
            *last = ptr1;
            *last1 = ptr2;
            (*last1)->link = *first1;
            break;
        }
        else if(ptr2->link->link == *first)     //for even number of elements
        {
            *first1 = ptr1->link;
            ptr1->link = *first;
            *last = ptr1;
            
            *last1 = ptr2->link;
            (*last1)->link = *first1;
            break;
        }
        ptr1 = ptr1->link;
        ptr2 = ptr2->link->link;
    }
}

int main()
{
    struct node *first = NULL;
    struct node *last = NULL;
    struct node *first1 = NULL;
    struct node *last1 = NULL;
    int choice;
    while (1)
    {
        printf("Enter 1 for INSERTION AT FIRST POSIION \nEnter 2 for DISPLAY \nEnter 3 to SPLIT LIST\n Enter your choice:\n");
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
            int select;
            printf("Enter 1 to display 1st list \nEnter 2 to display 2nd list \n Enter your choice:");
            scanf("%d",&select);
            if(select == 1)
            {
                display(first);
            }
            else
            {
                display(first1);
            }
            break;
        }

        case 3:
        {
            splitList(&first,&last,&first1,&last1);
            
            break;
        }
        default:
        {
            return 0;
        }
        }
    }
}