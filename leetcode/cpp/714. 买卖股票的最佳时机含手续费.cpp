#include <securec.h>
#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& a, int fee)
{
    int n = a.size();
    if (n <= 0) {
        return 0;
    } else {
        int dp0 = 0, dp1 = -a[0] - fee;
        for (int i = 0; i < n; i++) {
            int tmp = dp0;
            dp0 = max(dp0, dp1 + a[i]);
            dp1 = max(dp1, tmp - a[i] - fee);
        }
        return dp0;
    }
}

int main()
{
    vector<int> a = { 1, 3, 2, 8, 4, 9 };
    cout << maxProfit(a, 2) << endl; //8
    vector<int> a2 = { 1,3,7,5,10,3 };
    cout << maxProfit(a2, 3) << endl; //6
    return 0;
}

