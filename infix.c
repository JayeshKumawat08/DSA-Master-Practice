#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX 100


char opStack[MAX];
int opTop = -1;

int valStack[MAX];
int valTop = -1;

char infix[MAX];
char postfix[MAX];


void pushOp(char x) {
    if (opTop < MAX - 1) opStack[++opTop] = x;
}

char popOp() {
    if (opTop >= 0) return opStack[opTop--];
    return '\0';
}

void pushVal(int x) {
    if (valTop < MAX - 1) valStack[++valTop] = x;
}

int popVal() {
    if (valTop >= 0) return valStack[valTop--];
    return 0;
}

int precedence(char x) {
    if (x == '^') return 3;
    if (x == '*' || x == '/') return 2;
    if (x == '+' || x == '-') return 1;
    return 0;
}

int isOperator(char x) {
    return (x == '+' || x == '-' || x == '*' || x == '/' || x == '^');
}

void infixToPostfix() {
    int i = 0, j = 0;
    opTop = -1; 

    while (infix[i] != '\0') {
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') {
            pushOp(infix[i]);
        } else if (infix[i] == ')') {
            while (opTop != -1 && opStack[opTop] != '(') {
                postfix[j++] = popOp();
            }
            popOp(); 
        } else if (isOperator(infix[i])) {
            while (opTop != -1 && precedence(opStack[opTop]) >= precedence(infix[i])) {
                postfix[j++] = popOp();
            }
            pushOp(infix[i]);
        }
        i++;
    }

    while (opTop != -1) {
        postfix[j++] = popOp();
    }
    postfix[j] = '\0'; 

    printf("Postfix Output: %s\n", postfix);
}

void evaluatePostfix() {
    int i = 0, val1, val2, result;
    valTop = -1; 

    if (strlen(postfix) == 0) {
        printf("Error: No postfix expression to evaluate.\n");
        return;
    }

    while (postfix[i] != '\0') {
        if (isdigit(postfix[i])) {
            pushVal(postfix[i] - '0'); 
        } else if (isalpha(postfix[i])) {
            printf("Error: Cannot evaluate variables mathematically.\n");
            return;
        } else if (isOperator(postfix[i])) {
            val1 = popVal(); 
            val2 = popVal(); 

            switch (postfix[i]) {
                case '+': result = val2 + val1; break;
                case '-': result = val2 - val1; break;
                case '*': result = val2 * val1; break;
                case '/': 
                    if(val1 == 0) { printf("Error: Division by zero!\n"); return; }
                    result = val2 / val1; 
                    break;
                case '^': result = (int)pow(val2, val1); break;
            }
            pushVal(result);
        }
        i++;
    }
    printf("Result: %d\n", popVal());
}


int main() {
    int choice = -1;
    strcpy(infix, "");
    strcpy(postfix, "");

    while (choice != 0) {
        printf("\n--- MENU ---");
        printf("\n1. Enter Infix Expression");
        printf("\n2. Convert to Postfix");
        printf("\n3. Evaluate Postfix");
        printf("\n0. Exit");
        printf("\nChoice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF) { }
            choice = -1;
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter expression: ");
                scanf("%s", infix);
                strcpy(postfix, ""); 
                break;
            case 2:
                if (strlen(infix) == 0) printf("Error: Enter an expression first.\n");
                else infixToPostfix();
                break;
            case 3:
                evaluatePostfix();
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}