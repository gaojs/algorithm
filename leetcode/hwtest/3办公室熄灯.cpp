#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

// С���صƣ�0��λ��1���ӣ�2�ƣ�3С����4�ſ�
// С��Ҫ������ʱ���ڣ��߳��ţ��������ĵ�
#define EMPTY 0 // 0��λ
#define DESK 1 // 1����
#define LAMP 2 // 2��
#define ORIG 3 // 3С��
#define DEST 4 // 4�ſ�
#define MAX(a, b) ((a) > (b) ? (a) : (b))

#define N 53 // �����С
int a[N][N] = { 0 };
int v[N][N] = { 0 };
int dr, dc; // �յ�
int result = -1;

void dfs(int n, int limit, int r, int c, int count)
{
    if (n <= 0 || limit < 0 || r < 0 || r >= n || c < 0 || c >= n) {
        return;
    }
    // printf("[%d][%d]=(v=%d, a=%d), limit=%d, count=%d\n", r, c, v[r][c], a[r][c], limit, count);
    if (!v[r][c] && a[r][c] != DESK) { // û���ʹ������ҿɷ���
        v[r][c] = 1; // ��Ƿ��ʹ�
        switch (a[r][c]) {
        case ORIG: // ���յ㵽�����
            result = MAX(result, count);
            // printf("[%d][%d]=(v=%d) result=%d\n", r, c, v[r][c], result);
            break;
        case LAMP: // 2��
            count++;
            // printf("[%d][%d]=(v=%d) count=%d\n", r, c, v[r][c], count);
            break;
        }
        // ȥ����������������
        dfs(n, limit - 1, r - 1, c, count);
        dfs(n, limit - 1, r + 1, c, count);
        dfs(n, limit - 1, r, c - 1, count);
        dfs(n, limit - 1, r, c + 1, count);
        v[r][c] = 0; // ����
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
            if (v == DEST) { // �յ�
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