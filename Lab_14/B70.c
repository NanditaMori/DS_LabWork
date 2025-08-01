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
    if(*first == NULL)
    {
        printf("Your list is empty!! \n");
        return;
    }
    else{
        int counter=0,counter1=0;
        struct node *save = *first;
        do{
            save=save->link;
            counter++;
        }
        while(save != *first);
        printf("Total elements = %d\n",counter);

        save = *first;
        while(counter1 <= counter/2)
        {
            save = save->link;
            counter1++;
        }
        *last = save;
        (*last)->link=*first;

        *first1 = save->link;
        while(counter1 <= counter)
        {
            save = save->link;
            counter1++;
        }
        *last1 = save;
        (*last)->link = *first1;

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