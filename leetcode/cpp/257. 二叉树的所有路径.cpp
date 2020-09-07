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
    if (root != NULL) { // 非空才需要处理，这点也非常关键
        string path(str); // 这里对str做复制了，利用了程序的堆栈
        path.append(to_string(root->val)); // to_string()用的非常好
        if (root->left == NULL && root->right == NULL) {
            paths.push_back(path); // 无子节点了，是条路径
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
