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
	// dp[n][f]为第n天第k次购买后的最大收益 
	// f = 0, 为不持有股票， f = 1, 为持有股票 
	int dp[n][2]; // = {0}; 
	memset(dp, 0, sizeof(dp));	
	// 第0天，即刚开始的那天 
	dp[0][0] = 0; // 不持有，收益为0 
	dp[0][1] = 0 - a[0]; // 持有，收益为负 
	for(int i = 1; i < n; i++) { // 第i天 
		// 第i天，不持有：前1天不持有，当天无操作；前1天持有，当天卖出 
		dp[i][0] = MAX(dp[i-1][0], dp[i-1][1] + a[i]);
		// 第i天，持有：前1天持有，当天无操作；前1天不持有，当天买入
		dp[i][1] = MAX(dp[i-1][1], 0 - a[i]);
	}
	return dp[n-1][0]; // 最后1天，不持有股票 
}

int main()
{
	int a[] = {7,6,4,3,1}; // 0
	// int a[] = {7,1,5,3,6,4}; // 5
	int size = sizeof(a) / sizeof(a[0]);
	printf("%d\n", maxProfit(a, size));
	return 0;
}
