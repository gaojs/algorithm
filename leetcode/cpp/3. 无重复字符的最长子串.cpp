#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    vector<int> c(128, 0);
    int m, n, i, j;
    m = n = i = j = 0;
    while (j < s.size()) {
        if (c[s[j]] == 0) {
            c[s[j]] = 1;
            n += 1;
            if (m < n) {
                m = n;
            }
            j++;
        } else {
            if (i < j) {
                c[s[i]] = 0;
                n -= 1;
                i++;
            }
        }
    }
    return m;
}

int main()
{
    cout << lengthOfLongestSubstring("abcabcbb") << endl; // 3
    cout << lengthOfLongestSubstring("bbbbb") << endl; // 1
    cout << lengthOfLongestSubstring("pwwkew") << endl; // 3
    return 0;
}
