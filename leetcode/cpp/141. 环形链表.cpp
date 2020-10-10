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
        p = p->next; //慢
        q = q->next; //快
        if (q == nullptr) {
            return false;
        } else {
            q = q->next; //快
        }
        if (p == q) { //追上了
            return true;
        }
    }
    return false;
}

int main()
{
}