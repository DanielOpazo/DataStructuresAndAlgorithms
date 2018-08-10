#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

void printList(struct node* head) {
	struct node* curr = head;
	if (curr == NULL) {
		printf("Empty List\n");
	} else {
		while (curr != NULL) {
			printf("%d->", curr->data);
			curr = curr->next;
		}
		printf("NULL\n");
	}
}

void push(struct node** head, int val) {
	struct node* newNode = malloc(sizeof(struct node));
	newNode->data = val;
	newNode->next = *head;
	*head = newNode;	
}

int pop(struct node** head) {
	assert(head != NULL && *head != NULL);

	int data = 0;
	struct node* temp = *head;
	*head = (*head)->next;
	data = temp->data;
	free(temp);
	return data;
}

void insertNth(struct node** head, int index, int data)
{
	assert(head != NULL);
	struct node* before = *head;
	int idx = 0;
	//find the node before where we want to insert
	while (idx < index-1) {
		before = before->next;
		//reached end of list before getting to index
		assert(before != NULL);
		idx++;
	}

	//get the node after
	struct node* after = before->next;
	//there is no before if we're the new head
	if (index == 0)
		after = *head;

	//allocate new node and set data
	struct node* new = malloc(sizeof(struct node));
	new->data = data;
	new->next = after;
	
	if (index == 0)	{
		*head = new;
	} else {
		before->next = new;
	}

}

void destroyList(struct node** head) {
	if (head == NULL)
		return;

	struct node* temp = NULL;
	while (*head != NULL) {
		temp = *head;
		*head = (*head)->next;
		free(temp);
	}
}

int count(struct node* head) {
	int count = 0;
	struct node* curr = head;
	while (curr != NULL) {
		count++;
		curr = curr->next;
	}
	return count;
}

void recurse(struct node* curr, struct node* prev, struct node** head) {
	struct node* copyNext = curr->next;
	//my next is my previous
	curr->next = prev;

	//base case. at end of list
	if (copyNext == NULL) {
		//current is my new head
		*head = curr;
		return;
	}

	recurse(copyNext, curr, head);
}

//recursively reverse
void reverseList(struct node** head) {
	recurse(*head, NULL, head);
}
