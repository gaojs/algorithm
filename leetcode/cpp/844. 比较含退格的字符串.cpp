#include <bits/stdc++.h>

using namespace std;

string eraseBackspace(string s) {
    string t;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '#') {
            if (t.size() > 0) {
                t.erase(t.size() - 1, 1);
            }
        } else {
            t.append(1, s[i]);
        }
    }
    return t;
}

bool backspaceCompare(string s1, string s2) {
    string t1 = eraseBackspace(s1);
    string t2 = eraseBackspace(s2);
    return t1.compare(t2) == 0;
}

int main() {
    // cout << backspaceCompare("ab#c", "ad#c") << endl; // 1
    // cout << backspaceCompare("ab##", "c#d#") << endl; // 1
    // cout << backspaceCompare("a##c", "#a#c") << endl; // 1
    // cout << backspaceCompare("a#c", "b") << endl; // 0
    // cout << backspaceCompare("xywrrmp", "xywrrmu#p") << endl; // 1
    cout << backspaceCompare("y#fo##f", "y#f#o##f") << endl; // 1
    return 0;
}
