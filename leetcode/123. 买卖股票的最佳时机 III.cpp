#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define COUNT  100
int a[COUNT][COUNT] = {0}; // i��j��������� 
int m[COUNT] = {0}; // ǰi����Сֵ 
int maxProfit(int* prices, int size)
{
	if ( prices == NULL || size == 0) {
		return 0;
	}
	memset(a, 0, sizeof(a));
	m[0] = prices[0]; // ��һ�� 
	for (int i = 1; i < size; i++) {
		
	}
	  
}

int main()
{
	//int a[] = {}; // 0��ʾnull 
	int a[] = {3,3,5,0,0,3,1,4};
	int size = sizeof(a) / sizeof(a[0]);
	printf("%d", maxProfit(a, size));		
	return 0;
}

