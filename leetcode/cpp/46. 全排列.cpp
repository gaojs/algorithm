#include <securec.h>
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> permute(vector<int>& a)
{
    vector<vector<int>> vtt;
    int n = a.size(); // ���鳤��
    for (int i = 0; i < n; i++) {
        vector<int> h, t; //head,tail
        h.push_back(a[i]); //ͷ���
        t.assign(a.begin(), a.end());
        t.erase(t.begin() + i);
        if (t.size() == 0) {
            vtt.push_back(h);
        } else { // ѭ���ݹ�
            vector<vector<int>> tt;
            tt = permute(t); //�ݹ�
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