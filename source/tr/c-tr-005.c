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
};

// 제시된 소스 1
// Return by return type of struct *
//char *function1();
//char *function2();
//char *function3();
// 소스 1 끝

int main(){
	
	struct	Student *st = NULL;
	st = malloc(sizeof(struct Student));
	if ( st == NULL ){
		fprintf(stderr, "Improper value of st\n");
		exit (EXIT_FAILURE);
	}

	// 제시된 소스 2
	//char *school = NULL;
	//char *dept = NULL;
	//char *name = NULL;

	//school = function1();
	//dept = function2();
	//name = function3();
	//printf("%s\n%s\n%s\n", school, dept, name);
	return 0;
	// 소스 2 끝
}



