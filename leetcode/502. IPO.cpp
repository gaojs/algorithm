#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>

#define MAX_COUNT 100000 // 足够大了

int a[] = { 9,8,7,6,5,4,3,2,1 };

void swap(int *a, int *b)
{ // 交换两个元素
    int t = *a;
    *a = *b;
    *b = t;
}

bool HeadNodeAdjust(int *b, int n)
{ // 堆的非叶子节点的调整
    if (a == NULL || n < 0) {
        return false;
    }
    int k = n / 2 - 1; // 非叶子节点的最大位置
    for (int i = k; i >= 0; i--) { // 遍历所有非叶子节点
        int dad = i; // 非叶子节点，即父节点的编号
        while (dad <= k) { // 父节点，仍然是非叶子节点
            int son = dad * 2 + 1; // 左子节点的编号
            if (son + 1 < n && a[son] < a[son + 1]) {
                son = son + 1;  // 右子节点更大，选右边
            }
            if (a[son] <= a[dad]) { // 子节点都比较小
                break; // 不用再下沉了
            }
            swap(&a[son], &a[dad]);
            dad = son;
        }
    }
    return true;
}

bool HeapSort(int *b, int n)
{ // 堆排序，大顶堆，从小到大
    if (a == NULL || n < 0) {
        return false;
    }
    for (int i = n; i > 0; i--) {
        HeadNodeAdjust(a, i);
        swap(&a[0], &a[i - 1]);
    }
    return true;
}

/************************
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
*/

int main()
{
    /**********************************
    int k = 2, w = 0, p[] = { 1,2,3 }, c[] = { 0,1,1 };
    int pn = sizeof(p) / sizeof(p[0]);
    int cn = sizeof(p) / sizeof(p[0]);
    printf("%d", findMaximizedCapital(k, w, p, pn, c, cn));
    */

    //int a[6] = { 7, 3, 8, 5, 1, 2 };
    int n = sizeof(a) / sizeof(a[0]);
    HeapSort(a, n); // 堆排序
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}


