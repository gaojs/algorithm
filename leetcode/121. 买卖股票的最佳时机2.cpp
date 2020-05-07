#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX(x, y) (x) > (y) ? (x) : (y)
int maxProfit(int* a, int n)
{
	if (a == NULL || n ==0) {
		return 0; // �������� 
	}
	// dp[n][f]Ϊ��n���k�ι������������ 
	// f = 0, Ϊ�����й�Ʊ�� f = 1, Ϊ���й�Ʊ 
	int dp[n][2]; // = {0}; 
	memset(dp, 0, sizeof(dp));	
	// ��0�죬���տ�ʼ������ 
	dp[0][0] = 0; // �����У�����Ϊ0 
	dp[0][1] = 0 - a[0]; // ���У�����Ϊ�� 
	for(int i = 1; i < n; i++) { // ��i�� 
		// ��i�죬�����У�ǰ1�첻���У������޲�����ǰ1����У��������� 
		dp[i][0] = MAX(dp[i-1][0], dp[i-1][1] + a[i]);
		// ��i�죬���У�ǰ1����У������޲�����ǰ1�첻���У���������
		dp[i][1] = MAX(dp[i-1][1], 0 - a[i]);
	}
	return dp[n-1][0]; // ���1�죬�����й�Ʊ 
}

int main()
{
	int a[] = {7,6,4,3,1}; // 0
	// int a[] = {7,1,5,3,6,4}; // 5
	int size = sizeof(a) / sizeof(a[0]);
	printf("%d\n", maxProfit(a, size));
	return 0;
}
