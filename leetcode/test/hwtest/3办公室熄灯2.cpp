// 办公室熄灯
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

// 小明关灯，0空位，1桌子，2灯，3小明，4门口
// 小明要在有限时间内，走出门，并关最多的灯
enum {
    EMPTY, // 0空位
    DESK, // 1桌子
    LAMP, // 2灯
    ORIG, // 3小明
    DEST, // 4门口
};

#define N 53 // 矩阵大小
int a[N][N] = { 0 };
int v[N][N] = { 0 };
int dr, dc; // 终点
int result = -1;

void dfs(int n, int limit, int r, int c, int count)
{
    if (n <= 0 || limit < 0 || r < 0 || r >= n || c < 0 || c >= n) {
        return;
    }
    if (!v[r][c] && a[r][c] != DESK) { // 没访问过，并且可访问
        v[r][c] = 1; // 标记访问过
        switch (a[r][c]) {
            case ORIG: // 从终点到起点了
                result = max(result, count);
                break;
            case LAMP: // 2灯
                count++;
                break;
        }
        // 去访问它的上下左右
        dfs(n, limit - 1, r - 1, c, count);
        dfs(n, limit - 1, r + 1, c, count);
        dfs(n, limit - 1, r, c - 1, count);
        dfs(n, limit - 1, r, c + 1, count);
        v[r][c] = 0; // 回溯
    }
}

int search(int n, int limit)
{
    result = -1;
    memset(v, 0, sizeof(v));
    dfs(n, limit, dr, dc, 0);
    return result;
}

int main(void)
{
    int num;
    int timeLimit;
    cin >> num >> timeLimit;

    dr = dc = 0;
    memset(a, 0, sizeof(a));
    for (int r = 0; r < num; r++) {
        for (int c = 0; c < num; c++) {
            cin >> a[r][c];
            if (a[r][c] == DEST) { // 终点
                a[r][c] = 0;
                dr = r;
                dc = c;
            }
        }
    }
    cout << search(num, timeLimit);
    return 0;
}
