#include <securec.h>
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right; 
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
        return nullptr; // Խ����
    } else {
        int i = 0;
        int val = a[i++];
        TreeNode* root = new TreeNode(val);
        queue <TreeNode*> q;
        q.push(root);
        while (q.size() > 0) {
            TreeNode *t = q.front();
            q.pop(); // ��ջ
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
{
    if (root == nullptr) {
        return 0;
    } else {
        int left = height(root->left);
        int right = height(root->right);
        int t = (left > right) ? left : right;
        return (t + 1);
    }
}

int diameterOfBinaryTree(TreeNode* root)
{
    if (root == nullptr) {
        return 0;
    } else {
        int left = height(root->left);
        int right = height(root->right);
        int t = left + right;
        int lt = diameterOfBinaryTree(root->left);
        int rt = diameterOfBinaryTree(root->right);
        int tt = (lt > rt) ? lt : rt;
        return (t > tt) ? t : tt;
    }
}

int main()
{
    vector<int> a = { 1, 2, 3, 4, 5}; // 3
    TreeNode* root = CreateTree(a);
    cout << diameterOfBinaryTree(root);
    /*******************
    cout << "PreOrder: ";
    PreOrder(root); // ����
    cout << endl << "InOrder: ";
    InOrder(root); // ����
    cout << endl << "PostOrder: ";
    PostOrder(root); // ����
    DestroyTree(root);*/
    return 0;
}
