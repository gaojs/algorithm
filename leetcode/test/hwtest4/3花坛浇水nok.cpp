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

void createTree(struct TreeNode **root, int *a, int size)
{
    if (root == NULL) {
        return; // 参数有误
    } else if (a == NULL || size == 0) {
        *root = NULL;
        return; // 参数有误
    } else { // 创建 二叉树
        struct TreeNode* n = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        if (n == NULL) { // 内存申请失败
            *root = NULL;
            return;
        } else {
#define MAX_NODE_COUNT 100 // 认为足够大了
            struct TreeNode *que[MAX_NODE_COUNT] = { 0 };
            int head = 0, tail = 0; // 模拟队列
            int i = 0; // 索引
            n->val = a[i++];
            n->left = NULL;
            n->right = NULL;
            *root = n;
            que[tail++] = n;
            while (head < tail) {
                struct TreeNode *p = que[head++];
                if (p != NULL) {
                    printf("%d,", p->val);
                    if (i < size) {
                        int v = a[i++];
                        if (v != INT_MIN) {
                            n = (struct TreeNode*)malloc(sizeof(struct TreeNode));
                            if (n == NULL) { // 内存申请失败
                                return;
                            } else {
                                n->val = v;
                                n->left = NULL;
                                n->right = NULL;
                            }
                            p->left = n;
                            que[tail++] = n;
                        }
                    }
                    if (i < size) {
                        int v = a[i++];
                        if (v != INT_MIN) {
                            n = (struct TreeNode*)malloc(sizeof(struct TreeNode));
                            if (n == NULL) { // 内存申请失败
                                return;
                            } else {
                                n->val = v;
                                n->left = NULL;
                                n->right = NULL;
                            }
                            p->right = n;
                            que[tail++] = n;
                        }
                    }
                }
            }
            return;
        }
    }
}

enum {
    TYPE_JIN = 0, // 水井
    TYPE_HUA = 1, // 花坛
    TYPE_SHU = 2, // 雕塑
    TYPE_CHI = 3, // 水池
    TYPE_HUA_NO = -1, // 不可越过的花坛
    TYPE_SHU_NO = -2, // 不可越过的雕塑
};

// 思路有了: 先遍历树，将树转换成无向图，
// 并将所有水井，都放到一个水井的列表中，然后，广度遍历它（依据水管长度）。
// 再将能访问的水池，也放到一个列表中，再广度遍历水井和水池（长度为2）。
// 用辅助数组，标记出所有被水井和水池浇过的花，统计出个数。
// 以上列表和数组，最好都用元素不可重复的set。

int WateringFlowers(const TreeNode* root, int len)
{
    if (root == nullptr || len < 0) {
        return 0;
    }
    int cnt = 0;
    switch (root->val) {
        case TYPE_JIN:
            break;
        case TYPE_HUA:
            break;
        case TYPE_SHU:
            break;
        case TYPE_CHI:
            break;
        case TYPE_HUA_NO:
            break;
        case TYPE_SHU_NO:
            break;
        default:
            return 0;
    }
    return cnt;
}

int main()
{
    int a[] = { 1,0,3,2,-1,-2,1,INT_MIN,INT_MIN, INT_MIN,INT_MIN,2,INT_MIN,INT_MIN,1 };
    int size = sizeof(a) / sizeof(a[0]), len = 3;
    struct TreeNode *root = NULL;
    createTree(&root, a, size);
    cout << WateringFlowers(root, len);
    int a2[] = { 0,-1,1,0,INT_MIN,1,-2,1,2,INT_MIN, INT_MIN,3,INT_MIN,INT_MIN,INT_MIN,1,-1,-1, 1 };
    int size2 = sizeof(a) / sizeof(a[0]), len2 = 3;
    struct TreeNode *root2 = NULL;
    createTree(&root2, a2, size2);
    cout << WateringFlowers(root2, len2);
    return 0;
}
