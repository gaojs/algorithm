#include <securec.h>
#include <bits/stdc++.h>
using namespace std;

int lengthOfLastWord(string s)
{
    int n1 = s.find_last_not_of(' ');
    int n2 = s.find_last_of(' ', n1);
    int n = (n1 - n2); // ����֮���ǳ���
    return  n < 0 ? 0 : n; // ���Ȳ�Ϊ��
}

int main()
{
    cout << lengthOfLastWord("Hello World") << endl;
    cout << lengthOfLastWord("a") << endl;
    cout << lengthOfLastWord("a ") << endl;
    cout << lengthOfLastWord("") << endl;
    cout << lengthOfLastWord(" ") << endl;
    return 0;
}
