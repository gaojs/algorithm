#include <bits/stdc++.h>
using namespace std;

int longestOnes(vector<int>& a, int k)
{
    int m, n, i, j;
    m = n = i = j = 0;
    while (j < a.size()) {
        if (a[j] == 1) {
            j++;
            n++;
            if (m < n) {
                m = n;
            }
        } else if (a[j] == 0) {
            if (k > 0) {
                k--;
                j++;
                n++;
                if (m < n) {
                    m = n;
                }
            } else {
                if (a[i] == 0) {
                    k++;
                }
                i++;
                n--;
            }
        }
    }
    return m;
}

int main()
{
    {
        vector<int> a = { 1,1,1,0,0,0,1,1,1,1,0 };
        cout << longestOnes(a, 2) << endl;// 6
    }
    {
        vector<int> a = { 0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1 };
        cout << longestOnes(a, 3) << endl;// 10
    }
    return 0;
}
