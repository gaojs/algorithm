#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ����t�Ƿ��ܲ��뵽����a��m��λ�� 
bool ok(int *a, int n, int m, int t) 
{
	if (a == NULL || n <= 0) {
		return false;
	}
	for (int i = 0; i < m; i++) { // ǰ 
		for (int j = i + 1; j < m; j++) {
			if(a[i] + t == a[j] * 2) {
				return false;
			}
		}
	} 
	for (int i = m; i < n; i++) { // �� 
		for (int j = i + 1; j < n; j++) {
			if(a[j] + t == a[i] * 2) {
				return false;
			}
		}
	} 
	return true;
}

// ��t���뵽����a��m��λ�� 
int* insert(int *a, int n, int m, int t) 
{
	int *p = (int*)calloc(n + 1, sizeof(int));
	if (p == NULL) {
		return NULL;
	}
	if (m > 0) { // ǰ�� 
		memcpy(p, a, sizeof(int) * m);
	}
	p[m] = t; // ����λ��
	if (n > m) { // ���� 
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
			if (a == NULL) { // ����1���ռ� 			
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
					if (p != NULL) { // �ҵ�1�� 
						free(a); // �ͷ�a 					
						*returnSize = n;
						return p;
					}
				}
			}
			free(a); // �ͷ�a 
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

