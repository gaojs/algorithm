#include <securec.h>
#include <bits/stdc++.h>
using namespace std;

int threeSumClosest(vector<int>& a, int t)
{
    sort(a.begin(), a.end()); //先排序，再查找
    int bestDiff = INT_MAX;
    int bestSum = INT_MIN;
    int n = a.size();
    for (int i = 0; i < n; i++) {
        int j = i + 1;
        int k = n - 1;
        while (j < k) { // i, j, k
            int sum = a[i] + a[j] + a[k];
            int diff = abs(sum - t);
            if (bestDiff > diff) {
                bestDiff = diff;
                bestSum = sum;
            }
            if (sum == t) {
                return t; // 最优解
            } else if (sum > t) {
                k--; // 收缩右边界
            } else {
                j++;
            }
        }
    }
    return bestSum;
}

int main()
{
    // vector<int> a = { -1,2,1,-4 };  // 2
    // cout << threeSumClosest(a, 1) << endl;
    vector<int> a = { 1, 1, -1, -1, 3 };
    cout << threeSumClosest(a, -1) << endl;
    return 0;
}
