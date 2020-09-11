#include <bits/stdc++.h>
using namespace std;

int longestCommonSubsequence(string s1, string s2)
{
    int r = s1.size(); // ����
    int c = s2.size(); // ���� // ���ж���0����Ϊ��ʼֵ
    vector<vector<int>> t(r + 1, vector<int>(c + 1, 0));

    for (int i = 0; i < r; i++) { // s1
        for (int j = 0; j < c; j++) { // s2
            if (s1[i] == s2[j]) { // ��ȣ����ϼ�1
                t[i + 1][j + 1] = t[i][j] + 1;
            } else { // ���ȣ��ϱߺ���ߵ����ֵ
                t[i + 1][j + 1] = max(t[i + 1][j], t[i][j + 1]);
            }
        }
    }
    return t[r][c];
}

int main()
{
    // string s1 = "abcde", s2 = "ace"; // 3
    // string s1 = "abc", s2 = "abc"; // 3
    string s1 = "abc", s2 = "def"; // 0
    cout << longestCommonSubsequence(s1, s2);
    return 0;
}
