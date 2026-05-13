#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int key;
    int index;
    struct Node* next;
} Node;

#define TABLE_SIZE 7

int hash(int key) { return abs(key) % TABLE_SIZE; }

Node* table[TABLE_SIZE];

void insert(int key, int index) {
    int idx = hash(key);
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->index = index;

    newNode->next = table[idx];
    table[idx] = newNode;
}

int search(int key, int* index) {
    int found = -1;
    int idx = hash(key);
    Node* temp = table[idx];
    while (temp) {
        if (temp->key == key) {
            (*index) = temp->index;
            found = 0;
            break;
        }
        temp = temp->next;
    }
    //printf("temp->index = %d : *index = %d\n", temp->index, (*index));
    return found;
}

int* twoSum(int inputArray[], int sizeOfInputArray, int target) {
    int i = 0;
    int index = 0;
    for (; i < TABLE_SIZE; i++)
        table[i] = NULL;

    for (i = 0; i < sizeOfInputArray; i++) {
        int element = target - inputArray[i];
        if (search(element, &index) == 0) {
            int* output = (int*)malloc(2 * sizeof(int));
            output[0] = i;
            output[1] = index;
            return output;
        }
        insert(inputArray[i], i);
    }
    return NULL;
}

int main()
{
	int input_array[10] = {1,2,3,4,5,6,7,8,9,10};
	int target = 9;
	int size = sizeof(input_array) / sizeof(input_array[0]);

	int *output = twoSum(input_array, size, target);
	if(output != NULL)
	{
		printf("output indexes = [%d %d]\n", output[1], output[0]);
	}
	else
	{
		printf("No combination found.\n");
	}

	return 0;
}