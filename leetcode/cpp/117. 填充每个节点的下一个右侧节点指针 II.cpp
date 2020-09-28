#include <securec.h>
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL)
    {
    }

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL)
    {
    }

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next)
    {
    }
};

void InOrder(Node* root)
{
    if (root != nullptr) {
        InOrder(root->left);
        cout << root->val << ",";
        InOrder(root->right);
    }
}

void PreOrder(Node* root)
{
    if (root != nullptr) {
        cout << root->val << ",";
        PreOrder(root->left);
        PreOrder(root->right);
    }
}

void PostOrder(Node* root)
{
    if (root != nullptr) {
        PostOrder(root->left);
        PostOrder(root->right);
        cout << root->val << ",";
    }
}

void DestroyTree(Node* root)
{
    if (root != nullptr) {
        DestroyTree(root->left);
        DestroyTree(root->right);
        delete root;
    }
}

Node* CreateTree(vector<int> &a)
{
    if (a.size() <= 0) {
        return nullptr; // 越界了
    } else {
        int i = 0;
        int val = a[i++];
        Node* root = new Node(val);
        queue <Node*> q;
        q.push(root);
        while (q.size() > 0) {
            Node *t = q.front();
            q.pop(); // 出栈
            if (t == nullptr) {
                continue;
            }
            if (i < a.size()) {
                int val = a[i++];
                if (val != INT_MIN) {
                    t->left = new Node(val);
                    q.push(t->left);
                }
            }
            if (i < a.size()) {
                int val = a[i++];
                if (val != INT_MIN) {
                    t->right = new Node(val);
                    q.push(t->right);
                }
            }
        }
        return root;
    }
}

void level(queue <Node*> &q)
{
    if (q.size() > 0) {
        queue <Node*> qq;
        Node* pre = nullptr;
        while (q.size() > 0) {
            Node* p = q.front();
            q.pop(); // 出栈
            if (p->left != nullptr) {
                qq.push(p->left);
            }
            if (p->right != nullptr) {
                qq.push(p->right);
            }
            if (pre != nullptr) {
                pre->next = p;
            }
            pre = p;
        }
        // 递归下一层
        level(qq);
    }
}

Node* connect(Node* root)
{ // 分层遍历
    if (root != nullptr) {
        queue <Node*> q;
        q.push(root);
        level(q);
    }
    return root;
}

void next(Node* root)
{
    if (root != nullptr) {
        cout << root->val<<"-";
        if (root->next != nullptr) {
            cout << root->next->val;
        } else {
            cout << "#";
        }
        cout << ",";
        next(root->left);
        next(root->right);
    }
}

int main()
{
    vector<int> a = { 1, 2, 3, 4, 5, INT_MIN, 7 }; // 11
    Node* root = CreateTree(a);
    root = connect(root);
    next(root);
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
