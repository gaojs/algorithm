#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>

#define MAX_COUNT 100000 // �㹻����

int a[] = { 9,8,7,6,5,4,3,2,1 };

void swap(int *a, int *b)
{ // ��������Ԫ��
    int t = *a;
    *a = *b;
    *b = t;
}

bool HeadNodeAdjust(int *b, int n)
{ // �ѵķ�Ҷ�ӽڵ�ĵ���
    if (a == NULL || n < 0) {
        return false;
    }
    int k = n / 2 - 1; // ��Ҷ�ӽڵ�����λ��
    for (int i = k; i >= 0; i--) { // �������з�Ҷ�ӽڵ�
        int dad = i; // ��Ҷ�ӽڵ㣬�����ڵ�ı��
        while (dad <= k) { // ���ڵ㣬��Ȼ�Ƿ�Ҷ�ӽڵ�
            int son = dad * 2 + 1; // ���ӽڵ�ı��
            if (son + 1 < n && a[son] < a[son + 1]) {
                son = son + 1;  // ���ӽڵ����ѡ�ұ�
            }
            if (a[son] <= a[dad]) { // �ӽڵ㶼�Ƚ�С
                break; // �������³���
            }
            swap(&a[son], &a[dad]);
            dad = son;
        }
    }
    return true;
}

bool HeapSort(int *b, int n)
{ // �����򣬴󶥶ѣ���С����
    if (a == NULL || n < 0) {
        return false;
    }
    for (int i = n; i > 0; i--) {
        HeadNodeAdjust(a, i);
        swap(&a[0], &a[i - 1]);
    }
    return true;
}

/************************
int gd(int k, int w, int*p, int pn, int*c, int cn)
{
    if (k == 0 || w < 0 || p == NULL || pn <= 0 || c == NULL || cn <= 0) {
        return 0;
    }
    memset(visited, 0, sizeof(visited));
    for (; k > 0; k--) {
        int m = -1; // ������
        for (int i = 0; i < cn; i++) {
            if (!visited[i] && w >= c[i]) { // ��Ͷ��
                if (m == -1) {
                    m = i;
                } else if (p[m] < p[i]) {
                    m = i;
                }
            }
        }
        if (m != -1) { // �ҵ�
            w += p[m]; // ��������
            visited[m] = true;
        }
    }
    return w;
}

int findMaximizedCapital(int k, int w, int*p, int pn, int*c, int cn)
{
    if (k == 0 || w < 0 || p == NULL || pn <= 0 || c == NULL || cn <= 0) {
        return 0;
    }
    return gd(k, w, p, pn, c, cn);
}
*/

int main()
{
    /**********************************
    int k = 2, w = 0, p[] = { 1,2,3 }, c[] = { 0,1,1 };
    int pn = sizeof(p) / sizeof(p[0]);
    int cn = sizeof(p) / sizeof(p[0]);
    printf("%d", findMaximizedCapital(k, w, p, pn, c, cn));
    */

    //int a[6] = { 7, 3, 8, 5, 1, 2 };
    int n = sizeof(a) / sizeof(a[0]);
    HeapSort(a, n); // ������
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}


