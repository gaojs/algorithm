#include <securec.h>
#include <bits/stdc++.h>
using namespace std;

int maxProfit(int K, vector<int>& a)
{
    int n = a.size();
    if (n <= 0) {
        return 0;
    } else if (n < K) {
        int dp0 = 0, dp1 = -a[0];
        for (int i = 1; i < n; ++i) {
            int tmp = dp0;
            dp0 = max(dp0, dp1 + a[i]);
            dp1 = max(dp1, dp0 - a[i]);
        }
        return max(dp0, dp1);
    } else {
        // dp[n][k][f]Ϊ��n���k�ι������������  
        vector<vector<int>> dp(K + 1, vector<int>(2, 0));
        for (int k = 0; k <= K; k++) { // ��ʼֵ
            // dp[0][k][0] = 0; // 0������
            dp[k][1] = -a[0]; // 1����
        }
        for (int i = 1; i < n; i++) { // ����
            for (int k = 1; k <= K; k++) { // ���״���
                // ���첻���У����첻�����ҽ���û����������������ҽ���������
                dp[k][0] = max(dp[k][0], dp[k][1] + a[i]);
                // ������У���������ҽ���û�����������첻�����ҽ���������
                dp[k][1] = max(dp[k][1], dp[k - 1][0] - a[i]);
            }
        }
        return dp[K][0];
    }
}

int main()
{
    vector<int> a = { 2,4,1 };
    cout << maxProfit(2, a) << endl; //2
    vector<int> a2 = { 3,2,6,5,0,3 };
    cout << maxProfit(2, a2) << endl; //7
    vector<int> a3 = { 3,3,5,0,0,3,1,4 };
    cout << maxProfit(2, a3) << endl; //6
    return 0;
}

