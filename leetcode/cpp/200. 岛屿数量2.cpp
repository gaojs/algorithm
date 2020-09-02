#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<char>> &vt, vector<vector<char>>&vi,
    int r, int c, int &color)
{
    if (r < 0 || r >= vt.size() || c < 0 || c >= vt[0].size()) {
        return; // 越界了
    }
    if (!vi[r][c] && vt[r][c] == '1') {
        vi[r][c] = color;
        dfs(vt, vi, r - 1, c, color);
        dfs(vt, vi, r + 1, c, color);
        dfs(vt, vi, r, c - 1, color);
        dfs(vt, vi, r, c + 1, color);
    }
}

int numIslands(vector<vector<char>>& vt)
{
    vector<vector<char>> vi(vt);

    for (int r = 0; r < vi.size(); r++) {
        for (int c = 0; c < vi[r].size(); c++) {
            vi[r][c] = 0; // 清零
        }
    }
    int color = 0;
    for (int r = 0; r < vt.size(); r++) {
        for (int c = 0; c < vt[r].size(); c++) {
            if (!vi[r][c] && vt[r][c] == '1') {
                color++;
                dfs(vt, vi, r, c, color);
            }
        }
    }
    return color;
}

int main()
{
    vector<vector<char>> vt =
    {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'},
    };

    cout << numIslands(vt);
    return 0;
}
