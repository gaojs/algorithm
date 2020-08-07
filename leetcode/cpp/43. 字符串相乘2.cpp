#include <bits/stdc++.h>
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

vector<int> mul(const vector<int> a, const vector<int> b) 
{
    vector<int> c(a.size() + b.size()); // c = a * b
    
    // 先算乘积，竖式乘法 
    for(int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            int t = a[i] * b[j]; // 乘积 
            int w = (i + j); // 当前位 
            c[w] += t % 10; // 个位 
            c[w + 1] += t / 10; // 进位 
        }
    }
    // 再处理进位 
    for (int i = 0; i < c.size() - 1; i++) {
        c[i + 1] += c[i] / 10;
        c[i] %= 10;
    }
    // 舍去高位的0
    for (int i = c.size() - 1; i > 0; i--) {
        if (c[i] == 0) {
            c.pop_back();
        } else {
            break;
        }
    }
    return c;
}

string multiply(string n1, string n2) 
{
    vector<int> a = str2vec(n1);
    vector<int> b = str2vec(n2);
    vector<int> c = mul(a, b);
    return vec2str(c);
}

int main() 
{
    // vector<int> v = str2vec("123");
    // cout<<vec2str(v);
    // cout<<multiply("123","456");
    cout<<multiply("2","3");
    return 0;        
}

