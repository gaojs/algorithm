#include <bits/stdc++.h>
using namespace std;

int equalSubstring(string s, string t, int maxCost)
{
    int n = s.size();
    int tn = t.size();
    if (n <= 0 || n != tn) {
        return 0;
    } else {
        vector<int> v(n, 0);

        for (int i = 0; i < n; i++) {
            v[i] = abs(s[i] - t[i]);
        }
        // window, max, cost, i-j
        int w, m, c, i, j;
        w = m = c = i = j = 0;
        while (j < n) {
            if (c + v[j] <= maxCost) {
                c += v[j]; // 移动j
                w += 1;
                if (m < w) {
                    m = w;
                }
                j++;
            } else {
                if (i < j) { // 移动i
                    c -= v[i];
                    w -= 1;
                    i++;
                } else { // 一起移动
                    i++, j++;
                }
            }
        }
        return m;
    }
}

int main()
{
    cout << equalSubstring("abcd", "bcdf", 3) << endl; // 3
    // cout << equalSubstring("abcd", "cdef", 3) << endl; // 1
    // cout << equalSubstring("abcd", "acde", 0) << endl; // 1
    // cout << equalSubstring("anryddgaqpjdw", "zjhotgdlmadcf", 5) << endl; // 1
    return 0;
}
