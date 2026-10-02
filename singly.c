#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node *createNode(int  value){
    struct Node* newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    
    if(newNode == NULL){
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next =  NULL;
    return newNode;
}

void display(struct Node* head){
    if(head == NULL){
        printf("List is empty\n");
        return;
    }
    printf("List Elements are:\n");
    while(head != NULL){
        printf("%d ->",head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void insertatBeginning(struct Node **head, int value){
    struct Node* newNode = createNode(value);
    newNode->next = *head;
    *head = newNode;
}

void insertatEnd(struct Node **head, int value){
    struct Node* newNode = createNode(value);
    if(*head == NULL){
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
        temp->next = newNode;
    }
}

void insertPosition(struct Node **head, int value, int position){
    struct Node* newNode = createNode(value);
    if(position < 0){
        printf("Invalid Position\n");
        return;
    }
    if(position == 0){
        insertatBeginning(head, value);
        return;
    }
    struct Node *temp = *head;

    for(int i = 0; temp!=NULL && i<position-1; i++){
        temp = temp->next;
    }
    if(temp == NULL){
        printf("Position out of bounds\n");
        return;
    }
    struct Node* newNode = createNode(value);
    newNode->next = temp->next;
    temp->next =  newNode;
}

void deleteatBeginning(struct Node **head){
    if(*head == NULL){
        printf("List is Empty\n");
        return;
    }
    struct Node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteatEnd(struct Node **head){
    if(*head == NULL){
        printf("List is  Empty\n");
        return;
    }
    if((*head)->next == NULL){
        free(*head);
        *head = NULL;
        return;
    }
    struct Node *temp = *head;
    while(temp->next->next != NULL){
        temp =  temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

void deletePosition(struct Node **head, int position){
    if(*head == NULL){
        printf("list is empty\n");
        return;
    }
    if(position < 0){
        printf("Invalid Position\n");
        return;
    }
    if(position == 0){
        deleteatBeginning(head);
        return;
    }
    struct Node*temp = *head;
    for(int i = 0; temp != NULL && i<position-1; i++){
        temp = temp->next;
    }
    if(temp == NULL || temp->next == NULL){
        printf("Position out of bounds\n");
        return;
    }
    struct Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);
}

