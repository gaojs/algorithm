#include <securec.h>
#include <bits/stdc++.h>
using namespace std;

bool isUgly(int n)
{
    while (n > 0) {
        if (n == 1) {
            return true;
        } else if (n % 2 == 0) {
            n /= 2;
        } else if (n % 3 == 0) {
            n /= 3;
        } else if (n % 5 == 0) {
            n /= 5;
        } else {
            return false;
        }
    }
    return false;
}

int main()
{
    cout << isUgly(6) << endl; //true
    cout << isUgly(8) << endl; //true
    cout << isUgly(14) << endl; //false
    return 0;
}