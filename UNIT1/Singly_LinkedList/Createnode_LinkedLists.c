#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *link;
}*NODE;

NODE create_node(int data)
{
    NODE newNode = malloc(sizeof(int));
    if( newNode == NULL)
    {
        printf("memory not allocated successfully\n");
    }

    newNode->data = data;
    newNode->link = NULL;
    printf("Node is succesfully created and data of node is %d \n",newNode->data);

    return newNode;

}

int main()
{
    create_node(1);
    create_node(2);
}