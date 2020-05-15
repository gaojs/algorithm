#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "securec.h"
#define scanf_s scanf

// �������磬��ڵ��ΪS��·���������ǵ����������
struct node {
    int id; // ��ʶ
    int value; // ����
    int childNum; // �ӽڵ���
    struct node **childs; // �ӽڵ�
};

int result[100][100] = { 0 };
int count = 0;

void dfs(struct node **graph, int n, struct node **route, int k, int s)
{
    if (graph == NULL || n <= 0 || route == NULL || k <= 0 || s <= 0) {
        printf("param==null");
        return; // ��������
    }
    struct node *curr = route[k - 1]; // ��ǰ�ڵ�
    if (curr == NULL) {
        printf("curr==null\n");
        return;
    }
    //printf("id=%d, v=%d, k=%d\n", curr->id, curr->value, k);
    if (curr->childNum == 0 || curr->childs == NULL) { // ��Ҷ�ӽڵ�
        int sum = 0;
        for (int i = 0; i < k; i++) {
            sum += route[i]->value;
        }
        //printf("sum=%d\n", sum);
        if (sum == s) { // ����Ҫ��
            for (int i = 0; i < k; i++) {
                //printf("%d ", route[i]->value);
                result[count][i] = route[i]->value;
            }
            //printf("\n");*/
            count++;
        }
    } else { // ��Ҷ�ӽڵ�
        int num = curr->childNum;
        //printf("num=%d\n", num);
        for (int i = 0; i < num; i++) {
            //printf("i=%d\n", i);
            route[k] = curr->childs[i];
            dfs(graph, n, route, k + 1, s);
            route[k] = NULL; // ����
        }
    }
}

int cmp(const void *a, const void *b)
{
    int *a1 = (int *)a;
    int *b1 = (int *)b;
    for (int i = 0; a1[i] && b1[i]; i++) {
        if (a1[i] > b1[i]) {
            return -1;
        } else if (a1[i] < b1[i]) {
            return 1;
        }
    }
    return 0;
}

// graphͼ��route·�����飬n�ڵ�����k·�����ȣ�sĿ������
void VisitGraph(struct node **graph, int n, int s)
{
    if (graph == NULL || n <= 0 || s <= 0) {
        return; // ��������
    }
    struct node *route[n]; // ·������
    int size = sizeof(struct node*) * n;
    memset(route, 0, size);
    route[0] = graph[0];
    memset(result, 0, sizeof(result));
    count = 0;
    dfs(graph, n, route, 1, s);
    qsort(result, count, sizeof(result[0]), cmp);
    for (int i = 0; i < count; i++) {
        for (int j = 0; result[i][j]; j++) {
            if (j == 0) {
                printf("%d", result[i][j]);
            } else {
                printf(" %d", result[i][j]);
            }
        }
        printf("\n");
    }
}

void FreeGraph(struct node **graph, int n)
{
    if (graph == NULL || n == 0) {
        return;
    }
    for (int i = 0; i < n; i++) {
        if (graph[i] == NULL) {
            continue;
        }
        // printf("%d %d: ", graph[i]->id, graph[i]->childNum);
        if (graph[i]->childs != NULL) {
            for (int j = 0; j < graph[i]->childNum; j++) {
                // printf("(%d,%d)%d ", i,j,graph[i]->childs[j]->id);
            }
            free(graph[i]->childs);
            graph[i]->childs = NULL;
        }
        // printf("\n");
        free(graph[i]);
        graph[i] = NULL;
    }
}

/* �밴���ֻ����麯����������ߵ�Ȧ���Ӷ� */
int main(void)
{
    int n, m, s; // �ڵ�������Ҷ�ӽڵ�����������
    if (scanf_s("%d %d %d", &n, &m, &s) != 3) {
        return -1;
    }
    // printf("%d, %d, %d\n", n, m, s);
    struct node *graph[n]; // ָ������
    int size = sizeof(struct node*) * n;
    memset(graph, 0, size);

    int i;
    for (i = 0; i < n; i++) { // �ڵ������
        graph[i] = (struct node *)malloc(sizeof(struct node));
        if (graph[i] == NULL) {  // �ڴ�����ʧ��
            FreeGraph(graph, n); // �ͷ��ڴ�
            return -1;
        }
        memset(graph[i], 0, sizeof(struct node));
        if (scanf_s("%d", &graph[i]->value) != 1) {
            FreeGraph(graph, n); // �ͷ��ڴ�
            return -1;
        }
        // printf("%d ", graph[i]->value);
        graph[i]->id = i;
        // printf("%d ", graph[i]->id);
    }

    int parent, child;
    int childCnt;
    int j;
    for (i = 0; i < m; i++) { // �ڵ�Ĺ�ϵ
        if (scanf_s("%d %d", &parent, &childCnt) != 2) {
            FreeGraph(graph, n); // �ͷ��ڴ�
            return -1;
        }
        // printf("%d %d :", parent, childCnt);
        graph[parent]->childNum = childCnt;
        int size = sizeof(struct node*) * childCnt;
        graph[parent]->childs = (struct node **)malloc(size);
        if (graph[parent]->childs == NULL) { // �ڴ�����ʧ��
            FreeGraph(graph, n); // �ͷ��ڴ�
            return -1;
        }
        memset(graph[parent]->childs, 0, size);
        for (j = 0; j < childCnt; j++) {
            if (scanf_s("%d", &child) != 1) {
                FreeGraph(graph, n); // �ͷ��ڴ�
                return -1;
            }
            graph[parent]->childs[j] = graph[child];
            // printf("%d ", child);
        }
        // printf("\n");
    }
    VisitGraph(graph, n, s);
    FreeGraph(graph, n);
    return 0;
}

