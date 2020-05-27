#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 利用分治思想(Divide-and-Conquer)，找出一种放法。
// 奇数靠左，偶数靠右。a是个数组，n是数字元素的个数；
// 将n1开始，步长为step的数字，放到p1到p2的连续的位置上。
void dc(int *a, int n, int p1, int p2, int n1, int step) 
{
	if (a == NULL || n <= 0 || p1 >=n || p2 >=n || p1 > p2) {
		return; // 参数不对 
	} else if (p1 == p2) { // 只有1个元素 
		a[p1] = n1;
	} else { // 3个元素及以上
		int p = (p1 + p2) / 2; // 中间位置 
		dc(a, n, p1, p, n1, step * 2); // 左边
		dc(a, n, p + 1, p2, n1 + step, step * 2); // 右边
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
		dc(a, n, 0, n - 1, 1, 1);
		*returnSize = n;
		return a;
	}
}

int main()
{
	// for (int n = 1; n < 20; n++) {	
		{ int n = 100;
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

