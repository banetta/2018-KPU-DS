#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

//교재 296쪽의 프로그램은 삭제대상노드가 두 개의 서브트리를 가지고 있는 경우, 오른쪽 서브트리에서 삭제대상의 후계노드를 찾는 알고리즘을 구현하였다.
//이 경우 왼쪽 서브트리에서 삭제대상의 후계노드를 찾아도 된다.
//이를 구현하시오.

//#define RIGHT = 예제소스
//#define LEFT = 변경소스
#define LEFT

typedef struct TreeNode {
	int key;
	struct TreeNode *left, *right;
} TreeNode;
// 이진 탐색 트리 출력 함수
void display(TreeNode *p)
{
	if (p != NULL) {
		printf("(");
		display(p->left);
		printf("%d", p->key);
		display(p->right);
		printf(")");
	}
}
// 순환적인 탐색 함수
TreeNode *search(TreeNode *node, int key)
{
	if (node == NULL) return NULL;
	if (key == node->key) return node;
	else if (key < node->key)
		return search(node->left, key);
	else
		return search(node->right, key);
}
// 반복적인 탐색 함수
TreeNode *search1(TreeNode *node, int key)
{
	while (node != NULL) {
		printf("%d ", node->key);
		if (key == node->key) return node;
		else if (key < node->key) node = node->left;
		else node = node->right;
	}
	return NULL; 	// 탐색에 실패했을 경우 NULL 반환
}

// key를 이진 탐색 트리 root에 삽입한다. 
// key가 이미 root안에 있으면 삽입되지 않는다.
void insert_node(TreeNode **root, int key)
{
	TreeNode *p, *t; // p는 부모 노드, p는 자식 노드 
	TreeNode *n;	 // n은 새로운 노드

	t = *root;
	p = NULL;
	// 탐색을 먼저 수행 
	while (t != NULL) {
		if (key == t->key) return;
		p = t;
		if (key < t->key) t = t->left;
		else t = t->right;
	}
	// item이 트리 안에 없으므로 삽입 가능
	n = (TreeNode *)malloc(sizeof(TreeNode));
	if (n == NULL) return;
	// 데이터 복사
	n->key = key;
	n->left = n->right = NULL;
	// 부모 노드와 링크 연결
	if (p != NULL)
		if (key < p->key)
			p->left = n;
		else p->right = n;
	else *root = n;
}

#ifdef RIGHT
// 삭제 함수 (오른쪽->왼쪽)
void delete_node(TreeNode **root, int key)
{
	TreeNode *p, *child, *succ, *succ_p, *t;

	// key를 갖는 노드 t를 탐색, p는 t의 부모노드
	p = NULL;
	t = *root;
	while (t != NULL && t->key != key) {
		p = t;
		t = (key < t->key) ? t->left : t->right;
	}
	if (t == NULL) { 	// 탐색트리에 없는 키
		printf("key is not in the tree");
		return;
	}
	// 단말노드인 경우
	if ((t->left == NULL) && (t->right == NULL)) {
		if (p != NULL) {
			if (p->left == t)
				p->left = NULL;
			else   p->right = NULL;
		}
		else					// 부모노드가 없으면 루트
			*root = NULL;
	}
	// 하나의 자식만 가지는 경우
	else if ((t->left == NULL) || (t->right == NULL)) {
		child = (t->left != NULL) ? t->left : t->right;
		if (p != NULL) {
			if (p->left == t)	// 부모노드를 자식노드와 연결 
				p->left = child;
			else p->right = child;
		}
		else
			*root = child;
	}
	else {		// 두개의 자식을 가지는 경우
				// 오른쪽 서브트리에서 후속자를 찾는다.
		succ_p = t;
		succ = t->right;
		// 후속자를 찾아서 계속 왼쪽으로 이동한다.
		while (succ->left != NULL) {
			succ_p = succ;
			succ = succ->left;
		}
		// 후속자의 부모와 자식을 연결 
		if (succ_p->left == succ)
			succ_p->left = succ->right;
		else
			succ_p->right = succ->right;
		// 후속자를 현재 노드로 이동한다.
		t->key = succ->key;
		t = succ;
	}
	free(t);
}

#endif // RIGHT

#ifdef LEFT
// 삭제 함수 (왼쪽->오른쪽)
void delete_node(TreeNode **root, int key) {
	TreeNode *p, *child, *succ, *succ_p, *t;

	// key를 갖는 노드 t를 탐색, p는 t의 부모노드
	p = NULL;
	t = *root;
	while (t != NULL && t->key != key) {
		p = t;
		t = (key < t->key) ? t->left : t->right;
	}
	if (t == NULL) { 	// 탐색트리에 없는 키
		printf("key is not in the tree");
		return;
	}
	// 단말노드인 경우
	if ((t->left == NULL) && (t->right == NULL)) {
		if (p != NULL) {
			if (p->right == t)
				p->right = NULL;
			else   p->left = NULL;
		}
		else					// 부모노드가 없으면 루트
			*root = NULL;
	}
	// 하나의 자식만 가지는 경우
	else if ((t->left == NULL) || (t->right == NULL)) {
		child = (t->right != NULL) ? t->right : t->left;
		if (p != NULL) {
			if (p->right == t)	// 부모노드를 자식노드와 연결 
				p->right = child;
			else p->left = child;
		}
		else
			*root = child;
	}
	else {		// 두개의 자식을 가지는 경우
				// 왼쪽 서브트리에서 후속자를 찾는다.
		succ_p = t;
		succ = t->left;
		// 후속자를 찾아서 계속 오른쪽으로 이동한다.
		while (succ->right != NULL) {
			succ_p = succ;
			succ = succ->right;
		}
		// 후속자의 부모와 자식을 연결 
		if (succ_p->right == succ)
			succ_p->right = succ->left;
		else
			succ_p->left = succ->left;
		// 후속자를 현재 노드로 이동한다.
		t->key = succ->key;
		t = succ;
	}
	free(t);
}
#endif // LEFT

void main()
{
	TreeNode *root = NULL;

	// 삽입
	insert_node(&root, 13);
	insert_node(&root, 5);
	insert_node(&root, 25);
	insert_node(&root, 45);
	insert_node(&root, 2);
	insert_node(&root, 1);
	insert_node(&root, 4);
	insert_node(&root, 3);
	insert_node(&root, 9);
	insert_node(&root, 7);
	insert_node(&root, 12);
	insert_node(&root, 8);


	display(root); printf("\n");

	delete_node(&root, 4);
	display(root); printf("\n");

	//display(root->left->left); printf("\n");
}
