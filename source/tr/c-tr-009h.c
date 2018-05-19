#include "c-tr-009h.h"


void insert_node(TreeNode **root, int key)
{
	TreeNode *p, *t; // p�� �θ� ���, p�� �ڽ� ��� 
	TreeNode *n;	 // n�� ���ο� ���

	t = *root;
	p = NULL;
	// Ž���� ���� ���� 
	while (t != NULL) {
		if (key == t->key) return;
		p = t;
		if (key < t->key) t = t->left;
		else t = t->right;
	}
	// item�� Ʈ�� �ȿ� �����Ƿ� ���� ����
	n = (TreeNode *)malloc(sizeof(TreeNode));
	if (n == NULL) return;
	// ������ ����
	n->key = key;
	n->left = n->right = NULL;
	// �θ� ���� ��ũ ����
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
