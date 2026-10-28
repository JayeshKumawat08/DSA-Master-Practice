#include <stdio.h>
#include <string.h>

struct Student{
    char student_name[50];
    int student_roll_no;
    float total_marks;
};

void swap(struct Student* a, struct Student* b){
    struct Student temp = *a;
    *a = *b;
    *b = temp;
}

void medianOfThree(struct Student arr[], int low, int high) {
    int mid = low + (high - low) / 2;

    if (arr[low].student_roll_no > arr[mid].student_roll_no) {
        swap(&arr[low], &arr[mid]);
    }
    if (arr[low].student_roll_no > arr[high].student_roll_no) {
        swap(&arr[low], &arr[high]);
    }
    if (arr[mid].student_roll_no > arr[high].student_roll_no) {
        swap(&arr[mid], &arr[high]);
    }

    swap(&arr[mid], &arr[high]);
}

int partition(struct Student arr[], int low, int high) {
    medianOfThree(arr, low, high);
    struct Student pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j].student_roll_no <= pivot.student_roll_no) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(struct Student arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(struct Student arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("Roll: %-4d | Name: %-10s | Marks: %.1f\n", 
               arr[i].student_roll_no, arr[i].student_name, arr[i].total_marks);
    }
    printf("\n");
}

int main() {
    struct Student students[] = {
        {"Alice", 24, 85.5},
        {"Bob", 9, 92.0},
        {"Charlie", 29, 78.5},
        {"Diana", 14, 88.0},
        {"Eve", 19, 91.0},
        {"Frank", 4, 76.5},
        {"Grace", 34, 89.5}
    };
    int n = sizeof(students) / sizeof(students[0]);
    
    printf("Original array: \n");
    printArray(students, n);
    
    quickSort(students, 0, n - 1);
    
    printf("Sorted array (by Roll Number): \n");
    printArray(students, n);
    
    return 0;
}