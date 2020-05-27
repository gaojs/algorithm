#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int cmp(const void *a, const void *b)
{
	return *(int*)b - *(int*)a; // ÄæÐò
}

int findKthLargest(int*a, int n, int k)
{
	if (a == NULL || n == 0 || k == 0 || n < k) {
		return 0; // ²ÎÊý´íÎó
	}
	qsort(a, n, sizeof(int), cmp);
	return a[k - 1];
}

int main()
{
	// int a[] = {3,2,1,5,6,4}, k = 2; // 5
	int a[] = {3,2,3,1,2,4,5,5,6}, k = 4; // 4
	int n = sizeof(a)/sizeof(a[0]);
	printf("%d", findKthLargest(a, n, k));
	return 0;
}

