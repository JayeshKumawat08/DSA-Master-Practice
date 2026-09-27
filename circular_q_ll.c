#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void enqueue(int value){
    struct Node* newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data =  value;
    newNode-> next = NULL;
    if(front == NULL && rear == NULL){
        front = rear = newNode;
        rear -> next = front;

    }else{
        rear->next = newNode;
        rear = newNode;
        rear->next = front;
    }
    printf("Element Inserted: %d\n", value);
}

void dequeue(){
    if(front == NULL && rear == NULL){
        printf("Queue is Underflow\n");
        return;
    }else{
        struct Node* temp;
        temp = front;
        if(front == rear){
            printf("Dequeued element is %d\n", front->data);
            front = rear = NULL;
        }else{
            printf("Dequeued element is %d\n", front->data);
            front = front-> next;
            rear->next = front;
            free(temp);
        }
    }
}

void display(){
    struct Node* temp;
    if(front==NULL && rear == NULL){
        printf("Queue is Empty\n");
        return;
    }else{
        temp = front;
        printf("Queue is:\n");

        do{
            printf("%d,\n",temp->data);
            temp = temp-> next;
        }
        while(temp != front);
        printf("\n");
    }
}

int main(){
    int choice, value;
    while(1){
        printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit");
    printf("\nEnter Your Choice:");
    scanf("%d",&choice);

    switch(choice){

        case 1:
            printf("Enter the Value to be Inserted:");
            scanf("%d",&value);
            enqueue(value);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            return 0;
            break;
        default:
            printf("Invalid Choice/n");
    }

    }
    
}
