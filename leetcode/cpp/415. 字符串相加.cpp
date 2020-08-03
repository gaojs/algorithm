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

string addStrings(string n1, string n2)
{
    string ans;
    for (int i = n1.length() - 1, j = n2.length() - 1, c = 0;
        i >= 0 || j >= 0 || c != 0; i--, j--) {
        int x = (i >= 0) ? n1[i] - '0' : 0;
        int y = (j >= 0) ? n2[j] - '0' : 0;
        int t = x + y + c;
        c = t / 10; // 进位
        ans.push_back(t % 10 + '0');
    }
    // 计算完以后的答案需要翻转过来
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    cout << addStrings("9", "999");
    return 0;
}
