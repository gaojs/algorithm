#include <bits/stdc++.h>
using namespace std;

int romanToInt(string s)
{
    int ans = 0;

    int n = s.size();
    for (int i = 0; i < n; i++) {
        switch (s[i]) {
            case 'I': // 1
                if ((i + 1 < n) && (s[i + 1] == 'V' || s[i + 1] == 'X')) {
                    ans -= 1;
                } else {
                    ans += 1;
                }
                break;
            case 'V': // 5
                ans += 5;
                break;
            case 'X': // 10
                if ((i + 1 < n) && (s[i + 1] == 'L' || s[i + 1] == 'C')) {
                    ans -= 10;
                } else {
                    ans += 10;
                }
                break;
            case 'L': // 50
                ans += 50;
                break;
            case 'C': // 100
                if ((i + 1 < n) && (s[i + 1] == 'D' || s[i + 1] == 'M')) {
                    ans -= 100;
                } else {
                    ans += 100;
                }
                break;
            case 'D': // 500
                ans += 500;
                break;
            case 'M': // 1000
                ans += 1000;
                break;
        }
    }
    return ans;
}

int main()
{
    // string str = "III"; // 3
    // string str = "IV"; // 4
    // string str = "IX"; // 9
    // string str = "LVIII"; // 58
    string str = "MCMXCIV"; // 1994
    cout << romanToInt(str);
    return 0;
}
