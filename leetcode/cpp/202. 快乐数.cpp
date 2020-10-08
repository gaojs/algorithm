#include <securec.h>
#include <bits/stdc++.h>
using namespace std;


bool isHappy(int n)
{
    for (int i = 10000; i > 0; i--) {
        if (n == 1) {
            return true;
        }
        int m = 0;
        while (n > 0) {
            int t = n % 10;
            m += t * t;
            n /= 10;
        }
        n = m;
    }
    return false;
}

int main()
{
    cout << isHappy(19)<<endl; // 1
    cout << isHappy(2)<<endl; // 0
}
