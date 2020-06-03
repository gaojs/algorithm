#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>

// d[i] ������i��ʱ������<N�ĸ���
double new21Game(int N, int K, int W)
{
	double dp[K + W], s = 0;
	memset(dp, 0, sizeof(dp));
	for (int i = K; i < K + W; i++) {
		dp[i] = (i <= N) ? 1 : 0; 
		s += dp[i]; // <N�ĸ���
	}
	for (int i = K - 1; i >= 0; i--) {
		dp[i] = s / W; // <N�ĸ���
		s += dp[i] - dp[i+W];
	}
	return dp[0];
}

int main()
{
	// int N = 10, K = 1, W = 10; // 1.0
	// int N = 6, K = 1, W = 10; // 0.60000
	int N = 21, K = 17, W = 10; // 0.732778
	// int N = 5230, K = 5040, W = 1513; // ��ʱ
	printf("%lf", new21Game(N, K, W));
	return 0;
}


