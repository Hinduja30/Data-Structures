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
        printf("Memory not succesfully allocated\n");
        exit(1);
    }
    newNode->data = data;
    newNode->link = NULL;

    return newNode;
}

NODE insert_front(NODE Head, int data)
{
    NODE newNode = create_Node(data);
    if(newNode != NULL)
    {
     newNode->link = Head;   
    }
    return newNode;
}

void display(NODE Head)
{
    if(Head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    printf("HEAD- > ");
    NODE temp = Head;
    while (temp != NULL)
    {
        if(temp->link == NULL)
        {
            printf("%d ",temp->data);
        } 
        else
        {
        printf("%d -> ",temp->data);
        }
        temp = temp->link;
    }
    
    printf(" -> NULL\n");
}

NODE delete_Front(NODE Head)
{
    if(Head == NULL)
    {
        printf("Empty list\n");
        return Head;
    }
    NODE temp = Head;
    Head = temp->link;
    free(temp);
    //printf("\ndeleted element is:%d\n",temp->data);
    
    return Head;
}

NODE Reverse_LinkedList(NODE Head)
{
    NODE newHead = NULL;
    while(Head != NULL)
    {
       int data = Head->data;
       Head = delete_Front(Head);
       newHead = insert_front(newHead,data);
    }
    return newHead;

}

int main()
{
    NODE node = NULL;
    node = insert_front(node , 1);
    node = insert_front(node , 2);
    node = insert_front(node , 3);
    node = insert_front(node , 4);
    node = insert_front(node , 5);
    printf("The list is\n");
    display(node);

    printf("the reversed list is\n");
    node = Reverse_LinkedList(node);
    display(node);
  
    return 0;
}