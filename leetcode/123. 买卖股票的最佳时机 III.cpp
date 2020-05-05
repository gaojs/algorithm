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
	// dp[n][k][f]Ϊ��n���k�ι������������ 
	// f = 0, Ϊ�����й�Ʊ�� f = 1, Ϊ���й�Ʊ 
	int K = 3; // k = 2 ������2�� 
	int dp[n][K][2]; // = {0}; 
	memset(dp, 0, sizeof(dp));	
	for(int i = 0; i < n; i++) { // ��i�� 
		for(int k = 1; k < K; k++) { // ��k�β��� 
			if(i == 0) { // ��0�죬���տ�ʼ������ 
				dp[0][k][0] = 0; // �����У�����Ϊ0 
				dp[0][k][1] = -a[0]; // ���У�����Ϊ�� 
				continue;
			}
			// ��i�죬�����У�ǰ1�첻���У������޲�����ǰ1����У��������� 
			dp[i][k][0] = MAX(dp[i-1][k][0], dp[i-1][k][1] + a[i]);
			// ��i�죬���У�ǰ1����У������޲�����ǰ1�첻���У���������
			dp[i][k][1] = MAX(dp[i-1][k][1], dp[i-1][k-1][0] - a[i]);
		}
	}
	return dp[n-1][K-1][0]; // ���1�죬�����й�Ʊ 
}

int main()
{
	// int a[] = {3,3,5,0,0,3,1,4}; // 6
	// int a[] = {1,2,3,4,5}; // 4
	// int a[] = {7,6,4,3,1}; // 0
	int a[] = {2,1,4,5,2,9,7}; // 11
	int size = sizeof(a) / sizeof(a[0]);
	printf("%d\n", maxProfit(a, size));
	return 0;
}
