// https://leetcode-cn.com/problems/add-two-numbers/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){

    if (l1 == NULL && l2 == NULL) {
        return NULL;
    }    
    struct ListNode *head = NULL;
    struct ListNode *tail = NULL;
    struct ListNode *p = NULL;
    while (l1 != NULL && l2 != NULL) { // 处理加法
        p = (struct ListNode*)malloc(sizeof(struct ListNode));
        if (p == NULL) {
            return NULL;
        } else {
            p->next = NULL;
            p->val = l1->val + l2->val; // 加
            l1 = l1->next;
            l2 = l2->next;
            if (head == NULL) { // 设置头结点
                head = p;
                tail = p;
            } else { // 追加到链表最后
                tail->next = p;
                tail = p;
            }
        }        
    }
    while(l1 != NULL) { // 处理l1
        p = (struct ListNode*)malloc(sizeof(struct ListNode));
        if (p == NULL) {
            return NULL;
        } else {
            p->next = NULL;
            p->val = l1->val; // 加        
            l1 = l1->next;
            if (head == NULL) { // 设置头结点
                head = p;
                tail = p;
            } else { // 追加到链表最后
                tail->next = p;
                tail = p;
            }
        }        
    }
    while(l2 != NULL) { // 处理l2
        p = (struct ListNode*)malloc(sizeof(struct ListNode));
        if (p == NULL) {
            return NULL;
        } else {
            p->next = NULL;
            p->val = l2->val; // 加        
            l2 = l2->next;
            if (head == NULL) { // 设置头结点
                head = p;
                tail = p;
            } else { // 追加到链表最后
                tail->next = p;
                tail = p;
            }
        }        
    }
    int carry = 0;
    for (p = head; p != NULL; p=p->next) { // 处理进位
        int tmp = p->val + carry;
        p->val = tmp % 10;
        carry = tmp / 10;
    }
    if (carry > 0) { // 处理最后的进位
         p = (struct ListNode*)malloc(sizeof(struct ListNode));
        if (p == NULL) {
            return NULL;
        } else {
            p->next = NULL;
            p->val = carry;            
            if (head == NULL) { // 设置头结点
                head = p;
                tail = p;
            } else { // 追加到链表最后
                tail->next = p;
                tail = p;
            }
        }
    }
    return head;
}


struct ListNode *makeList(int *nums, int size) 
{
	struct ListNode *head = NULL; 
	for (int i = 0; i < size; i++) {
		struct ListNode *p = (struct ListNode *)malloc(sizeof(struct ListNode));
		p->val = nums[i];
		p->next = head;
		head = p;
	}
	return head;
}

void freeList(struct ListNode *p) 
{
	for (struct ListNode *pp = p; pp != NULL;) {
		struct ListNode *ppp = pp;
		pp = pp->next;
		free(ppp);
	}
}
	
int main()
{
	int n1[] = {3, 4, 2}, n2[] = {4, 6, 5};
	int size1 = sizeof(n1)/sizeof(n1[0]);
	int size2 = sizeof(n2)/sizeof(n2[0]);
	struct ListNode *p1 = NULL, *p2 = NULL;
	
	p1 = makeList(n1, size1);
	p2 = makeList(n2, size2);
	struct ListNode *p = addTwoNumbers(p1, p2);
	for (struct ListNode *pp = p; pp != NULL; pp = pp->next) {
		printf("%d", pp->val);
	}
	freeList(p);
	freeList(p1);
	freeList(p2);
	return 0;
}
