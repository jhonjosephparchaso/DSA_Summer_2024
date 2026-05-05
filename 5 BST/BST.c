#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BST.h"
#define MAX 10

void initTree(NodePtr* TREE){
	*TREE = NULL;	
}

void add(NodePtr* TREE, Product item){
	NodePtr* trav;
	for(trav = TREE; *trav != NULL; trav = (strcmp((*trav)->item.prodName, item.prodName) < 0)? &(*trav)->right : &(*trav)->left){}
	if(*trav == NULL){
		*trav = (NodePtr)malloc(sizeof(Nodetype));
		if(*trav != NULL){
			(*trav)->item = item;
	        (*trav)->left = NULL;
	        (*trav)->right = NULL;
		}
	}
}

void delete(NodePtr* TREE, char prodName[]) {
    NodePtr trav;
    NodePtr parent = NULL;
    NodePtr target = NULL;
    
    for(trav = *TREE; trav != NULL && strcmp(trav->item.prodName, prodName) != 0; trav = (strcmp(trav->item.prodName, prodName) < 0)? trav->right : trav->left){}
    parent = trav;

    if (trav == NULL) {
        printf("\nProduct '%s' not found.\n", prodName);
        return;
    } else {
        target = trav;
    }

    if (target->left == NULL && target->right == NULL) {
        if (parent == NULL) {
            *TREE = NULL;
        } else if (parent->left == target) {
            parent->left = NULL;
        } else {
            parent->right = NULL;
        }
        free(target);
    }
    else if (target->left == NULL || target->right == NULL) {
        NodePtr child = (target->left != NULL) ? target->left : target->right;

        if (parent == NULL) {
            *TREE = child;
        } else if (parent->left == target) {
            parent->left = child;
        } else {
            parent->right = child;
        }
        free(target);
    }
    else {
        NodePtr successor = target->right;
        parent = NULL;

        while (successor->left != NULL) {
            parent = successor;
            successor = successor->left;
        }

        strcpy(target->item.prodName, successor->item.prodName);
        target->item.prodPrice = successor->item.prodPrice;
        target->item.prodQty = successor->item.prodQty;
        target->item.expDate = successor->item.expDate;

        if (parent == NULL) {
            target->right = successor->right;
        } else {
            parent->left = successor->right;
        }
        free(successor);
    }
}

void BFS(NodePtr TREE) {

    NodePtr queue[MAX];
	int front = 0, rear = 0;

    queue[rear++] = TREE;
	
    while (front < rear) {
        NodePtr trav = queue[front++];
        printf("Name: %s\t Price: %.2f\t Quantity: %d\t Expiry: %d/%d/%d\n",
               trav->item.prodName, trav->item.prodPrice, trav->item.prodQty,
               trav->item.expDate.date, trav->item.expDate.month, trav->item.expDate.year);

        if (trav->left != NULL)
            queue[rear++] = trav->left;
        if (trav->right != NULL)
            queue[rear++] = trav->right;
    }
}

void inOrder(NodePtr TREE) {
    if (TREE != NULL) {
        inOrder(TREE->left);
        printf("Name: %s\t Price: %.2f\t Quantity: %d\t Expiry: %d/%d/%d\n",
               TREE->item.prodName, TREE->item.prodPrice, TREE->item.prodQty,
               TREE->item.expDate.date, TREE->item.expDate.month, TREE->item.expDate.year);
        inOrder(TREE->right);
    }
}

void postOrder(NodePtr TREE){
    if (TREE != NULL) {
        postOrder(TREE->left);
        postOrder(TREE->right);
        printf("Name: %s\t Price: %.2f\t Quantity: %d\t Expiry: %d/%d/%d\n",
               TREE->item.prodName, TREE->item.prodPrice, TREE->item.prodQty,
               TREE->item.expDate.date, TREE->item.expDate.month, TREE->item.expDate.year);
    }
}

void preOrder(NodePtr TREE){
    if (TREE != NULL) {
        printf("Name: %s\t Price: %.2f\t Quantity: %d\t Expiry: %d/%d/%d\n",
               TREE->item.prodName, TREE->item.prodPrice, TREE->item.prodQty,
               TREE->item.expDate.date, TREE->item.expDate.month, TREE->item.expDate.year);
        preOrder(TREE->left);
        preOrder(TREE->right);
    }	
}


