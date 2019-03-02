#include "c-tr-009h.h"


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

void display(TreeNode *p)
{
	if (p != NULL) {
		//printf("(");
		display(p->left);
		printf("%c", p->key);
		display(p->right);
		//printf(")");
	}
}
