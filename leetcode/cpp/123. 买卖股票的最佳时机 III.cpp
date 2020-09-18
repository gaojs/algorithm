#include <securec.h>
#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& a)
{
    int n = a.size();
    if (n <= 0) {
        return 0;
    } else {
        const int K = 2; // 最多交易次数 
        // dp[n][k][f]为第n天第k次购买后的最大收益  // int[n][k + 1][2]
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(K + 1, vector<int>(2, 0)));
        for (int k = 0; k <= K; k++) { // 初始值
            // dp[0][k][0] = 0; // 0不持有
            dp[0][k][1] = -a[0]; // 1持有
        }
        for (int i = 1; i < n; i++) { // 天数
            for (int k = 1; k <= K; k++) { // 交易次数
                // 今天不持有，昨天不持有且今天没操作，或昨天持有且今天卖出了
                dp[i][k][0] = max(dp[i - 1][k][0], dp[i - 1][k][1] + a[i]);
                // 今天持有，昨天持有且今天没操作，或昨天不持有且今天买入了
                dp[i][k][1] = max(dp[i - 1][k][1], dp[i - 1][k - 1][0] - a[i]);
            }
        }
        return dp[n - 1][K][0];
    }
}

int main()
{
    /* vector<int> a = { 3,3,5,0,0,3,1,4 };
    cout << maxProfit(a) << endl;
    vector<int> a2 = { 1,2,3,4,5 };
    cout << maxProfit(a2) << endl;
    vector<int> a3 = { 7,6,4,3,1 };
    cout << maxProfit(a3) << endl; */
    vector<int> a4 = { 1,2,4,2,5,7,2,4,9,0 };
    cout << maxProfit(a4) << endl; // 13
    return 0;
}
