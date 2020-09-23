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

TreeNode* dfs(TreeNode* root, int &sum)
{
    if (root != nullptr) {
        dfs(root->right, sum);
        sum += root->val;
        root->val = sum;
        dfs(root->left, sum);
        return root;
    }
    return nullptr;
}

TreeNode* convertBST(TreeNode* root)
{
    int sum = 0;
    return dfs(root, sum);
}

int main()
{
    return 0;
}
