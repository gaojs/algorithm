#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100000
int dp[N] = { 0 }; // dp[i][j]是i到j的最大值
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
    for (int c = 0; c < n; c++) {
        // 初始状态，dp[c]表示c到c的最大值
        dp[c] = a[c]; 
    }
    // print(dp, n);
    for (int r = 1; r < k; r++) {
        for (int c = 0; c < n - r; c++) {
            // dp[c]表示c到c+r的最大值 
            dp[c] = max(dp[c], a[c + r]); 
        }
        // print(dp, n - r);
    }
    *returnSize = n - k + 1;
    return dp;
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

