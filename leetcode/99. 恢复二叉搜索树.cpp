#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

void inOrder(struct TreeNode* root, struct TreeNode**prev,
	struct TreeNode**errMin, struct TreeNode**errMax)
{
	if (root == NULL || prev==NULL || errMin == NULL || errMax == NULL) {
		return; // ��������ֱ�ӷ��� 
	} else {	    
	    inOrder(root->left, prev, errMin, errMax);
	    // ��ǰ���ڵ㣬�Ž���ǰ�ڵ��ǰ���ڵ㣬���бȽ� 
	    if (*prev != NULL && (*prev)->val > root->val) { // �д� 
	        if (*errMax == NULL) { 
	            *errMax = *prev; // �״θ�ֵ 
	        } else if ((*prev)->val > (*errMax)->val) {
	            *errMax = *prev; // �и���ģ��ٴθ�ֵ 
	        }	        
	        if (*errMin == NULL) { 
	            *errMin = root; // �״θ�ֵ 
	        } else if (root->val < (*errMin)->val) {
	            *errMin = root; // �и�С�ģ��ٴθ�ֵ 
	        }
	    }
	    *prev = root; // ������������˵��root��Ĭ�ϵ�ǰ���ڵ� 
	    inOrder(root->right, prev, errMin, errMax);
	}
}

// ��Ϊֻ��һ�Խڵ㣨�����ڵ㣩Ū���� ��
// ���ԣ�ֻ���ҳ�Ū��Ľڵ��е�������С��Ȼ�󽻻������ɡ� 
void recoverTree(struct TreeNode* root)
{
    struct TreeNode *prev = NULL;
    struct TreeNode *errMin = NULL;
    struct TreeNode *errMax = NULL;
    
    inOrder(root, &prev, &errMin, &errMax);
    // ����������ժ�ҽڵ㣬ֱ�ӽ������ǵ�ֵ 
    int tmp = errMin->val;
    errMin->val = errMax->val;
    errMax->val = tmp;
    return;
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
	int a[] = {1,3,0,0,2}; 
	// int a[] = {3, 1, 4, 0, 0, 2}; // 0��ʾnull 
	int size = sizeof(a) / sizeof(a[0]);
	
	struct TreeNode *root = NULL;
	createTree(&root, a, size, 0);
	printf("\n");
	inOrderPrint(root);
	recoverTree(root);
	printf("\n");
	inOrderPrint(root);
	freeTree(root);
	return 0;
}

