#include <securec.h>
#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int>& a)
{
    int n = a.size();
    int sum = 0; // �����еĺ�
    int mx = INT_MIN; // ����Ԫ��
    int mxs = INT_MIN; // ���������еĺ�
    for (int i = 0; i < n; i++) {
        if (mx < a[i]) {
            mx = a[i];
        }
        sum += a[i];
        if (sum < 0) {
            sum = 0;
        }
        if (mxs < sum) {
            mxs = sum;
        }
    }
    return mxs > 0 ? mxs : mx;
}

int main()
{
    //vector<int> a = { -2,1,-3,4,-1,2,1,-5,4 };  // 6
    vector<int> a = { -1 };  // -1
    cout << maxSubArray(a) << endl;
    return 0;
}
