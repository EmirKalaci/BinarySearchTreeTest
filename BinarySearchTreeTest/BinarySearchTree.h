#include <stdbool.h>
#include <stdio.h>

#define NULL ((void *)0)

typedef struct Node
 {
 	int value;
 	struct Node *leftNode;
 	struct Node *rightNode;
} Node;

bool BinarySearchTreeTest(Node *,int ,int);
void BinaryTreeCreate(Node **, int);
void BinarySearchTreeCreate(Node **, int);
void PrintNode(Node *);


