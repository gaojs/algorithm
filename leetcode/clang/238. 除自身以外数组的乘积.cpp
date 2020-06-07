#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>

int* productExceptSelf(int* a, int n, int* returnSize)
{
	if (a == NULL || n < 0 || returnSize == NULL) {
		return NULL;
	}
	*returnSize = 0;
	int *result = (int *)malloc(sizeof(int) * n);
	if (result == NULL) {
		return NULL;
	}
	int left[n], right[n];
	left[0] = 1;
	for (int i = 1; i < n; i++) {
		left[i] = left[i - 1] * a[i - 1];
	}
	right[n - 1] = 1;
	for (int i = n - 2; i >=0; i--) {
		right[i] = right[i + 1] * a[i + 1];
	}
	for (int i = 0; i < n; i++) {
		result[i] = left[i] * right[i] ;
	}
	*returnSize = n;
	return result;
}

int main()
{
	int a[] = {1,2,3,4};
	int n = sizeof(a) / sizeof(a[0]);
	int returnSize = 0;
	int *p = productExceptSelf(a, n, &returnSize);
	if (p != NULL) {
		for (int i = 0; i < returnSize; i++) {
			printf("%d ", p[i]);
		}
		free(p);
	}
	return 0;
}


