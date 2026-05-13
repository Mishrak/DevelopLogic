#include <stdio.h>
#include <stdlib.h>

// --- Data Structures ---

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct List
{
    Node *head;
    Node *tail;
    size_t length;
} List;

// --- Function Prototypes ---

List* createList();
void addAtEnd(List *list, int data);
void joinLists(List *list1, List *list2);
void printList(List *list);
void freeList(List *list);

// --- Core Logic ---

/**
 * Join list2 to the end of list1 in O(1) time.
 */
void joinLists(List *list1, List *list2)
{
    if (!list1 || !list2 || list2->head == NULL)
    {
        return;
    }

    if (list1->head == NULL)
    {
        // If list1 is empty, it just becomes list2
        list1->head = list2->head;
        list1->tail = list2->tail;
    }
    else
    {
        // The O(1) magic: Connect tail of L1 to head of L2
        list1->tail->next = list2->head;
        // Update the tail of L1 to be the tail of L2
        list1->tail = list2->tail;
    }

    list1->length += list2->length;

    // Critical: Clear list2 so it doesn't point to the nodes now owned by list1
    list2->head = NULL;
    list2->tail = NULL;
    list2->length = 0;
}

// --- Helper Functions ---

List* createList()
{
    List *newList = (List*)malloc(sizeof(List));
    if (newList)
    {
        newList->head = newList->tail = NULL;
        newList->length = 0;
    }
    return newList;
}

void addAtEnd(List *list, int data)
{
    if (!list)
    {
        return;
    }

    Node *newNode = (Node*)malloc(sizeof(Node));
    if (!newNode)
    {
        return;
    }

    newNode->data = data;
    newNode->next = NULL;

    if (list->head == NULL)
    {
        list->head = list->tail = newNode;
    }
    else
    {
        list->tail->next = newNode;
        list->tail = newNode;
    }
    list->length++;
}

void printList(List *list)
{
    if (!list || !list->head)
    {
        printf("List is empty.\n");
        return;
    }
    Node *curr = list->head;
    while (curr)
    {
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
    printf("NULL (Length: %zu)\n", list->length);
}

void freeList(List *list)
{
    if (!list)
    {
        return;
    }
    Node *curr = list->head;
    while (curr)
    {
        Node *temp = curr;
        curr = curr->next;
        free(temp);
    }
    free(list);
}

// --- Driver Code ---

int main()
{
    List *listA = createList();
    List *listB = createList();

    addAtEnd(listA, 10);
    addAtEnd(listA, 20);
    printf("List A: ");
    printList(listA);

    addAtEnd(listB, 30);
    addAtEnd(listB, 40);
    printf("List B: ");
    printList(listB);

    printf("\nJoining List B into List A...\n");
    joinLists(listA, listB);

    printf("Resulting List A: ");
    printList(listA);
    printf("Resulting List B: ");
    printList(listB); // Should be empty

    freeList(listA);
    freeList(listB); // Wrapper still exists, though empty

    return 0;
}