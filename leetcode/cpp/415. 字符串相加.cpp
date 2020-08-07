#include <bits/stdc++.h>
using namespace std;

string addStrings(string n1, string n2)
{
    string ans;
    for (int i = n1.length() - 1, j = n2.length() - 1, c = 0;
        i >= 0 || j >= 0 || c != 0; i--, j--) {
        int x = (i >= 0) ? n1[i] - '0' : 0;
        int y = (j >= 0) ? n2[j] - '0' : 0;
        int t = x + y + c;
        c = t / 10; // ��λ
        ans.push_back(t % 10 + '0');
    }
    // ��ȥ��λ��0
    for (int i = ans.size() - 1; i > 0; i--) {
        if (ans[i] != '0') {
            break;
        }
        ans.pop_back();
    }
    // �������Ժ�Ĵ���Ҫ��ת����
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    cout << addStrings("9", "999");
    return 0;
}
