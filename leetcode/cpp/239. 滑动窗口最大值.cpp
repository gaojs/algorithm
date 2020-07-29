#include <cmath>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;

class MonoQueue {
    deque<int> data;

public:
    void push(int n)
    {
        while (!data.empty() && data.back() < n) {
            data.pop_back(); // �����ݼ�������С��
        }
        data.push_back(n);
    }

    void pop(int n)
    {
        if (!data.empty() && data.front() == n) {
            data.pop_front(); // ����ɾ
        }
    }

    int max()
    {// �����ݼ���ͷ���
        return data.front();
    }
};

vector<int> maxSlidingWindow(vector<int>& nums, size_t k)
{
    vector<int> rt;
    MonoQueue window;
    for (size_t i = 0; i < nums.size(); i++) {
        if (i < k - 1) { //���������ڵ�ǰ k - 1
            window.push(nums[i]);
        } else { // ������ǰ����
            window.push(nums[i]);
            rt.push_back(window.max());
            window.pop(nums[i - k + 1]);
        }
    }
    return rt;
}

int main(void)
{
    int k = 3;
    vector<int> nums = { 1, 3, -1, -3, 5, 3, 6, 7 };
    vector<int> vt = maxSlidingWindow(nums, k);
    for (int e : vt) {
        cout << e << " ";
    }
    return 0;
}
