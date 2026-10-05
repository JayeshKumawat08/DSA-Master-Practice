#include <stdio.h>
#include <string.h>

struct Student {
    char student_name[50];
    int student_roll_no;
    float total_marks;
};


void selectionSortByName(struct Student arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        
        for (int j = i + 1; j < n; j++) {

            // strcmp returns < 0 if the first string comes alphabetically BEFORE the second
            if (strcmp(arr[j].student_name, arr[min_idx].student_name) < 0) {
                min_idx = j;
            }
        }
        
       
        if (min_idx != i) {
            struct Student temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
        }
    }
}

void printStudents(struct Student arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Name: %-10s | Roll: %d | Marks: %.1f\n", 
               arr[i].student_name, arr[i].student_roll_no, arr[i].total_marks);
    }
}

int main() {
    // Initialize an array of Student structures
    struct Student students[] = {
        {"Zane", 101, 85.5},
        {"Alice", 102, 92.0},
        {"Charlie", 103, 78.5},
        {"Bob", 104, 88.0}
    };
    
    int n = sizeof(students) / sizeof(students[0]);

    printf("--- Unsorted Array ---\n");
    printStudents(students, n);

    // Call the sorting algorithm
    selectionSortByName(students, n);

    printf("\n--- Sorted Array (By Name) ---\n");
    printStudents(students, n);

    return 0;
}