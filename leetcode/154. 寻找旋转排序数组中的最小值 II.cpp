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
	while (left < right) {
		int mid = left + (right - left)/ 2;
		printf("(%d-%d)=%d=[%d]\n", left, right, mid, a[mid]);
		if (mid + 1 < n && a[mid] > a[mid + 1]) {
			return a[mid + 1]; // 找到断点就退出
		}
		if (mid > 0 && a[mid - 1] > a[mid]) {
			return a[mid]; // 找到断点就退出
		}
		if (a[left] > a[mid]) {
			right = mid - 1;
		} else if(a[left] < a[mid]) {
			left = mid + 1;
		} else { // 相等
			if (a[right] >= a[right - 1]) {
			   right -= 1; // 右侧最大
			} else { // 找到最小值
				return a[right];
			}
		}
	}
	return a[0];
}

int main()
{
	// int a[] = {1,3,5}; // 1
	// int a[] = {2,2,2,0,1}; // 0
	// int a[] = {10,1,10,10,10}; // 1
	// int a[] = {10,10,10,10,1}; // 1
	int a[] = {1,1}; // 1
	int n = sizeof(a)/sizeof(a[0]);
	printf("%d", findMin(a, n));
	return 0;
}

