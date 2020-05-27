#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

#define MAX(x, y) ((x) > (y) ? (x) : (y))
int maxSum(struct TreeNode* root, int *maxValue)
{
    if (root == NULL || maxValue == NULL) {
        return INT_MIN; // 最小值 
    }
    int maxLeft = maxSum(root->left, maxValue);
    int maxRight = maxSum(root->right, maxValue);    
    *maxValue = MAX(*maxValue, root->val);
    if (maxLeft != INT_MIN && maxRight != INT_MIN) {
        int sum = root->val + maxLeft + maxRight;
        *maxValue = MAX(*maxValue, sum);
    }
    if (maxLeft != INT_MIN) { // 左子树有值 
        maxLeft += root->val;
        *maxValue = MAX(*maxValue, maxLeft);
    } else {
        maxLeft = root->val;
    }
    if (maxRight != INT_MIN) { // 右子树边有值 
        maxRight += root->val;
        *maxValue = MAX(*maxValue, maxRight);
    } else {
        maxRight = root->val;
    }
    return MAX(MAX(root->val, maxLeft), maxRight); 
}

int maxPathSum(struct TreeNode* root)
{
    int maxValue = INT_MIN; // 最小值
    maxSum(root, &maxValue);
    return maxValue;
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
	// int a[] = {}; // 0表示null 
	// int a[] = {1,2,3}; // 6
	// int a[] = {-10,9,20,INT_MIN,INT_MIN,15,7}; //42 
	// int a[] = {1,2,INT_MIN,3,INT_MIN,4,INT_MIN,5}; // 15 
	int a[] = {9,6,-3,INT_MIN,INT_MIN,-6,2,INT_MIN,INT_MIN,2,INT_MIN,-6,-6,-6}; // 16 
	int size = sizeof(a) / sizeof(a[0]);
	printf("size=%d\n", size);	
	struct TreeNode *root = NULL;
	createTree(&root, a, size);	
	
	printf("\nPre Order:");
	preOrderPrint(root);
	printf("\nIn Order:");
	inOrderPrint(root);
	printf("\n");
	
	printf("\nMax=%d", maxPathSum(root));
	
	freeTree(root);
	return 0;
}

