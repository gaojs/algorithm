// 剔除元素
#include <iostream>
using namespace std;

// 剔除1个数，剩余数字满足有序序列，
// 原本已经有序时，返回-1；多个时，剔除最小的
#define MIN(a, b) ((a)<(b))?(a):(b)
#define N 201
int a[N] = { 0 };
int b[N] = { 0 };
int minCnt, maxCnt, equalCnt; // 小于，大于，等于

int ok(int *a, int n)
{
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
    if (minCnt == 0 || maxCnt == 0) { // 已经有序
        return -1;
    } else if (minCnt >= 2 && maxCnt >= 2) { // 多余1个
        return -1;
    } else {
        int ok = INT_MAX; // 默认取最大值
        if (minCnt == 1) { // 全是大于，只有1个小于
            for (int i = 0; i < n - 1; i++) {
                if (a[i] < a[i + 1]) { // 异常
                    if (i == 0) { // 最前
                        ok = MIN(ok, a[i]);
                    } else if (i + 1 == n - 1) { // 最后
                        ok = MIN(ok, a[i + 1]);
                    } else { // 中间
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
        if (maxCnt == 1) { // 全是小于，只有1个大于
            for (int i = 0; i < n - 1; i++) {
                if (a[i] > a[i + 1]) { // 异常
                    if (i == 0) { // 最前
                        ok = MIN(ok, a[i]);
                    } else if (i + 1 == n - 1) { // 最后
                        ok = MIN(ok, a[i + 1]);
                    } else { // 中间
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

int main()
{
    int n;
    cin >> n;
    cout << n << endl;

    memset(a, 0, sizeof(a));
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cout << a[i] << " ";
    }

    cout << ok(a, n);
    return 0;
}
