#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int findMin(int*a, int n)
{
	if (a == NULL || n == 0) {
		return -1;
	} else if (n == 1) {
		return a[0];
	}
	int left = 0, right = n - 1;
	while (left <= right) {
		int mid = left + (right - left)/ 2;
		// printf("(%d-%d)=%d=[%d]\n", left, right, mid, a[mid]);
		if (mid + 1 < n && a[mid] > a[mid + 1]) {
			return a[mid + 1]; // 找到断点就退出
		}
		if (mid > 0 && a[mid - 1] > a[mid]) {
			return a[mid]; // 找到断点就退出
		}
		if (a[left] > a[mid]) {
			right = mid - 1;
		} else {
			left = mid + 1;
		}
	}
	return a[0];
}

int main()
{
	int a[] = {1,2}; //1
	// int a[] = {3,4,5,6,1,2}; // 1
	// int a[] = {4,5,6,7,0,1,2}; // 0
	int n = sizeof(a)/sizeof(a[0]);
	printf("%d", findMin(a, n));
	return 0;
}

