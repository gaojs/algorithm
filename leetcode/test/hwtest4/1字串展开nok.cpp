#include <bits/stdc++.h>
using namespace std;

string UnzipString(string s)
{
    int n = s.size();
    if (n <= 0) {
        return "";
    } else {
        int s1 = s.find_first_of(')');
        cout << s1;
        return "";
    }
}

int main()
{
    // cout << UnzipString("abc(d)<2>e") << endl; // abcdde
    cout << UnzipString("a(b(c)<3>d)<2>e") << endl; // abcccdbcccde
    return 0;
}
