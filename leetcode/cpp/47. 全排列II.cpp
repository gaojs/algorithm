#include <securec.h>
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> permute(vector<int>& a)
{ // 全排列（46题）
    vector<vector<int>> vtt;
    int n = a.size(); // 数组长度
    for (int i = 0; i < n; i++) {
        vector<int> h, t; //head,tail
        h.push_back(a[i]); //头结点
        t.assign(a.begin(), a.end());
        t.erase(t.begin() + i);
        if (t.size() == 0) {
            vtt.push_back(h);
        } else { // 循环递归
            vector<vector<int>> tt;
            tt = permute(t); //递归
            for (vector<int> e : tt) {
                vector<int> ht(h);
                ht.insert(ht.end(), e.begin(), e.end());
                vtt.push_back(ht);
            }
        }
    }
    return vtt;
}

vector<vector<int>> permuteUnique(vector<int>& a)
{ // 全排列II（47题）// 只需要去重一下即可
    vector<vector<int>> vt = permute(a);
    set<vector<int>> st(vt.begin(), vt.end());
    vector<vector<int>> vtt(st.begin(), st.end());
    return vtt;
}

int main()
{
    vector < int> a = { 1, 2, 1 };
    // vector < int> a = { 1, 1, 0, 0, 1, -1, -1, 1 };
    vector<vector<int>> res = permuteUnique(a);
    for (vector<int> r : res) {
        cout << "[";
        for (int e : r) {
            cout << e << ",";
        }
        cout << "]," << endl;
    }
    return 0;
}
