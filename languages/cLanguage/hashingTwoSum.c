#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * @brief Node structure for the Hash Table.
 *
 * Each node stores the value (key) from the array and its
 * corresponding index to satisfy the Two Sum requirement.
 */
typedef struct Node
{
    int key;
    int index;
    struct Node* next;
} Node;

/**
 * @brief Prime number for table size to minimize hash collisions.
 */
#define TABLE_SIZE 10007

/**
 * @brief Hash function using the modulo operator.
 *
 * @param key The integer value to hash.
 * @return A valid index within the range [0, TABLE_SIZE - 1].
 */
int get_hash_index(int key)
{
    return abs(key) % TABLE_SIZE;
}

/**
 * @brief Inserts a key and its index into the hash table.
 *
 * @param table The hash table array.
 * @param key   The value from the input array.
 * @param index The original position in the array.
 */
void insert(Node* table[], int key, int index)
{
    int idx = get_hash_index(key);
    Node* newNode = (Node*)malloc(sizeof(Node));

    if (newNode == NULL)
    {
        return; // In production, handle allocation failure appropriately
    }

    newNode->key = key;
    newNode->index = index;
    newNode->next = table[idx];
    table[idx] = newNode;
}

/**
 * @brief Searches for a key in the hash table.
 *
 * @param table The hash table array.
 * @param key   The value we are looking for (the complement).
 * @param found_index Pointer to store the index if found.
 * @return true if found, false otherwise.
 */
bool search(Node* table[], int key, int* found_index)
{
    int idx = get_hash_index(key);
    Node* temp = table[idx];

    while (temp)
    {
        if (temp->key == key)
        {
            *found_index = temp->index;
            return true;
        }
        temp = temp->next;
    }
    return false;
}

/**
 * @brief Deallocates all nodes in the hash table to prevent memory leaks.
 */
void destroy_table(Node* table[])
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        Node* curr = table[i];
        while (curr)
        {
            Node* temp = curr;
            curr = curr->next;
            free(temp);
        }
        table[i] = NULL;
    }
}

/**
 * @brief Finds two indices such that the values add up to a target.
 *
 * Logic:
 * For every element x, we check if (target - x) exists in the hash table.
 * If yes, we found the pair. If no, we insert x into the table.
 *
 * @param inputArray       The source array of integers.
 * @param sizeOfInputArray The number of elements in the array.
 * @param target           The sum we are aiming for.
 * @return                 Pointer to a heap-allocated array of 2 integers,
 *                         or NULL if no pair is found.
 */
int* twoSum(int inputArray[], int sizeOfInputArray, int target)
{
    // Initialize Hash Table (Avoid global variables for better encapsulation)
    Node* hash_table[TABLE_SIZE] = { NULL };
    int complement_index = 0;
    int* result = NULL;

    for (int i = 0; i < sizeOfInputArray; i++)
    {
        int complement = target - inputArray[i];

        // Search for the complement in the table
        if (search(hash_table, complement, &complement_index))
        {
            result = (int*)malloc(2 * sizeof(int));
            if (result != NULL)
            {
                result[0] = complement_index;
                result[1] = i;
            }
            break; // Found the solution, exit loop
        }

        // Store current value and index for future complements
        insert(hash_table, inputArray[i], i);
    }

    // Clean up internal hash table before returning result to caller
    destroy_table(hash_table);
    return result;
}

int main(int argc, char* argv[])
{
    int input_array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target = 9;
    int size = sizeof(input_array) / sizeof(input_array[0]);

    printf("Searching for Two Sum (Target: %d)...\n", target);
    int* output = twoSum(input_array, size, target);

    if (output != NULL)
    {
        printf("Indices found: [%d, %d]\n", output[0], output[1]);
        printf("Values: %d + %d = %d\n", input_array[output[0]], input_array[output[1]], target);

        // Don't forget to free the result allocated in twoSum
        free(output);
    }
    else
    {
        printf("No combination found.\n");
    }

    return 0;
}
