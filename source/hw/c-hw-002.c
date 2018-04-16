#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include "c-hw-002h.h"

//	강의자료실에 주어진 이중연결리스트 예제처럼 dlist_insert()를 대신하여 사람의 이름을 사전적 순서로 정렬된 리스트를 유지하는 이중연결리스트 person *dllsorted_insert (person *list, person *bef, person *new)을 구현하고 완성하시오 (폴더내 dll 폴더 참조)

//	구조체 선언
typedef struct address_t {

	char name[64];
	char street[64];
	char city[64];
	char province[16];
	char zip[16];

	//	Double linked list (이중연결리스트)를 위한 포인터 선언
	struct address_t *prev;
	struct address_t *next;

} person;

//	필요 함수 선언
person *create_node();	//	node 생성 및 자료 입력
person *dllsorted_insert(person *, person *);	//	void dlist_insert()를 대체
person *dlist_delete(person **, person *);	//	list delete 함수 
void dlist_display(person *);	//	list display 함수
person *list_serch(person *);	//	dlist_delete 함수에서 지울 data를 찾기 위해 이용


int main() {

	person *link = NULL;	//	tail pointer 생성
			
	while (1)
	{
		//	menu 출력
		printf("===============================\n");
		printf("type the proper menu: \ni : insert an data \nd : delete an data \ns : show the list \nq : quit\n");
		printf("===============================\n");
		printf("input : ");

		switch (getchar())	//	menu 입력
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

	char temp[64] = { NULL };	// strcpy_s를 통해 입력 받기 위한 temp 선언

	// temp를 통해 입력 받은 후 strcpy_s를 이용해 node에 복사

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

	// dlist_display(new_node);	// 정상 입력이 됬는지 체크하기 위한 임시

	// 입력된 node pointer 반환
	return(new_node);
}


person *dllsorted_insert(person *head, person *i) {
	
	person *phead = head;
	
	if (phead == NULL)	// 처음 node를 삽입할 때
	{
		// node가 없고 Double Linked List이므로 자기 자신을 loop 연결
		i->next = i;
		i->prev = i;
		
		// tail을 node를 가리킴
		phead = i;

		return phead;	// tail에 반환
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

	printf("지울 data의 이름을 입력하세요 : ");
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
	
	if (p == del)	// 만약 tail이 자기 자신을 가리킬 때, tail를 옮겨준다. list를 가리킬 tail에 node정보가 잘못되어 error가 나기 때문
	{
		p = del->prev;	// head에 앞 노드의 정보를 넣어줌
		del->prev->next = del->next;
		del->next->prev = del->prev;
		free(del);
		dlist_display(p);
	}
	else
	{
		// head 체크 후 앞, 뒤 노드를 연결한 뒤 삭제
		del->prev->next = del->next;
		del->next->prev = del->prev;
		free(del);
		dlist_display(p);
	}
		return tail;	// if문의 조건에 만족해 head 정보가 바뀔 시에 적용

}

void dlist_display(person *tail) {

	// 출력 전 표시할 tail이 NULL인지 체크하여 error 방지
	if (tail == NULL)
	{
		printf("list is empty.\n");
		return;	// error 메시지 출력 후 함수 종료
	}
	
	// 출력
	person *p = tail;
	int i = 1;

	do
	{
		printf(" %d	name : %s, street : %s, city : %s, province : %s, zip : %s\n", i++, p->name, p->street, p->city, p->province, p->zip);
		p = p->next;
	} while (p != tail);
	
}