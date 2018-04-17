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
person *list_serch(person *);	//	dlist_delete �Լ����� ���� data�� ã�� ���� �̿�
person *dlist_delete(person *, person *);	//	list delete �Լ� 
void dlist_display(person *);	//	list display �Լ�


int main() {

	person *link = NULL;	//	tail pointer ����
			
	while (1)
	{
		//	menu ���
		printf("===============================\n");
		printf("type the proper menu: \ni : insert an data \nd : delete an data \ns : show the list \nq : quit\n");
		printf("===============================\n");
		printf("input : ");

		switch (getchar())	//	menu �Է� �� ����
		{
			case 'i':	//	insert menu
			
				link = dllsorted_insert(link, create_node());
				printf("\n");
				while (getchar() != '\n');	//	buffer clean
				break;

			case 'd':	//	delete menu
						
				link = dlist_delete(link, list_serch(link));
				printf("\n");
				while (getchar() != '\n');	//	buffer clean
				break;

			case 's':	//	print menu
			
				printf("Show List....\n\n");
				if (link == NULL)	//	list�� cheak�ؼ� loop ����
				{
					printf("list is empty\n\n");
					break;
				}
				dlist_display(link->next);	//	���� ���α׷������� tail���� ������ pointer�� ������ ���� �ʱ� ������ link->next�� �̿��� head�� ��������
				printf("\n");
				while (getchar() != '\n');	//	buffer clean
				break;

			case 'q':	//	program exit menu
			
				printf("Program exit\n");
				while (getchar() != '\n');	//	buffer clean
				return 0;	//	���α׷� ����
			
			default:
				//	error �߻� �ȳ���
				printf("\nError!! typed wrong choice.\n\n");	
				break;
		}
	}

	return 0;
}

person *create_node() {	//	�� node ���� �Լ�

	person *new_node = NULL;	//	node pointer ����
	new_node = (person*)malloc(sizeof(person));	//	malloc�� ���� data segment�� node ����
	if (new_node == NULL) {	//	���� error ����
		printf("Error: DLL malloc in myfunc\n");
		return NULL;
	}
	new_node->next = new_node->prev = NULL;	//	dllsorted_insert �Լ����� pointing�ϱ� ���� �ʱ�ȭ

	char temp[64] = { NULL };	// strcpy_s�� ���� �Է� �ޱ� ���� temp ����

	// scanf_s�� ���� �Է� ���� �� strcpy_s�� �̿��� node�� �� data�� ����

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

	// �Էµ� node pointer ��ȯ
	return(new_node);
}

person *dllsorted_insert(person *tail, person *i) {	//	������ node�� �����Ͽ� linked list �ۼ�
	
	if (i == NULL)	//	create_node���� malloc�� ���� ���� ���� ����� NULL ��ȯ
	{
		printf("create_node error!\n");
		return NULL;
	}
	if (tail == NULL)	// ó�� node�� ������ ��
	{
		// node�� ���� �ʱ������ Double Linked List�̹Ƿ� �ڱ� �ڽ��� loop ����
		i->next = i;
		i->prev = i;

		// pointer return�� ���� tail�� node�� ����Ŵ
		tail = i;

		return tail;	// tail�� ��ȯ
	}

	// �ʿ� pointer ����
	person *phead = tail->next;	//	head�� ����Ű�� pointer
	person *ptail = tail;	//	tail�� ����Ƽ�� pointer
	person *serch = tail->next;	//	���� ��� node�� ����Ű�� pointer
	
	//	���� ����
	while (1)
	{
		if (strcmp(serch, i) > 0)	//	serch�� �� Ŭ ���(i�� serch���� �տ� ��ġ���ִ� ���)
		{
			if (serch == tail)	//	���� ���ԵǾ��ִ� node�� 1���� ���� ��� or ������ i�� head�� �Ǵ� ���
			{
				// ������ node�� i�� head�� ����ְ� i->prev(tail)�� ��ȯ
				i->next = serch;
				i->prev = serch->prev;
				serch->prev->next = i;
				serch->prev = i;

				return i->prev;
			}
			serch = serch->next;	//	��� serch�ϱ� ���� ���� node�� �̵�
		}
		else if (strcmp(serch, i) < 0)	//	serch���� i�� �� ū��� (������ �ڸ��� ã��)
		{
			if (strcmp(serch->next, i) < 0)	//	�� node�� �ٽ��ѹ� üũ�Ͽ� Ʋ�� ���� üũ (node�� ������ �ڸ� ���� üũ)
			{
				if (phead == ptail || serch == ptail)	//	���� ���ԵǾ��ִ� node�� 1���� ���� ��� or ������ i�� tail�� �Ǵ� ���
				{
					// ������ node�� i�� tail�� ����ְ� ��ȯ
					i->next = serch->next;
					i->prev = serch;
					serch->next->prev = i;
					serch->next = i;

					return i;
				}
				//	���� üũ���� �� node�� ������ i�տ� �;��ϴ� ��� ���� pointer�� �Ѿ�� �ٽ� ����
				serch = serch->next;	

				continue;
			}

			//	node���̿� �� node i�� ������ ���
			i->next = serch->next;
			i->prev = serch;
			serch->next->prev = i;
			serch->next = i;
			
			return ptail;
			
		}
	}
}

person *list_serch(person *tail) {	//	dlist_delete�� ���� node�� ã���ִ� �Լ�

	char temp[64] = { NULL };	//	ã�� name�� ���� temp ���� ����

	//	���� node�� ã�� data�� �Է¹޾� temp�� �Է�
	printf("���� data�� �̸��� �Է��ϼ��� : ");
	scanf_s("%s", temp, sizeof(temp));

	//	ã�� node�� ����ų pointer ���� �� ���� node�� tail�� �Է�
	person *p = tail;
	
	//	list�� empty������ ��, NULL�� ��ȯ
	if (p == NULL)
	{
		printf("list is empty\n");
		return NULL;
	}

	//	�Է¹��� temp�� ���� ���� p�� ���������� pointer�� �н�
	while (strcmp(temp, p->name) != 0)
	{
		p = p->next;

		//	pointer�� �ѹ��� �� ������ �� tail�� �������� ��ȯ
		if (p == tail->prev)
		{
			return p;
		}		
	}
	
	// ã�� node�� ��ȯ
	return p;
	
} 

person *dlist_delete (person *tail, person * del) {	//	list���� ã�� node�� �����ִ� �Լ�
	
	person *pdel = tail;	//	temp pointer ����
	if (tail == NULL)	//	���� list�� ��������� �ʾ����� ���������ʰ� ����
	{
		printf("list is empty\n");
		return tail;
	}
	else if (del == NULL)	//	ã�� node�� ���ų� �Է��� �߸��Ȱ�� ���������ʰ� ����
	{
		printf("Error!! type wrong string\n");
		return tail;
	}

	if (tail == tail->next)	//	���� node�� �����ִ� ������ ���
	{
		// node�� �����ϰ� list pointer�� �ʱ�ȭ
		free(del);
		printf("list�� ���� �����Ǿ����ϴ�.\n");

		return NULL;
		
	}
	else if (tail == del)	// tail�� ������ ��
	{
		// tail�� �Ű��ְ� ����
		pdel = pdel->prev;
		pdel->next = del->next;
		pdel->next->prev = pdel;
		
		free(del);
		printf("�����Ǿ����ϴ�.\n");
		dlist_display(pdel->next);	//	����� ���������� Ȯ��

		// ����� tail�� ��ȯ
		return pdel;
	}
	else if (tail->next == del)	//	head�� ���� ���
	{
		if (tail == tail->next->next)	//	node�� ���� head�� tail 2���� node�� �������� ���
		{
			// ����� ���� node�� ���� node�� loop ����
			pdel->next = pdel;
			pdel->prev = pdel;

			free(del);
			printf("�����Ǿ����ϴ�.\n");
			// pointer return�� ���� tail�� node�� ����Ŵ
			tail = pdel;
			
			dlist_display(pdel->next);	//	����� ��������� Ȯ��

			return tail;	// tail ��ȯ
		}

		// head�� ���� node�� head�� ����Ű�� ����
		pdel = pdel->next;
		pdel->prev = tail;
		tail->next = pdel;
		
		free(del);
		printf("�����Ǿ����ϴ�.\n");
		dlist_display(pdel->next);	//	����� ��������� Ȯ��

		return tail;	// tail ��ȯ
	}
	else	//	�Ϲ� node�� ���� ��
	{
		//	del�� prev node�� next node�� �̾��� �� ����
		pdel = del->prev;
		pdel->next = del->next;
		del->next->prev = pdel;
		
		free(del);
		printf("�����Ǿ����ϴ�.\n");
		dlist_display(pdel->next);	//	����� ��������� Ȯ��

		return tail;	//	tail ��ȯ
	}
		

}

void dlist_display(person *tail) {

	// ��� �� ǥ���� tail�� NULL���� üũ�Ͽ� error ����
	if (tail == NULL)
	{
		printf("list is empty.\n");
		exit(1);	// error �޽��� ��� �� �Լ� ����
	}
	
	//	����� ���� temp pointer ����
	person *p = tail;
	int i = 1;	//	�� ��° node���� ����ϱ� ���� ����

	// ��� - head�� ���� ����� ��, pointer�� �ѹ��� �� �� ���� ���
	do
	{
		printf(" %d	name : %s, street : %s, city : %s, province : %s, zip : %s\n", i++, p->name, p->street, p->city, p->province, p->zip);
		p = p->next;
	} while (p != tail);
	
}