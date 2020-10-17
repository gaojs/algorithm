#include <securec.h>
#include <bits/stdc++.h>
using namespace std;

bool ok(vector<int> &s, int n, int i)
{
    if (i >= n) {
        return false;
    }
    for (int k = 0; k < i; k++) {
        if (s[k] == s[i]) { 
            return false; // 同列
        } 
        if (abs(i - k) == abs(s[i] - s[k])) {
            return false; // 同斜
        } 
    }
    return true;
}

void dfs(vector<vector<int>>&a, vector<int> &s, int n, int i)
{
    if (i == n) {
        a.push_back(s);
    } else if (i < n) {
        for (int k = 0; k < n; k++) {
            s[i] = k; // 尝试
            if (ok(s, n, i)) { 
                dfs(a, s, n, i + 1);
            }
        }
        // s[i] = -1; // 回退
    }
}

vector<vector<string>> solveNQueens(int n)
{
    vector<vector<int>> as;
    vector<int> s(n, -1);
    dfs(as, s, n, 0); // 递归
    vector<vector<string>> ans;
    for (vector<int> s : as) {
        vector<string> an;
        for (int e : s) {
            string a(n, '.');
            a[e] = 'Q';
            an.push_back(a);
        }
        ans.push_back(an);
    }
    return ans;
}

int main()
{
    vector<vector<string>> vvs = solveNQueens(4);
    for (vector<string> vs : vvs) {
        cout << "[" << endl;
        for (string s : vs) {
            cout << s << endl;
        }
        cout << "]," << endl;
    }
    return 0;
}