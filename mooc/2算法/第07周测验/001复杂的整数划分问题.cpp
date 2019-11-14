#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

#define MAXN 50
#define MAXM
#define INF 0x3f3f3f3f
typedef long long int LL;

int N,K;
LL dp[MAXN+10][MAXN+10];

void work1() { //选K个
	memset(dp,0,sizeof(dp));
	for(int i=1; i<=N; ++i) //将i分成1个数只有一种方案
		dp[i][1]=1;

	for(int i=1; i<=N; ++i)
		for(int j=2; j<=i; ++j) //将每个数统一减1，或去掉当前数中的1
			dp[i][j]=dp[i-j][j]+dp[i-1][j-1];

	printf("%d\n",dp[N][K]);//把N分成K个数
}

void work2() { //任意不同
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;

	for(int i=0; i<=N; i++) {
		for(int j=1; j<=N; j++) {
			//当前有数是j和降低上限
			if(j<=i)dp[i][j]=dp[i-j][j-1]+dp[i][j-1];
			else dp[i][j]=dp[i][i];//上限应为i
		}
	}

	printf("%lld\n",dp[N][N]);//划分N，上限为N
}

void work3() { //任意奇数（基本同work1）
	memset(dp,0,sizeof(dp));
	for(int i=0; i<=N; ++i) {
		dp[i][1]=1;
		if(i&1)dp[0][i]=1;//预处理第0层
	}

	for(int i=1; i<=N; i++) {
		for(int j=1; j<=N; j++) {
			if(j&1) { //同work1
				if(j<=i)dp[i][j]=dp[i-j][j]+dp[i][j-1];
				else dp[i][j]=dp[i][i];
			} else dp[i][j]=dp[i][j-1]; //当前非奇数
		}
	}

	printf("%lld\n",dp[N][N]);
}

int main() {
	while(~scanf("%d%d",&N,&K)) {
		work1();
		work2();
		work3();
	}
}
