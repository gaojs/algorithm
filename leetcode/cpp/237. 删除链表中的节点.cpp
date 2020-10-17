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

void deleteNode(ListNode* node)
{
    if (node->next != nullptr) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
}

int main()
{
    return 0;
}