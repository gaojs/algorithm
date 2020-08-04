#include <bits/stdc++.h>
using namespace std;


int maxWidthRamp(vector<int>& vt)
{
    stack<int> index;
    index.push(0); // �����ݼ�ջ
    for (size_t i = 1; i < vt.size(); i++) {
        if (vt[index.top()] > vt[i]) {
            index.push(i);
        }
    }
    int mx = 0; // ���ֵ
    for (int i = vt.size() - 1; i >= mx; i--) {
        int top = index.top(); // ջ��
        while (vt[top] <= vt[i]) {
            mx = max(mx, i - top);
            index.pop(); // ��ջ
            if (index.empty()) {
                return mx;
            }
            top = index.top();
        }
    }
    return mx;
}

int main(void)
{
    // vector<int> nums = { 9,8,1,0,1,9,4,0,4,1 };
    vector<int> nums = { 6,0,8,2,1,5 };
    cout << maxWidthRamp(nums);
    return 0;
}
