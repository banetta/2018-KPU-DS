#include <stdio.h>

int *sum (int *, int *); // function prototype: 함수 원형에 의한 선언

int main(){

	int a, b, *ap = NULL, *pt = ap, *bp = &b, c, *cp = NULL;

	ap = &a;
	*ap = 10;

	cp = sum (&a, &b);	// function call : call by reference and pointer return
	printf("%d + %d = %d\n", a, b, *cp);
	// c = *sum (&a, &b);	// 위와 같은 의미, 정적 변수 total의 값을 변수 c에 복사
	// printf("%d + %d = %d", a, b, c);
	

	return 0;
}

int *sum (int *x, int *y){ // function definition
	static int total; // 정적 변수는 자동 초기화 됨, 동적 메모리 할당으로 대체 가능

	total = *x + *y;
	return &total; // static 변수나 동적 메모리 할당된 포인터만 변환 가능
}
