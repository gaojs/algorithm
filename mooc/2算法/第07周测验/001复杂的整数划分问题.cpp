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

void work1() { //ѡK��
	memset(dp,0,sizeof(dp));
	for(int i=1; i<=N; ++i) //��i�ֳ�1����ֻ��һ�ַ���
		dp[i][1]=1;

	for(int i=1; i<=N; ++i)
		for(int j=2; j<=i; ++j) //��ÿ����ͳһ��1����ȥ����ǰ���е�1
			dp[i][j]=dp[i-j][j]+dp[i-1][j-1];

	printf("%d\n",dp[N][K]);//��N�ֳ�K����
}

void work2() { //���ⲻͬ
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;

	for(int i=0; i<=N; i++) {
		for(int j=1; j<=N; j++) {
			//��ǰ������j�ͽ�������
			if(j<=i)dp[i][j]=dp[i-j][j-1]+dp[i][j-1];
			else dp[i][j]=dp[i][i];//����ӦΪi
		}
	}

	printf("%lld\n",dp[N][N]);//����N������ΪN
}

void work3() { //��������������ͬwork1��
	memset(dp,0,sizeof(dp));
	for(int i=0; i<=N; ++i) {
		dp[i][1]=1;
		if(i&1)dp[0][i]=1;//Ԥ�����0��
	}

	for(int i=1; i<=N; i++) {
		for(int j=1; j<=N; j++) {
			if(j&1) { //ͬwork1
				if(j<=i)dp[i][j]=dp[i-j][j]+dp[i][j-1];
				else dp[i][j]=dp[i][i];
			} else dp[i][j]=dp[i][j-1]; //��ǰ������
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
