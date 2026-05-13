#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int data;
    struct Node *next;
}Node;


Node *addAtEnd(Node *start, int data)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    if(temp != NULL)
    {
        temp->data = data;
        temp->next = NULL;

        if(start != NULL)
        {
            Node *beginning = start;
            while(start->next != NULL)
            {
                start = start->next;
            }
            start->next = temp;
            return beginning;
        }
        else
        {
            start = temp;
        }
    }
    else
    {
        printf("Error in memory allocation.\n");
        return NULL;
    }
    return start;
}

Node *printNodes(Node *start)
{
    while(start)
    {
        printf("%d --> ", start->data);
        start = start->next;
    }
    printf("\n");
}

int does_merge_required(Node **inner_start)
{
    int length = 1;
    if((*inner_start)->next != NULL)
    {
        Node *first = (*inner_start)->next;
        if(first->next != NULL)
        {
            Node *last = first->next;
            while(last != NULL)
            {
                if(last->data != 0)
                {
                    length += 1;
                }
                else
                {
                    break;
                }
                last = last->next;
            }
        }
    }
    *inner_start = last;
    return length;
}

Node *mergeNodes(Node *first, int length)
{
    Node *inner_beginning = first;
    int i = 0;
    int sum = 0;
    for(; i<length; i++)
    {
        sum += first->data;
        Node *remove = first;
        first = first->next;
        free(remove);
    }
    inner_beginning->next = first;
    return inner_beginning;
}

Node *removeNodesBetweenZeros(Node *start)
{
    Node *beginning = start;
    bool is_merge_required = false;

    while(start != NULL)
    {
        if(start->data == 0)
        {
            int length = does_merge_required(&start);
            if((length == 0) || (length == 1))
            {
                continue;
            }
            else
            {
                start = mergeNodes(start, length);
            }
        }
        start = start->next;
    }
}



int main(int argc, char *argv[])
{
    int option = 0;
    Node *start = NULL;
    while(1)
    {
        printf("1) Add node at the end\n2) Remove all the nodes between zero\n3) Print nodes\n4)Exit\n");
        scanf("%d", &option);
        switch(option)
        {
        case 1:
            {
                int data = 0;
                printf("Enter Value = ");
                scanf("%d", &data);
                printf("\n");
                start = addAtEnd(start, data);
                break;
            }
        case 2:
            {
                start = removeNodesBetweenZeros(start);
                break;
            }
        case 3:
            {
                printNodes(start);
                break;
            }
        case 4:
            {
                exit(0);
                break;
            }
        default:
            {
                printf("Wrong option. Try again.\n");
                break;
            }

        }
    }
    return 0;
}