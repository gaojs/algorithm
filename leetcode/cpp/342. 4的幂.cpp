#include <securec.h>
#include <bits/stdc++.h>
using namespace std;

bool isPowerOfFour(int n)
{
    while (n > 0) {
        if (n == 1) {
            return true;
        } else if (n % 4 != 0) {
            return false;
        } else {
            n /= 4;
        }
    }
    return false;
}

int main()
{
    cout << isPowerOfFour(16) << endl; //true
    cout << isPowerOfFour(5) << endl; //false
    return 0;
}
