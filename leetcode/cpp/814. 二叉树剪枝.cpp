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

bool includeOne(TreeNode* root)
{
    if (root != nullptr) {
        if (includeOne(root->left)) {
            return true; // ����������1
        }
        if (includeOne(root->right)) {
            return true; // ����������1
        }
        if (root->val != 0) {
            return true; // ���ڵ㺬��1
        }
    }
    return false;
}

TreeNode* pruneTree(TreeNode* root)
{
    if (root != nullptr) {
        if (!includeOne(root)) {
            root = nullptr;
        } else {
            root->left = pruneTree(root->left);
            root->right = pruneTree(root->right);
        }
    }
    return root;
}

int main()
{
    vector<int> a = { 0, 1, 1, INT_MIN, 1, 1, 0, 0, 1, INT_MIN, 1, 1 };
    TreeNode* root = CreateTree(a);
    root = pruneTree(root);
    /********************/
    cout << "PreOrder: ";
    PreOrder(root); // ����
    cout << endl << "InOrder: ";
    InOrder(root); // ����
    cout << endl << "PostOrder: ";
    PostOrder(root); // ����
    DestroyTree(root);
    return 0;
}
