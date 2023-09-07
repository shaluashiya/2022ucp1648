#include<stdio.h>
#include<stdlib.h>

int linear_search(int array[], int size, int target) {
    
    for (int i = 0; i < size; i++) {
        
        if (array[i] == target) {
            return i;  // Return the index of the target if found
        }
       
    }
    return -1;  // Return -1 if the target is not found in the array
}

int binary_search(int array[], int left, int right, int target) {
    if (left <= right) {
        int mid = left + (right - left) / 2;

        if (array[mid] == target) {
            return mid;  // Return the index of the target if found
        } else if (array[mid] < target) {
            return binary_search(array, mid + 1, right, target);  // Search in the right half
        } else {
            return binary_search(array, left, mid - 1, target);  // Search in the left half
        }
    }
    return -1;  // Return -1 if the target is not found in the array
}

int ternary_search(int array[], int left, int right, int target) {
    if (left <= right) {
        int mid1 = left + (right - left) / 3;
        int mid2 = right - (right - left) / 3;

        if (array[mid1] == target) {
            return mid1;  // Return the index of the target if found
        }
        if (array[mid2] == target) {
            return mid2;  // Return the index of the target if found
        }

        if (target < array[mid1]) {
            return ternary_search(array, left, mid1 - 1, target);  // Search in the left segment
        } else if (target > array[mid2]) {
            return ternary_search(array, mid2 + 1, right, target);  // Search in the right segment
        } else {
            return ternary_search(array, mid1 + 1, mid2 - 1, target);  // Search in the middle segment
        }
    }
    return -1;  // Return -1 if the target is not found in the array
}


void insertion_sort(int array[], int size) {
    for (int i = 1; i < size; i++) {
        int key = array[i];
        int j = i - 1;

        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j--;
        }

        array[j + 1] = key;
    }
}

int main() {
    FILE *output = fopen("output.txt", "w"); // Open "output.txt" for writing
    if (output == NULL) {
        printf("Error opening output file");
        return 1;
    }

    FILE *input = fopen("search.txt", "r");
    if (input == NULL) {
        printf("Input file is empty");
        return 1;
    }

    int n;
    fscanf(input, "%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        fscanf(input, "%d", &arr[i]);
    }
    fclose(input);

    printf("Enter number to search: ");
    int x;
    scanf("%d", &x);

    // Linear search
    fprintf(output, "Linear search\n");
    int lindex = linear_search(arr, n, x);
    if (lindex >= 0)
        fprintf(output, "Target found at %d index\n", lindex);
    else
        fprintf(output, "Element not found\n");

    insertion_sort(arr, n);

    // Binary search
    fprintf(output, "Binary search\n");
    int bindex = binary_search(arr, 0, n - 1, x);
    if (bindex >= 0)
        fprintf(output, "Target found at %d index\n", bindex);
    else
        fprintf(output, "Element not found\n");

    // Ternary search
    fprintf(output, "Ternary search\n");
    int tindex = ternary_search(arr, 0, n - 1, x);
    if (tindex >= 0)
        fprintf(output, "Target found at %d index\n", tindex);
    else
        fprintf(output, "Element not found\n");

    free(arr);

    fclose(output); // Close the output file

    return 0;
}