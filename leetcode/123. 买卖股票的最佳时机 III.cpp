#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX(x, y) (x) > (y) ? (x) : (y)
int maxProfit(int* a, int n)
{
	if (a == NULL || n ==0) {
		return 0; // 参数有误 
	}
	// dp[n][k][f]为第n天第k次购买后的最大收益 
	// f = 0, 为不持有股票， f = 1, 为持有股票 
	int K = 3; // k = 2 可以买2次 
	int dp[n][K][2]; // = {0}; 
	memset(dp, 0, sizeof(dp));	
	for(int i = 0; i < n; i++) { // 第i天 
		for(int k = 1; k < K; k++) { // 第k次操作 
			if(i == 0) { // 第0天，即刚开始的那天 
				dp[0][k][0] = 0; // 不持有，收益为0 
				dp[0][k][1] = -a[0]; // 持有，收益为负 
				continue;
			}
			// 第i天，不持有：前1天不持有，当天无操作；前1天持有，当天卖出 
			dp[i][k][0] = MAX(dp[i-1][k][0], dp[i-1][k][1] + a[i]);
			// 第i天，持有：前1天持有，当天无操作；前1天不持有，当天买入
			dp[i][k][1] = MAX(dp[i-1][k][1], dp[i-1][k-1][0] - a[i]);
		}
	}
	return dp[n-1][K-1][0]; // 最后1天，不持有股票 
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
