#include <securec.h>
#include <bits/stdc++.h>
using namespace std;

int lengthOfLastWord(string s)
{
    int n1 = s.find_last_not_of(' ');
    int n2 = s.find_last_of(' ', n1);
    int n = (n1 - n2); // 两者之差是长度
    return  n < 0 ? 0 : n; // 长度不为负
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
