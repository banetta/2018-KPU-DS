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
person *list_serch(person *);	//	dlist_delete 함수에서 지울 data를 찾기 위해 이용
person *dlist_delete(person *, person *);	//	list delete 함수 
void dlist_display(person *);	//	list display 함수


int main() {

	person *link = NULL;	//	tail pointer 생성
			
	while (1)
	{
		//	menu 출력
		printf("===============================\n");
		printf("type the proper menu: \ni : insert an data \nd : delete an data \ns : show the list \nq : quit\n");
		printf("===============================\n");
		printf("input : ");

		switch (getchar())	//	menu 입력 및 구동
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
				if (link == NULL)	//	list를 cheak해서 loop 방지
				{
					printf("list is empty\n\n");
					break;
				}
				dlist_display(link->next);	//	현재 프로그램에서는 tail외의 별도의 pointer를 가지고 있지 않기 때문에 link->next를 이용해 head를 전달해줌
				printf("\n");
				while (getchar() != '\n');	//	buffer clean
				break;

			case 'q':	//	program exit menu
			
				printf("Program exit\n");
				while (getchar() != '\n');	//	buffer clean
				return 0;	//	프로그램 종료
			
			default:
				//	error 발생 안내문
				printf("\nError!! typed wrong choice.\n\n");	
				break;
		}
	}

	return 0;
}

person *create_node() {	//	새 node 생성 함수

	person *new_node = NULL;	//	node pointer 생성
	new_node = (person*)malloc(sizeof(person));	//	malloc을 통해 data segment에 node 생성
	if (new_node == NULL) {	//	생성 error 검출
		printf("Error: DLL malloc in myfunc\n");
		return NULL;
	}
	new_node->next = new_node->prev = NULL;	//	dllsorted_insert 함수에서 pointing하기 위해 초기화

	char temp[64] = { NULL };	// strcpy_s를 통해 입력 받기 위한 temp 선언

	// scanf_s를 통해 입력 받은 후 strcpy_s를 이용해 node의 각 data에 복사

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

	// 입력된 node pointer 반환
	return(new_node);
}

person *dllsorted_insert(person *tail, person *i) {	//	생성된 node를 정렬하여 linked list 작성
	
	if (i == NULL)	//	create_node에서 malloc을 통한 생성 에러 검출시 NULL 반환
	{
		printf("create_node error!\n");
		return NULL;
	}
	if (tail == NULL)	// 처음 node를 삽입할 때
	{
		// node가 없는 초기상태의 Double Linked List이므로 자기 자신을 loop 연결
		i->next = i;
		i->prev = i;

		// pointer return을 위한 tail을 node를 가리킴
		tail = i;

		return tail;	// tail에 반환
	}

	// 필요 pointer 선언
	person *phead = tail->next;	//	head를 가리키는 pointer
	person *ptail = tail;	//	tail을 가리티는 pointer
	person *serch = tail->next;	//	비교할 대상 node를 가리키는 pointer
	
	//	정렬 시작
	while (1)
	{
		if (strcmp(serch, i) > 0)	//	serch가 더 클 경우(i가 serch보다 앞에 위치해있는 경우)
		{
			if (serch == tail)	//	현재 삽입되어있는 node가 1개만 있을 경우 or 삽입할 i가 head가 되는 경우
			{
				// 삽입할 node인 i를 head로 잡아주고 i->prev(tail)을 반환
				i->next = serch;
				i->prev = serch->prev;
				serch->prev->next = i;
				serch->prev = i;

				return i->prev;
			}
			serch = serch->next;	//	계속 serch하기 위해 다음 node로 이동
		}
		else if (strcmp(serch, i) < 0)	//	serch보다 i가 더 큰경우 (정렬할 자리를 찾음)
		{
			if (strcmp(serch->next, i) < 0)	//	뒷 node를 다시한번 체크하여 틀린 정렬 체크 (node를 삽입할 자리 최종 체크)
			{
				if (phead == ptail || serch == ptail)	//	현재 삽입되어있는 node가 1개만 있을 경우 or 삽입할 i가 tail이 되는 경우
				{
					// 삽입할 node인 i를 tail로 잡아주고 반환
					i->next = serch->next;
					i->prev = serch;
					serch->next->prev = i;
					serch->next = i;

					return i;
				}
				//	최종 체크에서 뒷 node가 삽입할 i앞에 와야하는 경우 다음 pointer로 넘어가서 다시 정렬
				serch = serch->next;	

				continue;
			}

			//	node사이에 새 node i를 삽입할 경우
			i->next = serch->next;
			i->prev = serch;
			serch->next->prev = i;
			serch->next = i;
			
			return ptail;
			
		}
	}
}

person *list_serch(person *tail) {	//	dlist_delete를 위해 node를 찾아주는 함수

	char temp[64] = { NULL };	//	찾을 name을 받을 temp 변수 선언

	//	지울 node를 찾을 data를 입력받아 temp에 입력
	printf("지울 data의 이름을 입력하세요 : ");
	scanf_s("%s", temp, sizeof(temp));

	//	찾은 node를 가리킬 pointer 선언 및 시작 node로 tail을 입력
	person *p = tail;
	
	//	list가 empty상태일 때, NULL로 반환
	if (p == NULL)
	{
		printf("list is empty\n");
		return NULL;
	}

	//	입력받은 temp와 현재 비교할 p가 같을때까지 pointer를 패스
	while (strcmp(temp, p->name) != 0)
	{
		p = p->next;

		//	pointer가 한바퀴 다 돌았을 때 tail의 이전값을 반환
		if (p == tail->prev)
		{
			return p;
		}		
	}
	
	// 찾은 node를 반환
	return p;
	
} 

person *dlist_delete (person *tail, person * del) {	//	list에서 찾은 node를 지워주는 함수
	
	person *pdel = tail;	//	temp pointer 선언
	if (tail == NULL)	//	아직 list가 만들어지지 않았을때 실행하지않고 종료
	{
		printf("list is empty\n");
		return tail;
	}
	else if (del == NULL)	//	찾을 node가 없거나 입력이 잘못된경우 실행하지않고 종료
	{
		printf("Error!! type wrong string\n");
		return tail;
	}

	if (tail == tail->next)	//	단일 node만 남아있는 상태일 경우
	{
		// node를 삭제하고 list pointer도 초기화
		free(del);
		printf("list가 전부 삭제되었습니다.\n");

		return NULL;
		
	}
	else if (tail == del)	// tail을 삭제할 때
	{
		// tail을 옮겨주고 삭제
		pdel = pdel->prev;
		pdel->next = del->next;
		pdel->next->prev = pdel;
		
		free(del);
		printf("삭제되었습니다.\n");
		dlist_display(pdel->next);	//	제대로 지워졌는지 확인

		// 변경된 tail을 반환
		return pdel;
	}
	else if (tail->next == del)	//	head를 지울 경우
	{
		if (tail == tail->next->next)	//	node가 지울 head와 tail 2개의 node만 남아있을 경우
		{
			// 지우고 남은 node를 단일 node로 loop 연결
			pdel->next = pdel;
			pdel->prev = pdel;

			free(del);
			printf("삭제되었습니다.\n");
			// pointer return을 위한 tail을 node를 가리킴
			tail = pdel;
			
			dlist_display(pdel->next);	//	제대로 실행됬는지 확인

			return tail;	// tail 반환
		}

		// head의 다음 node를 head로 가리키고 지움
		pdel = pdel->next;
		pdel->prev = tail;
		tail->next = pdel;
		
		free(del);
		printf("삭제되었습니다.\n");
		dlist_display(pdel->next);	//	제대로 실행됬는지 확인

		return tail;	// tail 반환
	}
	else	//	일반 node를 지울 때
	{
		//	del의 prev node와 next node를 이어준 뒤 지움
		pdel = del->prev;
		pdel->next = del->next;
		del->next->prev = pdel;
		
		free(del);
		printf("삭제되었습니다.\n");
		dlist_display(pdel->next);	//	제대로 실행됬는지 확인

		return tail;	//	tail 반환
	}
		

}

void dlist_display(person *tail) {

	// 출력 전 표시할 tail이 NULL인지 체크하여 error 방지
	if (tail == NULL)
	{
		printf("list is empty.\n");
		exit(1);	// error 메시지 출력 후 함수 종료
	}
	
	//	출력을 위해 temp pointer 생성
	person *p = tail;
	int i = 1;	//	몇 번째 node인지 출력하기 위한 변수

	// 출력 - head를 먼저 출력한 뒤, pointer가 한바퀴 돌 때 까지 출력
	do
	{
		printf(" %d	name : %s, street : %s, city : %s, province : %s, zip : %s\n", i++, p->name, p->street, p->city, p->province, p->zip);
		p = p->next;
	} while (p != tail);
	
}