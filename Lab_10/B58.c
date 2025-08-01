// 58.WAP to check whether 2 singly linked lists are same or not.

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

int counter(struct node *first)
{
    int count = 0;
    struct node *save;
    save = first;
    while (save != NULL)
    {
        count++;
        save = save->link;
    }
    return count;
}
void compare(struct node *first, struct node *first1)
{
    int count = counter(first);
    int count1 = counter(first1);
    int sum = 0;
    struct node *save = first;
    struct node *save1 = first1;
    if (count == count1)
    {
        
        while (save != NULL  && save1 != NULL)
        {
            if (save->info != save1->info)
            {
                printf("Both the linked list are same\n");
                break;
            }
            save = save->link;
            save1 = save1->link;
        }
    }
    if (save == NULL && save1 == NULL)
    {
        printf("Both the linked lists are same\n");
    }
    else
    {
        printf("Both the linked lists are different\n");
    }
}

int main()
{
    int choice;
    struct node *first = (struct node *)malloc(sizeof(struct node));
    first = NULL;
    struct node *first1 = (struct node *)malloc(sizeof(struct node));
    first1 = NULL;
    while (1)
    {
        printf("Enter 1 for INSERTION of data\n Enter 2 to DISPLAY data\n Enter 3 to COMPARE data\n Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            int select, x;
            printf("Enter 0 to insert data in 1st linked list \nEnter 10 to enter data in 2nd linked list \n Enter your choice  \n");
            scanf("%d", &select);

            if (select == 0)
            {
                printf("Enter value to be inserted: \n");
                scanf("%d", &x);
                first = insertAtFirst(x, first);
            }
            else
            {
                printf("Enter value to be inserted: \n");
                scanf("%d", &x);
                first1 = insertAtFirst(x, first1);
            }
            break;
        }
        case 2:
        {
            int select, x;
            printf("Enter 0 to display data of 1st linked list \nEnter 10 to display data of 2nd linked list \n Enter your choice \n");
            scanf("%d", &select);
            if (select == 0)
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
            compare(first,first1);
            break;
        }
        default:
        {
            return 0;
        }
        }
    }
}