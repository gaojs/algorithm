#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, a;

    while (cin >> n) {
        for (m = n, a = 2; a <= m && m > 1; a++) {
            while (m % a == 0) {
                if (m != n) { // not first
                    cout << "*";
                }
                cout << a;
                m /= a;
            }
        }
        cout << "=" << n << endl;
    }
    return 0;
}
