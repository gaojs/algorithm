#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int findPos(int *a, int n)
{
	if (n <= 1) { // 只有1个，就它了
		return 0;
	} else if (n == 2) { // 有2个，选小的
		return a[0] < a[1] ? 0 : 1;
	}
	int min = 1; // 大于3个，选择中间的最小的
	for (int i = 2; i < n - 1; i++) {
		if (a[min] < a[i]) {
			continue;
		} else if (a[min] > a[i]) {
			min = i;
		} else {
			int mins = a[min - 1] * a[min + 1];
			int is = a[i - 1] * a[i + 1];
			if (mins < is) { // 选个左右乘积较大的
				min = i;
			}
		}
	}
	return min;
}

int calcOne(int *a, int n, int pos)
{
	int left = 1, right = 1;
	if (pos > 0) {
		left = a[pos - 1];
	}
    if (pos < n - 1) {
    	right = a[pos + 1];
	}
	return left * a[pos] * right;
}

int removeOne(int *a, int n, int pos)
{
	if (n - pos - 1 > 0) {
		memmove(&a[pos], &a[pos + 1], sizeof(int) * (n - pos - 1));
	}
	a[n - 1] = 0;
	return 0;
}

void print(int *a, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

int maxCoins(int*a, int n)
{
	if (a == NULL || n <= 0) {
		return 0;
	}
	print(a, n);
	int sum = 0;
	while (n > 0) {
		int pos = findPos(a, n);
		printf("pos = %d, ", pos);
		int t = calcOne(a, n, pos);
		removeOne(a, n, pos);
		sum += t;
		printf("num = %d, sum = %d\n", t, sum);
		n--;
		print(a, n);
	}
	return sum;
}

int main()
{
	// int a[] = {3,1,5,8}; // 167
	int a[] = {9,76,64,21,97,60}; // 1086136
	int n = sizeof(a)/sizeof(a[0]);
	printf("%d", maxCoins(a, n));
	return 0;
}

