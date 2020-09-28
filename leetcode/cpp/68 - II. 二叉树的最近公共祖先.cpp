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

bool PreOrderVisit(TreeNode* root, TreeNode* p, vector<TreeNode*> &v)
{
    if (root != nullptr && p != nullptr) {
        if (root == p) {
            v.push_back(root);
            return true;
        } else {
            v.push_back(root);
            if (PreOrderVisit(root->left, p, v)) {
                return true;
            }
            if (PreOrderVisit(root->right, p, v)) {
                return true;
            }
            v.pop_back();
        }
    }
    return false;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
    vector<TreeNode*> vp, vq;
    PreOrderVisit(root, p, vp);
    PreOrderVisit(root, q, vq);
    TreeNode* pq = nullptr;
    for (int i = 0; i < vp.size() && i < vq.size(); i++) {
        if (vp[i] == vq[i]) {
            pq = vp[i];
        } else {
            break;
        }
    }
    return pq;
}

TreeNode* PreOrderFind(TreeNode* root, int val)
{
    if (root != nullptr) {
        if (root->val == val) {
            return root;
        } else {
            TreeNode* left = PreOrderFind(root->left, val);
            if (left != nullptr) {
                return left;
            }
            return PreOrderFind(root->right, val);
        }
    }
    return nullptr;
}

int main()
{
    
    vector<int> a = { 3, 5, 1, 6, 2, 0, 8, INT_MIN, INT_MIN, 7, 4 };
    TreeNode* root = CreateTree(a);
    TreeNode* p = PreOrderFind(root, 5);
    TreeNode* q = PreOrderFind(root, 4);
    TreeNode* pq = lowestCommonAncestor(root, p, q);
    if (pq != nullptr) {
            cout << pq->val;
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