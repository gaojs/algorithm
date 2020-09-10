#include <bits/stdc++.h>
using namespace std;

int strStr(string haystack, string needle)
{
    const char *p = strstr(haystack.c_str(), needle.c_str());
    if (p == nullptr) { // Ö±½Ó·â×°strstr
        return -1;
    } else {
        return p - haystack.c_str();
    }
}


int main()
{
    // string haystack = "aaaaa", needle = "bba"; // -1
    string haystack = "hello", needle = "ll"; // 2
    cout << strStr(haystack, needle);
    return 0;
}
