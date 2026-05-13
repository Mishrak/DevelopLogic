#include "header.h"

void insert(int key)
{
	int idx = hash(key);

	Node *new_node = (Node *)malloc(sizeof(Node));
	new_node->key = key;

	// Add at beginning
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
		{
			return 1;
		}
		temp_node = temp_node->next;
	}
	return 0;
}

int * removeDuplicateElements(int input_array[], int size, int *output_array_size)
{
	int found = 0;
	*output_array_size = 0;

	for (int i = 0; i<TABLE_SIZE; i++)
		table[i] = NULL;

	int *output_array = (int *)malloc(size * sizeof(int));

	for(int i = 0; i<size; i++)
	{
		if(!search(input_array[i]))
		{
			// Element not found
			// Add to the hash table
			insert(input_array[i]);
			output_array[*output_array_size] = input_array[i];
			(*output_array_size)++;
		}
	}
	return output_array;
}

int main()
{
	int input_array[10] = {1,2,3,1,2,3,1,2,3,1};
	int size = sizeof(input_array) / sizeof(input_array[0]);
	int output_array_size = 0;

	int *output_array = removeDuplicateElements(input_array, size, &output_array_size);

	if(NULL != output_array)
	{
		printf("Output Array = [\t");
		for(int i = 0; i<output_array_size; i++)
			printf("%d\t", output_array[i]);
		printf("]\n");
	}

	return 0;
}