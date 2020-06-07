#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "securec.h"
#define scanf_s scanf

// 树形网络，求节点和为S的路径，并按非递增序列输出
struct node {
    int id; // 标识
    int value; // 容量
    int childNum; // 子节点数
    struct node **childs; // 子节点
};

int result[100][100] = { 0 };
int count = 0;

void dfs(struct node **graph, int n, struct node **route, int k, int s)
{
    if (graph == NULL || n <= 0 || route == NULL || k <= 0 || s <= 0) {
        printf("param==null");
        return; // 参数错误
    }
    struct node *curr = route[k - 1]; // 当前节点
    if (curr == NULL) {
        printf("curr==null\n");
        return;
    }
    //printf("id=%d, v=%d, k=%d\n", curr->id, curr->value, k);
    if (curr->childNum == 0 || curr->childs == NULL) { // 到叶子节点
        int sum = 0;
        for (int i = 0; i < k; i++) {
            sum += route[i]->value;
        }
        //printf("sum=%d\n", sum);
        if (sum == s) { // 符合要求
            for (int i = 0; i < k; i++) {
                //printf("%d ", route[i]->value);
                result[count][i] = route[i]->value;
            }
            //printf("\n");*/
            count++;
        }
    } else { // 非叶子节点
        int num = curr->childNum;
        //printf("num=%d\n", num);
        for (int i = 0; i < num; i++) {
            //printf("i=%d\n", i);
            route[k] = curr->childs[i];
            dfs(graph, n, route, k + 1, s);
            route[k] = NULL; // 回溯
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

// graph图，route路径数组，n节点数，k路径长度，s目标容量
void VisitGraph(struct node **graph, int n, int s)
{
    if (graph == NULL || n <= 0 || s <= 0) {
        return; // 参数错误
    }
    struct node *route[n]; // 路由数组
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

/* 请按需拆分或重组函数，避免过高的圈复杂度 */
int main(void)
{
    int n, m, s; // 节点数，非叶子节点数，总容量
    if (scanf_s("%d %d %d", &n, &m, &s) != 3) {
        return -1;
    }
    // printf("%d, %d, %d\n", n, m, s);
    struct node *graph[n]; // 指针数组
    int size = sizeof(struct node*) * n;
    memset(graph, 0, size);

    int i;
    for (i = 0; i < n; i++) { // 节点的容量
        graph[i] = (struct node *)malloc(sizeof(struct node));
        if (graph[i] == NULL) {  // 内存申请失败
            FreeGraph(graph, n); // 释放内存
            return -1;
        }
        memset(graph[i], 0, sizeof(struct node));
        if (scanf_s("%d", &graph[i]->value) != 1) {
            FreeGraph(graph, n); // 释放内存
            return -1;
        }
        // printf("%d ", graph[i]->value);
        graph[i]->id = i;
        // printf("%d ", graph[i]->id);
    }

    int parent, child;
    int childCnt;
    int j;
    for (i = 0; i < m; i++) { // 节点的关系
        if (scanf_s("%d %d", &parent, &childCnt) != 2) {
            FreeGraph(graph, n); // 释放内存
            return -1;
        }
        // printf("%d %d :", parent, childCnt);
        graph[parent]->childNum = childCnt;
        int size = sizeof(struct node*) * childCnt;
        graph[parent]->childs = (struct node **)malloc(size);
        if (graph[parent]->childs == NULL) { // 内存申请失败
            FreeGraph(graph, n); // 释放内存
            return -1;
        }
        memset(graph[parent]->childs, 0, size);
        for (j = 0; j < childCnt; j++) {
            if (scanf_s("%d", &child) != 1) {
                FreeGraph(graph, n); // 释放内存
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

