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

NODE Insert_rear(NODE Head ,int data)
{
   NODE newNode = create_node(data);

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



NODE Delete_atPos(NODE Head , int pos)
{
    if(Head == NULL)
    {
        return NULL;
    }
    if(pos==0)
    {
        return(delete_Front(Head));
    }
    
    NODE temp = Head;
    int position = 1;
    while(temp != NULL && position < (pos-1))
    {
        temp = temp->link;
        position++;
    }
     if(temp == NULL)
    {
        printf("Out of bound and will be deleted at end\n");
        return(delete_Rear(Head));
    }
    printf("\nthe deleted node is %d\n",temp->link->data);
    NODE curr = temp->link;
    temp->link = curr->link;
    free(curr);
    return Head;
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

    node = Delete_atPos(node , 3 );
    Display(node);

    

    return 0;
}