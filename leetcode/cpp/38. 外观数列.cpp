#include <securec.h>
#include <bits/stdc++.h>
using namespace std;

string countAndSay(int n)
{
    if (n <= 1) {
        return "1";
    } else {
        string a = countAndSay(n - 1);
        int n = a.size();
        int cnt = 1;
        string s;
        for (int i = 1; i < n; i++) {
            if (a[i] == a[i - 1]) {
                cnt++;
            } else {
                s.push_back(cnt + '0');
                s.push_back(a[i - 1]);
                cnt = 1;
            }
        }
        s.push_back(cnt + '0');
        s.push_back(a[n - 1]);
        return s;
    }
}

int main()
{
    cout << countAndSay(1) << endl;
    cout << countAndSay(2) << endl;
    cout << countAndSay(3) << endl;
    cout << countAndSay(4) << endl;
    cout << countAndSay(5) << endl;
    cout << countAndSay(6) << endl;
    return 0;
}
