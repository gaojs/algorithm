#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void print(int*a, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d,", a[i]);
	}
	printf("\n");
}

void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int findKthLargest(int*a, int n, int k)
{
	if (a == NULL || n <= 0 || k <= 0 || n < k) {
		return 0; // ��������
	}
	int i = 0, j = n - 1; // ��ͷ���м�
	while (i < j) { // ֱ�������
		while (i < j && a[i] >= a[j]) { // ����
			j--; // ��������
		}
		if (i < j) {
			swap(&a[i], &a[j]);
			i++; // ��������
		}
		while (i < j && a[i] >= a[j]) { // ����
			i++; // ��������
		}
		if (i < j) {
			swap(&a[i], &a[j]);
			j--; // ��������
		}
	}
	if (i == k - 1) { // �ҵ�
		return a[i];
	} else if (i > k - 1) { // ��ǰ���
		return findKthLargest(a, i, k);
	} else { // �ں���
		return findKthLargest(a + i + 1, n - i - 1, k - i - 1);
	}
}

int main()
{
	// int a[] = {3,2,1,5,6,4}, k = 2; // 5
	int a[] = {3,2,3,1,2,4,5,5,6}, k = 4; // 4
	int n = sizeof(a)/sizeof(a[0]);
	printf("%d", findKthLargest(a, n, k));
	return 0;
}

