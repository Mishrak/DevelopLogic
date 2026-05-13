i#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Configuration and Data Structures
 *
 * TABLE_SIZE: A prime number to minimize hash collisions.
 * Node: Represents a bucket in the hash table using Separate Chaining.
 */
#define TABLE_SIZE 10007

typedef struct Node
{
    int key;
    int value;
    struct Node *next;
} Node;

/**
 * @brief Generates a hash index for a given integer key.
 *
 * @param key The integer to be hashed.
 * @return An index within the range [0, TABLE_SIZE - 1].
 */
int get_hash_index(int key)
{
    // abs() ensures negative integers do not produce negative indices
    return abs(key) % TABLE_SIZE;
}

/**
 * @brief Searches for a key in the table. If found, increments the count.
 *        If not found, prepends a new node to the bucket's linked list.
 *
 * @param table The array of Node pointers (the hash table).
 * @param key   The integer value to track.
 */
void update_or_insert(Node *table[], int key)
{
    int idx = get_hash_index(key);
    Node *curr = table[idx];

    // Search phase: Traverse the chain at the calculated index
    while (curr)
    {
        if (curr->key == key)
        {
            curr->value++;
            return;
        }
        curr = curr->next;
    }

    // Insertion phase: Allocate memory for a new entry
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (!new_node)
    {
        fprintf(stderr, "Fatal: Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->key = key;
    new_node->value = 1;

    // Insert at the head of the list for O(1) performance
    new_node->next = table[idx];
    table[idx] = new_node;
}

/**
 * @brief Iterates through the table and frees all dynamically allocated nodes.
 */
void destroy_table(Node *table[])
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
 * @brief Orchestrates the frequency counting process and prints the results.
 *
 * @param input_array The data set to analyze.
 * @param size        The number of elements in the array.
 */
void count_element_frequency(int input_array[], int size)
{
    // Initialize the hash table to NULL pointers
    Node *hash_table[TABLE_SIZE] = { NULL };

    // 1. Populate the table
    for (int i = 0; i < size; i++)
    {
        update_or_insert(hash_table, input_array[i]);
    }

    // 2. Display the frequency report
    printf("\n\t%-15s %-15s\n", "Element", "Frequency");
    printf("\t-----------------------------\n");

    for (int i = 0; i < TABLE_SIZE; i++)
    {
        Node *temp = hash_table[i];
        while (temp)
        {
            printf("\t%-15d ---> %-15d\n", temp->key, temp->value);
            temp = temp->next;
        }
    }

    // 3. Clean up memory
    destroy_table(hash_table);
}

int main(int argc, char *argv[])
{
    int data[] = {5, 10, 5, 20, 10, 5, 30, 40, 20};
    int n = sizeof(data) / sizeof(data[0]);

    printf("Calculating element frequencies...\n");
    count_element_frequency(data, n);

    return 0;
}
