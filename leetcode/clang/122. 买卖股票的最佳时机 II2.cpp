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
	// 第0天，即刚开始的那天 
	int dp0 = 0; // 不持有，收益为0 
	int dp1 = 0 - a[0]; // 持有，收益为负 
	int d0_pre = 0; // 不持有的更前1天 
	for(int i = 1; i < n; i++) { // 第i天
        int d0 = dp0, d1 = dp1;
		// 第i天，不持有：前1天不持有，当天无操作；前1天持有，当天卖出 
		dp0 = MAX(d0, d1 + a[i]);
		// 第i天，持有：前1天持有，当天无操作；前1天不持有，当天买入
		dp1 = MAX(d1, d0_pre - a[i]);
		d0_pre = d0; 
	}
	return dp0; // 最后1天，不持有股票 
}

int main()
{
	int a[] = {1,2,3,0,2}; // 3
	int size = sizeof(a) / sizeof(a[0]);
	printf("%d\n", maxProfit(a, size));
	return 0;
}
