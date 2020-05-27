#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100000
int left[N] = { 0 }; // left[i]从(i/k)*k到i的最大值
int right[N] = { 0 }; // right[i]从(i/k+1)*k到i的最大值
int result[N] = { 0 }; // max
#define max(a,b) ((a)>(b)?(a):(b))

void print(int* a, int n)
{
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int* maxSlidingWindow(int* a, int n, int k, int* returnSize) {
    if (a == NULL || n <= 0 || k <= 0 || returnSize == NULL) {
        return NULL;
    }
    // print(a, n);
    for (int c = 0; c < n; c++) {
        if (c % k == 0) {
            left[c] = a[c];
        } else {
            left[c] = max(left[c - 1], a[c]);
        }
    }
    // print(left, n);
    for (int c = n - 1; c >= 0; c--) {
        if (c % k == k - 1 || c == n - 1) {
            right[c] = a[c];
        } else {
            right[c] = max(right[c + 1], a[c]);
        }
    }
    // print(right, n);
    for (int c = 0; c < n - k + 1; c++) {
        result[c] = max(right[c], left[c + k - 1]);
    }
    // print(result, n - k + 1);
    *returnSize = n - k + 1;
    return result;
}

int main()
{
    /*****************************
    */
    int a[] = { 1,3,-1,-3,5,3,6,7 }, k = 3; // 3,3,5,5,6,7
    // int a[] = { 1,-1 }, k = 1; // 1,-1
    int n = sizeof(a) / sizeof(a[0]);
    int returnSize = 0;
    int *p = maxSlidingWindow(a, n, k, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", p[i]);
    }
    return 0;
}

