#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <math.h>


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct TreeNode node_t;
#define MAX_NODE_COUNT 100000 // 足够大
node_t *que[MAX_NODE_COUNT] = { 0 };
int a[MAX_NODE_COUNT] = { 0 };

node_t *createTree(int *a, int size)
{
    if (a == NULL || size <= 0) {
        return NULL; // 参数有误
    } else { // 创建 二叉树
        node_t* root = (node_t*)malloc(sizeof(node_t));
        if (root == NULL) { // 内存申请失败
            return NULL;
        } else {
            memset(que, 0, sizeof(que));
            int head = 0, tail = 0; // 模拟队列
            int i = 0; // 索引
            root->val = a[i++];
            root->left = NULL;
            root->right = NULL;
            que[tail++] = root;
            while (head < tail) {
                node_t *p = que[head++];
                if (p != NULL) {
                    // printf("%d,", p->val);
                    if (i < size) {
                        int v = a[i++];
                        if (v != INT_MIN) {
                            node_t*n = (node_t*)malloc(sizeof(node_t));
                            if (n == NULL) { // 内存申请失败
                                return root;
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
                            node_t*n = (node_t*)malloc(sizeof(node_t));
                            if (n == NULL) { // 内存申请失败
                                return root;
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
            return root;
        }
    }
}

/** Decodes your encoded data to tree. */
node_t* deserialize(char* s)
{
    if (s == NULL || s[0] == 0) {
        return NULL;
    }
    int n = 0;
    int len = strlen(s);
    memset(a, 0, sizeof(a));
    for (int i = 0; i < len; i++) {
        if (isdigit(s[i]) || s[i] == '-' || s[i] == '+') {
            int sign = 1; // 正负号的标识
            if (s[i] == '-' || s[i] == '+') {
                sign = (s[i] == '-') ? -1 : 1;
                i++;
            }
            int num = 0;
            while (isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
                i++;
            }
            a[n++] = num * sign;
        } else { // null
            a[n++] = INT_MIN;
            while (isalpha(s[i])) {
                i++;
            }
        }
        if (n >= MAX_NODE_COUNT - 1) {
            printf("overflow");
        }
    }
    return createTree(a, n);
}

/** Encodes a tree to a single string. */
char* serialize(node_t* root)
{
    if (root == NULL) {
        return NULL;
    }
    int n = 0;
    int head = 0, tail = 0; // 模拟队列
    memset(que, 0, sizeof(que));
    memset(a, 0, sizeof(a));
    que[tail++] = root;
    while (head < tail) {
        node_t *p = que[head++];
        if (p == NULL) {
            a[n++] = INT_MIN;
        } else {
            a[n++] = p->val;
            que[tail++] = p->left;
            que[tail++] = p->right;
        }
    }
    while (n > 0 && a[n - 1] == INT_MIN) {
        a[n - 1] = 0;
        n--;
    }
    int size = n * sizeof("null,");
    char *s = (char*)malloc(size);
    if (s != NULL) {
        memset(s, 0, size);
        for (int i = 0; i < n; i++) {
            if (a[i] == INT_MIN) {
                strcat(s, "null,");
            } else {
                char t[30] = { 0 };
                sprintf(t, "%d,", a[i]);
                strcat(s, t);
            }
        }
        s[strlen(s) - 1] = 0;
        return s;
    }
    return NULL;
}

void freeTree(node_t* root)
{
    if (root == NULL) {
        return;
    } else { // 后根 销毁
        freeTree(root->left);
        root->left = NULL;
        freeTree(root->right);
        root->right = NULL;
        free(root);
        root = NULL;
    }
}

void preOrderPrint(node_t* root)
{
    if (root == NULL) {
        return;
    } else { // 先根 遍历
        printf("%d,", root->val);
        preOrderPrint(root->left);
        preOrderPrint(root->right);
    }
}

void inOrderPrint(node_t* root)
{
    if (root == NULL) {
        return;
    } else { // 中根 遍历
        inOrderPrint(root->left);
        printf("%d,", root->val);
        inOrderPrint(root->right);
    }
}

void postOrderPrint(node_t* root)
{
    if (root == NULL) {
        return;
    } else { // 先根 遍历
        postOrderPrint(root->left);
        postOrderPrint(root->right);
        printf("%d,", root->val);
    }
}

int main()
{
    /*************************
    char a[] = "1,2,3,null,null,4,5";*/
    node_t *root = deserialize(a);
    /*************************
    printf("\nPreOrder:");
    preOrderPrint(root);
    printf("\nInOrder:");
    inOrderPrint(root);
    printf("\nPostOrder:");
    postOrderPrint(root);*/
    printf("%s", serialize(root));
    freeTree(root);
    root = NULL;
    return 0;
}

