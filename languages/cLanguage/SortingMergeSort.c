#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Merges two sorted halves of an array.
 * * Logic: Compares elements from two subarrays and places the smaller
 * element into the destination array. This implementation maintains stability.
 * * @param arr   The source array.
 * @param aux   The auxiliary array used for merging.
 * @param left  Starting index of the first half.
 * @param mid   Ending index of the first half.
 * @param right Ending index of the second half.
 */
void merge(int arr[], int aux[], int left, int mid, int right)
{
    // Step 1: Copy only the necessary portion to the auxiliary array.
    // Optimization: In high-performance systems, we try to avoid this copy
    // by swapping array pointers at each recursion level.
    for (int i = left; i <= right; i++)
    {
        aux[i] = arr[i];
    }

    int i = left;      // Initial index of first subarray
    int j = mid + 1;   // Initial index of second subarray
    int k = left;      // Initial index of merged array

    // Step 2: Merge the two halves back into arr[]
    while (i <= mid && j <= right)
    {
        // Using <= ensures the sort is "Stable" (preserves order of equals)
        if (aux[i] <= aux[j])
        {
            arr[k++] = aux[i++];
        }
        else
        {
            arr[k++] = aux[j++];
        }
    }

    // Step 3: Copy remaining elements of the left half, if any.
    // Note: We don't need to copy the right half because they are already 
    // in the correct place in the original arr[].
    while (i <= mid)
    {
        arr[k++] = aux[i++];
    }
}

/**
 * @brief Recursive Merge Sort function.
 * * Time Complexity: O(N log N)
 * Space Complexity: O(N) for the auxiliary array.
 * * @param arr   Array to be sorted.
 * @param aux   Temporary array for merge operations.
 * @param left  Left boundary index.
 * @param right Right boundary index.
 */
void myMergeSort(int arr[], int aux[], int left, int right)
{
    // Base case: segment has 0 or 1 element
    if (left >= right)
    {
        return;
    }

    // Calculate mid point avoiding potential overflow
    int mid = left + (right - left) / 2;

    // Divide: Recursively sort first and second halves
    myMergeSort(arr, aux, left, mid);
    myMergeSort(arr, aux, mid + 1, right);

    // Conquer: Merge the sorted halves
    merge(arr, aux, left, mid, right);
}

/**
 * @brief Utility function to print array elements.
 */
void printArray(const int arr[], int size)
{
    if (arr == NULL || size <= 0)
    {
        printf("Array is empty.\n");
        return;
    }

    for (int i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    int arr[] = {5, 10, 25, 2, 1, 50, 80, 35, 16, 12, 48, 9};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Pre-allocating the auxiliary array once is a Senior-level optimization.
    int *aux = (int *)malloc(size * sizeof(int));
    if (aux == NULL)
    {
        fprintf(stderr, "Fatal: Memory allocation failed\n");
        return EXIT_FAILURE;
    }

    printf("Original Array: ");
    printArray(arr, size);

    myMergeSort(arr, aux, 0, size - 1);

    printf("Sorted Array:   ");
    printArray(arr, size);

    // Cleanup
    free(aux);
    aux = NULL; // Prevent dangling pointer

    return EXIT_SUCCESS;
}