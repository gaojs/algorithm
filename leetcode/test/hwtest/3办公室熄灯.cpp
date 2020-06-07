#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

// 小明关灯，0空位，1桌子，2灯，3小明，4门口
// 小明要在有限时间内，走出门，并关最多的灯
#define EMPTY 0 // 0空位
#define DESK 1 // 1桌子
#define LAMP 2 // 2灯
#define ORIG 3 // 3小明
#define DEST 4 // 4门口
#define MAX(a, b) ((a) > (b) ? (a) : (b))

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
    // printf("[%d][%d]=(v=%d, a=%d), limit=%d, count=%d\n", r, c, v[r][c], a[r][c], limit, count);
    if (!v[r][c] && a[r][c] != DESK) { // 没访问过，并且可访问
        v[r][c] = 1; // 标记访问过
        switch (a[r][c]) {
        case ORIG: // 从终点到起点了
            result = MAX(result, count);
            // printf("[%d][%d]=(v=%d) result=%d\n", r, c, v[r][c], result);
            break;
        case LAMP: // 2灯
            count++;
            // printf("[%d][%d]=(v=%d) count=%d\n", r, c, v[r][c], count);
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
    int n;
    if (scanf_s("%d", &n) != 1) {
        return -1;
    }
    int timeLimit;
    if (scanf_s("%d", &timeLimit) != 1) {
        return -1;
    }

    dr = dc = 0;
    memset(a, 0, sizeof(a));
    int r, c, v;
    for (r = 0; r < n; r++) {
        for (c = 0; c < n; c++) {
            if (scanf_s("%d", &v) != 1) {
                return -1;
            }
            a[r][c] = v;
            if (v == DEST) { // 终点
                a[r][c] = 0;
                dr = r;
                dc = c;
            }
        }
    }
    /*********************************
    printf("n=%d\n", n);
    printf("timeLimit=%d\n", timeLimit);
    printf("dest=(%d,%d)\n", dr, dc);
    for (r = 0; r < n; r++) {
        for (c = 0; c < n; c++) {
            printf("%d ", a[r][c]);
        }
        printf("\n");
    } */
    printf("%d", search(n, timeLimit));
    return 0;
}