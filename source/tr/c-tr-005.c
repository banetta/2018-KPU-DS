#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 아래의 프로그램을 완성하여 다음과 같은 출력을 가능하게 하시오
// 한국산업기술대학교
// 컴퓨터공학부
// 홍길동

typedef struct Student{
	char school[10];
	char dept[10];
	char name[10];
} student;

// 제시된 소스 1
// Return by return type of struct *
char *function1(student *st);
char *function2(student *st);
char *function3(student *st);
// 소스 1 끝
student *memory(student *st);

int main(){
	
	student *st = NULL;
	//st = malloc(sizeof(struct Student));
	//if ( st == NULL ){
	//	fprintf(stderr, "Improper value of st\n");
	//	exit (1);
	//}

	// 제시된 소스 2
	char *school = NULL;
	char *dept = NULL;
	char *name = NULL;

	school = function1(st);
	dept = function2(st);
	name = function3(st);
	printf("%s\n%s\n%s\n", school, dept, name);
	return 0;
	// 소스 2 끝
}

student *memory(student *st){

	st = malloc(sizeof(struct Student));
	if ( st == NULL ){
		fprintf(stderr, "Improper value of st\n");
		exit (1);
	}

	return st;
}

char *function1(student *st){
	strcpy(st->school, "한국산업기술대학교");
	return st->school;
}

char *function2(student *st){
	strcpy(st->dept, "컴퓨터공학부");
	return st->dept;
}

char *function3(student *st){
	strcpy(st->name, "홍길동");
	return st->name;
}
