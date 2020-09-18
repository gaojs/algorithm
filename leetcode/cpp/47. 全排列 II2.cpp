#include <securec.h>
#include <bits/stdc++.h>
using namespace std;

set<vector<int>> permute(vector<int>& a)
{ // ȫ���У�46�⣩
    set<vector<int>> st;
    int n = a.size(); // ���鳤��
    for (int i = 0; i < n; i++) {
        if (i > 0 && a[i] == a[i - 1]) {
            continue; // ��֦
        }
        vector<int> h, t; //head,tail
        h.push_back(a[i]); //ͷ���
        t.assign(a.begin(), a.end());
        t.erase(t.begin() + i);
        if (t.size() == 0) {
            st.insert(h);
        } else { // ѭ���ݹ�
            set<vector<int>> stt;
            stt = permute(t); //�ݹ�
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
{ // ȫ����II��47�⣩// ֻ��Ҫȥ��һ�¼���
    sort(a.begin(), a.end()); // ����
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
