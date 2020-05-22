#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100000000
bool a[N] = { 0 };

int bulbSwitch(int n)
{
    memset(a, 0, sizeof(a));
    for (int k = 1; k <= n; k++) {
        for (int i = k - 1; i < n; i += k) {
            a[i] = !a[i];
        }
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (a[i]) {
            sum++;
        }
    }
    return sum;
}

int main()
{
    /*****************************
    */
    // int n = 1; // 1
    // int n = 2; // 1
    // int n = 3; // 1
    // int n = 4; // 2
    int n = 99999999;
    printf("%d", bulbSwitch(n));
    return 0;
}

