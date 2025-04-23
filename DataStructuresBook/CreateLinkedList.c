#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

void printLinkedList(node *p)
{
    while(p != NULL)
    {
        printf("--> %d ", p->data);
        p = p->next;
    }
}

node *createLinkedList(int num)
{
    node *head = NULL;
    node *p = NULL;

    head = (node *)malloc(sizeof(node));
    printf("Enter the data = ");
    scanf("%d", &head->data);

    head->next = NULL;
    p = head;

    //for (int i = 1; i <num; i++)
    while(num > 1)
    {
        p->next = (node *) malloc(sizeof(node));
        p = p->next;
        printf("Enter the data = ");
        scanf("%d", &p->data);
        p ->next = NULL;
        num -= 1;
    }
    return head;
}

node * insertNodeAtEnd(node *p)
{
    node *head = p;
    while(p->next != NULL)
    {
        p = p->next;
    }
    p->next = (node *)malloc(sizeof(node));
    p = p->next;
    printf("Enter the data = ");
    scanf("%d", &p->data);
    p->next = NULL;
    return head;
}

node * insertNodeAtBeginning(node *p)
{
    node *head = (node *)malloc(sizeof(node));

    head->next = p;
    printf("Enter the data = ");
    scanf("%d", &head->data);

    return head;

}

node * insertNodeAfterAnElement(node *head)
{
    node *first = head;
    int element = 0;
    int num = 0;
    node *p = (node *)malloc(sizeof(node));
    printf("Enter an element after which you want to insert a new node = ");
    scanf("%d", &element);
    printf("Enter the data = ");
    scanf("%d", &p->data);
    p->next = NULL;

    while(first != NULL)
    {
        if(first->data == element)
        {
            p->next = first->next;
            first->next = p;
            break;
        }
        first = first->next;
    }
    return head;
}

int main (int argc, char ** argv)
{
    node *head = NULL;
    int num = 0;

    printf("Enter the number of nodes\n");
    scanf("%d", &num);

    head = createLinkedList(num);
    //head = insertNodeAtEnd(head);
    //head = insertNodeAtBeginning(head);
    head = insertNodeAfterAnElement(head);

    printLinkedList(head);

    return 0;
}