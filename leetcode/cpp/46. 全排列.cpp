#include <securec.h>
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> permute(vector<int>& a)
{
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

int main()
{
    vector < int> a = { 1, 2, 3 };
    vector<vector<int>> res = permute(a);
    for (vector<int> r : res) {
        cout << "[";
        for (int e : r) {
            cout << e << ",";
        }
        cout << "]," << endl;
    }
    return 0;
}