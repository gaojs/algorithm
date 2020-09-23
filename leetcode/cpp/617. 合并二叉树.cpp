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

TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2)
{
    if (t1 == nullptr && t2 == nullptr) {
        return nullptr;
    } else {
        TreeNode* t = new TreeNode();
        if (t1 != nullptr && t2 != nullptr) {
            t->val = t1->val + t2->val;
            t->left = mergeTrees(t1->left, t2->left);
            t->right = mergeTrees(t1->right, t2->right);
        } else if (t1 != nullptr) {
            t->val = t1->val;
            t->left = mergeTrees(t1->left, nullptr);
            t->right = mergeTrees(t1->right, nullptr);
        } else { // if(t2 != nullptr) {
            t->val = t2->val;
            t->left = mergeTrees(nullptr, t2->left);
            t->right = mergeTrees(nullptr, t2->right);
        }
        return t;
    }
}

int main()
{
    return 0;
}
