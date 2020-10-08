#include <securec.h>
#include <bits/stdc++.h>
using namespace std;

vector<int> selfDividingNumbers(int left, int right)
{
    vector<int> res;
    for (int n = left; n <= right; n++) {
        bool flag = true;
        for (int m = n; m > 0; m /= 10) {
            int t = m % 10;
            if (t == 0 || n % t != 0) {
                flag = false;
                break;
            }
        }
        if (flag) {
            res.push_back(n);
        }
    }
    return res;
}

int main()
{
    int left = 1, right = 22;
    vector<int> res = selfDividingNumbers(left, right);
    for (int e : res) {
        cout << e << ",";
    }
    return 0;
}
