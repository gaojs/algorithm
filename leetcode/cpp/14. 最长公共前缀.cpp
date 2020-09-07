#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string>& strs)
{
    int n = strs.size();
    if (n <= 0) {
        return "";
    } else {
        int c = 0;
        int len = strs[0].length();
        for (c = 0; c < len; c++) {
            for (int i = 1; i < n; i++) {
                if (strs[0][c] != strs[i][c]) {
                    return strs[0].substr(0, c);
                }
            }
        }
        return strs[0].substr(0, c);
    }
}

int main()
{
    // vector<string> strs = { "flower","flow","flight" };  // fl
    vector<string> strs = { "dog","racecar","car" };  // ""
    cout << longestCommonPrefix(strs);
    return 0;
}
