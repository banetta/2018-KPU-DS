#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)


// 함수안 메모리 할당의 반환을 이용 각 3명의 학생의 이름과 학번 그리고 취미를 저장, 출력하는 프로그램을 작성하시오
// 구조체를 사용하여 메모리 할당을 반환하시오

// 제시된 소스 1
typedef struct student_tag{
	int ID;
	char name[32];
	char hobby[128];
} student;

student *get_data();
void display_data (student *st);
// 소스 1 끝

int main(int argc, char **argv){
	// 제시된 소스 2
	student *st = NULL;

	st = get_data();
	display_data(st);

	return 0;
	// 소스 2 끝

}

student *get_data(){
	student *st = NULL;
	st = (student *)malloc(3 * sizeof(student));
	if ( st == NULL ) {
		fprintf(stderr, "malloc error\n");
		//exit(1);
		return 0;
	}
	st[0].ID = 1;
	strcpy(st[0].name, "홍길동");
	strcpy(st[0].hobby, "축구");

	st[1].ID = 2;
	strcpy(st[1].name, "안철수");
	strcpy(st[1].hobby, "컴퓨터 게임");

	st[2].ID = 3;
	strcpy(st[2].name, "김영희");
	strcpy(st[2].hobby);

	return st;

}

void display_data (student *st){
	int i = NULL;
	for( i = 0; i < 3; i++){
		printf("학번 : %d, 이름 : %s, 취미 : %s\n", st[i].ID, st[i].name, st[i].hobby);
	}

}

