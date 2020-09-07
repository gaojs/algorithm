#include <bits/stdc++.h>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr)
    {
    }
    ListNode(int x) : val(x), next(nullptr)
    {
    }
    ListNode(int x, ListNode *next) : val(x), next(next)
    {
    }
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
    if (l1 == nullptr && l2 == nullptr) {
        return nullptr;
    } else if (l1 == nullptr) {
        return l2;
    } else if (l2 == nullptr) {
        return l1;
    } else {
        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        if (l1->val <= l2->val) {
            head = tail = l1;
            l1 = l1->next;
        } else {
            head = tail = l2;
            l2 = l2->next;
        }
        while (l1 != nullptr && l2 != nullptr) {
            ListNode* p = nullptr;
            if (l1->val <= l2->val) {
                p = l1;
                l1 = l1->next;
            } else {
                p = l2;
                l2 = l2->next;
            }
            tail->next = p;
            tail = p;
        }
        if (l1 != nullptr) {
            tail->next = l1;
        }
        if (l2 != nullptr) {
            tail->next = l2;
        }
        return head;
    }
}

int main()
{
    return 0;
}
