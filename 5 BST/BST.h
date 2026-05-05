#ifndef BST
#define BST

typedef struct {
	int date, month, year;
} Date;

typedef struct {
	char prodName[20];
	float prodPrice;
	int prodQty;
	Date expDate;
} Product;

typedef struct node{
	Product item;
	struct node *left, *right;
} Nodetype, *NodePtr;

void initTree(NodePtr* TREE);
void add(NodePtr* TREE, Product item);
void delete(NodePtr* TREE, char prodName[]);
void BFS(NodePtr TREE);
void inOrder(NodePtr TREE);
void postOrder(NodePtr TREE);
void preOrder(NodePtr TREE);

#endif


