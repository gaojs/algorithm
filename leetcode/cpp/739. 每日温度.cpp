#include <cmath>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;

vector<int> dailyTemperatures(vector<int>& vt)
{
    stack<int> index;
    vector<int> rt(vt.size(), 0);
    for (size_t i = 0; i < vt.size(); i++) {
        while (index.size() > 0) {
            int h = vt[index.top()];
            if (vt[i] <= h) { // �ݼ�
                break; // ֱ����ջ
            }
            int t = index.top();
            rt[t] = i - t;
            index.pop(); // ��ջ
        }
        index.push(i); // ��ջ
    }
    return rt;
}

int main(void)
{
    vector<int> vt = { 73, 74, 75, 71, 69, 72, 76, 73 };
    vector<int> rt = dailyTemperatures(vt);
    for (int e : rt) {
        cout << e << " ";
    }
    return 0;
}

