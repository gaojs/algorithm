#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>&a, int target) {
        for (int i = 0; i < a.size(); i++) {
            for (int j = i + 1; j < a.size(); j++) {
                if (a[i] + a[j] == target) {
                    return {i, j}; //列表转向量 
                }
            }
        }
        return {0, 0} ;
    }
};
    
int main () 
{
    vector<int>a = {2, 7, 11, 15};
    int target = 9;
    Solution s;
    
    vector<int> result = s.twoSum(a, target);
    for(int i : result) {
        cout<<i<<" ";
    }        
} 
    
