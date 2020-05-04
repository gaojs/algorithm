// https://leetcode-cn.com/problems/add-two-numbers/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

void printList(struct ListNode *p);

struct ListNode* reverse(struct ListNode* root) 
{
    struct ListNode *head = NULL;
	struct ListNode *p = root;
	while (p != NULL) {	
		struct ListNode *pp = p;
		p = p->next;
        if (head == NULL) { // ����ͷ���
            pp->next = NULL; 
            head = pp;
        } else { // ׷�ӵ��������
            pp->next = head;
            head = pp;
        }
	}
	return head;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    if (l1 == NULL && l2 == NULL) {
        return NULL;
    }    
    struct ListNode *head = NULL;
    struct ListNode *tail = NULL;
    struct ListNode *p = NULL;
    l1 = reverse(l1); // ���� 
    l2 = reverse(l2); // ���� 
    while (l1 != NULL && l2 != NULL) { // ����ӷ�
        p = (struct ListNode*)malloc(sizeof(struct ListNode));
        if (p == NULL) {
            return NULL;
        } else {
            p->next = NULL;
            p->val = l1->val + l2->val; // ��
            l1 = l1->next;
            l2 = l2->next;
            if (head == NULL) { // ����ͷ���
                head = p;
                tail = p;
            } else { // ׷�ӵ��������
                tail->next = p;
                tail = p;
            }
        }        
    }
    while(l1 != NULL) { // ����l1
        p = (struct ListNode*)malloc(sizeof(struct ListNode));
        if (p == NULL) {
            return NULL;
        } else {
            p->next = NULL;
            p->val = l1->val; // ��        
            l1 = l1->next;
            if (head == NULL) { // ����ͷ���
                head = p;
                tail = p;
            } else { // ׷�ӵ��������
                tail->next = p;
                tail = p;
            }
        }        
    }
    while(l2 != NULL) { // ����l2
        p = (struct ListNode*)malloc(sizeof(struct ListNode));
        if (p == NULL) {
            return NULL;
        } else {
            p->next = NULL;
            p->val = l2->val; // ��        
            l2 = l2->next;
            if (head == NULL) { // ����ͷ���
                head = p;
                tail = p;
            } else { // ׷�ӵ��������
                tail->next = p;
                tail = p;
            }
        }        
    }
    int carry = 0;
    for (p = head; p != NULL; p=p->next) { // �����λ
        int tmp = p->val + carry;
        p->val = tmp % 10;
        carry = tmp / 10;
    }
    if (carry > 0) { // �������Ľ�λ
         p = (struct ListNode*)malloc(sizeof(struct ListNode));
        if (p == NULL) {
            return NULL;
        } else {
            p->next = NULL;
            p->val = carry;            
            if (head == NULL) { // ����ͷ���
                head = p;
                tail = p;
            } else { // ׷�ӵ��������
                tail->next = p;
                tail = p;
            }
        }
    }
    return reverse(head);
}

struct ListNode *makeList(int *nums, int size) 
{
	struct ListNode *head = NULL; 
	struct ListNode *tail = NULL; 
	struct ListNode *p = NULL; 
	for (int i = 0; i < size; i++) {
		p = (struct ListNode *)malloc(sizeof(struct ListNode));
		p->val = nums[i];
		p->next = NULL;
		if (head == NULL) {
			head = p; // ͷ��� 
			tail = p;
		} else { // ������ 
			tail->next = p;
			tail = p;
		} 
	}
	return head;
}

void printList(struct ListNode *p) 
{
	printf("\nList: ");
	while (p != NULL) {
		printf("%d,", p->val);
		p = p->next;	
	}
	printf("\n");
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
	int n1[] = {7, 2, 4, 3}, n2[] = {5, 6, 4};
	int size1 = sizeof(n1)/sizeof(n1[0]);
	int size2 = sizeof(n2)/sizeof(n2[0]);
	struct ListNode *p1 = NULL, *p2 = NULL;
	
	p1 = makeList(n1, size1);
	printList(p1);
	p2 = makeList(n2, size2);
	printList(p2);
	struct ListNode *p = addTwoNumbers(p1, p2);
	printList(p);
	freeList(p);
	freeList(p1);
	freeList(p2);
	return 0;
}
