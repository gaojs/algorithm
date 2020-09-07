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

void dfs(TreeNode* root, string str, vector<string> &paths)
{
    if (root != NULL) { // �ǿղ���Ҫ�������Ҳ�ǳ��ؼ�
        string path(str); // �����str�������ˣ������˳���Ķ�ջ
        path.append(to_string(root->val)); // to_string()�õķǳ���
        if (root->left == NULL && root->right == NULL) {
            paths.push_back(path); // ���ӽڵ��ˣ�����·��
        } else {
            path.append("->");
            dfs(root->left, path, paths);
            dfs(root->right, path, paths);
        }
    }
}

vector<string> binaryTreePaths(TreeNode* root)
{
    vector<string> paths;
    dfs(root, "", paths);
    return paths;
}

int main()
{
    return 0;
}
