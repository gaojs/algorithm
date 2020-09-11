#include <bits/stdc++.h>
using namespace std;

string UnzipString(string s)
{
    int s1, s2, m1, m2;
    s2 = s.find_first_of(')');
    if (s2 == string::npos) {
        return s;
    } else {
        s1 = s.find_last_of('(', s2);
        m1 = s.find_first_of('<', s2);
        m2 = s.find_first_of('>', m1);
        string a = s.substr(0, s1);
        string tmp = s.substr(s1 + 1, s2 - s1 - 1);
        string b = UnzipString(tmp);
        string c = s.substr(m2 + 1);
        tmp = s.substr(m1 + 1, m2 - m1);
        int cnt = tmp.size() > 1 ? stoi(tmp) : 0;
        for (int i = 0; i < cnt; i++) {
            a.append(b);
        }
        a.append(c);
        return UnzipString(a);
    }
}

int main()
{
    // cout << UnzipString("abc(d)<2>e") << endl; // abcdde
    // cout << UnzipString("a(b(c)<3>d)<2>e") << endl; // abcccdbcccde
    cout << UnzipString("a(b)<1>(b)<1>c") << endl; // 1
    return 0;
}
