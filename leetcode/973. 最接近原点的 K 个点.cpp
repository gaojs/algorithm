#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void*a, const void*b)
{
	int x1=(*(int**)a)[0], y1=(*(int**)a)[1];
	int x2=(*(int**)b)[0], y2=(*(int**)b)[1];
	return (x1*x1+y1*y1) - (x2*x2+y2*y2);
}

int** kClosest(int** a, int n, int* col, int k, 
	int* returnSize, int** returnColumnSizes)
{
	*returnSize = k;
	qsort(a, n, sizeof(int**), cmp);	
	*returnColumnSizes = (int*)calloc(k, sizeof(int));
	for (int i = 0; i < k; i++) {
		(*returnColumnSizes)[i] = 2;
	}
	return a;
}

int main()
{
	/***************** 
	int p[][2]={{1,3},{-2,2}}; //[-2,2]
	int *a[] = {p[0], p[1]}, k = 1;	
	int col[] = {2,2}; */
	//int p[][2]={{3,3},{5,-1},{-2,4}}; //[3,3] [-2, 4]
	int p[][2]={{-5,4},{-6,-5},{4,6}};
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
			// free(pr[i]);
		}
		free(returnColumnSizes);
		// free(pr);
	}
	return 0;
} 

