#include <stdio.h>

/**
 * @brief Finds the smallest missing natural number in a sorted array.
 * * Logic:
 * In an array with no missing numbers starting from 1, arr[i] should be i + 1.
 * We use Binary Search to find the FIRST index where arr[i] != i + 1.
 * * @param arr  Sorted array of integers.
 * @param size Number of elements in the array.
 * @return The missing number, or size + 1 if no number is missing within the range.
 */
int findMissingNumber(int arr[], int size)
{
    // Senior Tip: Handle edge cases first
    if (size == 0)
    {
        return 1;
    }

    if (arr[0] != 1)
    {
        return 1;
    }

    int left = 0;
    int right = size - 1;

    // Check if the missing number is beyond the current array elements
    if (arr[size - 1] == size)
    {
        return size + 1;
    }

    /**
     * Standard Binary Search convergence.
     * We look for the first index 'left' where arr[left] != left + 1.
     */
    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == mid + 1)
        {
            // The left side is perfect; the mismatch must be on the right
            left = mid + 1;
        }
        else
        {
            // This could be the first mismatch, or the first mismatch is further left
            right = mid - 1;
        }
    }

    /**
     * At the end of the loop, 'left' will point to the index where 
     * the sequence first breaks. The missing number is therefore left + 1.
     */
    return left + 1;
}

int main(int argc, char *argv[])
{
    // Test Case 1: Missing in the middle
    int arr1[] = {1, 2, 3, 5, 6};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);

    // Test Case 2: No missing (returns size + 1)
    int arr2[] = {1, 2, 3, 4};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    printf("Array 1: Missing = %d\n", findMissingNumber(arr1, size1));
    printf("Array 2: Missing = %d\n", findMissingNumber(arr2, size2));

    return 0;
}