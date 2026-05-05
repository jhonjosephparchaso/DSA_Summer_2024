#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char name[20];
	int idNum;
	int age;
}info;

typedef struct node {
	info data;
	struct node* next;
}Node, *NodePtr;

void initList(NodePtr* head){
	*head = NULL;
}

void display(NodePtr head)
{
	int ctr = 0;
	for(;head != NULL; head = head->next){
		printf("%s = %d = %d\n", head->data.name, head->data.idNum, head->data.age);
		ctr++;
	}
	printf("\nTotal: %d", ctr);
}

void insertFirst(NodePtr* head, info elem){
	NodePtr temp;
	temp = (NodePtr)malloc(sizeof(Node));
	if(temp!=NULL){
		temp->data = elem;
		temp->next = *head;
		*head = temp;
	}
}

void insertLast(NodePtr* head, info elem){
	NodePtr *trav, temp;
	temp = (NodePtr)malloc(sizeof(Node));
	if(temp!=NULL){
	for(trav=head; *trav != NULL; trav = &(*trav)->next){}
		temp->data = elem;
		temp->next = *trav;
		*trav = temp;
	}
}

void insertatIndex(NodePtr* head, info elem, int ndx){
	NodePtr *trav, temp;
	int ctr = 0;

	temp = (NodePtr)malloc(sizeof(Node));
	if(temp!=NULL){
		for(trav=head; ctr < ndx && *trav != NULL; trav = &(*trav)->next, ctr++){}
		if(ctr < ndx){
			temp->data = elem;
			temp->next = *trav;
			*trav = temp;
		}
	}	
}

void insertSorted(NodePtr* head, info elem){
	NodePtr *trav, temp;
	temp = (NodePtr)malloc(sizeof(Node));
	if(temp!=NULL){
		for(trav=head; *trav != NULL && (*trav)->data.age <= elem.age; trav = &(*trav)->next){}
		temp->data = elem;
		temp->next = *trav;
		*trav = temp;
	}
}

void deleteFirst(NodePtr* head){
	NodePtr temp = *head;
	*head = (*head)->next;
	free(temp);
}

void deleteLast(NodePtr* head) {
    if (*head == NULL) return;

    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    NodePtr *trav;
    for (trav = head; (*trav)->next->next != NULL; trav = &(*trav)->next) {}
    free((*trav)->next);
    (*trav)->next = NULL;
}

void deleteMember(NodePtr* head, info elem) {
    NodePtr *trav, temp;
    for (trav = head; *trav != NULL && (strcmp((*trav)->data.name, elem.name) != 0 || (*trav)->data.idNum != elem.idNum || (*trav)->data.age != elem.age); trav = &(*trav)->next) {}

    if (*trav != NULL) {
        temp = *trav;
        *trav = (*trav)->next;
        free(temp);
    }
}

int main(void) {
	
	NodePtr LL;
	info students[] = {{"Parchaso", 18100807, 24},
					   {"Potot", 18102727, 23},
					   {"Achas", 18101111, 24},
					   {"Menano", 18102222, 70},
					   {"Maya", 99999, 24},
					   {"Collado", 18103333, 55},
					   {"baloy", 10000001, 69}
					  };
					  
	initList(&LL);
	
	insertFirst(&LL, students[0]);
	insertFirst(&LL, students[3]);
	insertLast(&LL, students[2]);
	insertLast(&LL, students[1]);
	insertatIndex(&LL, students[4], 2);
	insertSorted(&LL, students[6]);
	display(LL);
	
	printf("\n\n");
	
	deleteFirst(&LL);
	deleteLast(&LL);
	deleteLast(&LL);
	deleteMember(&LL, students[4]);
	display(LL);
	
	return 0;
}
