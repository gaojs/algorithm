#include <bits/stdc++.h>
using namespace std;

vector<int> str2vec(const string s)
{
    vector<int> v; // �����Ÿ�λ���� 
    
    for (int i = s.size() - 1; i >= 0; i--) {
        v.push_back(s[i] - '0'); // �ַ�ת����
    }
    return v; 
}

string vec2str(const vector<int> v)
{
    string s; // �������ַ��� 
    
    for (int i = v.size() - 1; i >= 0; i--) {
        s.push_back(v[i] + '0'); // ����ת�ַ�
    }
    return s;
}

vector<int> mul(const vector<int> a, const vector<int> b) 
{
    vector<int> c(a.size() + b.size()); // c = a * b
    
    // ����˻�����ʽ�˷� 
    for(int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            int t = a[i] * b[j]; // �˻� 
            int w = (i + j); // ��ǰλ 
            c[w] += t % 10; // ��λ 
            c[w + 1] += t / 10; // ��λ 
        }
    }
    // �ٴ����λ 
    for (int i = 0; i < c.size() - 1; i++) {
        c[i + 1] += c[i] / 10;
        c[i] %= 10;
    }
    // ��ȥ��λ��0
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

