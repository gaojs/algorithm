#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int maxProfit(int* a, int n)
{
	if (a == NULL || n ==0) {
		return 0; // �������� 
	}
	int min = a[0]; // �����ƽ� 
	int profit = 0; // Ĭ����0 
	for (int i = 1; i < n; i++) {
		if (a[i] < a[i - 1]) { 
			profit += a[i - 1] - min;
			min = a[i]; // ������ 
		}
	}
	profit += a[n - 1] - min;
	return profit;
}

int main()
{
	// int a[] = {7,6,4,3,1}; // 0
	// int a[] = {7,1,5,3,6,4}; // 7
	int a[] = {1,2,3,4,5}; // 4
	int size = sizeof(a) / sizeof(a[0]);
	printf("%d\n", maxProfit(a, size));
	return 0;
}
