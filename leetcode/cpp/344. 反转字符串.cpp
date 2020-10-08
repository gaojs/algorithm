#include <securec.h>
#include <bits/stdc++.h>
using namespace std;


void reverseString(vector<char>& s)
{
    int n = s.size();
    for (int i = 0; i < (n + 1) / 2; i++) {
        char t = s[i];
        s[i] = s[n - i - 1];
        s[n - i - 1] = t;
    }
}

int main()
{

    vector<char> a = { 'h', 'e', 'l', 'l', 'o' };
    reverseString(a);
    for (char e : a) {
        cout << e;
    }
    return 0;
}
