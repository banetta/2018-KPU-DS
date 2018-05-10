#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

//���� 296���� ���α׷��� ��������尡 �� ���� ����Ʈ���� ������ �ִ� ���, ������ ����Ʈ������ ��������� �İ��带 ã�� �˰����� �����Ͽ���.
//�� ��� ���� ����Ʈ������ ��������� �İ��带 ã�Ƶ� �ȴ�.
//�̸� �����Ͻÿ�.

//#define RIGHT = �����ҽ�
//#define LEFT = ����ҽ�
#define LEFT

typedef struct TreeNode {
	int key;
	struct TreeNode *left, *right;
} TreeNode;
// ���� Ž�� Ʈ�� ��� �Լ�
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
// ��ȯ���� Ž�� �Լ�
TreeNode *search(TreeNode *node, int key)
{
	if (node == NULL) return NULL;
	if (key == node->key) return node;
	else if (key < node->key)
		return search(node->left, key);
	else
		return search(node->right, key);
}
// �ݺ����� Ž�� �Լ�
TreeNode *search1(TreeNode *node, int key)
{
	while (node != NULL) {
		printf("%d ", node->key);
		if (key == node->key) return node;
		else if (key < node->key) node = node->left;
		else node = node->right;
	}
	return NULL; 	// Ž���� �������� ��� NULL ��ȯ
}

// key�� ���� Ž�� Ʈ�� root�� �����Ѵ�. 
// key�� �̹� root�ȿ� ������ ���Ե��� �ʴ´�.
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

#ifdef RIGHT
// ���� �Լ� (������->����)
void delete_node(TreeNode **root, int key)
{
	TreeNode *p, *child, *succ, *succ_p, *t;

	// key�� ���� ��� t�� Ž��, p�� t�� �θ���
	p = NULL;
	t = *root;
	while (t != NULL && t->key != key) {
		p = t;
		t = (key < t->key) ? t->left : t->right;
	}
	if (t == NULL) { 	// Ž��Ʈ���� ���� Ű
		printf("key is not in the tree");
		return;
	}
	// �ܸ������ ���
	if ((t->left == NULL) && (t->right == NULL)) {
		if (p != NULL) {
			if (p->left == t)
				p->left = NULL;
			else   p->right = NULL;
		}
		else					// �θ��尡 ������ ��Ʈ
			*root = NULL;
	}
	// �ϳ��� �ڽĸ� ������ ���
	else if ((t->left == NULL) || (t->right == NULL)) {
		child = (t->left != NULL) ? t->left : t->right;
		if (p != NULL) {
			if (p->left == t)	// �θ��带 �ڽĳ��� ���� 
				p->left = child;
			else p->right = child;
		}
		else
			*root = child;
	}
	else {		// �ΰ��� �ڽ��� ������ ���
				// ������ ����Ʈ������ �ļ��ڸ� ã�´�.
		succ_p = t;
		succ = t->right;
		// �ļ��ڸ� ã�Ƽ� ��� �������� �̵��Ѵ�.
		while (succ->left != NULL) {
			succ_p = succ;
			succ = succ->left;
		}
		// �ļ����� �θ�� �ڽ��� ���� 
		if (succ_p->left == succ)
			succ_p->left = succ->right;
		else
			succ_p->right = succ->right;
		// �ļ��ڸ� ���� ���� �̵��Ѵ�.
		t->key = succ->key;
		t = succ;
	}
	free(t);
}

#endif // RIGHT

#ifdef LEFT
// ���� �Լ� (����->������)
void delete_node(TreeNode **root, int key) {
	TreeNode *p, *child, *succ, *succ_p, *t;

	// key�� ���� ��� t�� Ž��, p�� t�� �θ���
	p = NULL;
	t = *root;
	while (t != NULL && t->key != key) {
		p = t;
		t = (key < t->key) ? t->left : t->right;
	}
	if (t == NULL) { 	// Ž��Ʈ���� ���� Ű
		printf("key is not in the tree");
		return;
	}
	// �ܸ������ ���
	if ((t->left == NULL) && (t->right == NULL)) {
		if (p != NULL) {
			if (p->right == t)
				p->right = NULL;
			else   p->left = NULL;
		}
		else					// �θ��尡 ������ ��Ʈ
			*root = NULL;
	}
	// �ϳ��� �ڽĸ� ������ ���
	else if ((t->left == NULL) || (t->right == NULL)) {
		child = (t->right != NULL) ? t->right : t->left;
		if (p != NULL) {
			if (p->right == t)	// �θ��带 �ڽĳ��� ���� 
				p->right = child;
			else p->left = child;
		}
		else
			*root = child;
	}
	else {		// �ΰ��� �ڽ��� ������ ���
				// ���� ����Ʈ������ �ļ��ڸ� ã�´�.
		succ_p = t;
		succ = t->left;
		// �ļ��ڸ� ã�Ƽ� ��� ���������� �̵��Ѵ�.
		while (succ->right != NULL) {
			succ_p = succ;
			succ = succ->right;
		}
		// �ļ����� �θ�� �ڽ��� ���� 
		if (succ_p->right == succ)
			succ_p->right = succ->left;
		else
			succ_p->left = succ->left;
		// �ļ��ڸ� ���� ���� �̵��Ѵ�.
		t->key = succ->key;
		t = succ;
	}
	free(t);
}
#endif // LEFT

void main()
{
	TreeNode *root = NULL;

	// ����
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
