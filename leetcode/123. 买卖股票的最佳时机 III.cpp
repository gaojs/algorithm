#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define COUNT  100
int a[COUNT][COUNT] = {0}; // i到j的最大利润 
int m[COUNT] = {0}; // 前i项最小值 
int maxProfit(int* prices, int size)
{
	if ( prices == NULL || size == 0) {
		return 0;
	}
	memset(a, 0, sizeof(a));
	m[0] = prices[0]; // 第一项 
	for (int i = 1; i < size; i++) {
		
	}
	  
}

int main()
{
	//int a[] = {}; // 0表示null 
	int a[] = {3,3,5,0,0,3,1,4};
	int size = sizeof(a) / sizeof(a[0]);
	printf("%d", maxProfit(a, size));		
	return 0;
}

