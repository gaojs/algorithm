#include <bits/stdc++.h>
using namespace std;

bool ok(const vector<vector<int>>& a, int d, int n)
{
    int c = 0;
    int s = 0;
    int r = a.size();
    for (int i = 0; i < r; i++) {
        s = max(s, a[i][0]);
        for (; s <= a[i][1]; s += d) {
            c += 1;
        }
    }
    return (c >= n);
}

int DistanceBetweenTree(int n, const vector<vector<int>>& a)
{
    int r = a.size();
    if (r == 0) {
        return -1;
    }
    int best = -1;
    int mn = 1;
    int mx = a[r - 1][1];
    while (mn <= mx) {
        int md = mn + (mx - mn) / 2;
        if (ok(a, md, n)) {
            if (best < md) {
                best = md;
            }
            mn = md + 1;
        } else {
            mx = md - 1;
        }
    }
    return best;
}

int main()
{
    vector<vector<int>> a1 = { {1, 3},{5, 6},{8, 9},{10, 11} };
    cout << DistanceBetweenTree(5, a1) << endl; // 2
    // vector<vector<int>> a2 = { {1,3},{5,5} };
    // cout << DistanceBetweenTree(5, a2) << endl; // -1
    return 0;
}
