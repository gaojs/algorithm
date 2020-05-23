#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 利用分治思想，找出一种放法，保证符合题意。
// a是个数组，n是数字元素的个数；奇数放左边，偶数放右边。
// 将n1开始，步长为step的数字，放到p1到p2的连续的位置上。
void dfs(int *a, int n, int p1, int p2, int n1, int step) 
{
	if (a == NULL || n <= 0 || p1 >=n || p2 >=n || p1 > p2) {
		return; // 参数不对 
	} else if (p1 == p2) { // 只有1个元素 
		a[p1] = n1;
	} else { // 3个元素及以上
		int p = (p1 + p2) / 2; // 中间位置 
		dfs(a, n, p1, p, n1, step * 2); // 左边
		dfs(a, n, p + 1, p2, n1 + step, step * 2); // 右边
	} 
} 

int* beautifulArray(int n, int* returnSize)
{
	if (n < 1 || returnSize == NULL) {
		return NULL;
	} else {
		int size = sizeof(int) * n;
		int *a = (int*)malloc(size);			
		if (a == NULL) {			
			*returnSize = 0;
			return NULL;
		}
		dfs(a, n, 0, n - 1, 1, 1);
		*returnSize = n;
		return a;
	}
}

int main()
{
	//for (int n = 1; n < 20; n++) {	
		{ int n = 4;
		int returnSize = 0;
		int *a = beautifulArray(n, &returnSize);
		if (a != NULL) {
			printf("%d: ", n);
			for (int i = 0; i < returnSize; i++) {
				printf("%d ", a[i]);
			}
			printf("\n");
			free(a);
		}
	}
	return 0;
} 

