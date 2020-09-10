#include <bits/stdc++.h>
using namespace std;

string addBinary2(string a, string b)
{ // 翻转a和b，从左到右加
    string d;
    int c = 0, i = 0;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    for (; i < a.size() && i < b.size(); i++) {
        int t = ((a[i] - '0') + (b[i] - '0') + c);
        d.push_back(t % 2 + '0');
        c = t / 2;
    }
    for (; i < a.size(); i++) {
        int t = ((a[i] - '0') + c);
        d.push_back(t % 2 + '0');
        c = t / 2;
    }
    for (; i < b.size(); i++) {
        int t = ((b[i] - '0') + c);
        d.push_back(t % 2 + '0');
        c = t / 2;
    }
    while (c > 0) {
        d.push_back(c % 2 + '0');
        c = c / 2;
    }
    reverse(d.begin(), d.end());
    return d;
}

string addBinary(string a, string b)
{ // 不翻转a和b，从右往左加，更好
    string d;
    int c = 0;
    int ai = a.size() - 1;
    int bi = b.size() - 1;
    for (; ai >= 0 || bi >= 0 || c != 0; ai--, bi--) {
        int at = ai < 0 ? 0 : (a[ai] - '0');
        int bt = bi < 0 ? 0 : (b[bi] - '0');
        int t = at + bt + c;
        d.push_back(t % 2 + '0');
        c = t / 2;
    }
    reverse(d.begin(), d.end());
    return d;
}

int main()
{    
    // string a = "11", b = "1"; // 100
    string a = "1010", b = "1011"; // 10101
    cout << addBinary(a, b);
    return 0;
}
