#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *link;
}*NODE;

NODE create_Node(int data)
{
    NODE newNode = malloc(sizeof(struct Node));

    if(newNode == NULL)
    {
        printf("Memory not allocated succesfully");
    }
    newNode->data = data;
    newNode->link = NULL;

    return newNode;
}

NODE insert_Front(NODE Head , int data)
{
    NODE newNode = create_Node(data);
    if(newNode != NULL)
    {
        newNode->link = Head;
    }
    return newNode;
}

NODE Insert_inOrder(NODE Head , int data)
{
    NODE newNode = create_Node(data);
    NODE curr = Head;

    if(newNode == NULL)
    {
        return Head;
    }
    if(Head == NULL || Head->data <= data)
    {
        return(insert_Front(Head,data)) ;
    }
    while(curr->link != NULL && curr->link->data > data)
    {
        curr = curr->link;
    }
    newNode->link = curr->link;
    curr->link = newNode;

    return Head;
}

void display(NODE Head)
{
    if(Head == NULL)
    {
        printf("Empty list\n");
        return;
    }
    else
    {
        printf("HEAD -> ");
        NODE temp = Head;
        while(temp != NULL)
        {
            if(temp->link == NULL){
                printf("%d",temp->data);
            }
            else
            {
                printf("%d -> ",temp->data);
            }
            temp = temp -> link;
        }
        printf("-> NULL\n");
    }

}

int main()
{
    NODE node = NULL;
     
    node = insert_Front(node,1);
    node = insert_Front(node,2);
    node = insert_Front(node,3);
    node = insert_Front(node,6);
    node = insert_Front(node,7);
    
    display(node);


    node = Insert_inOrder(node,5);
    display(node);

    return 0;
}