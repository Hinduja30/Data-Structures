#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *link;
}*NODE;

NODE create_Node(int data)
{
    NODE newNode = malloc(sizeof(int));

    if(newNode == NULL)
    {
        printf("Memory not allocated succesfully");
    }
    newNode->data = data;
    newNode->link = NULL;

    return newNode;
}

void display_Node(NODE Head)
{
    NODE temp = Head;
    if(Head == NULL)
    {
        printf("The list is empty");
    }

    while(temp != NULL)
    {
        printf("%d ->",temp->data);
    }
    temp = temp->link;
}

int main()
{
    NODE node = NULL;
    create_Node(2);
    create_Node(3);
    display_Node(node);

    return 0;
}