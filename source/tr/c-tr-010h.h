#ifndef __HUF_

#define __HUF_

#include <stdio.h> 
#include <stdlib.h>
#define MAX_ELEMENT 100

typedef struct TreeNode {
	int freq;
	struct TreeNode *left;
	struct TreeNode *right;
} TreeNode;
typedef struct minHeap {
	TreeNode heap[MAX_ELEMENT];
	int heap_size;
} minHeap;



#endif // !__HUF_

