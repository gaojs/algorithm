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
        return; // ��������
    } else if (a == NULL || size == 0) {
        *root = NULL;
        return; // ��������
    } else { // ���� ������
        struct TreeNode* n = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        if (n == NULL) { // �ڴ�����ʧ��
            *root = NULL;
            return;
        } else {
#define MAX_NODE_COUNT 100 // ��Ϊ�㹻����
            struct TreeNode *que[MAX_NODE_COUNT] = { 0 };
            int head = 0, tail = 0; // ģ�����
            int i = 0; // ����
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
                            if (n == NULL) { // �ڴ�����ʧ��
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
                            if (n == NULL) { // �ڴ�����ʧ��
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
    TYPE_JIN = 0, // ˮ��
    TYPE_HUA = 1, // ��̳
    TYPE_SHU = 2, // ����
    TYPE_CHI = 3, // ˮ��
    TYPE_HUA_NO = -1, // ����Խ���Ļ�̳
    TYPE_SHU_NO = -2, // ����Խ���ĵ���
};

// ˼·����: �ȱ�����������ת��������ͼ��
// ��������ˮ�������ŵ�һ��ˮ�����б��У�Ȼ�󣬹�ȱ�����������ˮ�ܳ��ȣ���
// �ٽ��ܷ��ʵ�ˮ�أ�Ҳ�ŵ�һ���б��У��ٹ�ȱ���ˮ����ˮ�أ�����Ϊ2����
// �ø������飬��ǳ����б�ˮ����ˮ�ؽ����Ļ���ͳ�Ƴ�������
// �����б�����飬��ö���Ԫ�ز����ظ���set��

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
