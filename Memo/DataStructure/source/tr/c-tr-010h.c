#include "c-tr-010h.h"

// 초기화 함수 
void init(minHeap *h) {
	h->heap_size = 0;
}

// 삽입 함수 
void insert_minHeap(minHeap *h, TreeNode *item) {
	int i;
	i = ++(h->heap_size);

	// 트리를 거슬러 올라가면서 부모 노드와 비교하는 과정 
	while ((i != 1) && (item->freq < h->heap[i / 2].freq)) {
		h->heap[i] = h->heap[i / 2]; i /= 2;
	}
	h->heap[i] = *item; // 새로운 노드를 삽입
}

// 삭제 함수 
TreeNode delete_minHeap(minHeap *h) {
	int parent, child;
	TreeNode item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];

	parent = 1;
	child = 2;

	while (child <= h->heap_size) {
		if ((child < h->heap_size) && (h->heap[child].freq) > h->heap[child + 1].freq)
			child++;
		if (temp.freq <= h->heap[child].freq)
			break;

		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}

	h->heap[parent] = temp;
	return item;
}

// 이진 트리 생성 함수 
TreeNode *make_tree(TreeNode *left, TreeNode *right) {
	TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
	if (node == NULL) {
		fprintf(stderr, "메모리 에러\n");
		exit(1);
	}

	node->left = left;
	node->right = right;
	return node;
}

void show_huffman_tree(TreeNode item) {
	if (&item != NULL) {
		//printf("(");
		show_huffman_tree(*item.left);
		printf("%d", item.freq);
		show_huffman_tree(*item.right);
		//printf(")");
	}
}

void huffman_tree(int freq[], int n) { // 허프만 코드 생성 함수 
	int i;
	TreeNode *node, *x, item, item1, item2;
	minHeap heap;
	init(&heap);
	for (i = 0; i<n; i++) {
		node = make_tree(NULL, NULL);
		node->freq = freq[i];
		insert_minHeap(&heap, node);
	}
	for (i = 1; i<n; i++) { // 최소값을 가지는 두개의 노드를 삭제 
		item1 = delete_minHeap(&heap);
		item2 = delete_minHeap(&heap);
		// 두개의 노드를 합친다. 
		x = make_tree(&item1, &item2);
		x->freq = item1.freq + item2.freq;
		insert_minHeap(&heap, x);
	}	

	item = delete_minHeap(&heap); // 최종 트리
	show_huffman_tree(item);
}
