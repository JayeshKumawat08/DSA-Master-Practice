#include <stdio.h>
#include <stdlib.h>

struct Student
{
    int roll;
    char name[30];
    struct Student *prev;
    struct Student *next;
};

struct Student *head = NULL;

// Create Node
struct Student* createNode()
{
    struct Student *newNode;

    newNode = (struct Student*)malloc(sizeof(struct Student));

    printf("Enter Roll Number: ");
    scanf("%d", &newNode->roll);

    printf("Enter Name: ");
    scanf("%s", newNode->name);

    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}

// Insert at End
void insert()
{
    struct Student *newNode = createNode();

    if(head == NULL)
    {
        head = newNode;
        head->next = head;
        head->prev = head;
        return;
    }

    struct Student *last = head->prev;

    last->next = newNode;
    newNode->prev = last;

    newNode->next = head;
    head->prev = newNode;
}

// Display List
void display()
{
    if(head == NULL)
    {
        printf("List Empty\n");
        return;
    }

    struct Student *temp = head;

    printf("\nStudent Records:\n");

    do
    {
        printf("Roll = %d  Name = %s\n",
               temp->roll,
               temp->name);

        temp = temp->next;

    } while(temp != head);
}

// Search and Display Previous & Next
void search()
{
    if(head == NULL)
    {
        printf("List Empty\n");
        return;
    }

    int key;

    printf("Enter Roll Number to Search: ");
    scanf("%d", &key);

    struct Student *temp = head;

    do
    {
        if(temp->roll == key)
        {
            printf("\nRecord Found\n");

            printf("Current : %d %s\n",
                   temp->roll,
                   temp->name);

            printf("Previous : %d %s\n",
                   temp->prev->roll,
                   temp->prev->name);

            printf("Next : %d %s\n",
                   temp->next->roll,
                   temp->next->name);

            return;
        }

        temp = temp->next;

    } while(temp != head);

    printf("Record Not Found\n");
}

// Delete by Roll Number
void deleteRecord()
{
    if(head == NULL)
    {
        printf("List Empty\n");
        return;
    }

    int key;

    printf("Enter Roll Number to Delete: ");
    scanf("%d", &key);

    struct Student *temp = head;

    do
    {
        if(temp->roll == key)
        {
            // Only one node
            if(temp->next == temp)
            {
                head = NULL;
            }

            // First node
            else if(temp == head)
            {
                struct Student *last = head->prev;

                head = head->next;

                last->next = head;
                head->prev = last;
            }

            // Other node
            else
            {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
            }

            free(temp);

            printf("Record Deleted Successfully\n");

            // Display current predecessor & successor
            if(head != NULL)
            {
                printf("Current First Node = %d\n",
                       head->roll);

                printf("Predecessor = %d\n",
                       head->prev->roll);

                printf("Successor = %d\n",
                       head->next->roll);
            }

            return;
        }

        temp = temp->next;

    } while(temp != head);

    printf("Record Not Found\n");
}

int main()
{
    int choice;

    while(1)
    {
        printf("\n---- MENU ----\n");
        printf("1. Insert Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Delete Student\n");
        printf("5. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                insert();
                break;

            case 2:
                display();
                break;

            case 3:
                search();
                break;

            case 4:
                deleteRecord();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid Choice\n");
        }
    }

    return 0;
}