#include <bits/stdc++.h>
using namespace std;

vector<int> findRedundantConnection(vector<vector<int>>& es)
{
    int vn = es.size(); // 顶点数vexcount
    vector<int> uf(vn); // 并查集unoinfind
    vector<int> ans; // 结果answer

    for (int i = 0; i < vn; i++) {
        uf[i] = i;
    }
    for (int i = 0; i < es.size(); i++) {
        int s = es[i][0] - 1; // 起点start
        int t = es[i][1] - 1; // 终点terminal
        if (uf[s] == uf[t]) {
            ans.push_back(s + 1);
            ans.push_back(t + 1);
            return ans;
        } else { // 合并
            int p = uf[s]; // 暂存
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
