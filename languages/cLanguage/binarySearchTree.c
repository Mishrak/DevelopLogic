#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Node structure for a Binary Search Tree.
 */
typedef struct Node
{
    struct Node *left;
    int data;
    struct Node *right;
} Node;

/**
 * @brief Helper function to allocate and initialize a new node.
 * @param value The integer data to store.
 * @return Pointer to the new node, or NULL on failure.
 */
Node *createNode(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode != NULL)
    {
        newNode->left = NULL;
        newNode->data = value;
        newNode->right = NULL;
    }
    return newNode;
}

/**
 * @brief Recursively inserts a value into the BST.
 * Maintains unique values and returns the (potentially new) root.
 */
Node *addNode(Node *root, int value)
{
    // Base case: current position is empty
    if (root == NULL)
    {
        return createNode(value);
    }

    // Standard BST insertion logic
    if (value < root->data)
    {
        root->left = addNode(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = addNode(root->right, value);
    }
    else
    {
        // Senior Tip: Don't just print errors; decide how the system handles duplicates.
        printf("Notice: Value %d already exists in the BST. Skipping.\n", value);
    }

    return root;
}

/**
 * @brief Performs an In-Order Traversal (Left, Root, Right).
 * This effectively prints the BST values in ascending order.
 */
void printInOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    printInOrder(root->left);
    printf("%d --> ", root->data);
    printInOrder(root->right);
}

/**
 * @brief Recursively frees all nodes in the tree to prevent memory leaks.
 */
void destroyTree(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    // Post-order deletion: Children first, then the parent
    destroyTree(root->left);
    destroyTree(root->right);
    free(root);
}

int main(int argc, char *argv[])
{
    int choice = 0;
    Node *root = NULL;

    while (1)
    {
        printf("\n--- BST Manager ---\n");
        printf("1) Add Node\n2) Display (In-Order)\n3) Exit\nSelection: ");
        
        // Safety: check if scanf actually read an integer
        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // Clear the input buffer
            continue;
        }

        switch (choice)
        {
            case 1:
            {
                int value = 0;
                printf("Enter the Value: ");
                scanf("%d", &value);
                root = addNode(root, value);
                break;
            }
            case 2:
            {
                if (root == NULL)
                {
                    printf("Tree is empty.\n");
                }
                else
                {
                    printInOrder(root);
                    printf("NULL\n");
                }
                break;
            }
            case 3:
            {
                printf("Cleaning up memory and exiting...\n");
                destroyTree(root);
                return 0; // Standard successful exit code
            }
            default:
            {
                printf("Option not recognized.\n");
                break;
            }
        }
    }

    return 0;
}