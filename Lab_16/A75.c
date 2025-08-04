/*
    A 75.Write a menu driven program to implement Binary Search root (BST) & perform following operations:
•Insert a node
•Delete a node
•Search a node
•Preorder Traversal
•Postorder Traversal
•Inorder Traversal

*/

#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node *lptr;
    struct node *rptr;
};

struct node * insertNode(int x , struct node * root)
{
    if(root == NULL)
    {
        root->info = x;
        root->lptr = NULL;
        root->rptr = NULL;
        return root;
    }
    else if(x < root->info)
    {
        struct node * save = (struct node *)malloc (sizeof(struct node));
        if(root->lptr == NULL)
        {
            save->info = x;
            save ->lptr = NULL;
            save->rptr = NULL;
            root->lptr = save;
            return root;
        }    
        else{
            root = save;
            return insertNode(x , root);
        }
    }
    else{
        struct node * save = (struct node *)malloc(sizeof(struct node));
        if(root->rptr == NULL)
        {
            save->info = x;
            save ->lptr = NULL;
            save->rptr = NULL;
            root->rptr = save;
            return root;
        }
        else{
            root = save;
            return insertNode(x,root);
        }
    }
}

int search(struct node *root , int x)
{
    if(root == NULL || root->info == x)
    {
        printf("Tree is Empty!! \n");
        return 0;
    }
    if(x > root->info)
    {
        return search(root->rptr , x);
    }
    else{
        return search(root->lptr , x);
    }
}

void PreorderTraversal(struct node *root)
{
    if(root == NULL)
    {
        printf("Tree is Empty!! \n");
        return;
    }
    else{
        printf("%d ",root->info);
    }
    if(root->lptr != NULL)
    {
        PreorderTraversal(root->lptr);
    }
    if(root->rptr != NULL)
    {
        PreorderTraversal(root->rptr);
    }
}

void InorderTraversal(struct node *root)
{
    if(root == NULL)
    {
        printf("Tree is Empty!! \n");
        return;
    }
    if(root->lptr != NULL)
    {
        InorderTraversal(root->lptr);
    }
    printf("%d ",root->info);
    if(root->rptr != NULL)
    {
        InorderTraversal(root->rptr);
    }
}

void PostOrderTraversal(struct node *root)
{
    if(root == NULL)
    {
        printf("Tree is Empty!! \n");
        return;
    }
     if(root->lptr != NULL)
    {
        InorderTraversal(root->lptr);
    }
    
    if(root->rptr != NULL)
    {
        InorderTraversal(root->rptr);
    }
    printf("%d ",root->info);
}

int main()
{
    struct node * root = NULL;
    while(1)
    {
        int choice;

        printf("Enter your choice:");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
            {
                int x;
                printf("Enter a value to be inserted: \n");
                scanf("%d",&x);
                root = insertNode(x,root);
            }
        }
    }
}