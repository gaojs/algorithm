#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

int dfs(struct TreeNode* root, int base)
{
	if (root == NULL) {
		return 0; 
	} else {
		int value = base * 10 + root->val;
		int left = dfs(root->left, value);
		int right = dfs(root->right, value);
		// printf("v=%d, left=%d, right=%d\n", root->val, left, right);
		if (left > 0 || right > 0) {
			return left + right;
		} else {			
			return value;
		} 
	}
}

int sumNumbers(struct TreeNode* root)
{
	return dfs(root, 0);
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
	// int a[] = {}; // 0��ʾnull 
	// int a[] = {1,2,3}; // 0��ʾnull
	int a[] = {4,9,0,5,1}; 
	int size = sizeof(a) / sizeof(a[0]);
	printf("size=%d\n", size);	
	struct TreeNode *root = NULL;
	createTree(&root, a, size);	
	
	printf("\nPre Order:");
	preOrderPrint(root);
	printf("\n");
	
	printf("\nSum=%d", sumNumbers(root));
	
	freeTree(root);
	return 0;
}

