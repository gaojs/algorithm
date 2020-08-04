#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    int appendNode(ListNode* &head, ListNode* &tail, int val) {
        if (head == NULL) {
            head = tail = new ListNode(val % 10);
        } else {
            tail->next = new ListNode(val % 10);
            tail = tail->next;            
        }
        return val / 10; // 返回进位 
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = NULL, *tail = NULL;        
        int carry = 0; // 处理进位 
        while (l1 != NULL && l2 != NULL) {
            int t = l1->val + l2->val + carry;
            carry = appendNode(head, tail, t);
            l1 = l1->next;
            l2 = l2->next;
        }           
        while (l1 != NULL) {
            int t = l1->val + carry;
            carry = appendNode(head, tail, t);
            l1 = l1->next;
        }           
        while (l2 != NULL) {
            int t = l2->val + carry;
            carry = appendNode(head, tail, t);
            l2 = l2->next;
        }
        if (carry > 0) { // 有进位     
            appendNode(head, tail, carry);
        }
        return head;
    }
};

ListNode* createList(vector<int>a) {
    ListNode* head = NULL;
    for (int i: a) {
        ListNode* p = new ListNode(i);
        p->next = head;
        head = p;
    }
    return head;
}

void destroyList(ListNode*head) {
    while (head != NULL) {
        ListNode* p = head;
        head = head->next;
        delete p;
    }   
}

int main () 
{
    vector<int>a = {3,4,2};
    vector<int>b = {4,6,5};
    Solution s;
    ListNode* a2 = createList(a);
    ListNode* b2 = createList(b);
    ListNode* sum = s.addTwoNumbers(a2, b2);
    while (sum != NULL) {
        ListNode* p = sum;
        sum = sum->next;
        cout<<p->val;
        delete p;
    }       
    destroyList(a2);
    destroyList(b2);
} 
    
