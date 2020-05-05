#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int maxProfit(int* a, int n)
{
	if (a == NULL || n ==0) {
		return 0; // 参数有误 
	}
	int min = a[0]; // 暴力破解 
	int profit = 0; // 默认是0 
	for (int i = 1; i < n; i++) {
		if (min > a[i]) { // 最低价 
			min = a[i];
		}
		int d1 = profit; // 之前卖 
		int d2 = a[i] - min; // 当天卖 
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
