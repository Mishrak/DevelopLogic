/* 	Input nodes 	: a->b->c->d->e->f->g

	Output nodes 	: a->g->b->f->c->e->d

*/


#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node *next;
}Node;

Node *addAtEnd(Node *start, int num)
{
	Node *temp = (Node *)malloc(sizeof(Node));
	if(temp == NULL)
	{
		printf("Error allocating memory to the new node.\n");
		return NULL;
	}

	temp->data = num;
	temp->next = NULL;

	if(start == NULL)
		return temp;

	Node *curr = start;
	while(curr->next != NULL)
		curr = curr->next;

	curr->next = temp;

	return start;
}

Node *addAtBeginning(Node *start, int num)
{
	Node *temp = (Node *)malloc(sizeof(Node));
	if(temp != NULL)
	{
		temp->data = num;
	}
	else
	{
		printf("Error allocating memory to the new node.\n");
		return NULL;
	}

	if(start == NULL)
	{
		temp->next = NULL;
		return temp;
	}
	temp->next = start;
	start = temp;

	return start;
}

Node *createList(Node *start)
{
	int number_of_nodes = 0;
	int data = 0;
	int i = 0;
	printf("Enter the number of nodes you want to enter? = \n");
	scanf("%d", &number_of_nodes);
	for(; i < number_of_nodes; i++)
	{
		printf("Enter the element to be inserted = \n");
		scanf("%d", &data);
		start = addAtEnd(start, data);
	}
	return start;
}

void display(Node *start)
{
	while(start)
	{
		printf("%d\t", start->data);
		start = start->next;
	}
	printf("\n\n\n");
}

Node *nodePattern(Node *start)
{
	// corner scenarios
	if(!start || !start->next || !start->next->next)
	{
		return NULL;
	}

	// Find the middle point
	Node *slow = start;
	Node *fast = start;

	while((fast->next != NULL) && (fast->next->next != NULL))
	{
		slow = slow->next;
		fast = fast->next->next;
	}

	// Split the linked list and reverse the secondhalf
	Node *curr = slow->next;
	Node *prev = NULL;
	Node *next = NULL;
	slow->next = NULL;

	while(curr != NULL)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}

	// interleave the nodes
	Node *first_half = start;
	Node *second_half = prev;

	while(second_half != NULL)
	{
		Node *tmp1 = first_half->next;
		Node *tmp2 = second_half->next;

		first_half->next = second_half;
		second_half->next = tmp1;

		first_half = tmp1;
		second_half = tmp2;
	}

	// return the final linkedlist
	return start;
}

int main(int argc, char *argv[])
{
	Node *start = NULL;

	start = createList(start);
	display(start);
	start = nodePattern(start);
	display(start);
	return 0;
}