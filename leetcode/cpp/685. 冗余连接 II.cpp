#include <securec.h>
#include <bits/stdc++.h>
using namespace std;

vector<int> findRedundantDirectedConnection(vector<vector<int>>& es)
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
    vector<vector<int>> es = { {1,2},{1,3 },{2,3} };
    vector<int> res = findRedundantDirectedConnection(es);
    for (int e : res) {
        cout << e << " ";
    }
    vector<vector<int>> es2 = { {1,2},{2,3 },{3,4},{4,1},{1,5} };
    vector<int> res2 = findRedundantDirectedConnection(es2);
    for (int e : res2) {
        cout << e << " ";
    }
    return 0;
}

