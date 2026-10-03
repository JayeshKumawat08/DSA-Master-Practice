#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int value){
    struct Node* newNode ;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter  the Element to be pushed:");
    scanf("%d",&value);
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    printf("Element pushed: %d\n", value);
}

void pop(){
    if(top==NULL){
        printf("Stack is Underflow\n");
        return;
    }
    struct Node* temp;
    temp =  top;
    printf("Element Popped: %d\n",top->data);
    top =  top->next;
    free(temp);
}

void peek(){
    if(top == NULL){
        printf("Stack is Empty\n");
        return;
    }
    printf("Top Element is: %d\n", top->data);

}

void display(){
    if(top == NULL){
        printf("Stack is empty\n");
        return;
    }
    struct Node* temp;
    temp = top;
    printf("Stack Elements are:\n");
    while(temp != NULL){
        printf("%d\n",temp->data);
        temp =  temp->next;
    }
}

int main(){
    int choice, value;
    while(1){
        printf("1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\n");
        printf("Enter Your Choice:\n");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                push(value);break;
            case 2:
                pop();break;
            case 3:
                peek();break;
            case 4:
                display();break;
            case 5:
                return 0;
                break;
            default:
                printf("Invalid Choice\n");
        }
    }
}