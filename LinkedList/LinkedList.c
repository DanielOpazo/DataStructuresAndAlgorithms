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

void destroyList(struct node** head) {
	if (head == NULL)
		return;

	struct node* temp = NULL;
	while (*head != NULL) {
		temp = *head;
		*head = (*head)->next;
		printf("freeing %d\n", temp->data);
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
