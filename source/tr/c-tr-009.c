#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#define CHAR

#ifdef CHAR
typedef struct Tree
{
	char key;
	struct Tree *left, *right;
}TreeNode;

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

#endif // CHAR

#ifdef STR
typedef struct Tree
{
	char key;
	struct Tree *left, *right;
}TreeNode;
#endif // STR


int main() {

	TreeNode *root = NULL;
#ifdef CHAR

	//char str[10] = { 'e','r','t','a','b','g','z','h','d','u' };
	char str[10] = { "korea poly" };

	for (int i = 0; i < 10; i++)
	{
		printf("%c", str[i]);
	}
	printf("\n");

	for (int i = 0; i < 10; i++)
	{
		insert_node(&root, str[i]);
	}

#endif // CHAR

#ifdef STR
	char str1[10], str2[10], str3[10], str4[10], str5[10];
	strcpy_s(str1, 10, "kpu");
	strcpy_s(str2, 10, "kr");
	strcpy_s(str3, 10, "poly");
	strcpy_s(str4, 10, "ac");

#endif // STR


	display(root);
	printf("\n");

	return 0;
}