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


TreeNode* PreOrderFind(TreeNode* root, int val)
{
    if (root != nullptr) {
        if (root->val == val) {
            return root;
        }
        TreeNode* left = PreOrderFind(root->left, val);
        if (left != nullptr) {
            return left;
        }
        TreeNode* right = PreOrderFind(root->right, val);
        if (right != nullptr) {
            return right;
        }
    }
    return nullptr;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
    while (true) {
        if (p->val < root->val && q->val < root->val) {
            root = root->left; // 在左子树上
        } else if (p->val > root->val && q->val > root->val) {
            root = root->right; // 在右子树上
        } else { // 就是它了
            break;
        }
    }
    return root;
}

int main()
{
    // int p = 2, q = 8; // 6
    int p = 0, q = 9; // 6
    vector<int> a = { 6, 2, 8, 0, 4, 7, 9, INT_MIN, INT_MIN, 3, 5};
    TreeNode* root = CreateTree(a);
    TreeNode* pNode = PreOrderFind(root, p);
    TreeNode* qNode = PreOrderFind(root, q);
    TreeNode* c = lowestCommonAncestor(root, pNode, qNode);
    if (c != nullptr) {
        cout << c->val;
    }
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
