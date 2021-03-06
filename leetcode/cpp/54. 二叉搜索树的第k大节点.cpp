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

void InOrderVisit(TreeNode* root, vector<int> &a)
{
    if (root != nullptr) {
        InOrderVisit(root->left, a);
        a.push_back(root->val);
        InOrderVisit(root->right, a);
    }
}

int kthLargest(TreeNode* root, int k)
{
    vector<int> a;
    InOrderVisit(root, a);
    int n = a.size();
    if (k >= 1 && k <= n) {
        return a[n - k];
    }
    return 0;
}

int main()
{

    vector<int> a = { 3, 1, 4, INT_MIN, 2 };
    TreeNode* root = CreateTree(a);
    cout << kthLargest(root, 1) << endl;
    vector<int> a2 = { 5, 3, 6, 2, 4, INT_MIN, INT_MIN, 1 };
    TreeNode* root2 = CreateTree(a2);
    cout << kthLargest(root2, 3) << endl;
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