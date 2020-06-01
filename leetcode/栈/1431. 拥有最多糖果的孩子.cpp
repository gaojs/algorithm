#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>

bool* kidsWithCandies(int*a, int n, int k, int* returnSize)
{
	if (a == NULL || returnSize == NULL || n <= 0) {
		return NULL;
	}
	*returnSize = 0;
	bool *result = (bool*)calloc(n, sizeof(bool));
	if (result == NULL) {
		return NULL;
	}
	int max = a[0];
	for (int i = 1; i < n; i++) {
		if (max < a[i]) {
			max = a[i];
		}
	}
	for (int i = 0; i < n; i++) {
		if (a[i] + k >= max) {
			result[i] = true;
		} else {
			result[i] = false;
		}
	}
	*returnSize = n;
	return result;
}

int main()
{
	// int a[] = {2,3,5,1,3}, k = 3;
	int a[] = {12,1,12}, k = 10;
	int n = sizeof(a) / sizeof(a[0]);
	int returnSize = 0;
	bool *p = kidsWithCandies(a, n, k, &returnSize);
	if (p != NULL) {
		for (int i = 0; i < returnSize; i++) {
			(p[i]) ? printf("true ") : printf("false ");
		}
		free(p);
	}
	return 0;
}


