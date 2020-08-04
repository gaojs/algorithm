#include <bits/stdc++.h>
using namespace std;

struct node {
    int v; // value
    int i; // index
    
    node(int vt, int it) {
        v=vt, i=it;
    }
}; 

bool cmp(const node &a, const node &b) {
    return a.v < b.v;
}

class Solution {
public:
    vector<int> twoSum(vector<int>&a, int target) {
        vector<node>ns;
        for (int i = 0; i < a.size(); i++) {
            ns.emplace_back(a[i], i);
        }
        sort(ns.begin(), ns.end(), cmp);
        int left = 0, right = ns.size()-1;
        while (left < right) {
            int t = ns[left].v + ns[right].v;
            if (t == target) {
                return {ns[left].i, ns[right].i};
            } else if (t < target) {
                left++;
            } else {
                right--;
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
    
