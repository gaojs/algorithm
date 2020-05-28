#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>

#define MAX_COUNT 100000
bool visited[MAX_COUNT] = { 0 };
int max = 0; // 最大收益

void dfs(int k, int w, int*p, int pn, int*c, int cn)
{
    if (k == 0 || w < 0 || p == NULL || pn <= 0 || c == NULL || cn <= 0) {
        return;
    }
    for (int i = 0; i < cn; i++) {
        if (!visited[i] && w >= c[i]) { // 可投资
            int w2 = w + p[i]; // 收益增加
            if (max < w2) {
                max = w2;
            }
            visited[i] = true;
            dfs(k - 1, w2, p, pn, c, cn);
            visited[i] = false;
        }
    }
}

int findMaximizedCapital(int k, int w, int*p, int pn, int*c, int cn)
{
    if (k == 0 || w < 0 || p == NULL || pn <= 0 || c == NULL || cn <= 0) {
        return 0;
    }
    max = 0;
    memset(visited, 0, sizeof(visited));
    dfs(k, w, p, pn, c, cn);
    return max;
}

int main()
{
    int k = 2, w = 0, p[] = { 1,2,3 }, c[] = { 0,1,1 };
    int pn = sizeof(p) / sizeof(p[0]);
    int cn = sizeof(p) / sizeof(p[0]);
    printf("%d", findMaximizedCapital(k, w, p, pn, c, cn));
    return 0;
}


