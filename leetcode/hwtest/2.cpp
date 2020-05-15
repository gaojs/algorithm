#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// �޳�1������ʣ�����������������У�
// ԭ���Ѿ�����ʱ������-1�����ʱ���޳���С��
#define MIN(a, b) ((a)<(b))?(a):(b)
#define N 201
int a[N] = { 0 };
int b[N] = { 0 };
int minCnt, maxCnt, equalCnt; // С�ڣ����ڣ�����

int ok(int *a, int n) {
    if (a == NULL || n <= 1) {
        return -1;
    }
    memset(b, 0, sizeof(b));
    minCnt = maxCnt = equalCnt = 0;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] < a[i + 1]) {
            minCnt++;
        } else if (a[i] > a[i + 1]) {
            b[i] = 1;
            maxCnt++;
        } else {
            equalCnt++;
        }
    }
    if (minCnt == 0 || maxCnt == 0) { // �Ѿ�����
        return -1;
    } else if (minCnt >= 2 && maxCnt >= 2) { // ����1��
        return -1;
    } else {
        int ok = INT_MAX; // Ĭ��ȡ���ֵ
        if (minCnt == 1) { // ȫ�Ǵ��ڣ�ֻ��1��С��
            for (int i = 0; i < n - 1; i++) {
                if (a[i] < a[i + 1]) { // �쳣
                    if (i == 0) { // ��ǰ
                        ok = MIN(ok, a[i]);
                    } else if (i + 1 == n - 1) { // ���
                        ok = MIN(ok, a[i + 1]);
                    } else { // �м�
                        if (a[i - 1] > a[i + 1]) {
                            ok = MIN(ok, a[i]);
                        }
                        if (a[i] > a[i + 2]) {
                            ok = MIN(ok, a[i + 1]);
                        }
                    }
                    break;
                }
            }
        }
        if (maxCnt == 1) { // ȫ��С�ڣ�ֻ��1������
            for (int i = 0; i < n - 1; i++) {
                if (a[i] > a[i + 1]) { // �쳣
                    if (i == 0) { // ��ǰ
                        ok = MIN(ok, a[i]);
                    } else if (i + 1 == n - 1) { // ���
                        ok = MIN(ok, a[i + 1]);
                    } else { // �м�
                        if (a[i - 1] < a[i + 1]) {
                            ok = MIN(ok, a[i]);
                        }
                        if (a[i] < a[i + 2]) {
                            ok = MIN(ok, a[i + 1]);
                        }
                    }
                    break;
                }
            }
        }
        return (ok == INT_MAX) ? -1 : ok;
    }
}

int main(void)
{
    int n;
    if (scanf_s("%d\n", &n) != 1) {
        return -1;
    }
    memset(a, 0, sizeof(a));
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int v;
        if (scanf_s("%d", &v) != 1) {
            return -1;
        }
        a[cnt++] = v;
    }
    printf("%d", ok(a, n));
    return 0;
}

