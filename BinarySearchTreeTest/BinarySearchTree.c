#include "BinarySearchTree.h"

int counter_data = 0;

/*
 * This function is to create a binary search tree.It takes currentNode
 * and newNodeValue as inputs.currentNode is head of the binary search
 * tree.newNodeValue is new value of node to insert in binary search
 * tree.It doesn't return a value as output. At the same time it doesn't
 * change any global variable.
 */
void BinarySearchTreeCreate(struct Node **currentNode, int newNodeValue)
{
	/* If there is not any value in the tree, first node is created. */
	if((*currentNode == NULL))
	{
		(*currentNode) = (struct Node *)malloc(sizeof(struct Node));
		(*currentNode)->value = newNodeValue;
		(*currentNode)->leftNode = NULL;
		(*currentNode)->rightNode = NULL;
	}

	/*
	 * If new value is bigger than current node value and left child is null,
	 * memory is allocated for new node and new value is assigned to left of
	 * the current node.Else call BinarySearchTreeCreate function with left
	 * child and new node value parameter to find correct position of new value.
	 */
	if (newNodeValue < (*currentNode)->value)
	{
		if ((*currentNode)->leftNode == NULL)
		{
			(*currentNode)->leftNode = (struct Node *)malloc(sizeof(struct Node));
			(*currentNode)->leftNode->value = newNodeValue;
		}
		else
		{
			BinarySearchTreeCreate(&((*currentNode)->leftNode),newNodeValue);
		}

	}

	/*
	 * If new value is smaller than current node value and right child is null,
	 * memory is allocated for new node and new value is assigned to right of
	 * the current node.Else call BinarySearchTreeCreate function with left
	 * child and new node value parameters to find correct position of new value.
	 */
	if (newNodeValue > (*currentNode)->value)
	{
		if ((*currentNode)->rightNode == NULL)
		{
			(*currentNode)->rightNode = (struct Node *)malloc(sizeof(struct Node));
			(*currentNode)->rightNode->value = newNodeValue;
		}
		else
		{
			BinarySearchTreeCreate((&(*currentNode)->rightNode), newNodeValue);
		}

	}

}


/*
 * This function is to create a binary tree.It takes currentNode
 * and newNodeValue as inputs.currentNode is head of the binary search
 * tree.newNodeValue is new value of node to insert in binary search
 * tree.It doesn't return a value as output. At the same time it doesn't
 * change any global variable.
 */
void BinaryTreeCreate(struct Node **currentNode, int newNodeValue)
{
	int random = rand()%2;

	/* If there is not any value in the current node, this position
	 * is correct position to add node. A random value is created to
	 * decide position of new node.If random value is 0, position of
	 * current node is updated as left of the current node.If random
	 * value is 1, position of current node is updated as right of
	 * the current node.
	 */
	if(*currentNode == NULL)
	{
		*currentNode = (struct Node *)malloc(sizeof(struct Node));
		(*currentNode)->value = newNodeValue;
		(*currentNode)->leftNode = NULL;
		(*currentNode)->rightNode = NULL;
	}
	else if(random == 0 && *currentNode != NULL)
	{
		BinaryTreeCreate(&((*currentNode)->leftNode), newNodeValue);
	}
	else if(random == 1 && *currentNode != NULL)
	{
		BinaryTreeCreate(&((*currentNode)->rightNode), newNodeValue);
	}

 }


/*
 * This function is to show values in the tree.It takes
 * root of the tree as input and doesn't return an output.
 * At the same time it doesn't change any global variable.
 */
void PrintNode(Node *currentNode)
{
	if (currentNode == NULL)
	{
		return;
	}

	if (currentNode->leftNode != NULL)
	{
		PrintNode(currentNode->leftNode);
	}

	printf (" %d ", currentNode->value);

	if (currentNode->rightNode != NULL)
	{
		PrintNode(currentNode->rightNode);
	}

}


/*
 * This function is created to check a tree,binary search tree
 * or not. It takes root of the tree, a min and max values as
 * input. The function starts from root of the tree to decide binary
 * search tree or not.min and max values are updated for each node
 * during the test.These values are compared value of current node.
 * If value of current node doesn't stay in min-max range during
 * the test, the function returns false as output.Finally if
 * current node is null the function returns true as output.
 * The function doesn't change any global variable.
 */
bool BinarySearchTreeTest(Node *currentNode, int min, int max)
{
	if(currentNode == NULL)
	{
		return true;
	}

	if(!(min <= currentNode->value && currentNode->value < max))
	{
		return false;
	}

	return BinarySearchTreeTest(currentNode->leftNode, min, currentNode->value);
	return BinarySearchTreeTest(currentNode->rightNode, currentNode->value, max);
}
