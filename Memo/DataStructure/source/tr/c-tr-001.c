#include <stdio.h>
#include <math.h>

typedef struct Point {
	int x,y;
};

int get_distance(struct Point p1, struct Point p2);

int main() {
	
	struct Point p1, p2;

	//p1.x = 1;
	//p1.y = 2;
	//p2.x = 9;
	//p2.y = 8;
	//
	// 값을 입력받아서 처리해보자
	
	printf("get_distance()\n");

	printf("insert p1.x : ");
	scanf("%d", &p1.x);

	printf("insert p1.y : ");
	scanf("%d", &p1.y);

	printf("insert p2.x : ");
	scanf("%d", &p2.x);

	printf("insert p2.y : ");
	scanf("%d", &p2.y);

	printf("result : %d\n", get_distance(p1, p2));

}

int get_distance(struct Point p1, struct Point p2) {

	return sqrt((p1.x + p2.x) * (p1.x + p2.x) + (p1.y + p2.y) * (p1.y + p2.y));
};
