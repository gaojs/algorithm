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

void InOrder(TreeNode* root)
{
    if (root != nullptr) {
        InOrder(root->left);
        cout << root->val << ",";
        InOrder(root->right);
    }
}

void PreOrder(TreeNode* root)
{
    if (root != nullptr) {
        cout << root->val << ",";
        PreOrder(root->left);
        PreOrder(root->right);
    }
}

void PostOrder(TreeNode* root)
{
    if (root != nullptr) {
        PostOrder(root->left);
        PostOrder(root->right);
        cout << root->val << ",";
    }
}

void DestroyTree(TreeNode* root)
{
    if (root != nullptr) {
        DestroyTree(root->left);
        DestroyTree(root->right);
        delete root;
    }
}

TreeNode* CreateTree(vector<int> &a)
{
    if (a.size() <= 0) {
        return nullptr; // 越界了
    } else {
        int i = 0;
        int val = a[i++];
        TreeNode* root = new TreeNode(val);
        queue <TreeNode*> q;
        q.push(root);
        while (q.size() > 0) {
            TreeNode *t = q.front();
            q.pop(); // 出栈
            if (t == nullptr) {
                continue;
            }
            if (i < a.size()) {
                int val = a[i++];
                if (val != INT_MIN) {
                    t->left = new TreeNode(val);
                    q.push(t->left);
                } 
            }
            if (i < a.size()) {
                int val = a[i++];
                if (val != INT_MIN) {
                    t->right = new TreeNode(val);
                    q.push(t->right);
                }
            }
        }
        return root;
    }
}

int height(TreeNode* root)
{ // 求树的高度
    if (root == nullptr) {
        return 0;
    } else {
        int left = height(root->left);
        int right = height(root->right);
        int h = left > right ? left : right;
        return h + 1;
    }
}

bool isBalanced(TreeNode* root)
{
    if (root == nullptr) {
        return true;
    } else {
        if (!isBalanced(root->left)) {
            return false; // 左子树不平衡
        }
        else if (!isBalanced(root->right)) {
            return false; // 右子树不平衡
        } else {
            int left = height(root->left);
            int right = height(root->right);
            if (left > right + 1 || right > left + 1) {
                return false;  // 左右子树不平衡
            }
        }
        return true;
    }
}

int main()
{
    
    vector<int> a = { 3, 9, 20, INT_MIN, INT_MIN, 15, 7 };
    TreeNode* root = CreateTree(a);
    cout << isBalanced(root) << endl;
    
    vector<int> a2 = { 1, 2, 2, 3, 3, INT_MIN, INT_MIN, 4, 4 };
    TreeNode* root2 = CreateTree(a2);
    cout << isBalanced(root2) << endl;
    /*******************
    cout << "PreOrder: ";
    PreOrder(root); // 先序
    cout << endl << "InOrder: ";
    InOrder(root); // 中序
    cout << endl << "PostOrder: ";
    PostOrder(root); // 后序
    DestroyTree(root);*/
    return 0;
}
