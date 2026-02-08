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

        return newNode;
    
}

DNODE Insert_Front(DNODE Head , int data)
{
    DNODE newNode = Create_DNode(data);
    newNode->right = Head;
    if(Head != NULL){
    Head->left = newNode;
    }
    return newNode;
}

DNODE Delete_Front(DNODE Head)
{
    if(Head == NULL)
    {
        printf("The list is empty\n");
        return Head;
    }
    if(Head->right == NULL)
    {
        printf("the deleted node is %d ", Head->data);
        free(Head);
        return NULL;
    }
        DNODE temp = Head;
        Head = Head->right;
        Head->left = NULL;
        printf("the deleted node is %d\n",temp->data);
        free(temp);
        return Head;
}
void Display(DNODE Head)
{
    if(Head == NULL)
    {
        printf("The list is empty\n");
        return;
    }
    DNODE curr = Head;
    printf("HEAD -> ");
    while(curr != NULL)
    {
       printf("%d -> ",curr->data);
       curr = curr->right;
    }
    printf("NULL\n");
}

int main()
{
  DNODE node = NULL;
    node = Insert_Front(node , 1);
    node = Insert_Front(node , 2);
    node = Insert_Front(node , 3);
    node = Insert_Front(node , 4);
    node = Insert_Front(node , 5);
    Display(node);
    node = Delete_Front(node);
    Display(node);   
}