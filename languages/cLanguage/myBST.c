#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	struct Node *left;
	int data;
	struct Node *right;
}Node;

Node *addNode(Node *root, int value)
{
	if(root == NULL)
	{
		Node *new_node = (Node *)malloc(sizeof(Node));
		if(new_node != NULL)
		{
			new_node->left = NULL;
			new_node->data = value;
			new_node->right = NULL;
			return new_node;
		}
	}

	if(value < root->data)
	{
		root->left = addNode(root->left, value);
	}
	else if(value > root->data)
	{
		root->right = addNode(root->right, value);
	}
	else
	{
		printf("Error: BST must have unique values\n");
	}
	return root;
}

void printInOrder(Node *root)
{
	if(root == NULL)
		return;
	
	printInOrder(root->left);
	printf("%d --> ", root->data);
	printInOrder(root->right);
}


int main(int argc, char *argv[])
{
	int choice = 0;
	Node *root = NULL;

	while(1)
	{
		printf("Choose from the option.\n");
		printf("1) Add Node\n2)Display Nodes\n3)Exit\n");
		scanf("%d", &choice);

		switch(choice)
		{
		case 1:
			{
				int value = 0;
				printf("Enter the Value\n");
				scanf("%d", &value);
				root = addNode(root, value);
				break;
			}
		case 2:
			{
				printInOrder(root);
				break;
			}
		case 3:
			{
				return -1;
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