#include <stdio.h>

int main() {

	int a[3] = { 3, 4, 6 };
	int *p = NULL, i;

	printf("%d\n", *p++);
	printf("%d\n", (*p)++);
	printf("%d\n", *(p++));
	printf("%d\n", *(++p));
}
