#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &vt, vector<int>&visited, int i, int &color)
{
    for (int j = 0; j < vt.size(); j++) {
        if (vt[i][j] && !visited[j]) {
            visited[j] = color;
            dfs(vt, visited, j, color);
        }
    }
}

int findCircleNum(vector<vector<int>>& vt)
{
    vector<int> visited(vt.size(), 0);
    int color = 0;

    for (int i = 0; i < vt.size(); i++) {
        if (!visited[i]) {
            color++; // ÑÕÉ«Ôö¼Ó
            dfs(vt, visited, i, color);
        }
    }
    return color;
}

int main()
{
    vector<vector<int>> vt =
    {
        {1,0,0,1},
        {0,1,1,0},
        {0,1,1,1},
        {1,0,1,1},
    };

    cout << findCircleNum(vt);
    return 0;
}
