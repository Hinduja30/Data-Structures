#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int sid;
    struct node *prev,*next;
}*NODE;


NODE createNode (int value) {
NODE newNode = (NODE) malloc (sizeof (struct node));
if (newNode == NULL) {
printf("Memory allocation failed\n");
return NULL;
}
newNode->sid = value;
newNode->prev = newNode->next = NULL;
return newNode;
}

void insertFront(NODE *head, int value) {
    NODE newNode = createNode(value);
    if (newNode == NULL) return;
    if (*head == NULL) {
        *head = newNode;
    } else {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

void insertRear(NODE *head, int value) {
    NODE newNode = createNode(value);
    if (newNode == NULL) return;
    if (*head == NULL) {
        *head = newNode;
    } else {
        NODE temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void deleteRear(NODE *head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    NODE temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    } else {
        *head = NULL;
    }
    free(temp);
}

void traverse(NODE head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("Forward: ");
    NODE temp = head;
    while (temp != NULL) {
        printf("%d ", temp->sid);
        temp = temp->next;
    }
    printf("\nBackward: ");
    temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    while (temp != NULL) {
        printf("%d ", temp->sid);
        temp = temp->prev;
    }
    printf("\n");
}

int main() {
    NODE head = NULL;
    int choice, value;
    while (1) {
        printf("\n1. Insert at front\n2. Insert at rear\n3. Delete at rear\n4. Traverse\n5. Exit\nEnter choice: ");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("Enter value: ");
            scanf("%d", &value);
            insertFront(&head, value);
            traverse(head);
        } else if (choice == 2) {
            printf("Enter value: ");
            scanf("%d", &value);
            insertRear(&head, value);
            traverse(head);
        } else if (choice == 3) {
            deleteRear(&head);
            traverse(head);
        } else if (choice == 4) {
            traverse(head);
        } else if (choice == 5) {
            exit(0);
        } else {
            printf("Invalid choice\n");
        }
    }
    return 0;
}
