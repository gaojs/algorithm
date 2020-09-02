#include <bits/stdc++.h>
using namespace std;

// 并查集UnionFind
vector<int> uf;

void initUnionFind(int n)
{ // 每个人都是自己的师傅
    for (int i = 0; i < n; i++) {
        uf.push_back(i);
    }
}

int findMaster(int x)
{ // 查找它的师傅
    if (uf[x] == x) {
        return uf[x];
    } else { // 路径压缩
        uf[x] = findMaster(uf[x]);
        return uf[x];
    }
}

void merge(int i, int j)
{ // 合并两个帮派
    i = findMaster(i);
    j = findMaster(j);
    uf[i] = j;
}

int findCircleNum(vector<vector<int>>& M)
{
    int n = M.size();
    initUnionFind(n); //初始化
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (M[i][j]) {
                merge(i, j);
            }
        }
    }

    int cnt = 0;
    // 如果一个人的师傅是它自己，它就是帮主
    for (int i = 0; i < n; i++) {
        if (i == uf[i]) {
            cnt++;
        }
    }
    return cnt;
}

int numIslands(vector<vector<char>>& vt)
{
    int r = vt.size();
    if (r <= 0) {
        return 0;
    }
    int c = vt[0].size();
    initUnionFind(r * c);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (vt[i][j] != '1') {
                continue;
            }
            if (i > 0 && vt[i - 1][j] == '1') {
                merge(i * c + j, (i - 1) * c + j);
            }
            if (j > 0 && vt[i][j - 1] == '1') {
                merge(i * c + j, i * c + (j - 1));
            }
            if (i < r - 1 && vt[i + 1][j] == '1') {
                merge(i * c + j, (i + 1) * c + j);
            }
            if (j < c - 1 && vt[i][j + 1] == '1') {
                merge(i * c + j, i * c + (j + 1));
            }
        }
    }

    int cnt = 0;
    // 如果一个人的师傅是它自己，它就是帮主
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (vt[i][j] != '1') {
                continue;
            }
            int k = i * c + j;
            if (k == uf[k]) {
                cnt++;
            }
        }
    }
    return cnt;
}

int main()
{
    vector<vector<char>> vt =
    {
        {'1','0','1','1','1'},
        {'1','0','1','0','1'},
        {'1','1','1','0','1'},
    };

    cout << numIslands(vt);
    return 0;
}
