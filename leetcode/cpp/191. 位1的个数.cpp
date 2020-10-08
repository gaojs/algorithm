#include <securec.h>
#include <bits/stdc++.h>
using namespace std;

int hammingWeight(uint32_t n)
{
    int cnt = 0;
    while (n > 0) {
        if (n & 0x01) {
            cnt++;
        }
        n = n >> 1;
    }
    return cnt;
}

int main()
{
    cout << hammingWeight(5);
}
