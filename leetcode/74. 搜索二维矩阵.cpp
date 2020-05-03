#include <stdio.h>
#include <stdlib.h>

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target)
{
	if (matrix == NULL || matrixColSize == NULL || matrixSize == 0) {
		return false;
	}
	// printf("%d, %d\n", matrixSize, matrixColSize[0]);
	int *p = (int *)calloc(sizeof(int), matrixSize * matrixColSize[0]);	
	if (p == NULL) {
		return false;
	}
	int cnt = 0;
	for (int r = 0; r < matrixSize; r++) {
		for (int c = 0; c < matrixColSize[r]; c++) {
			// printf("%p, %p\n", matrix, matrix[r]);
			p[cnt++] = matrix[r][c];
		}
	}
	int left = 0;
	int right = cnt - 1;
	printf("cnt=%d\n", cnt);
	while (left <= right) {
		int mid =  (left + right) / 2;		
		// printf("a[%d]=%d\n", mid, p[mid]);
		if (p[mid] == target) {
			free(p);
			return true;
		} else if (p[mid] < target) {
			left = mid + 1;
		} else {
			right = mid - 1;
		}		
	}
	free(p);
	return false;
}

int main()
{
	int a1[] = {1,   3,  5,  7};
	int a2[] = {10, 11, 16, 20};
	int a3[] = {23, 30, 34, 50};
	int *matrix[] = {a1, a2, a3};
	int matrixSize = sizeof(matrix) / sizeof(matrix[0]);
	int matrixColSize[3] = {4, 4, 4};
	int target = 13;
	
	printf("%p, %p\n", matrix, matrix[0]);
	if (searchMatrix((int**)matrix, matrixSize, matrixColSize, target)) {
		printf("true");
	} else {
		printf("false");
	}
	return 0;
}
