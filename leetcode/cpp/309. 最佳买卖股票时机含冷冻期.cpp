#include <securec.h>
#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& a)
{
    int n = a.size();
    if (n <= 0) {
        return 0;
    } else {
        int dp0 = 0, dp1 = -a[0];
        int dpre = 0; // dp[i-2][0]
        for (int i = 1; i < n; ++i) {
            int tmp = dp0;
            dp0 = max(dp0, dp1 + a[i]);
            dp1 = max(dp1, dpre - a[i]);
            dpre = tmp;
        }
        return max(dp0, dp1);
    }
}

int main()
{
    vector<int> a = { 1,2,3,0,2 };
    cout << maxProfit(a) << endl; //3
    return 0;
}

