#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include "c-hw-002h.h"

// 강의자료실에 주어진 이중연결리스트 예제처럼 dlist_insert()를 대신하여 사람의 이름을 사전적 순서로 정렬된 리스트를 유지하는 이중연결리스트 person *dllsorted_insert (person *list, person *bef, person *new)을 구현하고 완성하시오 (폴더내 dll 폴더 참조)

// 구조체 선언
typedef struct address_t {
	
	char name[64];
	char street[64];
	char city[64];
	char province[16];
	char zip[16];

	// Double linked list (이중연결리스트)를 위한 포인터 선언
	struct address_t *prev;
	struct address_t *next;

} person;

// 필요 함수 선언
person *create_node(person *);
person *dllsorted_insert(person *, person *, person *);	// void dlist_insert()를 대체
person *dlist_delete (person *, person *);	// list delete 함수 
void dlist_display (person *);	// list display 함수


int main() {

	person *link = NULL;
	char command = NULL;
	create_node(link);
	printf("input command : ");

	while (1)
	{
		switch (command)
		{
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		default:
			break;
		}
	}

	return 0;
}

person *create_node(person *link) {

	person *new_node;
	new_node = (person*)malloc(sizeof(person));
	if (new_node == NULL) {
		perror("메모리 할당 에러");
	}

	char temp[64] = { NULL };
	
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

	strcpy_s(new_node->name, 16, temp);
	
	dlist_display(new_node);

	return(new_node);
}

/*
person *dllsorted_insert(person *head, person *bef, person *new) {
	

	
}

// list에서 node 삭제 함수
// 반환형으로 person * 를 선언한 이유는 head의 정보가 바뀔 수 있기 때문에 갱신을 해주기 위함
person *dlist_delete (person **head, person *i) { 

	if (*head == i)	// 만약 head(tail)가 자기 자신을 가리킬 때, head를 옮겨준다. list를 가리킬 head에 node정보가 잘못되어 error가 나기 때문
	{
		*head = i->prev;	// head에 앞 노드의 정보를 넣어줌
	}
	// head 체크 후 앞, 뒤 노드를 연결한 뒤 삭제
	i->prev->next = i->next;

	free(i);
	
	return *head;	// if문의 조건에 만족해 head 정보가 바뀔 시에 적용
}
*/
// list display 함수
// 표시할 node를 받아서 출력
void dlist_display (person *i) {	

	// 출력 전 표시할 node가 NULL인지 체크하여 error 방지
	if (i == NULL)
	{
		printf("이 node는 비어있습니다.\n");
		return;	// error 메시지 출력 후 함수 종료
	}

	int repeat = NULL; // repeat 변수를 추가로 받아서 전체 노드를 출력할지 현재 노드만 출력할지 체크하여 출력

	printf("반복 출력하시겠습니까?");
	scanf_s("%d", repeat);

	if (repeat = 1)	// 반복 출력일 경우
	{
		// 반복 출력시 출력의 끝부분을 체크하기 위해 pointer를 추가로 생성하여 체크
		person *p; 
		p = i;
		
		do
		{
			//	현재 p = i; 이기 때문에 while문을 바로 돌리면 실행하지않고 바로 종료하기에 
			//	do-while문을 이용, 먼저 선출력 후 check pointer를 다음 pointer로 넘기고 while문을 실행
			printf("name : %s, street : %s, city : %s, province : %s, zip : %s\n", p->name);

			p = p->next;

		} while (p != i);
	}
	else	//	단일 node 출력
	{
		printf("name : %s, street : %s, city : %s, province : %s, zip : %s\n", i->name);
	}
	
}


