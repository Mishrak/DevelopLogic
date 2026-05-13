#include "header.h"


void searchAndUpdate(int key)
{
	int idx = hash(key);
	Node *temp_node = table[idx];

	while(temp_node)
	{
		if(temp_node->key == key)
		{
			temp_node->value = temp_node->value + 1;
			return;
		}
		temp_node = temp_node->next;
	}

	Node *new_node = (Node *)malloc(sizeof(Node));
	new_node->key = key;
	new_node->value = 1;

	new_node->next = table[idx];
	table[idx] = new_node;
}

void countFrequenctOfElements(int input_array[], int size)
{
	int found = 0;
	// Initialize hashTable
	for (int i=0; i<TABLE_SIZE; i++)
		table[i] = NULL;

	// Traverse and Update the Table
	for(int i=0; i<size; i++)
		searchAndUpdate(input_array[i]);

	printf("\tElement\t--->\tCount\n");
	for(int i=0; i<TABLE_SIZE; i++)
	{
		Node *temp = table[i];
		while(temp)
		{
			printf("\t%d\t--->\t%d\n", temp->key, temp->value);
			temp = temp->next;
		}
		
	}
}

int main()
{
	int input_array[10] = {1,2,3,1,2,3,1,2,3,1};
	int size = sizeof(input_array)/sizeof(input_array[0]);

	countFrequenctOfElements(input_array, size);
	return 0;
}