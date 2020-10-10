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

ListNode *detectCycle(ListNode *head)
{
    set<ListNode *>q;
    for (ListNode *p = head; p != nullptr; p = p->next) {
        if (q.find(p) != q.end()) {
            return p;
        } else {
            q.insert(p);
        }
    }
    return nullptr;
}

ListNode *createList(vector<int> &a, int pos)
{
    ListNode *head, *tail, *p;

    head = tail = p = nullptr;
    for (int i = 0; i < a.size(); i++) {
        ListNode *q = new ListNode(a[i]);
        if (head == nullptr) {
            head = tail = q;
        } else {
            tail->next = q;
            tail = q;
        }
        if (pos == i) {
            p = q;
        }
    }
    tail->next = p;
    return head;
}

int main()
{
    vector<int> a = { 3, 2, 0, -4 };

    ListNode *root = createList(a, 1);
    ListNode *p = detectCycle(root);
    if (p != nullptr) {
        cout << p->val;
    } else {
        cout << -1;
    }
}
