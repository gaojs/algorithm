#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* prevPermOpt1(int *a, int n, int *returnSize)
{
	int *b = (int*)calloc(n, sizeof(int));
	if (b == NULL) {
		return NULL;
	}
	*returnSize = n;
	memcpy(b, a, sizeof(int)*n);
	for (int i = n - 2; i >= 0; i--) {
		for (int j = i + 1; j < n; j++) {
			if (b[i] > b[j] ) { // 发现从小到大的逆序了 
				while (j + 1 < n && b[j+1] < b[i]
					&& b[j] < b[j+1]) { // 挑个最大的 
					j++; // 找到小于b[i]的最大值 
				}
				int t = b[i];
				b[i] = b[j];
				b[j] = t;
				return b;
			}
		}
	}
	return b;
}

int main()
{
	// int a[] = {3,2,1};  // 3 1 2 
	// int a[] = {1,9,4,6,7};  // 1,7,4,6,9
	int a[] = {3,1,1,3};  // 1,3,1,3
	int n = sizeof(a) / sizeof(a[0]);
	int returnSize = 0;
	int *b = prevPermOpt1(a, n, &returnSize);
	for (int i = 0; i < n; i++) {
		printf("%d ", b[i]);
	}
	free(b);
	return 0;
} 
