#include <bits/stdc++.h>
using namespace std;

bool isValid(string s)
{
    stack<char> st;
    for (char c : s) {
        switch (c) {
            case '(':
            case '[':
            case '{':
                st.push(c);
                break;
            case ')':
                if (!st.empty() && st.top() == '(') {
                    st.pop();
                } else {
                    return false;
                }
                break;
            case ']':
                if (!st.empty() && st.top() == '[') {
                    st.pop();
                } else {
                    return false;
                }
                break;
            case '}':
                if (!st.empty() && st.top() == '{') {
                    st.pop();
                } else {
                    return false;
                }
                break;
            default:
                break;
        }
    }
    return st.empty();
}

int main()
{
    cout << isValid("()");
    cout << isValid("()]{}");
    return 0;
}
