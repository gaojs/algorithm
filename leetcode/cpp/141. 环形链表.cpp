#include <securec.h>
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL)
    {
    }
};

bool hasCycle(ListNode *head)
{
    ListNode *p = head;
    ListNode *q = head;
    while (p != nullptr && q != nullptr) {
        p = p->next; //��
        q = q->next; //��
        if (q == nullptr) {
            return false;
        } else {
            q = q->next; //��
        }
        if (p == q) { //׷����
            return true;
        }
    }
    return false;
}

int main()
{
}