#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	struct Node *left;
	int data;
	struct Node *right;
}Node;

Node *insert(Node *root, int data)
{

	if(root == NULL)
	{
		Node *temp = (Node *)malloc(sizeof(Node));
		if(temp != NULL)
		{
			temp->left = NULL;
			temp->data = data;
			temp->right = NULL;
			return temp;
		}
		else
		{
			printf("Error allocating memory to the temprary node.\n");
			return NULL;
		}
	}

	if(data < root->data)
	{
		root->left = insert(root->left, data);
	}
	else if(data > root->data)
	{
		root->right = insert(root->right, data);
	}

	return root;
}

void printPreOrder(Node *root)
{
	if(root == NULL)
		return;
	printf("%d\t", root->data);
	printPreOrder(root->left);
	printPreOrder(root->right);
}

void printInOrder(Node *root)
{
	if(root == NULL)
		return;
	printInOrder(root->left);
	printf("%d-->", root->data);
	printInOrder(root->right);
}

void printPostOrder(Node *root)
{
	if(root == NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	printf("%d\t", root->data);
}

int searchNode(Node *root, int data)
{
	if(root == NULL)
	{
		return -1;
	}
	searchNode(root->left, data);
	if(root->data == data)
	{
		return 0;
	}
	searchNode(root->right, data);

}

int findMinimumValue(Node *root)
{
	if(root->left == NULL)
	{
		return root->data;
	}

	findMinimumValue(root->left);
}

int findMaximumValue(Node *root)
{
	if(root->right == NULL)
	{
		return root->data;
	}

	findMaximumValue(root->right);
}

int findPreviousValue(Node *root, int data)
{
	// Find Previous Value in In-order BST is finding the predecessor

	Node *predecessor = NULL;
	Node *curr = root;

	while(curr != NULL)
	{
		if(data < curr->data)
		{
			curr = curr->left;
		}
		else if(data > curr->data)
		{
			predecessor = curr;
			curr = curr->right;
		}
		else
		{
			if(curr->left != NULL)
			{
				Node *temp = curr->left;
				while(temp->right != NULL)
					temp = temp->right;
				predecessor = temp;
			}
			break;
		}
	}
	return predecessor->data;
}

int main(int argc, char *argv[])
{
	int option = 0;
	int data = 0;
	Node *root = NULL;
	while(1)
	{
		printf("BST Menu:\n1)insert element\n2)delete element\n3)search element\n4)print element\n5)Find Minimum\n6)Find Maximum\n7)Find Previous\n8)exit\n");
		scanf("%d", &option);
		switch(option)
		{
		case 1:
			{
				printf("Plase enter the value: ");
				scanf("%d", &data);
				printf("\n");

				root = insert(root, data);
				break;
			}
		case 2:
			{
				break;
			}
		case 3:
			{
				printf("Plase enter the value: ");
				scanf("%d", &data);
				printf("\n");
				int result = searchNode(root, data);
				if(result == 0)
				{
					printf("%d is available in the tree.\n", data);
				}
				else
				{
					printf("%d is not available in the tree.\n", data);
				}
				break;
			}
		case 4:
			{
				int choice = 0;
				printf("How do you like to print the data?\n1)Pre-order?\n2)In-order?\n3)Post-order?\n4)Exit\n");
				scanf("%d", &choice);
				switch(choice)
				{
				case 1:
					{
						printPreOrder(root);
						break;
					}
				case 2:
					{
						printInOrder(root);
						break;
					}
				case 3:
					{
						printPostOrder(root);
						break;
					}
				case 4:
					{
						break;
					}
				default:
					{
						printf("Wrong input\n");
						break;
					}
				}
				break;
			}
		case 5:
			{
				int result = findMinimumValue(root);
				printf("Minimum Value in BST = %d\n", result);
				break;
			}
		case 6:
			{
				int result = findMaximumValue(root);
				printf("Maximum Value in BST = %d\n", result);
				break;
			}
		case 7:
			{
				printf("Plase enter the value: ");
				scanf("%d", &data);
				printf("\n");
				int result = findPreviousValue(root, data);
				printf("Previous Value of %d is %d\n", data, result);
				break;
			}
		case 8:
			{
				exit(0);
			}
		default:
			{
				printf("Enter valid option\n");
				break;
			}
		}
	}
	return 0;
}