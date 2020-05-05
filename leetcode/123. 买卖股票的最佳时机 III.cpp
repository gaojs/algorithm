#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int maxProfit(int* a, int n)
{
	if (a == NULL || n ==0) {
		return 0; // 参数有误 
	}
	// p[i][j]为第i天到第j天的最大收益 
	int *p = (int*)calloc(sizeof(int), n * n);
	if (p == NULL) { // 内存申请失败 
		return 0;
	}
	for (int i = 0; i < n; i++) {
		int min = a[i]; // 二重循环，暴力破解 
		for (int j = i + 1; j < n; j++) {
			if (min > a[j]) {
				min = a[j];
			}
			p[i * n + j] = a[j] - min;
		}		
	}
	int max = p[0 * n + n - 1]; // 1天的最大值
	for (int i = 0; i < n; i++) { // 查找2天的最大值 
		int d2 = p[0 * n + i] + p[i * n + n - 1];
		if (max < d2) {
			max = d2;
		}	
	}	
	free(p); 
	return max;
}

int main()
{
	// int a[] = {3,3,5,0,0,3,1,4}; // 6
	// int a[] = {1,2,3,4,5}; // 4
	int a[] = {7,6,4,3,1}; // 0
	int size = sizeof(a) / sizeof(a[0]);
	printf("%d\n", maxProfit(a, size));
	return 0;
}
