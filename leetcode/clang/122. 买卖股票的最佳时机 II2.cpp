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
	// ��0�죬���տ�ʼ������ 
	int dp0 = 0; // �����У�����Ϊ0 
	int dp1 = 0 - a[0]; // ���У�����Ϊ�� 
	int d0_pre = 0; // �����еĸ�ǰ1�� 
	for(int i = 1; i < n; i++) { // ��i��
        int d0 = dp0, d1 = dp1;
		// ��i�죬�����У�ǰ1�첻���У������޲�����ǰ1����У��������� 
		dp0 = MAX(d0, d1 + a[i]);
		// ��i�죬���У�ǰ1����У������޲�����ǰ1�첻���У���������
		dp1 = MAX(d1, d0_pre - a[i]);
		d0_pre = d0; 
	}
	return dp0; // ���1�죬�����й�Ʊ 
}

int main()
{
	int a[] = {1,2,3,0,2}; // 3
	int size = sizeof(a) / sizeof(a[0]);
	printf("%d\n", maxProfit(a, size));
	return 0;
}
