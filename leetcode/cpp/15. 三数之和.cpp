#include <securec.h>
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>& a)
{
    vector<vector<int>> ans;
    sort(a.begin(), a.end()); // �������ٲ���
    int n = a.size(); // ����Ԫ�ظ���
    for (int i = 0; i < n; i++) { // ��
        if (i > 0 && a[i] == a[i - 1]) {
            continue; // �Թ��ظ������
        }
        int j = i + 1; // ��
        int k = n - 1; // ��
        while (j < k) { // i, j, k
            int sum = a[i] + a[j] + a[k];
            if (sum == 0) { // OK // ���д�ȥ��
                vector<int> an = { a[i], a[j], a[k] };
                ans.push_back(an); // �ҵ�һ����
                for (j++; j < k && a[j] == a[j - 1]; j++) {
                    ; // �Թ��ظ������
                }
            } else if (sum > 0) {
                k--; // ��С
            } else {
                j++; // ����
            }
        }
    }
    return ans;
}

int main()
{
    // vector<int> a = { 0, 0, 0, 0 }; //[0,0,0]
    // vector<int> a = { -1, 0, 1, 2, -1, -4 }; //[-1,-1,2,],[-1,0,1,]
    // vector<int> a = { -2,0,1,1,2 }; //[-2,0,2,],[-2,1,1,]
    //[-4,-2,6,],[-4,0,4,],[-4,1,3,],[-4,2,2,],[-2,-2,4,],[-2,0,2,]
    vector<int> a = { -4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6 }; 
    vector<vector<int>> rt = threeSum(a);
    for (vector<int> r : rt) {
        cout << "[";
        for (int e : r) {
            cout << e << ",";
        }
        cout << "],";
    }
    return 0;
}
