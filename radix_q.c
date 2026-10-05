#include <stdio.h>

// Helper function to find the absolute largest number in the array
// This tells us exactly how many digits (passes) we need to process.
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// A highly optimized, stable Counting Sort used specifically for sorting specific digits
// 'exp' represents the current place value (1s, 10s, 100s, etc.)
void countSort(int arr[], int n, int exp) {
    int output[n];         // Temporary array to hold the sorted state of this pass
    int count[10] = {0};   // Frequency buckets for digits 0-9

    // Step 1: Extract the specific digit and count its frequency
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    // Step 2: Convert frequencies into actual index positions for the output array
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Step 3: Build the output array by walking BACKWARDS through the original array.
    // Walking backwards is mathematically required to maintain "stability" (keeping duplicate digits in their original order).
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Step 4: Copy the partially sorted data back into the main array for the next pass
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// Main Radix Sort function
void radixSort(int arr[], int n) {
    int max = getMax(arr, n);

    // Loop through each place value (1, 10, 100).
    // The loop condition automatically stops when we exceed the number of digits in our max value.
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countSort(arr, n, exp);
    }
}

// Helper function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    // A standard set of numbers with varying lengths to test the digit extraction
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("--- Unsorted Numbers ---\n");
    printArray(arr, n);

    // Call the optimal Radix Sort
    radixSort(arr, n);

    printf("\n--- Sorted Numbers (Radix Sort) ---\n");
    printArray(arr, n);

    return 0;
}