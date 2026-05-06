#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
	struct Node *prev;
	int data;
	struct Node *next;
}Node;


Node *addAtEnd(Node *start, int data)
{
	Node *beginning = start;
	Node *temp = (Node *)malloc(sizeof(Node));
	if(temp != NULL)
	{
		temp->data = data;
		temp->next = NULL;
	}
	else
	{
		printf("Error allocating memory to the node.\n");
		return NULL;
	}

	if(start == NULL)
	{
		temp->prev = NULL;
		return temp;
	}

	while(start->next != NULL)
	{
		start = start->next;
	}
	start->next = temp;
	temp->prev = start;

	return beginning;
}

void display(Node *start)
{
	while(start)
	{
		printf("%d\t", start->data);
		start = start->next;
	}
}

Node *addAtBeginning(Node *start, int data)
{
	Node *temp = (Node *)malloc(sizeof(Node));
	if(temp != NULL)
	{
		temp->prev = NULL;
		temp->data = data;
	}
	else
	{
		printf("Error allocating memeory to the new node.\n");
		return NULL;
	}

	if(start == NULL)
	{
		temp->next = NULL;
		return temp;
	}

	temp->next = start;
	start->prev = temp;

	return temp;
}

Node *removePerticularNode(Node *start, int data)
{
	if(start == NULL)
	{
		printf("Error: LinkedList is Empty\n");
		return NULL;
	}

	Node *curr = start;
	while((curr != NULL) && (curr->data != data))
	{
		curr = curr->next;
	}

	if(curr == start)
	{
		start = curr->next;
	}

	if(curr->next != NULL)
	{
		curr->next->prev = curr->prev;
	}

	if(curr->prev != NULL)
	{
		curr->prev->next = curr->next;
	}

	free(curr);
	return start;
}

Node *removeAllNodes(Node *start, int data)
{
	bool is_data_available = false;
	if(start == NULL)
	{
		printf("Error: LinkedList is Empty\n");
		return NULL;
	}

	Node *curr = start;

	while(curr != NULL)
	{
		if(curr->data != data)
		{
			curr = curr->next;
			continue;
		}
		is_data_available = true;
		Node *remove_node = curr;

		if(curr == start)
		{
			start = curr->next;
		}

		if(curr->next != NULL)
		{
			curr->next->prev = curr->prev;
		}

		if(curr->prev != NULL)
		{
			curr->prev->next = curr->next;
		}
		free(remove_node);
	}

	if((curr == NULL) && (is_data_available == false))
	{
		printf("LinkedList does not contain the value %d\n", data);
	}
	return start;
}

int main(int argc, char *argv[])
{
	Node *start = NULL;
	int option = 0;
	while(1)
	{
		printf("Enter your option.\n");
		printf("1) Create a LinkedList\n2) Add at beginning\n3) Add at the end\n4) Display\n5) Remove a perticular Node\n6) Remove all the occurance of a Node\n7) Exit\n");
		scanf("%d", &option);


		switch(option)
		{
		case 1:
			{
				int choice = 0;
				int i = 0;
				printf("Enter the number of nodes you want to enter?\n");
				scanf("%d", &choice);
				for(; i<choice; i++)
				{
					int value = 0;
					printf("Enter the Value\n");
					scanf("%d", &value);
					start = addAtEnd(start, value);
				}
				break;
			}
		case 2:
			{
				int value = 0;
				printf("Enter the Value\n");
				scanf("%d", &value);
				start = addAtBeginning(start, value);
				break;
			}
		case 3:
			{
				int value = 0;
				printf("Enter the Value\n");
				scanf("%d", &value);
				start = addAtEnd(start, value);
				break;
			}
		case 4:
			{
				display(start);
				break;
			}
		case 5:
			{
				int value = 0;
				printf("Enter the Value you want to remove from the LinkedList\n");
				scanf("%d", &value);
				start = removePerticularNode(start, value);
				break;
			}
		case 6:
			{
				int value = 0;
				printf("Enter the Value you want to remove from the LinkedList\n");
				scanf("%d", &value);
				start = removeAllNodes(start, value);
				break;
				break;
			}
		case 7:
			{
				return 0;
				break;
			}
		default:
			{
				break;
			}
		}
	}
	
	return 0;
}