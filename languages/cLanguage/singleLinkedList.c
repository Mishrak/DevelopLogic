#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

/**
 * @brief Adds a node to the end of the list.
 * Note: A senior engineer would typically use a 'List' wrapper
 * to keep track of the tail for O(1) insertion.
 */
Node *addAtEnd(Node *start, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        fprintf(stderr, "Memory allocation failed.\n");
        return start;
    }

    newNode->data = data;
    newNode->next = NULL;

    if (start == NULL)
    {
        return newNode;
    }

    Node *curr = start;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = newNode;

    return start;
}

/**
 * @brief Merges nodes between zeros, handling non-standard starts/ends.
 * * This version treats the start of the list as an implicit zero if 
 * one isn't present, and ignores trailing data after the last zero.
 */
Node *mergeNodesBetweenZeros(Node *head)
{
    if (head == NULL) return NULL;

    // Create a new dummy list to store results
    Node dummy = {0, NULL};
    Node *result_ptr = &dummy;
    
    Node *curr = head;
    int current_sum = 0;
    bool in_segment = false;

    while (curr != NULL)
    {
        if (curr->data == 0)
        {
            // If we hit a zero and we have a sum, "close" the segment
            if (in_segment)
            {
                Node *newNode = (Node *)malloc(sizeof(Node));
                newNode->data = current_sum;
                newNode->next = NULL;
                
                result_ptr->next = newNode;
                result_ptr = result_ptr->next;
                
                current_sum = 0; // Reset for next segment
            }
            in_segment = true; 
        }
        else
        {
            // If we are between zeros, keep adding
            if (in_segment)
            {
                current_sum += curr->data;
            }
        }
        curr = curr->next;
    }

    // Optional: Free the original list here to prevent leaks
    return dummy.next;
}

void printNodes(Node *start)
{
    while (start != NULL)
    {
        printf("%d%s", start->data, (start->next ? " --> " : ""));
        start = start->next;
    }
    printf("\n");
}

/**
 * @brief Utility to clear memory before exit.
 */
void destroyList(Node *head)
{
    while (head != NULL)
    {
        Node *temp = head;
        head = head->next;
        free(temp);
    }
}

int main(int argc, char *argv[])
{
    int option = 0;
    Node *start = NULL;

    while (1)
    {
        printf("\n1) Add node\n2) Merge between zeros\n3) Print\n4) Exit\nSelection: ");
        if (scanf("%d", &option) != 1) break;

        switch (option)
        {
            case 1:
            {
                int val;
                printf("Enter Value: ");
                scanf("%d", &val);
                start = addAtEnd(start, val);
                break;
            }
            case 2:
            {
                start = mergeNodesBetweenZeros(start);
                printf("Nodes merged.\n");
                break;
            }
            case 3:
            {
                printNodes(start);
                break;
            }
            case 4:
            {
                destroyList(start);
                exit(0);
            }
            default:
                printf("Invalid option.\n");
        }
    }
    return 0;
}
