#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

// 判断是否为一对情侣的方法，是a=b^1（异或），这个很巧妙。
// 也可以使用（a/2==b/2）来判断，但还是异或操作更快速。
int minSwapsCouples(int*a, int n)
{
    if (a == NULL || n <= 0) {
        return 0; // 参数错误
    }
    int cnt = 0; // 交换次数
    for (int i = 0; i < n - 1; i += 2) {
        if (a[i] == (a[i + 1] ^ 1)) {
            continue; // 已经是一对了，继续
        }
        for (int j = i + 2; j < n; j++) {
            if (a[i] == (a[j] ^ 1)) {
                int t = a[i + 1];
                a[i + 1] = a[j];
                a[j] = t;
                cnt++;
                break;
            }
        }
    }
    return cnt;
}

int main()
{
    int a[] = { 0, 2, 1, 3 }; // 1
    // int a[] = {3, 2, 0, 1}; // 0
    int n = sizeof(a) / sizeof(a[0]);
    // printf("%d", minSwapsCouples(a, n));
    return 0;
}


