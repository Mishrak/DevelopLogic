#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define TABLE_SIZE 1007

typedef struct Node
{
	int key;
	int count;
	struct Node *next;
}Node;

Node *table[TABLE_SIZE];

int hash(int key)
{
	return abs(key)%TABLE_SIZE;
}

bool checkTable(void)
{
	bool is_anagram = true;
	int i = 0;

	for(; i<TABLE_SIZE; i++)
	{
		Node *temp = table[i];
		while(temp != NULL)
		{
			if(temp->count != 0)
			{
				is_anagram = false;
			}
			Node *temp_temp = temp;
			temp = temp->next;
			free(temp_temp);
		}
		table[i] = NULL;
	}
	return is_anagram;

}

void updateTable(int key, int count)
{
	int idx = hash(key);
	Node *temp = table[idx];

	while(temp)
	{
		if(temp->key == key)
		{
			temp->count += count;
			return;
		}
		temp = temp->next;
	}

	Node *new_node = (Node *)malloc(sizeof(Node));
	if(new_node != NULL)
	{
		new_node->key = key;
		new_node->count = count;

		new_node->next = table[idx];
		table[idx] = new_node;
	}
}

bool myAnagram(const char *s1, const char *s2)
{
	int len1 = strlen(s1);
	int len2 = strlen(s2);

	int i = 0;
	if(len1 != len2)
		return false;

	for(; i<TABLE_SIZE; i++)
	{
		table[i] = NULL;
	}

	for(i=0; i<len1; i++)
	{
		updateTable(*s1, 1);
		updateTable(*s2, -1);
	}
	return checkTable();
}

int main(int argc, char *argv[])
{
	if(argc != 3)
	{
		printf("Usage: %s <string1> <string2>\n", argv[0]);
		return -1;
	}
	bool result = false;
	result = myAnagram(argv[1], argv[2]);
	if(result == true)
	{
		printf("%s and %s are anagram\n", argv[1], argv[2]);
	}	
	else
	{
		printf("%s and %s are not anagram\n", argv[1], argv[2]);
	}
	return 0;
}