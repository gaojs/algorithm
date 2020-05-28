#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>

#define MAX_COUNT 100000
bool visited[MAX_COUNT] = { 0 };

int gd(int k, int w, int*p, int pn, int*c, int cn)
{
    if (k == 0 || w < 0 || p == NULL || pn <= 0 || c == NULL || cn <= 0) {
        return 0;
    }
    memset(visited, 0, sizeof(visited));
    for (; k > 0; k--) {
        int m = -1; // 找最优
        for (int i = 0; i < cn; i++) {
            if (!visited[i] && w >= c[i]) { // 可投资
                if (m == -1) {
                    m = i;
                } else if (p[m] < p[i]) {
                    m = i;
                }
            }
        }
        if (m != -1) { // 找到
            w += p[m]; // 收益增加
            visited[m] = true;
        }
    }
    return w;
}

int findMaximizedCapital(int k, int w, int*p, int pn, int*c, int cn)
{
    if (k == 0 || w < 0 || p == NULL || pn <= 0 || c == NULL || cn <= 0) {
        return 0;
    }
    return gd(k, w, p, pn, c, cn);
}

int main()
{
    int k = 2, w = 0, p[] = { 1,2,3 }, c[] = { 0,1,1 };
    int pn = sizeof(p) / sizeof(p[0]);
    int cn = sizeof(p) / sizeof(p[0]);
    printf("%d", findMaximizedCapital(k, w, p, pn, c, cn));
    return 0;
}


