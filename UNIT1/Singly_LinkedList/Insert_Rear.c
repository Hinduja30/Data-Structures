#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *link;
}*NODE;

NODE create_Node(int data)
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

NODE Insert_rear(NODE Head ,int data)
{
   NODE newNode = create_Node(data);

    if(Head == NULL)
    {
        return newNode;
    }
   NODE temp = Head;
   while(temp->link != NULL)
   {
    temp=temp->link;
   }
   temp->link = newNode; 
   return Head;
}

void display(NODE Head)
{
    if(Head == NULL)
    {
        printf("the list empty\n");
        return;
    }
    NODE temp = Head;
    printf("HEAD -> ");
    while(temp != NULL){
    if(temp->link == NULL)
    {
        printf("%d",temp->data);
    }
    else
    {
        printf("%d -> ",temp->data);
    }
    temp = temp->link;
}
printf(" -> NULL\n");
}
int main()
{
    NODE node= NULL;
    node = Insert_rear(node , 4);
    node = Insert_rear(node, 6);
    display(node);

    return 0;
}