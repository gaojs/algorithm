#include <bits/stdc++.h>
using namespace std;

string multiply(string n1, string n2)
{
    vector<int> a(n1.size(), 0);
    vector<int> b(n2.size(), 0);
    vector<int> c(n1.size() + n2.size(), 0);

    for (int i = n1.size() - 1, j = 0; i >= 0; i--) {
        a[j++] = n1[i] - '0'; // �ַ���n1ת����a
    }
    for (int i = n2.size() - 1, j = 0; i >= 0; i--) {
        b[j++] = n2[i] - '0'; // �ַ���n2ת����b
    }
    // ����˻�����ʽ�˷�  // c = a * b
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            c[i + j] += a[i] * b[j];
        }
    }
    // �ٴ����λ 
    for (int i = 0; i < c.size() - 1; i++) {
        c[i + 1] += c[i] / 10;
        c[i] %= 10;
    }
    // ��ȥ��λ��0
    int i = c.size() - 1;
    for (; i > 0 && c[i] == 0; i--) {
        c.pop_back();
    }
    string ans; // ת���ַ���
    for (; i >= 0; i--) {
        ans.push_back(c[i] + '0');
    }
    return ans;
}

int main()
{
    cout << multiply("123", "456");
    // cout << multiply("2", "3");
    return 0;
}
