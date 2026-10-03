#include<stdio.h>
#define MAX 100

int Stack[MAX];
int top = -1;

//push operation
void push(int value) {
    
    if (top >= MAX - 1){
        printf("Stack is Overflow\n");
    }
    printf("Enter the Element to be pushed: ");
    scanf("%d", &value);
    top++;
    Stack[top] = value;
    printf("Element pushed: %d\n", value);  
}
 void pop(){
    if(top == -1){
        printf("Stack is Underflow\n");
        return;
    }
    printf("Element popped: %d\n", Stack[top]);
    top--;
}

void peek(){
    if(top == -1){
        printf("Stack is Empty\n");
        return;
    
    }
    printf("Top element is: %d\n", Stack[top]);
}

void display(){
    if(top == -1){
        printf("Stack is Empty\n");
        return;
    }
    printf("Stack Elements are:\n");
    for(int i = top; i>=0; i--){
        printf("%d\n", Stack[i]);
    }
}

int main(){
    int choice, value;
    while(1){
        printf("1.Push\n2.Pop\n3.Peek\n4.Display\n5.exit\n");
        printf("enter Your Choice:");
        scanf("%d", &choice);

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