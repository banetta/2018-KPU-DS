#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode *link;
} ListNode;

ListNode *create_node(element data, ListNode *link){

	ListNode *new_node;
	new_node = (ListNode *)malloc(sizeof(ListNode));
	if ( new_node = NULL ) {
		perror("메모리 할당 에러");
	}
	new_node->data = data;
	new_node->link = link;
	return(new_node);
}

void display(ListNode *head){
	
	ListNode *p;
	if ( head == NULL ) return;

	p = head;
	do {
		printf("%d->", p->data);
		p = p->link;
	}
	while( p != head);
}

void insert_first(ListNode **phead, ListNode *node){

	if ( phead == NULL) {
		*phead = node;
		node->link = node;
	}
	else{
		node->link = (*phead)->link;
		(*phead)->link = node;
	}
}

void insert_last(ListNode **phead, ListNode *node){

	if ( *phead == NULL) {
		*phead = node;
		node->link = node;
	}
	else {
		node->link = (*phead)->link;
		(*phead)->link = node;
		*phead = node;
	}
}

void get_length(ListNode *head) {

	int i = NULL;
	ListNode *p;
	if ( head == NULL ) return;

	p = head;

	do {
		p = p->link;
		
		i++;
	}
	while( p != head);

	printf("length : %d\n", i);
}


int main() {

	ListNode *list1 = NULL;

	insert_first(&list1, create_node(10, NULL));

	insert_first(&list1, create_node(20, NULL));

	insert_last(&list1, create_node(30, NULL));

	display(list1);

	get_length(list1);

	return 0;

}
