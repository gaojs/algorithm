#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

bool dfs(struct TreeNode*left, struct TreeNode*right)
{
	if (left == NULL && right == NULL) {
		return true; // ȫ�� 
	} else if (left == NULL || right == NULL) {
		return false; // һ��Ϊ�գ�һ������ 
	} 
	else if (left == right) { // ָ��ͬһ���ڵ� 
		return dfs(left->left, right->right);
	} else {
		if (left->val != right->val) {
			return false; // �ԱȽڵ�ֵ 
		}
		if (!dfs(left->left, right->right)) {
			return false; // �Ա������� 
		}
		if (!dfs(left->right, right->left)) {
			return false; // �Ա������� 
		}
		return true;
	} 
}

bool isSymmetric(struct TreeNode* root)
{
	return dfs(root, root);
}

void createTree(struct TreeNode **root, int *a, int size, int i)
{ 
	if (root == NULL || a == NULL || size == 0) {
		return; // �������� 
	} else if (i >= size || a[i] <= 0){	
		printf("a[%d]=%d,", i, a[i]);
		*root = NULL;
		return;
	} else { // ���� ������ 
		struct TreeNode* n = (struct TreeNode*)malloc(sizeof(struct TreeNode));
		if (n == NULL) {
			*root = NULL; 
			return;
		} else {
			printf("a[%d]=%d,", i, a[i]);
			n->val = a[i];
			n->left = NULL;
			n->right = NULL;
			*root = n;
			if (2 * i + 1 < size) {
				createTree(&n->left, a, size, 2 * i + 1);
			}
			if (2 * i + 2 < size) {
				createTree(&n->right, a, size, 2 * i + 2);
			}
			return;
		}
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
	// int a[] = {1,2,2,3,4,4,3};
	int a[] = {1,2,2,0,3,0,3}; // 0��ʾnull 
	int size = sizeof(a) / sizeof(a[0]);
	
	struct TreeNode *root = NULL;
	createTree(&root, a, size, 0);
	printf("\n");
	inOrderPrint(root);
	printf("\n");
	if(isSymmetric(root)) {
		printf("true");
	} else {
		printf("false");
	}
	freeTree(root);
	return 0;
}

