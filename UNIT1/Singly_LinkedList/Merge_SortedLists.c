#include<stdio.h>
#include<stdlib.h>
#include <stddef.h>

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
        exit(1);
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


NODE Merge_SortedLists(NODE Head1 , NODE Head2)
{
    while(Head2 != NULL)
    {
        int data = Head2->data;
        Head2 = delete_Front(Head2);
        Head1 = Insert_inOrder(Head1 , data);
    }
    return Head1;
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

    NODE node1 = NULL;
     
    node1 = insert_Front(node1,8);
    node1 = insert_Front(node1,9);
    node1 = insert_Front(node1,10);
    node1 = insert_Front(node1,40);
    node1 = insert_Front(node1,50);
    
    display(node1);

    NODE node3 = NULL;
    node3 = Merge_SortedLists( node , node1);
    display(node3);

    return 0;
}