#include <securec.h>
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL)
    {
    }
};

int sumOfLeftLeaves(TreeNode* root)
{
    if (root == nullptr) {
        return 0;
    } else if (root->left == nullptr) {
        return sumOfLeftLeaves(root->right);
    } else {
        int sum = 0;
        if (root->left->left == nullptr
            && root->left->right == nullptr) {
            sum += root->left->val;
        } else {
            sum += sumOfLeftLeaves(root->left);
        }
        sum += sumOfLeftLeaves(root->right);
        return sum;
    }
}

int main()
{
    return 0;
}
