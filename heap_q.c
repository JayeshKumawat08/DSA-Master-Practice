#include <stdio.h>
#include <string.h>

// Define the Student structure exactly as requested
struct Student {
    char student_name[50];
    int student_roll_no;
    float total_marks;
};

// Heapify subroutine to maintain the Max-Heap property based on roll_no
void heapify(struct Student arr[], int n, int i) {
    int largest = i;             // Initialize largest as root
    int left = 2 * i + 1;        // Left child index
    int right = 2 * i + 2;       // Right child index

    // If left child's roll_no is larger than root's roll_no
    if (left < n && arr[left].student_roll_no > arr[largest].student_roll_no)
        largest = left;

    // If right child's roll_no is larger than the current largest roll_no
    if (right < n && arr[right].student_roll_no > arr[largest].student_roll_no)
        largest = right;

    // If the largest is not the root, swap the entire struct and continue down
    if (largest != i) {
        struct Student temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// Main Heap Sort function
void heapSortByRollNo(struct Student arr[], int n) {
    // Phase 1: Build the Max-Heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Phase 2: Extract elements one by one from the heap
    for (int i = n - 1; i >= 0; i--) {
        // Move current root (the maximum roll_no) to the end of the array
        struct Student temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Call max heapify on the reduced heap to find the next largest
        heapify(arr, i, 0);
    }
}

// Helper function to print the array
void printStudents(struct Student arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Roll: %-4d | Name: %-10s | Marks: %.1f\n", 
               arr[i].student_roll_no, arr[i].student_name, arr[i].total_marks);
    }
}

int main() {
    // Initialize an unsorted array of Student structures
    struct Student students[] = {
        {"Alice", 104, 92.0},
        {"Zane", 101, 85.5},
        {"Bob", 105, 88.0},
        {"Charlie", 102, 78.5}
    };
    
    int n = sizeof(students) / sizeof(students[0]);

    printf("--- Unsorted Array ---\n");
    printStudents(students, n);

    // Call the sorting algorithm
    heapSortByRollNo(students, n);

    printf("\n--- Sorted Array (By Roll Number) ---\n");
    printStudents(students, n);

    return 0;
}