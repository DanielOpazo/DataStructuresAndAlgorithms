#define TRUE 1
#define FALSE 0
//#define NULL (0)

typedef unsigned char tBoolean;

struct node {
    int data;
	struct node* left;
	struct node* right;
};

tBoolean lookupBST(struct node* node, int target);
struct node* insertBST(struct node* node, int data);
int size(struct node* node);
int maxDepth(struct node* node);
