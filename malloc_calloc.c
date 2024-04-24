#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr1, *arr2;
    int n = 5;

    // Using malloc() to allocate memory for an integer array
    arr1 = (int *)malloc(n * sizeof(int));
    if (arr1 == NULL) {
        printf("Memory allocation failed for arr1\n");
        return 1;
    }

    // Using calloc() to allocate memory for an integer array and initialize it to zero
    arr2 = (int *)calloc(n, sizeof(int));
    if (arr2 == NULL) {
        printf("Memory allocation failed for arr2\n");
        return 1;
    }

    // Displaying the contents of both arrays
    printf("Contents of arr1 (uninitialized):\n"); 
    for (int i = 0; i < n; i++) {
        // there might be garbage values in arr1
        printf("%d ", arr1[i]); // Accessing uninitialized memory
    }
    printf("\n");

    printf("Contents of arr2 (initialized to zero):\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr2[i]); // Accessing initialized memory (all elements are zero)
    }
    printf("\n");

    // Freeing the allocated memory
    free(arr1);
    free(arr2);

    return 0;
}

