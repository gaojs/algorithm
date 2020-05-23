#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
	int x, y;
	int d;
} node_t;

int cmp(const void*a, const void*b)
{
	node_t *a1 = (node_t *)a;
	node_t *b1 = (node_t *)b;
	return a1->d - b1->d;
}

int** kClosest(int** a, int n, int* col, int k, 
	int* returnSize, int** returnColumnSizes)
{
	if (a == NULL || col == NULL || n == 0 || k == 0
		|| returnSize == NULL || returnColumnSizes== NULL) {
		return NULL;
	}
	*returnSize = k;
	*returnColumnSizes = (int*)calloc(k, sizeof(int));
	int **result = (int**)calloc(k, sizeof(int*));
	node_t *p = (node_t *)calloc(n, sizeof(node_t)); 
	for (int i = 0; i < n; i++) {
		int x = a[i][0];
		int y = a[i][1];
		int d = x*x+y*y;
		p[i].x=x;
		p[i].y=y;
		p[i].d=d;
		// printf("(%d,%d)=%d\n", x, y, d);
	}
	qsort(p, n, sizeof(node_t), cmp);	
	/* for (int i = 0; i < n; i++) {
		printf("(%d,%d)=%d\n", p[i].x, p[i].y, p[i].d);
	}*/
	for (int i = 0; i < k; i++) {
		(*returnColumnSizes)[i] = 2;
		result[i] = (int*)malloc(sizeof(int)*2); 
		result[i][0] = p[i].x;
		result[i][1] = p[i].y; 
	}
	free(p);
	return result;
}

int main()
{
	/***************** 
	int p[][2]={{1,3},{-2,2}}; //[-2,2]
	int *a[] = {p[0], p[1]}, k = 1;	
	int col[] = {2,2}; */
	int p[][2]={3,3,5,-1,-2,4}; //[3,3] [-2, 4]
	int *a[] = {p[0], p[1], p[2]}, k = 2;
	int col[] = {2,2,2};
	int n = sizeof(a) / sizeof(a[0]);
	int returnSize = 0; 
	int* returnColumnSizes = NULL;
	int **pr = kClosest(a, n, col, k, 
		&returnSize, &returnColumnSizes);
	if (pr != NULL) {
		for (int i = 0; i < returnSize; i++) {			
			printf("[%d,%d] ", pr[i][0], pr[i][1]);			
			free(pr[i]);
		}
		free(returnColumnSizes);
		free(pr);
	}
	return 0;
} 

