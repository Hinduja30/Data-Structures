#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *prev, *next;
}*Node;

Node createNode(int value)
{
    Node nn=(Node)malloc(sizeof(struct node));
    if(nn == NULL)
    {
        printf("Memory not allocated\n");
    }
    nn->data=value;
    nn->prev = nn->next = NULL;

    return nn;
}

Node insert(Node head,int value)
{
    Node nn=createNode(value);
    if(head==NULL)
    {
        return NULL;
    }
    nn->next=head;
    head->prev=nn;
    head==nn;

    return head;
}

node Delete(Node head)
{
    if(head==NULL)
    {
        printf("empty list\n");
        return NULL;
    }
    if(head->next==NULL)
    {
        free(head);
        head=NULL;
        return head;
    }
    Node temp = head;
    while(temp!=NULL)
    {

    }
}
