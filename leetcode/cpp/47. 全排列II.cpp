#include <securec.h>
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> permute(vector<int>& a)
{ // ȫ���У�46�⣩
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

vector<vector<int>> permuteUnique(vector<int>& a)
{ // ȫ����II��47�⣩// ֻ��Ҫȥ��һ�¼���
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
