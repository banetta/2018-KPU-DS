#include <stdio.h>

int *sum (int *, int *);	// function prototype

int main(){
	int a[2] = {83, 95}, b[2] = {77, 89}, *ap = a, *bp = b, *cp = NULL;
	int i;

	cp = sum (a, b);	// function call
	for (i = 0; i < 2; i++){
		printf("%d + %d = %d\n", ap[i], bp[i], cp[i]);
	}

	return 0;
}

int *sum (int *x, int *y){	//function definition:
	static int total[2]; // 정적 변수는 자동 초기화 되므 동적 메모리 할당으로 대체 가능
	int i;

	
	for (i = 0; i < 2; i++){
		total[i] = x[i] + y[i];
	}

	return total; //static 변수나 동적 메모리 할당된 포인터만 변환 가능
}
