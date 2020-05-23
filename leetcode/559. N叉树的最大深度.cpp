#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct Node {
	int val;
	int numChildren;
	struct Node** children;
} node_t;

int maxDepth(struct Node* root)
{
	if (root == NULL) {
		return 0; 
	} else {
		int d = 1, m = 0;
		for (int i = 0; i < root->numChildren; i++)
		{
			int c = maxDepth(root->children[i]);
			if (m < c) { // 找子树的最大深度 
				m = c;
			}
		}
		return d + m;
	}
}

int main()
{
	int a[] = {1,INT_MIN,3,2,4,INT_MIN,5,6}; // INT_MIN表示null
	int size = sizeof(a) / sizeof(a[0]);
	// node_t *root = createTree(a, size);	
	return 0;
}

