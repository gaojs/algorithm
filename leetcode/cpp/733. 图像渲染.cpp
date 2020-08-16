#include <bits/stdc++.h>
using namespace std;

vector <vector<int>> visit;

void dfs(vector<vector<int>>& vt, int sr, int sc, int oc, int nc)
{
    if (sr < 0 || sr >= vt.size() ||
        sc < 0 || sc >= vt[0].size()) {
        return;
    }
    if (visit[sr][sc] == 0) {
        visit[sr][sc] = 1;
        if (vt[sr][sc] == oc) {
            vt[sr][sc] = nc;
            dfs(vt, sr - 1, sc, oc, nc);
            dfs(vt, sr + 1, sc, oc, nc);
            dfs(vt, sr, sc - 1, oc, nc);
            dfs(vt, sr, sc + 1, oc, nc);
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor)
{
    vector <vector<int>> result;
    result = image;
    visit.clear();
    visit = image;
    for (int r = 0; r < visit.size(); r++) {
        for (int c = 0; c < visit[r].size(); c++) {
            visit[r][c] = 0; // Çå¿ÕÊý×é
        }
    }
    dfs(result, sr, sc, image[sr][sc], newColor);
    return result;
}

int main()
{
    vector <vector<int>> image = { {1, 1, 1}, {1, 1, 0}, {1, 0, 1} };
    vector <vector<int>> result;
    int sr = 1, sc = 1, nc = 2;

    result = floodFill(image, sr, sc, nc);
    for (int r = 0; r < result.size(); r++) {
        for (int c = 0; c < result[r].size(); c++) {
            cout << "(" << r << "," << c << ")=" << result[r][c] << " ";
        }
        cout << endl;
    }
    return 0;
}
