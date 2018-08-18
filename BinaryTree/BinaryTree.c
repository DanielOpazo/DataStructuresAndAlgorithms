#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

tBoolean lookupBST(struct node* node, int target) {
	if (node == NULL) {
		return FALSE;
	} else {
		if (node->data == target) {
			return TRUE;
		} else {
			if (node->data > target)
				return lookupBST(node->left, target);
			else
				return lookupBST(node->right, target);
		}
	}
}

struct node* newNode(int data) {
	struct node* newNode = malloc(sizeof(newNode));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

struct node* insertBST(struct node* node, int data) {
	if (node == NULL) {
		return newNode(data);
	} else {
		if (node->data > data) {
			node->left = insertBST(node->left, data);
		} else if (node->data < data){
			node->right = insertBST(node->right, data);
		}
		//else duplicate, don't insert
		return node;
	}
}

int size(struct node* node) {
	if (node == NULL)
		return 0;
	else
		return 1 + size(node->left) + size(node->right);
}

int maxDepth(struct node* node) {
	if (node == NULL)
		return 0;

	int depthLeft = 1 + maxDepth(node->left);
	int depthRight = 1 + maxDepth(node->right);
	return (depthLeft > depthRight) ? depthLeft : depthRight;
}

void printTreeInOrder(struct node* node) {
	if (node == NULL)
		return;

	printTreeInOrder(node->left);
	printf("%d\n", node->data);
	printTreeInOrder(node->right);
}

void printTreePostOrder(struct node* node) {
	if (node == NULL)
		return;

	printTreePostOrder(node->left);
	printTreePostOrder(node->right);
	printf("%d\n", node->data);
}

//this'll return true for empty tree and sum 0
tBoolean hasPathSum(struct node* node, int sum) {
	if (node == NULL)
		return (sum == 0) ? TRUE : FALSE;

	if (hasPathSum(node->left, sum - node->data) ||
		 hasPathSum(node->right, sum - node->data))
		return TRUE;
	
	return FALSE;
}

void mirror(struct node* node) {
	if (node == NULL) return;
	struct node* temp;
	temp = node->left;
	node->left = node->right;
	node->right = temp;
	mirror(node->left);
	mirror(node->right);
}
