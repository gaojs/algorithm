#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// dp(i, j)表示戳破第i个气球和第j个气球之间的气球，能获得的最大数量。注意不包括第i个气球和第j个气球。
// 假设i，j之间最后一个被戳破的气球是k，则dp(i,j) = max(dp(i,k) + a[i] * a[k] * a[j] + dp(k,j)) i < k < j;
// a[i] * a[k] * a[j] 表示最后一次戳破时的获得的最大数量，开头和结尾添加两个无法戳破的虚拟气球。
// dp(i,k)是在戳破k之前，戳破i和k之间的气球获得收益；dp(k,j)是在戳破k之前，戳破k和j之间的气球获得收益；
int maxCoins(int*nums, int numsSize)
{
	if (nums == NULL || numsSize <= 0) {
		return 0;
	}
	int a[numsSize + 2];
	int n = sizeof(a) / sizeof(a[0]);
	a[0] = a[n-1] = 1; // 首位各加个1
	memcpy(&a[1], nums, sizeof(int)*numsSize);
	int dp[n][n]; // = {0}; // dp[i][j]是从i到j的最大值
	memset(dp, 0, sizeof(dp));

	for (int s = 2; s < n; s++) { // 步长
    	for(int i = 0; i < n - s; i++) { // 从前往后
    		int j = i + s; // 最右端；先计算短步长，更好理解
            for(int k = i + 1; k < j; k++) { // 方向任意
            	// 转化方程，因为dp[i][j]已经被初始化为0了
            	int t = dp[i][k] + dp[k][j] + a[i] * a[k] * a[j];
				if (dp[i][j] < t) { // 找最大的
					dp[i][j] = t;
				}
            }
        }
    }
    return dp[0][n-1];
}

int main()
{
	// int a[] = {3,1,5,8}; // 167
	int a[] = {9,76,64,21,97,60}; // 1086136
	int n = sizeof(a)/sizeof(a[0]);
	printf("%d", maxCoins(a, n));
	return 0;
}

