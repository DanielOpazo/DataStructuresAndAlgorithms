struct node {
	int data;
	struct node* next;
};

//adds new element to head of the list
void push(struct node** head, int val);
//removes head from the list and returns its data
int pop(struct node** head);
//insert into range [0..length]
void insertNth(struct node** head, int index, int data);
//frees list memory
void destroyList(struct node** head);
//return the number of nodes in the list
int count(struct node* head);
//print the elements in the list
void printList(struct node* head);
