#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
 
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	void appendNode(ListNode* &head, ListNode* &tail, int val) {
		if (head == NULL) {
			head = tail =  new ListNode(val);
		} else {
			tail->next = new ListNode(val);
			tail = tail->next;			
		}
	}
	
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* head = NULL, *tail = NULL;        
		while (l1 != NULL && l2 != NULL) {
			appendNode(head, tail, l1->val + l2->val);
			l1 = l1->next;
			l2 = l2->next;
		}   	    
		while (l1 != NULL) {
			appendNode(head, tail, l1->val);
			l1 = l1->next;
		}   	    
		while (l2 != NULL) {
			appendNode(head, tail, l2->val);
			l2 = l2->next;
		}
		int carry = 0; // 处理进位 
		for (ListNode *p = head; p != NULL; p = p->next) {
			int t = p->val + carry;
			p->val = t % 10;
			carry = t / 10;
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
    
