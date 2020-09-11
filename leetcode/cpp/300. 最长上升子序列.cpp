#include <bits/stdc++.h>
using namespace std;

int lengthOfLIS(vector<int>& a)
{
    int n = a.size();
    vector<int> c(n, 1);
    int mx = (n > 0) ? 1 : 0; // max

    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j > i; j--) {
            if (a[i] < a[j] && c[i] < c[j] + 1) {
                c[i] = c[j] + 1; // max(c[i], c[j] + 1)
                if (mx < c[i]) {
                    mx = c[i];
                }
            }
        }
    }
    return mx;
}

int main()
{
    //vector<int> a;
    vector<int> a(1, 0);
    cout << a.size() << endl;
    // vector<int> a = { 10,9,2,5,3,7,101,18 };
    cout << lengthOfLIS(a);
    return 0;
}
