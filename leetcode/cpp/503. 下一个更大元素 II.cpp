#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElements(vector<int>& nums)
{
    stack<int> index;
    int size = nums.size();
    vector<int> rt(size, -1);
    for (int i = 0; i < size * 2; i++) {
        int idx = i % size; // �±겻Ҫ����
        if (index.size() > 0) { // ��Ԫ����
            int top = index.top();
            while (nums[idx] > nums[top]) {
                rt[top] = nums[idx];
                index.pop(); // ��ջ
                if (index.empty()) {
                    break; // ջ��
                }
                top = index.top();
            }
        }
        index.push(idx); // ѹջ
    }
    return rt;
}

int main(void)
{
    vector<int> nums = { 1,2,1 };
    vector<int> rt = nextGreaterElements(nums);
    for (int e : rt) {
        cout << e << " ";
    }
    return 0;
}
