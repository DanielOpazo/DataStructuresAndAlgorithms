struct node {
	int data;
	struct node* next;
};

//adds new element to head of the list
void push(struct node** head, int val);
//frees list memory
void destroyList(struct node** head);
//return the number of nodes in the list
int count(struct node* head);
//print the elements in the list
void printList(struct node* head);
