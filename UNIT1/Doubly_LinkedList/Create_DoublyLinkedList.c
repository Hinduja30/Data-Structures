#include<stdio.h>
#include<stdlib.h>

typedef struct DNode
{
    int data;
    struct DNode *left , *right;
}*DNODE;

DNODE Create_DNode(int data)
{
    DNODE newNode = malloc(sizeof(struct DNode));
    if(newNode == NULL)
    {
        printf("Memory not allocated successfully\n");
        exit(1);
    }
        newNode->data = data;
        newNode->left = newNode->right = NULL;
        printf("The created node is %d\n",newNode->data);
        return newNode;
    
}

int main()
{
    Create_DNode(1);
    Create_DNode(2);
    Create_DNode(3); 
}
