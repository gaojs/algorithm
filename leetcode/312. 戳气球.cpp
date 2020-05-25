#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// dp(i, j)��ʾ���Ƶ�i������͵�j������֮��������ܻ�õ����������ע�ⲻ������i������͵�j������
// ����i��j֮�����һ�������Ƶ�������k����dp(i,j) = max(dp(i,k) + a[i] * a[k] * a[j] + dp(k,j)) i < k < j;
// a[i] * a[k] * a[j] ��ʾ���һ�δ���ʱ�Ļ�õ������������ͷ�ͽ�β��������޷����Ƶ���������
// dp(i,k)���ڴ���k֮ǰ������i��k֮������������棻dp(k,j)���ڴ���k֮ǰ������k��j֮������������棻
int maxCoins(int*nums, int numsSize)
{
	if (nums == NULL || numsSize <= 0) {
		return 0;
	}
	int a[numsSize + 2];
	int n = sizeof(a) / sizeof(a[0]);
	a[0] = a[n-1] = 1; // ��λ���Ӹ�1
	memcpy(&a[1], nums, sizeof(int)*numsSize);
	int dp[n][n]; // = {0}; // dp[i][j]�Ǵ�i��j�����ֵ
	memset(dp, 0, sizeof(dp));

	for (int s = 2; s < n; s++) { // ����
    	for(int i = 0; i < n - s; i++) { // ��ǰ����
    		int j = i + s; // ���Ҷˣ��ȼ���̲������������
            for(int k = i + 1; k < j; k++) { // ��������
            	// ת�����̣���Ϊdp[i][j]�Ѿ�����ʼ��Ϊ0��
            	int t = dp[i][k] + dp[k][j] + a[i] * a[k] * a[j];
				if (dp[i][j] < t) { // ������
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

