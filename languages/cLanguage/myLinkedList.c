#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node *next;
}Node;


Node *addAtEnd(Node *start, int data)
{
	Node *new_node = (Node *)malloc(sizeof(Node));
	if(new_node == NULL)
	{
		printf("Error allocating mempry to the new node.\n");
		return start;
	}
	new_node->data = data;
	new_node->next = NULL;

	if(start == NULL)
	{
		return new_node;
	}

	Node *curr = start;
	while(curr->next != NULL)
	{
		curr = curr->next;
	}
	curr->next = new_node;

	return start;
}

Node *createList(Node *start)
{
	int choice = 0;
	int i = 0;
	printf("Enter the number of Nodes you want to Enter.\n");
	scanf("%d", &choice);
	for(; i<choice; i++)
	{
		int value = 0;
		printf("Enter the Value\n");
		scanf("%d", &value);
		start = addAtEnd(start, value);
	}
	return start;
}

void display(Node *start)
{
	if(start == NULL)
	{
		printf("LinkedList is Empty\n");
		return;
	}
	while(start != NULL)
	{
		printf("%d\t", start->data);
		start = start->next;
	}
	printf("\n");
}

int countNumberOfNodes(Node *start)
{
	int count = 0;
	if(start == NULL)
	{
		printf("LinkedList is Empty\n");
		return -1;
	}
	while(start != NULL)
	{
		count++;
		start = start->next;
	}
	return count;
}

int searchElement(Node *start, int data)
{
	int count = 0;
	if(start == NULL)
	{
		printf("LinkedList is Empty\n");
		return -1;
	}

	while(start != NULL)
	{
		count++;
		if(start->data == data)
		{
			return count;
		}
		start = start->next;
	}
	return -1;
}

Node *addAtBeginning(Node *start, int data)
{
	Node *new_node = (Node *)malloc(sizeof(Node));
	if(new_node == NULL)
	{
		printf("Error allocating memory to the new node\n");
		return start;
	}

	new_node->data = data;

	if(start == NULL)
	{
		new_node->next = NULL;
		return new_node;
	}

	new_node->next = start;
	return new_node;
}

Node *addNodeAfterSpecificNode(Node *start, int dataToBeInserted, int availableData)
{
	if(start == NULL)
	{
		printf("Error allocating memory to the new node\n");
		return NULL;
	}

	Node *new_node = (Node *)malloc(sizeof(Node));
	if(new_node == NULL)
	{
		printf("Error allocating memory to the new node\n");
		return start;
	}

	new_node->data = dataToBeInserted;


	Node *curr = start;
	while(curr != NULL)
	{
		if(curr->data == availableData)
		{
			new_node->next = curr->next;
			curr->next = new_node;
			break;
		}
		curr = curr->next;
	}
	if(curr == NULL)
	{
		printf("%d is not available in the linkedList.\n", availableData);
	}
	return start;
}

Node *addNodeBeforeSpecificNode(Node *start, int dataToBeInserted, int availableData)
{
	if(start == NULL)
	{
		printf("Error allocating memory to the new node\n");
		return NULL;
	}

	Node *new_node = (Node *)malloc(sizeof(Node));
	if(new_node == NULL)
	{
		printf("Error allocating memory to the new node\n");
		return start;
	}

	new_node->data = dataToBeInserted;

	Node *curr = start;
	Node *prev = start;
	while(curr != NULL)
	{
		if(curr->data == availableData)
		{
			new_node->next = curr;
			if(curr == prev)
			{
				return new_node;
			}
			prev->next = new_node;
			break;
		}
		prev = curr;
		curr = curr->next;
	}
	return start;
}


Node *addNodeAtSpecificPosition(Node *start, int dataToBeInserted, int position)
{
	if(start == NULL)
	{
		printf("Error allocating memory to the new node\n");
		return NULL;
	}
	int count = countNumberOfNodes(start);
	if((position > count+1) || (position < 1))
	{
		printf("Entered position is beyond the limit.\n");
		return start;
	}

	Node *new_node = (Node *)malloc(sizeof(Node));
	if(new_node == NULL)
	{
		printf("Error allocating memory to the new node\n");
		return start;
	}

	new_node->data = dataToBeInserted;

	Node *curr = start;
	Node *prev = start;
	while(position > 0)
	{
		prev = curr;
		curr = curr->next;
		position--;
	}
}

void printSplittedLinkedList(Node *even, Node *odd)
{
	if(even == NULL && odd == NULL)
    {
        printf("Empty LinkedList\n");
        return;
    }

    printf("EvenList (Index 0, 2, 4) = ");
    Node *tempE = even;
    while(tempE != NULL)
    {
        printf("%d\t", tempE->data);
        tempE = tempE->next;
    }
    printf("\n");

    printf("OddList  (Index 1, 3, 5) = ");
    Node *tempO = odd;
    while(tempO != NULL)
    {
        printf("%d\t", tempO->data);
        tempO = tempO->next;
    }
    printf("\n");

}

void splitLinkedListInEvenAndOdd(Node *start, Node **even, Node **odd)
{
	if(start == NULL)
	{
		(*even) = NULL;
		(*odd) = NULL;
		printf("LinkedList is Empty\n");
		return;
	}

	(*even) = start;
	(*odd) = start->next;
	Node *e = (*even);
	Node *o = (*odd);

	while((o != NULL) && (o->next != NULL))
	{
		e->next = o->next;
		e = e->next;

		o->next = e->next;
		o = o->next;
	}

	if (e != NULL)
	{
        e->next = NULL;
    }
}

int main(void)
{
	int choice = 0;
	int data = 0;
	int item = 0;
	Node *start = NULL;

	while(1)
	{
		printf("1. Create List\n");
		printf("2. Display\n");
		printf("3. Count\n");
		printf("4. Search\n");
		printf("5. Add at the beginning\n");
		printf("6. Add at end\n");
		printf("7. Add after node\n");
		printf("8. Add before node\n");
		printf("9. Add at position\n");
		printf("10. Delete\n");
		printf("11. Reverse\n");
		printf("12. Seperate Even and Odd LinkedList\n");
		printf("13. Quit\n");
		printf("Enter Your choice = ");
		scanf("%d", &choice);
		printf("\n");

		switch (choice)
		{
		case 1:
			{
				start = createList(start);
				break;
			}
		case 2:
			{
				display(start);
				break;
			}
		case 3:
			{
				int count = 0;
				count = countNumberOfNodes(start);
				printf("Count = %d\n", count);
				break;
			}
		case 4:
			{
				printf("Enter the element to be searched = ");
				scanf("%d", &data);
				printf("\n");
				int result = searchElement(start, data);
				if(result == -1)
				{
					printf("%d is not present in the LinkedList\n", data);
				}
				else
				{
					printf("%d is found at the position %d\n", data, result);
				}
				break;
			}
		case 5:
			{
				printf("Enter the element to be inserted = ");
				scanf("%d", &data);
				start = addAtBeginning(start, data);
				break;
			}
		case 6:
			{
				printf("Enter the element to be inserted = ");
				scanf("%d", &data);
				start = addAtEnd(start, data);
				break;
			}
		case 7:
			{
				printf("Enter the element to be inserted = ");
				scanf("%d", &data);
				printf("Enter the element after which you want to insert %d = ", data);
				scanf("%d", &item);
				start = addNodeAfterSpecificNode(start, data, item);
				break;
			}
		case 8:
			{
				printf("Enter the element to be inserted = ");
				scanf("%d", &data);
				printf("Enter the element before which you want to insert %d = ", data);
				scanf("%d", &item);
				start = addNodeBeforeSpecificNode(start, data, item);
				break;
			}
		case 9:
			{
				printf("Enter the element to be inserted = ");
				scanf("%d", &data);
				printf("Enter the element at which position you want to insert %d = ", data);
				scanf("%d", &item);
				start = addNodeAtSpecificPosition(start, data, item);
				break;
			}
		case 10:
			{
				printf("Enter the element to be deleted = ");
				scanf("%d", &data);
				//start = deleteElement(start, data);
				break;
			}
		case 11:
			{
				//start = reverseElement(start);
				break;
			}
		case 12:
			{
				Node *even = NULL;
				Node *odd = NULL;
				splitLinkedListInEvenAndOdd(start, &even, &odd);
				printSplittedLinkedList(even, odd);
			}
		case 13:
			{
				if(start)
					free(start);
				exit(0);
				break;
			}
		default:
			{
				printf("Wrong Choice. Try Again\n");
				break;
			}
		}
	}
	return 0;
}