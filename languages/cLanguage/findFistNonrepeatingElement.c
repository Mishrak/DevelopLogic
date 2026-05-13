#include "header.h"

void insert(int key)
{
	int idx = hash(key);
	Node *new_node = (Node *)malloc(sizeof(Node));

	new_node->key = key;

	new_node->next = table[idx];
	table[idx] = new_node;
}

int search(int key)
{
	int idx = hash(key);

	Node *temp_node = table[idx];
	while(temp_node)
	{
		if(temp_node->key == key)
			return 1;
		temp_node = temp_node->next;
	}
	return 0;
}

int findFirstNonrepeatingElement(int input_array[], int size)
{
	int found = 0;
	for(int i=0; i<TABLE_SIZE; i++)
		table[i] = NULL;

	for(int i=0; i<size; i++)
	{
		found = search(input_array[i]);
		if(!found)
			return input_array[i];
		else
			insert(input_array[i]);
	}
	return -1;
}

int main()
{
	int input_array[10] = {1,2,3,1,2,3,1,2,3,4};
	int size = sizeof(input_array)/sizeof(input_array[0]);

	int result = findFirstNonrepeatingElement(input_array, size);
	printf("Result = %d\n", result);
	return 0;
}