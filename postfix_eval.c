#include <stdio.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int item){
    stack[++top] = item;
}

int pop(){
    return stack[top--];
}

int evaluatePostfix(char postfix[]){
    int i = 0;
    char c;

    while((c = postfix[i++]) != '\0'){

        if (isdigit(c)){
            push(c - '\0');
        }
        else{
            int val1 = pop();
            int val2 = pop();

            switch(c){
                case '+': push(val2 + val1); break;
                case '-': push(val2 - val1); break;
                case '/': push(val2 / val1); break;
                case '*': push(val2 * val1); break;
            }
        }
    }
    return pop();

}

int main(){
    char postfix[] = "5-3+82/*";
    printf("result of the Postfix Evaluation: %d\n",evaluatePostfix(postfix));
    return 0;
}
