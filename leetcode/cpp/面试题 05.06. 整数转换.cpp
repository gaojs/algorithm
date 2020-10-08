#include <securec.h>
#include <bits/stdc++.h>
using namespace std;

int convertInteger(int a, int b)
{
    int sum = 0;
    unsigned int c;
    c = a ^ b; // Òì»ò
    while (c != 0) {
        if (c & 0x01) {
            sum++;
        }
        c = c >> 1;
    }
    return sum;
}

int main()
{
    cout << convertInteger(1, 2) << endl; //2
    cout << convertInteger(29, 15) << endl; //2
    return 0;
}
