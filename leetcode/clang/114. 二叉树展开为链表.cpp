#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};
void inOrderPrint(struct TreeNode* root);
void preOrderPrint(struct TreeNode* root);
void postOrderPrint(struct TreeNode* root);

void flatten(struct TreeNode* root)
{
	if (root == NULL) {
		return;
	}
	flatten(root->left); 
	flatten(root->right);
	if (root->left != NULL) {
		struct TreeNode* lr = root->left;
		while (lr->right != NULL) {
			lr = lr->right;
		}
		lr->right = root->right;
		root->right = root->left;
		root->left = NULL;
		// printf("\nPreOrder(%d):\n", root->val);
		// preOrderPrint(root);
	}
}

void createTree(struct TreeNode **root, int *a, int size)
{ 
	if (root == NULL) {
		return; // 参数有误 
	} else if(a == NULL || size == 0) {
		*root = NULL;
		return; // 参数有误 
	} else { // 创建 二叉树 
		struct TreeNode* n = (struct TreeNode*)malloc(sizeof(struct TreeNode));
		if (n == NULL) { // 内存申请失败 
			*root = NULL; 
			return;
		} else {
			#define MAX_NODE_COUNT 100 // 认为足够大了 
			struct TreeNode *que[MAX_NODE_COUNT] = { 0 }; 
			int head = 0, tail = 0; // 模拟队列 		
			int i = 0; // 索引 
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
							if (n == NULL) { // 内存申请失败 
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
							if (n == NULL) { // 内存申请失败 
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
	} else { // 先根 遍历 
		printf("%d,", root->val);
		preOrderPrint(root->left);
		preOrderPrint(root->right);
	}	
}

void inOrderPrint(struct TreeNode* root)
{
	if (root == NULL) {
		return;
	} else { // 中根 遍历 
		inOrderPrint(root->left);
		printf("%d,", root->val);
		inOrderPrint(root->right);
	}	
}

void postOrderPrint(struct TreeNode* root)
{
	if (root == NULL) {
		return;
	} else { // 先根 遍历 
		postOrderPrint(root->left);
		postOrderPrint(root->right);
		printf("%d,", root->val);
	}	
}

void freeTree(struct TreeNode* root)
{
	if (root == NULL) {
		return;
	} else { // 后根 销毁 
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
	//int a[] = {}; // 0表示null 
	int a[] = {1,2,5,3,4,INT_MIN,6};
	int size = sizeof(a) / sizeof(a[0]);
	printf("size=%d\n", size);	
	struct TreeNode *root = NULL;
	createTree(&root, a, size);	
	
	printf("\nPre Order:");
	preOrderPrint(root);
	printf("\n");
	
	flatten(root);
	
	printf("\nResult:");
	while (root != NULL) {
		struct TreeNode *p = root;
		printf("%d ", p->val);
		root = root->right;
		free(p);
	}
	printf("\n");
		
	return 0;
}

