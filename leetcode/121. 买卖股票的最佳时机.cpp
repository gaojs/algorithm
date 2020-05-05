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
		if (min > a[i]) { // ��ͼ� 
			min = a[i];
		}
		int d1 = profit; // ֮ǰ�� 
		int d2 = a[i] - min; // ������ 
		profit = d1 > d2 ? d1 : d2;
	}	
	return profit;
}

int main()
{
	int a[] = {7,6,4,3,1}; // 0
	// int a[] = {7,1,5,3,6,4}; // 5
	int size = sizeof(a) / sizeof(a[0]);
	printf("%d\n", maxProfit(a, size));
	return 0;
}
