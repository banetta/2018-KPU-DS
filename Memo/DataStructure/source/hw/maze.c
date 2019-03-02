/* 23. 프로그램 5.8의 미로 탐색 프로그램에서 탐색 성공 시에 입구부터 출구까지의 경로를 출력하도록 하라.

=> 현재 위치에서 가능한 다음 위치를 모두 스택에 저장하지 않고, 한 개씩만 저장하도록 변경한다. 
*/

/*
 *	maze.c
 */

#include <stdio.h>
#include <string.h>

#define MAX_STACK_SIZE 100
#define MAZE_SIZE 6
#define true 1
#define false 0
#define EXIT_ROW 4
#define EXIT_COL 5

typedef struct  StackObjectRec { 
	short r;
	short c;
	int dir;
} StackObject;

StackObject  stack[MAX_STACK_SIZE]; 

typedef struct {
	short vert;
	short horiz;
} offsets;

offsets move[4] = {{-1,0}, {0,1}, {1,0}, {0, -1}}; // 방향이북, 동, 남, 서순서로

int  top = -1; // 스택바닥위치
StackObject entry={1,0,0};  // 시작위치, 방향은 북쪽부터
char maze[MAZE_SIZE][MAZE_SIZE] = {
	{'1', '1', '1', '1', '1', '1'},
	{'e', '0', '1', '0', '0', '1'},
	{'1', '0', '0', '0', '1', '1'},
	{'1', '0', '1', '0', '1', '1'},
	{'1', '0', '1', '0', '0', 'x'},
	{'1', '1', '1', '1', '1', '1'},
};

void initialize()
{
	top = -1;
}

int isEmpty()
{
	return (top == -1);
}

int isFull()
{
	return (top == (MAX_STACK_SIZE-1));
}

void push(StackObject item)
{ 
	  if( isFull() ) { 
		  printf("stack is full\n");
	  } 
	  else stack[++top] = item; 
}

StackObject pop() 
{ 
	if( isEmpty() ) {
		printf("stack is empty\n");
	}
	else return stack[top--]; 
} 

StackObject peek() 
{ 
	if( isEmpty() ) {
		printf("stack is empty\n");
	}
	else return stack[top]; 
} 

void main()
{
	int r,c, dir, nextrow, nextcol, i;
	int flag =0;// 현재위치가막혔는지판단
	int found = false
	StackObject here;

	initialize(); // 스택초기화
	here = entry; // 현재위치를시작위치로설정
	maze[here.r][here.c] = '.' // 현재위치방문으로표시
	push(here); // 시작위치를스택에저장

	while (top > -1 && !found){
		here = pop();
		r = here.r;
		c = here.c;
		dir = here.dir;
		while (dir <4 && !found) {
			// dir 방향으로이동
			nextrow = r + move[dir].vert;
			nextcol = c + move[dir].horiz;
			if (maze[nextrow][nextcol] == 'x') {
				found = true
				here.r = r; here.c = c; // 마지막 이전 위치를 
						      // 스택에 저장
				here.dir = ++dir;
				push(here);
			} else if( maze[nextrow][nextcol] != '1' && maze[nextrow][nextcol] != '.' ){ // 벽이아니고방문되지않았으면
				maze[nextrow][nextcol] = '.'; 
				here.r = r; here.c = c;
				here.dir = ++dir;
				push(here); // 현재 위치를 스택에 저장하고
				r = nextrow; c = nextcol; dir = 0; // 다음 위치로 이동
			}
			else
				++dir;
		} // end while
	} // end while

	if (found) { // 성공한 경우
		printf("The path is: \n");
		printf("row   col\n");
		for (i=0; i<=top; i++) // 스택 바닥부터 탑까지 저장된 경로를 출력
			printf("%2d%5d\n", stack[i].r, stack[i].c);
		printf("%2d%5d\n",  EXIT_ROW, EXIT_COL);
	} else
		printf("The maze does not have a path\n");
}
