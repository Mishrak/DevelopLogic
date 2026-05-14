#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Node structure for the linked list.
 */
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

/**
 * @brief List Wrapper to enable O(1) joins and appends.
 * * By maintaining a tail pointer, we eliminate the need to traverse 
 * the list to find the end.
 */
typedef struct List
{
    Node *head;
    Node *tail;
    size_t length;
} List;

/**
 * @brief Safely allocates a new List wrapper.
 * @return Pointer to new List or NULL if allocation fails.
 */
List* create_list()
{
    List *newList = (List*)malloc(sizeof(List));
    if (newList != NULL)
    {
        newList->head = NULL;
        newList->tail = NULL;
        newList->length = 0;
    }
    return newList;
}

/**
 * @brief Inserts a node at the end in O(1) time.
 * @param list Target list wrapper.
 * @param data Value to insert.
 */
void add_at_end(List *list, int data)
{
    if (list == NULL)
    {
        return;
    }

    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        fprintf(stderr, "Error: Node allocation failed.\n");
        return;
    }

    newNode->data = data;
    newNode->next = NULL;

    if (list->head == NULL)
    {
        list->head = newNode;
        list->tail = newNode;
    }
    else
    {
        list->tail->next = newNode;
        list->tail = newNode;
    }
    list->length++;
}

/**
 * @brief Joins list2 to the end of list1 in O(1) time.
 * * Ownership of nodes is transferred from list2 to list1.
 * list2 is left in a valid, empty state.
 */
void join_lists(List *list1, List *list2)
{
    // Senior Guard: Handle NULL pointers or an empty source list
    if (list1 == NULL || list2 == NULL || list2->head == NULL)
    {
        return;
    }

    if (list1->head == NULL)
    {
        // Case: Destination is empty; simply adopt list2's nodes
        list1->head = list2->head;
        list1->tail = list2->tail;
    }
    else
    {
        /**
         * The O(1) Logic: 
         * 1. Connect the end of L1 to the start of L2.
         * 2. Move L1's tail pointer to L2's tail.
         */
        list1->tail->next = list2->head;
        list1->tail = list2->tail;
    }

    list1->length += list2->length;

    /**
     * Senior Protection: 
     * Reset list2 to prevent double-free or aliasing errors.
     */
    list2->head = NULL;
    list2->tail = NULL;
    list2->length = 0;
}

/**
 * @brief Prints the list contents and length metadata.
 */
void print_list(const char *label, List *list)
{
    printf("%s: ", label);
    if (list == NULL || list->head == NULL)
    {
        printf("Empty\n");
        return;
    }

    Node *curr = list->head;
    while (curr != NULL)
    {
        printf("%d%s", curr->data, (curr->next ? " -> " : ""));
        curr = curr->next;
    }
    printf(" | [Size: %zu]\n", list->length);
}

/**
 * @brief Fully deallocates the list nodes and the wrapper.
 */
void free_list(List *list)
{
    if (list == NULL)
    {
        return;
    }

    Node *curr = list->head;
    while (curr != NULL)
    {
        Node *temp = curr;
        curr = curr->next;
        free(temp);
    }
    free(list);
}

int main(int argc, char *argv[])
{
    List *listA = create_list();
    List *listB = create_list();

    add_at_end(listA, 10);
    add_at_end(listA, 20);
    print_list("List A", listA);

    add_at_end(listB, 30);
    add_at_end(listB, 40);
    print_list("List B", listB);

    printf("\n>>> Performing O(1) Join...\n\n");
    join_lists(listA, listB);

    print_list("Final List A", listA);
    print_list("Final List B", listB);

    free_list(listA);
    free_list(listB);

    return 0;
}