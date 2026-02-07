#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *link;
}*NODE;

NODE create_node(int data)
{
   NODE newNode = malloc(sizeof(struct Node));
   if(newNode == NULL)
   {
    printf("Memory not allocated successfully\n");
    exit(1);
   } 
   newNode->data = data;
   newNode->link = NULL;

   return newNode;
}

NODE Insert_Front(NODE Head , int data)
{
    NODE newNode = create_node(data);
    if(newNode != NULL)
    {
        newNode->link = Head;
    }
    return newNode;
}


void Display(NODE Head)
{
    if(Head == NULL)
    {
        printf("List is Empty\n");
    }
    NODE temp = Head;
    while(temp != NULL)
    {
        if(temp->link == NULL)
        {
            printf("%d\n",temp->data);
        }
        else{
        printf("%d -> ",temp->data);
        }
        temp = temp->link;
    }
}

NODE delete_Rear(NODE Head)
{
    if(Head == NULL)
    {
        printf("The list is Empty\n");
    }
    if(Head->link == NULL)
    {
        printf("deleted %d\n",Head->data);
    }
    NODE temp = Head;
    NODE prev = NULL;
    while(temp -> link != NULL)
    {   
        prev = temp;
        temp = temp-> link;
    }
    printf("deleted Node is %d\n",temp->data);
    prev->link = NULL;
    free(temp);

    return Head;
}

int main()
{
    NODE node = NULL;
    node = Insert_Front(node,1);
    node = Insert_Front(node,2);
    node = Insert_Front(node,3);
    node = Insert_Front(node,4);
    node = Insert_Front(node,5);

    Display(node);

    node = delete_Rear(node);

    Display(node);

    return 0;
}