#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	void *data;
	struct Node *next;
}Node;

void *pop(Node **start)
{
	void *data = NULL;
	if((*start) != NULL)
	{
		Node *temp = (*start);
		(*start) = (*start)->next;
		data = temp->data;
		free(temp);
		return data;
	}
	else
	{
		printf("Stack is empty\n");
	}
	return NULL;
}

Node *push(Node *start, void *value)
{
	Node *temp = (Node *)malloc(sizeof(Node));
	temp->data = value;
	temp->next = start;
	start = temp;

	return start;
}

int main(int argc, char *argv[])
{
	int intValue = 10;
	char charValue[] = "hello";

	Node *start = NULL;

	start = push(start, (void *)&intValue);
	start = push(start, (void *)charValue);

	void *resultValue = NULL;

	resultValue = pop(&start);
	printf("Popped Value = %s\n", (char *)resultValue);

	resultValue = pop(&start);
	printf("Popped Value = %d\n", *(int *)resultValue);

	return 0;
}