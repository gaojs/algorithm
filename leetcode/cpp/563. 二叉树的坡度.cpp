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

int sum(TreeNode* root)
{ // �����нڵ�ĺ�
    if (root != nullptr) {
        int t = root->val;
        t += sum(root->left);
        t += sum(root->right);
        return t;
    }
    return 0;
}

int findTilt(TreeNode* root)
{ // ���¶�
    if (root != nullptr) {
        int left = sum(root->left);
        int right = sum(root->right);
        int t = abs(left - right);
        t += findTilt(root->left);
        t += findTilt(root->right);
        return t;
    }
    return 0;
}

int main()
{
    // vector<int> a = { 1, 2, 3 }; // 1
    vector<int> a = { 1, 2, 3, 4, INT_MIN, 5}; // 11
    TreeNode* root = CreateTree(a);
    cout << findTilt(root) << endl;
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
