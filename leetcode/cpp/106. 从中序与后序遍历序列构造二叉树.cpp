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

TreeNode* buildTree(vector<int>& io, vector<int>& po)
{
    if (io.size() <= 0 || po.size() <= 0) {
        return nullptr;
    } else {
        int val = *(po.rbegin()); // 取后序遍历的最后一个元素
        vector<int>::iterator pos = find(io.begin(), io.end(), val);
        vector<int> ioLeft(io.begin(), pos), ioRight(pos + 1, io.end());
        pos = po.begin() + ioLeft.size(); // 中序和后序的数量相等，所以相加
        vector<int> poLeft(po.begin(), pos), poRight(pos, po.end() - 1);
        TreeNode *root = new TreeNode(val); // 当前节点的值
        root->left = buildTree(ioLeft, poLeft); // 左子树
        root->right = buildTree(ioRight, poRight); // 右子树
        return root;
    }
}

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
        PreOrder(root->left);
        PreOrder(root->right);
        cout << root->val << ",";
    }
}

void Destroy(TreeNode* root)
{
    if (root != nullptr) {
        Destroy(root->left);
        Destroy(root->right);
        delete root;
    }
}

int main()
{
    vector<int>inorder = { 9, 3, 15, 20, 7 };
    vector<int>postorder = { 9, 15, 7, 20, 3 };
    TreeNode* root = buildTree(inorder, postorder);
    cout << "PreOrder: ";
    PreOrder(root); // 先序
    cout << endl << "InOrder: ";
    InOrder(root); // 中序
    cout << endl << "PostOrder: ";
    PostOrder(root); // 后序
    Destroy(root);
    return 0;
}
