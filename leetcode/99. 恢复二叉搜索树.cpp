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
		return; // 参数错误，直接返回 
	} else {	    
	    inOrder(root->left, prev, errMin, errMax);
	    // 有前驱节点，才将当前节点跟前驱节点，进行比较 
	    if (*prev != NULL && (*prev)->val > root->val) { // 有错 
	        if (*errMax == NULL) { 
	            *errMax = *prev; // 首次赋值 
	        } else if ((*prev)->val > (*errMax)->val) {
	            *errMax = *prev; // 有更大的，再次赋值 
	        }	        
	        if (*errMin == NULL) { 
	            *errMin = root; // 首次赋值 
	        } else if (root->val < (*errMin)->val) {
	            *errMin = root; // 有更小的，再次赋值 
	        }
	    }
	    *prev = root; // 对于右子树来说，root是默认的前驱节点 
	    inOrder(root->right, prev, errMin, errMax);
	}
}

// 因为只有一对节点（两个节点）弄错了 ，
// 所以，只需找出弄错的节点中的最大和最小，然后交换，即可。 
void recoverTree(struct TreeNode* root)
{
    struct TreeNode *prev = NULL;
    struct TreeNode *errMin = NULL;
    struct TreeNode *errMax = NULL;
    
    inOrder(root, &prev, &errMin, &errMax);
    // 交换，无需摘挂节点，直接交换它们的值 
    int tmp = errMin->val;
    errMin->val = errMax->val;
    errMax->val = tmp;
    return;
}

void createTree(struct TreeNode **root, int *a, int size, int i)
{ 
	if (root == NULL || a == NULL || size == 0) {
		return; // 参数有误 
	} else if (i >= size || a[i] <= 0){	
		printf("a[%d]=%d,", i, a[i]);
		*root = NULL;
		return;
	} else { // 创建 二叉树 
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
	} else { // 中根 遍历 
		inOrderPrint(root->left);
		printf("%d,", root->val);
		inOrderPrint(root->right);
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
	int a[] = {1,3,0,0,2}; 
	// int a[] = {3, 1, 4, 0, 0, 2}; // 0表示null 
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

