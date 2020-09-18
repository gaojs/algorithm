#include <securec.h>
#include <bits/stdc++.h>
using namespace std;

set<vector<int>> permute(vector<int>& a)
{ // 全排列（46题）
    set<vector<int>> st;
    int n = a.size(); // 数组长度
    for (int i = 0; i < n; i++) {
        if (i > 0 && a[i] == a[i - 1]) {
            continue; // 剪枝
        }
        vector<int> h, t; //head,tail
        h.push_back(a[i]); //头结点
        t.assign(a.begin(), a.end());
        t.erase(t.begin() + i);
        if (t.size() == 0) {
            st.insert(h);
        } else { // 循环递归
            set<vector<int>> stt;
            stt = permute(t); //递归
            for (vector<int> e : stt) {
                vector<int> ht(h);
                ht.insert(ht.end(), e.begin(), e.end());
                st.insert(ht);
            }
        }
    }
    return st;
}

vector<vector<int>> permuteUnique(vector<int>& a)
{ // 全排列II（47题）// 只需要去重一下即可
    sort(a.begin(), a.end()); // 排序
    set<vector<int>> st = permute(a);
    vector<vector<int>> vtt(st.begin(), st.end());
    return vtt;
}

int main()
{
    // vector < int> a = { 1, 2, 1 };
    vector < int> a = { 1, 1, 0, 0, 1, -1, -1, 1 };
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
