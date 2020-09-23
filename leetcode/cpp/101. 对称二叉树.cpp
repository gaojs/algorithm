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

bool isSymmetricDfs(TreeNode* left, TreeNode* right)
{
    if (left == nullptr && right == nullptr) {
        return true;
    } else if (left == nullptr || right == nullptr) {
        return false;
    } else {
        if (left->val != right->val) {
            return false;
        }
        if (!isSymmetricDfs(left->left, right->right)) {
            return false;
        }
        if (!isSymmetricDfs(left->right, right->left)) {
            return false;
        }
        return true;
    }
}

bool isSymmetric(TreeNode* root)
{
    if (root == nullptr) {
        return true;
    }
    return isSymmetricDfs(root->left, root->right);
}

int main()
{
    return 0;
}
