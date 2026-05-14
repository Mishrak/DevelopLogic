#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
} Node;

/**
 * @brief Safely adds a node to the end of the DLL.
 * Maintains the 'beginning' pointer to return the head.
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
        newNode->prev = NULL;
        return newNode;
    }

    Node *curr = start;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }

    curr->next = newNode;
    newNode->prev = curr;

    return start;
}

/**
 * @brief Removes ALL occurrences of a value from the DLL.
 * Logic: Captures 'next' before freeing 'curr' to prevent use-after-free.
 */
Node *removeAllNodes(Node *start, int data)
{
    if (start == NULL)
    {
        printf("List is empty.\n");
        return NULL;
    }

    Node *curr = start;
    bool found = false;

    while (curr != NULL)
    {
        // Capture next node immediately so we don't lose it if we free 'curr'
        Node *nextNode = curr->next;

        if (curr->data == data)
        {
            found = true;

            // Rewire neighbors
            if (curr->prev != NULL)
            {
                curr->prev->next = curr->next;
            }
            if (curr->next != NULL)
            {
                curr->next->prev = curr->prev;
            }

            // Update head if we are deleting the start node
            if (curr == start)
            {
                start = nextNode;
            }

            free(curr);
        }

        // Move to the next node captured earlier
        curr = nextNode;
    }

    if (!found)
    {
        printf("Value %d not found in the list.\n", data);
    }

    return start;
}

/**
 * @brief Displays the list from head to tail.
 */
void display(Node *start)
{
    if (start == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    printf("DLL: NULL <-> ");
    while (start)
    {
        printf("[%d] <-> ", start->data);
        start = start->next;
    }
    printf("NULL\n");
}

/**
 * @brief Deallocates all memory before exit.
 */
void destroyList(Node *start)
{
    while (start != NULL)
    {
        Node *temp = start;
        start = start->next;
        free(temp);
    }
}

// ... helper functions like addAtBeginning follow the same Allman pattern ...

int main(int argc, char *argv[])
{
    Node *start = NULL;
    int option = 0;

    while (1)
    {
        printf("\n--- Doubly Linked List Manager ---\n");
        printf("1) Create/Add Multiple\n2) Display\n3) Remove All Occurrences\n4) Exit\nSelection: ");
        
        if (scanf("%d", &option) != 1) break;

        switch (option)
        {
            case 1:
            {
                int count, val;
                printf("How many nodes? ");
                scanf("%d", &count);
                for (int i = 0; i < count; i++)
                {
                    printf("Value %d: ", i + 1);
                    scanf("%d", &val);
                    start = addAtEnd(start, val);
                }
                break;
            }
            case 2:
            {
                display(start);
                break;
            }
            case 3:
            {
                int val;
                printf("Enter value to remove: ");
                scanf("%d", &val);
                start = removeAllNodes(start, val);
                break;
            }
            case 4:
            {
                destroyList(start);
                return 0;
            }
            default:
                printf("Invalid option.\n");
        }
    }
    return 0;
}