#include "BinarySearchTree.h"
#include <time.h>

Node *root;
Node *root2;

 int main()
 {
	root = NULL;
	root2 = NULL;
	int randomData = 0;

	srand(time(NULL));

	for (int i = 0; i<30; ++i)
	{
		randomData = rand()%1000;
		BinarySearchTreeCreate(&root,randomData);
		BinaryTreeCreate(&root2,randomData);
	}

	bool isBinarySearchTree = BinarySearchTreeTest(root,0,1000);
	bool isBinarySearchTree2 = BinarySearchTreeTest(root2,0,1000);

	PrintNode(root);
	printf("\n%s\n", isBinarySearchTree ? "The tree is a binary search tree.\n" : "The tree is not a binary search tree.\n");
	PrintNode(root2);
	printf("\n%s\n", isBinarySearchTree2 ? "The tree is binary a search tree." : "The tree is not a binary search tree.");
 }
