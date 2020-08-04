#include <bits/stdc++.h>
using namespace std;

vector<int> int2vec(int n)
{
    vector<int> rt;
    while (n > 0) { // ��������
        rt.push_back(n % 10);
        n = n / 10;
    }
    return rt;
}

int vec2int(vector<int> v)
{
    long long rt = 0;
    while (v.size() > 0) {
        int t = v.back();
        rt = rt * 10 + t;
        v.pop_back();
    }
    if (rt > INT_MAX) {
        return -1; // ��2
    }
    return rt;
}

int nextGreaterElement(int n)
{
    vector<int> nums = int2vec(n);
    int size = nums.size();
    stack<int> index;
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (index.size() > 0) { // ��Ԫ����
            int top = index.top();
            if (nums[i] < nums[top]) {
                int idx = top;
                while (nums[i] < nums[top]) {
                    idx = top; // ��¼����
                    index.pop(); // ��ջ
                    if (index.empty()) {
                        break; // ջ��
                    }
                    top = index.top();
                }
                // ��������Ԫ��
                int t = nums[i];
                nums[i] = nums[idx];
                nums[idx] = t;
                found = true;
                if (i > 1) { // ��1���Ӵ�С���򣬱�֤��С
                    sort(&nums[0], &nums[i], greater<int>());
                }
                break;
            }
        }
        index.push(i); // ѹջ
    }
    return found ? vec2int(nums) : -1;
}

int main(void)
{
    // int n = 230241; //230412
    // int n = 12443322; //13222344
    int n = 1999999999;
    /*
    vector<int> v = int2vec(n);
    for (int e : v) {
        cout << e << " ";
    }
    cout << endl << vec2int(v) << endl;
    */
    cout << nextGreaterElement(n);
    return 0;
}
