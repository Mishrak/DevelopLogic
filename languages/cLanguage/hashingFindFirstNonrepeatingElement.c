#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Configuration and Data Structures
 *
 * TABLE_SIZE: Prime number to reduce collision probability.
 * Node: Stores the key and its frequency count, supporting Separate Chaining.
 */
#define TABLE_SIZE 10007

typedef struct Node
{
    int key;
    int count;
    struct Node *next;
} Node;

/**
 * @brief Maps an integer key to a valid index within the table bounds.
 */
int get_hash_index(int key)
{
    return abs(key) % TABLE_SIZE;
}

/**
 * @brief Updates the frequency count of a key if it exists;
 *        otherwise, inserts a new node into the hash table.
 */
void update_frequency(Node *table[], int key)
{
    int idx = get_hash_index(key);
    Node *curr = table[idx];

    while (curr)
    {
        if (curr->key == key)
        {
            curr->count++;
            return;
        }
        curr = curr->next;
    }

    Node *new_node = (Node *)malloc(sizeof(Node));
    if (!new_node)
    {
        return;
    }

    new_node->key = key;
    new_node->count = 1;
    new_node->next = table[idx];
    table[idx] = new_node;
}

/**
 * @brief Retrieves the stored frequency count for a given key.
 *
 * @return The count if found, 0 otherwise.
 */
int get_count(Node *table[], int key)
{
    int idx = get_hash_index(key);
    Node *curr = table[idx];

    while (curr)
    {
        if (curr->key == key)
        {
            return curr->count;
        }
        curr = curr->next;
    }
    return 0;
}

/**
 * @brief Deallocates all nodes in the hash table to prevent memory leaks.
 */
void clear_table(Node *table[])
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        Node *curr = table[i];
        while (curr)
        {
            Node *temp = curr;
            curr = curr->next;
            free(temp);
        }
        table[i] = NULL;
    }
}

/**
 * @brief Finds the first element in the array that appears exactly once.
 *
 * Logic:
 * 1. Build frequency map of all elements.
 * 2. Scan original array to find the first element with count == 1.
 *
 * @return The first non-repeating element, or -1 if none exist.
 */
int find_first_non_repeating(int input_array[], int size)
{
    Node *hash_table[TABLE_SIZE] = { NULL };

    // Pass 1: Build the frequency table
    for (int i = 0; i < size; i++)
    {
        update_frequency(hash_table, input_array[i]);
    }

    // Pass 2: Identify the first element with a count of 1
    int result = -1;
    for (int i = 0; i < size; i++)
    {
        if (get_count(hash_table, input_array[i]) == 1)
        {
            result = input_array[i];
            break;
        }
    }

    // Cleanup memory before returning
    clear_table(hash_table);
    return result;
}

int main(int argc, char *argv[])
{
    int input_array[] = {1, 2, 3, 1, 2, 3, 1, 2, 3, 4};
    int size = sizeof(input_array) / sizeof(input_array[0]);

    printf("Input Array: ");
    for (int i = 0; i < size; i++) printf("%d ", input_array[i]);
    printf("\n");

    int result = find_first_non_repeating(input_array, size);

    if (result != -1)
    {
        printf("First non-repeating element: %d\n", result);
    }
    else
    {
        printf("All elements repeat.\n");
    }

    return 0;
}
