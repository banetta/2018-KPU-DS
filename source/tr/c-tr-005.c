#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 아래의 프로그램을 완성하여 다음과 같은 출력을 가능하게 하시오
// 한국산업기술대학교
// 컴퓨터공학부
// 홍길동

typedef struct Student{
	char school[30]; // Visual Studio 에서는 [20]으로도 정상 출력되지만 리눅스에서는 그 이상으로 잡아줘야 정상 출력이 된다 locale이 달라서 그런듯?
	char dept[20];
	char name[20];
} student;

// 제시된 소스 1
// Return by return type of struct *
char *function1(char *school);
char *function2(char *dept);
char *function3(char *name);
// 소스 1 끝
//student *memory(student *st);

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
	
	st = (student *)malloc(sizeof(struct Student));
	if ( st == NULL ){
		fprintf(stderr, "Improper value of st\n");
		exit (1);
	}


	school = function1(st->school);
	dept = function2(st->dept);
	name = function3(st->name);
	printf("%s\n%s\n%s\n", school, dept, name);
	return 0;
	// 소스 2 끝
}

//student *memory(student *st){
//
//	st = malloc(sizeof(struct Student));
//	if ( st == NULL ){
//		fprintf(stderr, "Improper value of st\n");
//		exit (1);
//	}
//
//	return st;
//}

char *function1(char *school){
	strcpy(school, "한국산업기술대학교");
	return school;
}

char *function2(char *dept){
	strcpy(dept, "컴퓨터공학부");
	return dept;
}

char *function3(char *name){
	strcpy(name, "홍길동");
	return name;
}
