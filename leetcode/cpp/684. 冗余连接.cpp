#include <bits/stdc++.h>
using namespace std;

vector<int> findRedundantConnection(vector<vector<int>>& es)
{
    int vn = es.size(); // ������vexcount
    vector<int> uf(vn); // ���鼯unoinfind
    vector<int> ans; // ���answer

    for (int i = 0; i < vn; i++) {
        uf[i] = i;
    }
    for (int i = 0; i < es.size(); i++) {
        int s = es[i][0] - 1; // ���start
        int t = es[i][1] - 1; // �յ�terminal
        if (uf[s] == uf[t]) {
            ans.push_back(s + 1);
            ans.push_back(t + 1);
            return ans;
        } else { // �ϲ�
            int p = uf[s]; // �ݴ�
            for (int j = 0; j < vn; j++) {
                if (uf[j] == p) {
                    uf[j] = uf[t];
                }
            }
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> vt = { {1,2},{2,3},{3,4},{1,4} ,{1,5} };
    vector<int> e = findRedundantConnection(vt);
    for (int i : e) {
        cout << i << " ";
    }
    return 0;
}
