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
