#include <stdio.h>

// 강의자료실에 주어진 이중연결리스트 예제처럼 dlist_insert()를 대신하여 사람의 이름을 사전적 순서로 정렬된 리스트를 유지하는 이중연결리스트
// person *dllsorted_insert (person *list, person *bef, person *new)을 구현하고 완성하시오 (폴더내 dll 폴더 참조)


typedef struct address_t {
	
	char name[64];
	char street[64];
	char city[64];
	char province[16];
	char zip[16];
	struct address_t *prev;
	struct address_t *next;

} person;

void dlist_insert (person *i);
void dlist_delete (person *i);
void dlist_display (person *i);


int main() {


	return 0;
}

void dlist_insert (person *i) {



}

void dlist_delete (person *i) {



}

void dlist_display (person *i) {


}

