#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define N 100
int h[N][N] = { 0 }; // ����(Heath)ֵ
int b[N][N] = { 0 }; // �(Bad)��������(Best)ֵ

int calculateMinimumHP(int** a, int n, int* col)
{
    if (a == NULL || n == 0 || col == NULL) {
        return 0;
    }
    memset(h, 0, sizeof(h));
    memset(b, 0, sizeof(b));
    h[0][0] = a[0][0];
    b[0][0] = (h[0][0] < 0) ? h[0][0] : 0; // ���
    printf("[0][0]=(%d,%d) ", h[0][0], b[0][0]);
    for (int c = 1; c < col[0]; c++) { // ����
        h[0][c] = h[0][c - 1] + a[0][c];
        b[0][c] = b[0][c - 1]; // Ĭ�����
        if (h[0][c] < 0 && b[0][c] > h[0][c]) { 
            b[0][c] = h[0][c]; // ȡ��ֵ����Сֵ
        }
       printf("[0][%d]=(%d,%d) ", c, h[0][c], b[0][c]); 
    }
    printf("\n");
    for (int r = 1; r < n; r++) { // ������
        for (int c = 0; c < col[r]; c++) { // ���������μ���
            int left = (c == 0) ? INT_MIN : b[r][c - 1];
            if (left >= b[r - 1][c]) { // ��߸���
                h[r][c] = h[r][c - 1] + a[r][c];
                b[r][c] = left;
            } else { // �ϱ߸���
                h[r][c] = h[r - 1][c] + a[r][c];
                b[r][c] = b[r - 1][c];
            }
            if (h[r][c] < 0 && b[r][c] > h[r][c]) {
                b[r][c] = h[r][c]; // ȡ��ֵ����Сֵ
            }
            printf("[%d][%d]=(%d,%d) ", r, c, h[r][c], b[r][c]); 
        }
        printf("\n");
    }
    return 1 - b[n - 1][col[n - 1] - 1];
}

int main()
{
    /************************
    int r1[] = { -2, -3, 3 };
    int r2[] = { -5, -10, 1 };
    int r3[] = { 10, 30, -5 };
    int col[] = { 3, 3, 3 };
    int *a[] = { r1, r2, r3 };
    */ // 7
    /************************
    int r1[] = { 0, 0, 0 };
    int r2[] = { 1, 1, -1 };
    int col[] = { 3, 3 };
    int *a[] = { r1, r2 };
    */ // 1
    int r1[] = { 1, -3, 3 };
    int r2[] = { 0, -2, 0 };
    int r3[] = { -3, -3, -3 };
    int col[] = { 3, 3, 3 };
    int *a[] = { r1, r2, r3 };
    int n = sizeof(a) / sizeof(a[0]);
    int ret = calculateMinimumHP(a, n, col);
    printf("%d", ret);
    return 0;
}
