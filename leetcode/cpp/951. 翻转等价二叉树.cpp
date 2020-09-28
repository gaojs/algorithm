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

bool flipEquiv(TreeNode* root1, TreeNode* root2)
{
    if (root1 == nullptr && root2 == nullptr) {
        return true;
    } else if (root1 == nullptr || root2 == nullptr) {
        return false;
    } else if (root1->val != root2->val) {
        return false;
    } else {
        if (!flipEquiv(root1->left, root2->right)
            && !flipEquiv(root1->left, root2->left)) {
            return false;
        }
        if (!flipEquiv(root1->right, root2->right)
            && !flipEquiv(root1->right, root2->left)) {
            return false;
        }
        return true;
    }
}

int main()
{
    
    vector<int> a = { 1, 2, 3, 4, 5, 6, INT_MIN, INT_MIN, INT_MIN, 7, 8 };
    vector<int> a2 = { 1, 3, 2, INT_MIN, 6, 4, 5, INT_MIN, INT_MIN, INT_MIN, INT_MIN, 8, 7 };
    TreeNode* root = CreateTree(a);
    TreeNode* root2 = CreateTree(a2);
    cout << flipEquiv(root, root2) << endl;
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
