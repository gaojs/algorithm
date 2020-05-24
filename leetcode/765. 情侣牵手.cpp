#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int minSwapsCouples(int*a, int n)
{

}

int main()
{
	int a[] = {0, 2, 1, 3}; // 1
	// int a[] = {3, 2, 0, 1}; // 0
	int n = sizeof(a) / sizeof(a[0]);
	printf("%d", minSwapsCouples(a, n));
	return 0;
} 


