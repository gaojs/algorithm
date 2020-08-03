#include <cmath>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;

vector<int> str2vec(const string s)
{
    vector<int> v; // 倒序存放各位数字 

    for (int i = s.size() - 1; i >= 0; i--) {
        v.push_back(s[i] - '0'); // 字符转数字
    }
    return v;
}

string vec2str(const vector<int> v)
{
    string s; // 正序存放字符串 

    for (int i = v.size() - 1; i >= 0; i--) {
        s.push_back(v[i] + '0'); // 数字转字符
    }
    return s;
}

vector<int> c(const vector<int> a, const vector<int> b)
{
    int mx = max(a.size(), b.size());
    int mn = min(a.size(), b.size());
    vector<int> c(mx + 1); // c = a + b

    int i = 0; // 下标
    for (; i < mn; i++) {
        c[i] = a[i] + b[i];
    }
    for (; i < a.size(); i++) {
        c[i] = a[i];
    }
    for (; i < b.size(); i++) {
        c[i] = b[i];
    }

    // 再处理进位 
    for (int i = 0; i < c.size() - 1; i++) {
        c[i + 1] += c[i] / 10;
        c[i] %= 10;
    }
    // 舍去高位的0
    for (int i = c.size() - 1; i > 0; i--) {
        if (c[i] != 0) {
            break;
        }
        c.pop_back();
    }
    return c;
}

string addStrings(string n1, string n2)
{
    vector<int> a = str2vec(n1);
    vector<int> b = str2vec(n2);
    vector<int> c = c(a, b);
    return vec2str(c);
}

int main()
{
    cout << addStrings("9", "999");
    return 0;
}
