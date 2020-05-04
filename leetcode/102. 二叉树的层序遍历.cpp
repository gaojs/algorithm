#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

#define MAX_COUNT 2000 // ��Ϊ�㹻���� 
struct TreeNode *que[MAX_COUNT] = { 0 }; 
int order[MAX_COUNT] = { 0 }; // �㼶��� 
int head = 0, tail = 0; // ģ����� 

void bfs(int **pp, int* returnSize, int** returnColumnSizes) {
	if (pp == NULL || returnSize == NULL || returnColumnSizes == NULL) {	
		return;	
	} 
	else if (head < tail) {
		struct TreeNode* root = que[head];		
		if (root != NULL) { // �����л���		
			int row = *returnSize - 1;
			if (*returnSize != order[head] + 1) { 
				*returnSize = order[head] + 1;
				row = *returnSize - 1; // �²� 	
				(*returnColumnSizes)[row] = 1; 
			} else { // ͬ�� 
				(*returnColumnSizes)[row]++;
			} 
			// printf("pp[%d]=%p ", row, pp[row]);
			if (pp[row] == NULL) { // �²�
				int size = MAX_COUNT; // (int)pow(2, row);
				// printf("size=%d ", size);
				pp[row] = (int*)calloc(sizeof(int), size);
				if (pp[row] == NULL) {
					return;
				}
			}
			int col = (*returnColumnSizes)[row] - 1;
			// printf("[%d][%d]=%d ", row, col, root->val);				
			pp[row][col] = root->val;
			if(root->left != NULL) {
				order[tail] = row + 1;
				que[tail++] = root->left;
			}			
			if(root->right != NULL) {
				order[tail] = row + 1;
				que[tail++] = root->right;
			}
		}
		head++;
		bfs(pp, returnSize, returnColumnSizes);
	}
}

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes)
{
	if (returnSize == NULL || returnColumnSizes == NULL) {	
		return NULL;	
	} else if (root == NULL) {
		*returnSize = 0;
		*returnColumnSizes = NULL;
		return NULL;
	}
	*returnSize = 0;
	*returnColumnSizes = (int*)calloc(sizeof(int), MAX_COUNT);
	if (*returnColumnSizes == NULL) {
		return NULL;
	}
	int **pp = (int**)calloc(sizeof(int*), MAX_COUNT);
	if (pp == NULL) {
		free(*returnColumnSizes);
		*returnColumnSizes = NULL;
		return NULL;
	}
	memset(order, 0, sizeof(order));
	memset(que, 0, sizeof(que));
	tail = head = 0;
	que[tail++] = root;
	bfs(pp, returnSize, returnColumnSizes);
	return pp;	 
}

void createTree(struct TreeNode **root, int *a, int size)
{ 
	if (root == NULL) {
		return; // �������� 
	} else if(a == NULL || size == 0) {
		*root = NULL;
		return; // �������� 
	} else { // ���� ������ 
		struct TreeNode* n = (struct TreeNode*)malloc(sizeof(struct TreeNode));
		if (n == NULL) { // �ڴ�����ʧ�� 
			*root = NULL; 
			return;
		} else {
			#define MAX_NODE_COUNT 100 // ��Ϊ�㹻���� 
			struct TreeNode *que[MAX_NODE_COUNT] = { 0 }; 
			int head = 0, tail = 0; // ģ����� 		
			int i = 0; // ���� 
			n->val = a[i++];
			n->left = NULL;
			n->right = NULL;
			*root = n;
			que[tail++] = n;
			while (head < tail) {				
				struct TreeNode *p = que[head++];
				if (p != NULL) {					
					printf("%d,", p->val);
					if (i < size) {
						int v = a[i++];
						if (v != INT_MIN) {
							n = (struct TreeNode*)malloc(sizeof(struct TreeNode));
							if (n == NULL) { // �ڴ�����ʧ�� 
								return;
							} else {
								n->val = v;
								n->left = NULL;
								n->right = NULL;								
							}	
							p->left = n;
							que[tail++] = n;
						} 
					}
					if (i < size) {
						int v = a[i++];
						if (v != INT_MIN) {
							n = (struct TreeNode*)malloc(sizeof(struct TreeNode));
							if (n == NULL) { // �ڴ�����ʧ�� 
								return;
							} else {
								n->val = v;
								n->left = NULL;
								n->right = NULL;								
							}	
							p->right = n;
							que[tail++] = n;
						} 
					}
				}				
			}
			return;
		}
	}
}

void preOrderPrint(struct TreeNode* root)
{
	if (root == NULL) {
		return;
	} else { // �ȸ� ���� 
		printf("%d,", root->val);
		preOrderPrint(root->left);
		preOrderPrint(root->right);
	}	
}

void inOrderPrint(struct TreeNode* root)
{
	if (root == NULL) {
		return;
	} else { // �и� ���� 
		inOrderPrint(root->left);
		printf("%d,", root->val);
		inOrderPrint(root->right);
	}	
}

void postOrderPrint(struct TreeNode* root)
{
	if (root == NULL) {
		return;
	} else { // �ȸ� ���� 
		postOrderPrint(root->left);
		postOrderPrint(root->right);
		printf("%d,", root->val);
	}	
}

void freeTree(struct TreeNode* root)
{
	if (root == NULL) {
		return;
	} else { // ��� ���� 
		freeTree(root->left);
		root->left = NULL; 
		freeTree(root->right);
		root->right = NULL;
		free(root);	
		root = NULL;	
	}	
}

int main()
{
	//int a[] = {}; // 0��ʾnull 
	//int a[] = {3,9,20,0,0,15,7}; // 0��ʾnull
	int a[] = {0,-4,-3,INT_MIN,-1,8,INT_MIN,INT_MIN,3,INT_MIN,-9,-2,INT_MIN,4}; 
	int size = sizeof(a) / sizeof(a[0]);
	printf("size=%d\n", size);	
	struct TreeNode *root = NULL;
	createTree(&root, a, size);	
	
	printf("\nPre Order:");
	preOrderPrint(root);
	printf("\n");
	int returnSize = 0;
	int *returnColumnSizes = NULL;
	int**pp=levelOrder(root, &returnSize, &returnColumnSizes);
	if (pp != NULL) {
		printf("\nLevel Order:\n");
		for (int i = 0; i < returnSize; i++) {
			for (int j = 0; j < returnColumnSizes[i]; j++) {
				printf("%d,", pp[i][j]);
			}
			printf("\n");
			free(pp[i]);
		}
		free(pp);
		free(returnColumnSizes);
	} 
	freeTree(root);
	return 0;
}

