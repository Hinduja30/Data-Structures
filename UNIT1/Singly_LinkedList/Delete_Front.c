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
    
    printf(" -> NULL");
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
    printf("\ndeleted element is:%d\n",temp->data);
   

    return Head;
}

int main()
{
    NODE node = NULL;
    node = insert_front(node , 1);
    node = insert_front(node , 2);
    node = insert_front(node , 3);
    node = insert_front(node , 4);
    node = insert_front(node , 5);

    display(node);

    node = delete_Front(node);
    
    display(node);
  
    return 0;
}