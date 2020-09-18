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

TreeNode* invertTree(TreeNode* root)
{
    if (root != nullptr) {
        TreeNode* t = root->left;
        root->left = root->right;
        root->right = t;

        root->left = invertTree(root->left);
        root->right = invertTree(root->right);
    }
    return root;
}

int main()
{
    return 0;
}
