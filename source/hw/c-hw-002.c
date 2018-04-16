#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include "c-hw-002h.h"

//	�����ڷ�ǿ� �־��� ���߿��Ḯ��Ʈ ����ó�� dlist_insert()�� ����Ͽ� ����� �̸��� ������ ������ ���ĵ� ����Ʈ�� �����ϴ� ���߿��Ḯ��Ʈ person *dllsorted_insert (person *list, person *bef, person *new)�� �����ϰ� �ϼ��Ͻÿ� (������ dll ���� ����)

//	����ü ����
typedef struct address_t {

	char name[64];
	char street[64];
	char city[64];
	char province[16];
	char zip[16];

	//	Double linked list (���߿��Ḯ��Ʈ)�� ���� ������ ����
	struct address_t *prev;
	struct address_t *next;

} person;

//	�ʿ� �Լ� ����
person *create_node();	//	node ���� �� �ڷ� �Է�
person *dllsorted_insert(person *, person *);	//	void dlist_insert()�� ��ü
person *dlist_delete(person **, person *);	//	list delete �Լ� 
void dlist_display(person *);	//	list display �Լ�
person *list_serch(person *);	//	dlist_delete �Լ����� ���� data�� ã�� ���� �̿�


int main() {

	person *link = NULL;	//	tail pointer ����
			
	while (1)
	{
		//	menu ���
		printf("===============================\n");
		printf("type the proper menu: \ni : insert an data \nd : delete an data \ns : show the list \nq : quit\n");
		printf("===============================\n");
		printf("input : ");

		switch (getchar())	//	menu �Է�
		{
			case 'i':	//	insert menu
			
				link = dllsorted_insert(link, create_node());
				printf("\n");
				while (getchar() != '\n');
				break;

			case 'd':	//	delete menu
						
				dlist_delete(&link, list_serch(link));
				printf("\n");
				while (getchar() != '\n');
				break;

			case 's':
			
				printf("Show List....\n\n");
				dlist_display(link->next);
				printf("\n");
				while (getchar() != '\n');
				break;

			case 'q':
			
				printf("Program exit\n");
				while (getchar() != '\n');
				return 0;
			
			default:
			
				printf("\nError!! typed wrong choice.\n\n");
				break;
		}
	}

	return 0;
}

person *create_node() {

	person *new_node = NULL;
	new_node = (person*)malloc(sizeof(person));
	if (new_node == NULL) {
		printf("Error: DLL malloc in myfunc\n");
		return 0;
	}
	new_node->next = new_node->prev = NULL;

	char temp[64] = { NULL };	// strcpy_s�� ���� �Է� �ޱ� ���� temp ����

	// temp�� ���� �Է� ���� �� strcpy_s�� �̿��� node�� ����

	printf("insert name : ");
	scanf_s("%s", temp, sizeof(temp));

	strcpy_s(new_node->name, 64, temp);

	printf("insert street : ");
	scanf_s("%s", temp, sizeof(temp));

	strcpy_s(new_node->street, 64, temp);

	printf("insert city : ");
	scanf_s("%s", temp, sizeof(temp));

	strcpy_s(new_node->city, 64, temp);

	printf("insert province : ");
	scanf_s("%s", temp, sizeof(temp));

	strcpy_s(new_node->province, 16, temp);

	printf("insert zip : ");
	scanf_s("%s", temp, sizeof(temp));

	strcpy_s(new_node->zip, 16, temp);

	// dlist_display(new_node);	// ���� �Է��� ����� üũ�ϱ� ���� �ӽ�

	// �Էµ� node pointer ��ȯ
	return(new_node);
}


person *dllsorted_insert(person *head, person *i) {
	
	person *phead = head;
	
	if (phead == NULL)	// ó�� node�� ������ ��
	{
		// node�� ���� Double Linked List�̹Ƿ� �ڱ� �ڽ��� loop ����
		i->next = i;
		i->prev = i;
		
		// tail�� node�� ����Ŵ
		phead = i;

		return phead;	// tail�� ��ȯ
	}

	//i->next = p->next;
	//i->prev = p;
	//p->next->prev = i;
	//p->next = i;
	
	
	

	while (1)
	{
		if (strcmp(phead, i) > 0)
		{
			phead = phead->prev;
		}
		else if (strcmp(phead, i) < 0)
		{
			if (strcmp(phead->prev, i) < 0)
			{
				phead = phead->prev;
				continue;
			}
			i->next = phead->next;
			i->prev = phead;
			phead->next->prev = i;
			phead->next = i;

			return phead;
		}
	}
}

person *list_serch(person *tail) {

	char temp[64] = { NULL };

	printf("���� data�� �̸��� �Է��ϼ��� : ");
	scanf_s("%s", temp, sizeof(temp));
	//strcpy_s(data.name, 64, temp);

	person *p = tail;
	
	if (p == NULL)
	{
		printf("list is empty\n");
		return NULL;
	}

	while (strcmp(temp, p->name) != 0)
	{
		p = p->next;
		
	}
		
	return p;
	
}

person *dlist_delete (person *tail, person * del) {
	
	person *p = tail;

	if (del == NULL)
	{
		printf("list is empty\n");
		return tail;
	}
	
	if (p == del)	// ���� tail�� �ڱ� �ڽ��� ����ų ��, tail�� �Ű��ش�. list�� ����ų tail�� node������ �߸��Ǿ� error�� ���� ����
	{
		p = del->prev;	// head�� �� ����� ������ �־���
		del->prev->next = del->next;
		del->next->prev = del->prev;
		free(del);
		dlist_display(p);
	}
	else
	{
		// head üũ �� ��, �� ��带 ������ �� ����
		del->prev->next = del->next;
		del->next->prev = del->prev;
		free(del);
		dlist_display(p);
	}
		return tail;	// if���� ���ǿ� ������ head ������ �ٲ� �ÿ� ����

}

void dlist_display(person *tail) {

	// ��� �� ǥ���� tail�� NULL���� üũ�Ͽ� error ����
	if (tail == NULL)
	{
		printf("list is empty.\n");
		return;	// error �޽��� ��� �� �Լ� ����
	}
	
	// ���
	person *p = tail;
	int i = 1;

	do
	{
		printf(" %d	name : %s, street : %s, city : %s, province : %s, zip : %s\n", i++, p->name, p->street, p->city, p->province, p->zip);
		p = p->next;
	} while (p != tail);
	
}