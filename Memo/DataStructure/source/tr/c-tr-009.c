#include "c-tr-009h.h"

#define CHAR

int main() {

	TreeNode *root = NULL;

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

	display(root);
	printf("\n");

	return 0;
}