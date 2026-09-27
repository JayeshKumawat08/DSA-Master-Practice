#include<stdio.h>
#define MAX 6

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int value){
    if(front == -1 && rear == -1){
        front = 0;
        rear = 0;
        queue[rear] = value;
    }else if((rear+1)%MAX == front){
        printf("Queue is Overflow\n");
        return;
    }else{
        rear = (rear+1)%MAX;
        queue[rear] = value;
    }
}

int dequeue(){
    if(front == -1 && rear == -1){
        printf("Queue is Underflow\n");
        
    }else if(front == rear){
        printf("Dequeued element is %d\n", queue[front]);
        front = -1;
        rear = -1;
        return queue[front];
    }else{
        printf("Dequeued element is %d\n", queue[front]);
        front = (front+1)%MAX;
        return queue[front];
    }
}

void peek(){
    if(front == -1 && rear == -1){
        printf("Queue is Empty\n");
        return;
    }else{
        printf("Front Element is: %d\n", queue[front]);
    }
}

void display(){
    if(front == -1 && rear == -1){
        printf("Queue is Empty\n");
        return;
    }else{
        printf("Queue Elements are:\n");
        while (front != rear){
            printf("%d\n", queue[front]);
            front = (front+1)%MAX;
        }
        printf("%d\n", queue[front]);
    }
}

int main(){
    int choice, value;
    while(1){
        printf("1.Enqueue\n2.Dequeue\n3.Peek\n4.Display\n5.Exit\n");
        printf("Enter Your Choice:\n");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("Enter the Value to be inserted:");
                scanf("%d",&value);
                enqueue(value);break;
            case 2:
                dequeue();break;
            case 3:
                peek();break;
            case 4:
                display();break;
            case 5:
                return 0;
            default:
                printf("Invalid Choice\n");
        }
    }
}