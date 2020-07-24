// 树形网络
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

void dfs(const vector< vector<int> > &nt, const vector<int> &ws,
    vector< vector<int> >&result, vector<int> &road, int s)
{
    int top = road.back();
    if (nt[top].size() == 0) { // 叶子节点了
        int w = 0;
        for (int i = 0; i < road.size(); i++) {
            w += ws[road[i]];
        }
        if (w == s) { // 是一个解
            vector<int> ok;
            for (int e : road) {
                ok.push_back(e);
            }
            result.push_back(ok);
        }
    } else {
        for (int i = 0; i < nt[top].size(); i++) {
            road.push_back(nt[top][i]);
            dfs(nt, ws, result, road, s);
            road.pop_back();
        }
    }
}

vector<int> *g_ws = NULL;
bool cmp(const vector<int> &a, const vector<int> &b)
{
    if (a.size() == 0) {
        return false;
    } else if (b.size() == 0) {
        return true;
    } else {
        vector<int> &ws = (*g_ws);
        for (int i = 0; i < a.size() && i < b.size(); i++) {
            if (a[i] == b[i] || ws[a[i]] == ws[b[i]]) {
                continue;
            } else if (ws[a[i]] > ws[b[i]]) {
                return true;
            } else {
                return false;
            }
        }
        if (a.size() <= b.size()) {
            return false;
        } else {
            return true;
        }
    }
}

int main(void)
{
    int n, m, s;

    cin >> n >> m >> s; //n节点数，m非叶子节点数，s总权重
    // cout << "n=" << n << ", m=" << m << ", s= " << s << endl;

    vector<int> ws(n);
    for (int i = 0; i < n; i++) {
        int w;
        cin >> w;
        ws[i] = w;
    }
    /************************************
    cout << "ws.size=" << ws.size() << endl;
    for (int i = 0; i < ws.size(); i++) {
        cout << ws[i] << " ";
    }
    cout << endl;
    ************************************/

    vector< vector<int> > nt(n);
    for (int i = 0; i < m; i++) {
        int parent; // 父节点编号
        int childCnt; // 子节点个数
        cin >> parent >> childCnt;
        nt[parent] = vector<int>(childCnt);
        for (int j = 0; j < childCnt; j++) {
            int child;
            cin >> child;
            nt[parent][j] = child;
        }
    }
    /************************************
    cout << "nt.size=" << nt.size() << endl;
    for (int i = 0; i < nt.size(); i++) {
        cout << "nt[" << i << "].size=" << nt[i].size() << endl;
        for (int j = 0; j < nt[i].size(); j++) {
            cout << nt[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    ************************************/

    vector< vector<int> > result;
    vector<int> road;
    road.push_back(0);
    dfs(nt, ws, result, road, s);

    g_ws = &ws;
    sort(result.begin(), result.end(), cmp);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            if (j != 0) { //行尾不得有多余的空格
                cout << " ";
            }
            cout << ws[result[i][j]];
        }
        cout << endl;
    }
    return 0;
}