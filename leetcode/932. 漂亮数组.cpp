#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 测试t是否能插入到数组a的m的位置 
bool ok(int *a, int n, int m, int t) 
{
	if (a == NULL || n <= 0) {
		return false;
	}
	for (int i = 0; i < m; i++) { // 前 
		for (int j = i + 1; j < m; j++) {
			if(a[i] + t == a[j] * 2) {
				return false;
			}
		}
	} 
	for (int i = m; i < n; i++) { // 后 
		for (int j = i + 1; j < n; j++) {
			if(a[j] + t == a[i] * 2) {
				return false;
			}
		}
	} 
	return true;
}

// 将t插入到数组a的m的位置 
int* insert(int *a, int n, int m, int t) 
{
	int *p = (int*)calloc(n + 1, sizeof(int));
	if (p == NULL) {
		return NULL;
	}
	if (m > 0) { // 前面 
		memcpy(p, a, sizeof(int) * m);
	}
	p[m] = t; // 插入位置
	if (n > m) { // 后面 
		memcpy(&p[m + 1], &a[m], sizeof(int) * (n-m));
	}
	return p;
} 

int* beautifulArray(int n, int* returnSize)
{
	if (n < 1 || returnSize == NULL) {
		return NULL;
	} else {
		if(n == 1) {
			int *a = (int*)calloc(1, sizeof(int));
			if (a == NULL) { // 申请1个空间 			
				*returnSize = 0;
				return NULL;
			}
			*returnSize = a[0] = 1;
			return a;			
		} else {
			int size = 0;
			int *a = beautifulArray(n - 1, &size);
			if (a == NULL || size == 0) {			
				*returnSize = 0;
				return NULL;
			}
			for (int i = n - 1; i >= 0; i--) {
				if (ok(a, n - 1, i, n)) {
					int *p = insert(a, n - 1, i, n);
					if (p != NULL) { // 找到1个 
						free(a); // 释放a 					
						*returnSize = n;
						return p;
					}
				}
			}
			free(a); // 释放a 
			*returnSize = 0;
			return NULL;
		} 		
	}
}

int main()
{
	for (int n = 1; n < 101; n++) {		
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

