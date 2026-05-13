#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	void *data;
	struct Node *next;
}Node;

void push(Node **start, void *data)
{
	Node *temp = (Node *)malloc(sizeof(Node));
	if(temp == NULL)
		return;

	temp->data = data;
	temp->next = *start;
	*start = temp;
}

void *pop(Node **start)
{
	if((*start) == NULL)
	{
		printf("Stack is Empty\n");
		return NULL;
	}

	Node *toDelete = *start;
	void *data = toDelete->data;
	
	*start = (*start)->next;
	free(toDelete);

	return data;
}

int main(int argc, char *argv[])
{
	Node *start = NULL;
	int intData = 15;
	char *pCharData = "Mishrak";
	float floatData = 10.55;
	void *pPoppedData = NULL;

	push(&start, &intData);
	push(&start, pCharData);
	push(&start, &floatData);

	pPoppedData = pop(&start);
	printf("Float = %f\n", *(float *)pPoppedData);

	pPoppedData = pop(&start);
	printf("String = %s\n", (char *)pPoppedData);

	pPoppedData = pop(&start);
	printf("Int = %d\n", *(int *)pPoppedData);


	return 0;
}