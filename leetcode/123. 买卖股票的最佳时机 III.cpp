#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int maxProfit(int* a, int n)
{
	if (a == NULL || n ==0) {
		return 0; // �������� 
	}
	// p[i][j]Ϊ��i�쵽��j���������� 
	int *p = (int*)calloc(sizeof(int), n * n);
	if (p == NULL) { // �ڴ�����ʧ�� 
		return 0;
	}
	for (int i = 0; i < n; i++) {
		int min = a[i]; // ����ѭ���������ƽ� 
		for (int j = i + 1; j < n; j++) {
			if (min > a[j]) { // ��ͼ� 
				min = a[j];
			}
			int d1 = p[i * n + j - 1]; // ֮ǰ�� 
			int d2 = a[j] - min; // ������ 
			p[i * n + j] = d1 > d2 ? d1 : d2;
			printf("(%d-%d)=%d\n", i, j, p[i * n + j]);
		}		
	}
	int max = p[0 * n + n - 1]; // 1������ֵ
	for (int i = 0; i < n; i++) { // ����2������ֵ 
		int d1 = p[0 * n + i]; // ǰ1�� 
		int d2 = p[i * n + n - 1]; // ��1��
		int t = d1 + d2;
		if (max < t) {
			printf("%d:(%d-%d)=%d\n", i, d1, d2, t);
			max = t;
		}	
	}	
	free(p); 
	return max;
}

int main()
{
	// int a[] = {3,3,5,0,0,3,1,4}; // 6
	// int a[] = {1,2,3,4,5}; // 4
	// int a[] = {7,6,4,3,1}; // 0
	int a[] = {2,1,4,5,2,9,7}; // 11
	int size = sizeof(a) / sizeof(a[0]);
	printf("%d\n", maxProfit(a, size));
	return 0;
}
