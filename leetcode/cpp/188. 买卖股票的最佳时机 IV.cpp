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
        // dp[n][k][f]为第n天第k次购买后的最大收益  
        vector<vector<int>> dp(K + 1, vector<int>(2, 0));
        for (int k = 0; k <= K; k++) { // 初始值
            // dp[0][k][0] = 0; // 0不持有
            dp[k][1] = -a[0]; // 1持有
        }
        for (int i = 1; i < n; i++) { // 天数
            for (int k = 1; k <= K; k++) { // 交易次数
                // 今天不持有，昨天不持有且今天没操作，或昨天持有且今天卖出了
                dp[k][0] = max(dp[k][0], dp[k][1] + a[i]);
                // 今天持有，昨天持有且今天没操作，或昨天不持有且今天买入了
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

