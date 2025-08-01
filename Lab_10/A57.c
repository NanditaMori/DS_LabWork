// 57.Write a menu driven program to implement following operations on the singly linked list.

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *link;
};

struct node *first = NULL;

void insertAtFirst(int x)
{ // insert at first
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->info = x;
    newnode->link = first;
    first = newnode;
}

void insertAtEnd(int x)
{ // insert at end
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->info = x;
    newnode->link = NULL;
    if (first == NULL)
    {
        first = newnode;
    }
    else
    {
        struct node *save;
        save = first;
        while (save->link != NULL)
        {
            save = save->link;
        }
        save->link = newnode;
    }
}

void display()
{
    struct node *save;
    save = first;
    printf("[");
    while (save != NULL)
    {
        printf("%d ", save->info);
        save = save->link; // save++
    }
    printf("] \n");
}

void counter()
{
    int count = 0;
    struct node *save;
    save = first;
    while (save != NULL)
    {
        count++;
        save = save->link;
    }
    printf("Number of elements in linked list are: %d", count);
}

void deleteFirst()
{
    if (first == NULL)
    {
        printf("Your linked list is already empty!!");
    }
    else
    {
        struct node *newnode = first;
        first = first->link;
        free(newnode);
    }
}
void deleteLast()
{
        if(first == NULL){
            printf("Your linked list is already empty!!");
        }
        else if(first->link == NULL){
            struct node *newnode = first;
            first = first->link;
            free(newnode);
        }
        else{
            struct node *save;
            struct node *pred = NULL;
            save = first;
            while (save->link != NULL)
            {
                pred = save;
                save = save->link;
            }
            pred->link = NULL;
            free(save);
        }
}

void deleteAtPosition()
{
    int position,count=0;
    printf("Enter an index of which the node is to be deleted: ");
    scanf("%d",&position);
    if(first == NULL)
    {
        printf("Your linked list is already empty!!");

    }
    else
    {
        struct node* save = first;
        struct node *pred = NULL;
        while(save->link != NULL && count != position)
        {
            pred = save;
            save=save->link;
            count++;
        }
        pred->link = save->link;
        free(save);
    }

}


int main()
{

    while (1)
    {

        int choice;
        printf("\n Enter 1 for INSERTION AT FIRST POSITION \n Enter 2 INSERTION AT LAST POSITION \n Enter 3 for DISPLAY OF ELEMENTS \n Enter 4 to COUNT NUMBER OF ELEMENTS \n Enter 5 for DELETION OF FIRST ELEMENT \n Enter 6 for DELETION OF LAST ELEMENT \n Enter 7 for DELETION OF ELEMENT FROM SPECIFIC POSITION \n  Enter 8 to EXIT \n Select a number from 1-8:");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
            {
                int x;
                printf("Enter a number to be inserted:");
                scanf("%d", &x);
                insertAtFirst(x);
                break;
            }
            case 2:
            {
                int x;
                printf("Enter a number to be inserted:");
                scanf("%d", &x);
                insertAtEnd(x);
                break;
            }
            case 3:
            {
                display();
                break;
            }
            case 4:
            {
                counter();
                break;
            }
            case 5:
            {
                deleteFirst();
                break;
            }
            case 6:
            {
                deleteLast();
                break;
            }
            case 7:
            {
                deleteAtPosition();
                break;
            }
            default :
            {
                return 0;
            
            }
        }
        
    }
}
