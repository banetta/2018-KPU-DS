#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Return by a referred argument
//
// c-tr-005와 같은내용

typedef struct student {
	char school[30];
	char dept[20];
	char name[20];
}student;

//void function1 (char **school);
//void function2 (char **dept);
//void function3 (char **name);
//student *get_data();
student *get_data(char **school, char **dept, char **name);
int main() {
	
	student *st = NULL;	
//	st = get_data();
	char *school = st->school;
	char *dept = st->dept;
	char *name = st->name;

	st = get_data(&school, &dept, &name);

//	함수 하나로 합치기 위해 주석
//	function1 (&school);
//	function2 (&dept);
//	function3 (&name);
	printf("%s \n%s \n%s \n", school, dept, name);

	return 0;
}

// 함수 하나로 통합하기위해 지움
//student *get_data(){
//
//	student *stu = NULL;
//
//	stu = (student *)malloc(sizeof(struct student));
//	if ( stu == NULL ){
//		fprintf(stderr, "malloc error\n");
//		exit(1);
//	}
//
//
//	return stu;
//}
student *get_data(char **school, char **dept, char **name){

	student *stu = NULL;

	stu = (student *)malloc(sizeof(struct student));
	if ( stu == NULL ){
		fprintf(stderr, "malloc error\n");
		exit(1);
	}

	strcpy(*school, "한국산업기술대학교");
	strcpy(*dept, "컴퓨터공학과");
	strcpy(*name, "홍길동");

	return stu;
}


//void function1 (char **school){
//
//	strcpy(*school, "한국산업기술대학교");
//
//}

//void function2 (char **dept){
//
//	strcpy(*dept, "컴퓨터공학과");

//}

//void function3 (char **name){
//
//	strcpy(*name, "홍길동");

//}


