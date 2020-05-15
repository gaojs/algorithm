#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 用二叉树，比较好

void print(int* a, int n)
{
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

#define N 100000
int tmp[N] = { 0 };
int result[N] = { 0 };

int find(int* a, int n, int t)
{ // 折半查找
    if (a == NULL || n < 0) {
        return -1; // 参数错误
    } else if (n == 0) {
        return 0; // 无元素，直接返回0
    }
    int left = 0, right = n, mid = 0;
    while (left <= right) { // 从大到小排序
        mid = left + (right - left) / 2;
        if (a[mid] == t) {
            return mid; // 找到
        } else if (a[mid] < t) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return left; // 这里较大
}

int insertOne(int* a, int n, int t)
{
    if (a == NULL || n < 0) {
        return -1;
    }
    int pos = find(a, n, t);
    if (pos <= n) { // 往后移动
        int size = sizeof(int)*(n - pos + 1);
        memmove(a + pos + 1, a + pos, size);
    }
    a[pos] = t;
    return 0;
}

int removeOne(int* a, int n, int t)
{
    if (a == NULL || n < 0) {
        return -1;
    }
    int pos = find(a, n, t);
    if (pos < n) { // 往前移动
        int size = sizeof(int)*(n - pos);
        memmove(a + pos, a + pos + 1, size);
    }
    return 0;
}

int* maxSlidingWindow(int* a, int n, int k, int* returnSize) {
    if (a == NULL || n <= 0 || k <= 0 || returnSize == NULL) {
        return NULL;
    }
    *returnSize = 0;
    memset(tmp, 0, sizeof(tmp));
    memset(result, 0, sizeof(result));
    int index = 0, count = 0;
    for (int i = 0; i < k; i++) {
        insertOne(tmp, i, a[i]);
    }
    for (int i = k; i < n; i++) {
        result[*returnSize] = tmp[0];
        removeOne(tmp, k, a[i - k]);
        insertOne(tmp, k - 1, a[i]);
        (*returnSize)++;
    }
    result[*returnSize] = tmp[0];
    (*returnSize)++;
    return result;
}

int main()
{
    /*****************************
    */
    // int a[] = { 1,3,-1,-3,5,3,6,7 }, k = 3; // 3,3,5,5,6,7
    int a[] = { 1,-1 }, k = 1; // 1,-1
    int n = sizeof(a) / sizeof(a[0]);
    int returnSize = 0;
    int *p = maxSlidingWindow(a, n, k, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", p[i]);
    }
    return 0;
}

