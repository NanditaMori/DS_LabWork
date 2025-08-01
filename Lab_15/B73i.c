
// B73 WAP to delete alternate nodes of a doubly linked list

#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *lptr;
    struct node *rptr;
};

void insertAtFirst(int x,struct node **left,struct node **right)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->info = x;
    newnode->lptr = NULL;

    if(*left == NULL)
    {
        newnode->rptr = NULL;
        *left = newnode;
        *right = newnode;
    }
    else
    {
        newnode->rptr = *left;
        (*left)->lptr = newnode;
        (*left) = newnode;
    }
}

void display(struct node *left)
{
    struct node *save = left;
    printf("[");
    do
    {
        printf("%d ",save->info);
        save = save->rptr;
    }
    while(save != NULL);
    printf("] \n");
}

void insertAtLast(int x,struct node **left,struct node **right)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->info = x;
    newnode->rptr = NULL;

    if(*left == NULL)
    {
        newnode->lptr = NULL;
        *left = newnode;
        *right = newnode;
    }
    else
    {
        (*right)->rptr = newnode;
        newnode->lptr = *right;
        *right = newnode;
    }
}

void deleteAtPosition(int index,struct node **left,struct node **right)
{
    if(*left == NULL)
    {
        printf("Your list is already empty!!");
        return;
    }
    else if(index == 0)
    {
        struct node *save = *left;
        *left = (*left)->rptr;
        (*left)->lptr = NULL;
        free(save);
        return;
    }
    else
    {
        struct node *prev = *left;
        struct node *next = prev->rptr;
        int count = 1;
        while(count<index && next!=NULL)
        {
            prev=prev->rptr;
            next = next->rptr;
            count++;
        }
        prev->rptr = next->rptr;
        next->rptr->lptr = prev;
        free(next);
    }
}

void deleteAlternate(struct node **left, struct node **right)
{
    if (*left == NULL)
    {
        printf("Your linked list is already empty!!\n");
        return;
    }
    struct node *prev = (*left);
    struct node *current = prev->rptr;
    struct node *next = current->rptr;

    while (current != NULL)
    {
        struct node *toDelete = current;

        if (next != NULL)
        {
            next->lptr = prev;
            current = next->rptr;
        }    
        else
        {
            *right = prev;
            current = NULL;
        }
        free(toDelete);
        prev = toDelete->lptr;
        next = toDelete->rptr;
        prev->rptr = next;
    }
}

int main()
{
    struct node *left = NULL;
    struct node *right = NULL;
    while(1)
    {
        int choice;
        printf("Enter 1 for INSERTION AT FIRST \nEnter 2 TO DISPLAY \nEnter 3 for INSERTION AT LAST \nEnter 4 TO DELETE AT POSITION \nEnter 5 TO DELETE AT Alternate POSITION \n Enter your choice: \n");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
        {
            int x;
            printf("Enter a number to be inserted:");
            scanf("%d",&x);
            insertAtFirst(x,&left,&right);
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
            scanf("%d",&x);
            insertAtLast(x,&left,&right);
            break;
        }
        case 4:
        {
            int index;
            printf("Enter the index to be deleted:");
            scanf("%d",&index);
            deleteAtPosition(index,&left,&right);
            break;
        }
        case 5 :
        {
            deleteAlternate(&left,&right);
            break;
        }
        default:
        {
            return 0;
        }
        }
    }
}
