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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL)
    {
    }
};

int maxDepth(TreeNode* root)
{
    if (root == NULL) {
        return 0;
    } else {
        int left, right;
        left = right = 1;
        if (root->left != NULL) {
            left += maxDepth(root->left);
        }
        if (root->right != NULL) {
            right += maxDepth(root->right);
        }
        return max(left, right);
    }
}

int main(void)
{
    vector<int> vt = { 73, 74, 75, 71, 69, 72, 76, 73 };
    vector<int> rt = maxDepth(NULL);
    for (int e : rt) {
        cout << e << " ";
    }
    return 0;
}

