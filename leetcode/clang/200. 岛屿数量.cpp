#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define N 300 // ��֤�㹻��
int visit[N][N] = { 0 }; // 0-δ���ʣ�>0-�ѷ���
int color = 0; // ����ͼͿɫ����ɫ��

bool dfs(char** a, int n, int* col, int r, int c)
{
    if (a == NULL || col == NULL || n <= 0 || *col <= 0) {
        return false;
    } else if (r < 0 || r >= n || c < 0 || c >= *col) {
        return false;
    }
    // printf("(%d,%d)=[%d,%d] ", r, c, a[r][c], visit[r][c]);
    if (a[r][c] =='1' && !visit[r][c]) { // �е��첢��δ����
        visit[r][c] = color + 1;
        // printf("(%d,%d)=%d ", r, c, color + 1);
        // ����������Ҳͼ����ɫ
        dfs(a, n, col, r - 1, c);
        dfs(a, n, col, r + 1, c);
        dfs(a, n, col, r, c - 1);
        dfs(a, n, col, r, c + 1);
        return true;
    }
    return false;
}

int numIslands(char** a, int n, int* col)
{
    if (a == NULL || col == NULL || n <= 0 || *col <= 0) {
        return 0; // ��������
    }
    color = 0;
    memset(visit, 0, sizeof(visit));
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < *col; c++) {
            if (dfs(a, n, col, r, c)) {
                color++; // �ҵ�С������ɫ��1
            }
        }
    }
    return color;
}

int main()
{
    /**********************************
    char r1[] = { '1','1','1','1','0' };
    char r2[] = { '1','1','0','1','0' };
    char r3[] = { '1','1','0','0','0' };
    char r4[] = { '0','0','0','0','0' };
    int col[] = { 5, 5, 5, 5, 5 }; */
    char r1[] = { '1', '1', '0', '0', '0' };
    char r2[] = { '1', '1', '0', '0', '0' };
    char r3[] = { '0', '0', '1', '0', '0' };
    char r4[] = { '0', '0', '0', '1', '1' };
    int col[] = { 5, 5, 5, 5, 5 };
    char *a[] = { r1, r2, r3, r4 };
    int n = sizeof(a) / sizeof(a[0]);
    int ret = numIslands(a, n, col);
    printf("%d", ret);
    return 0;
}
