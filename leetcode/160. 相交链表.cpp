#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) 
{
	if (headA == NULL || headB == NULL) {
		return NULL;
	} else {
		struct ListNode *lA = headA;
		struct ListNode *lB = headB;		
		while (true) {	
			if(lA == lB) { // NULL
				return lA;
			}
			if (lA == NULL) {
				//printf("A->B\n");
				lA = headB;
			}	
			if (lB == NULL) {
				//printf("B->A\n");
				lB = headA;
			}
			if(lA == lB) { // NODE
				return lA;
			}
			printf("%d-%d\n", lA->val, lB->val);
			lA = lA->next;
			lB = lB->next;
		}
		return NULL;
	}
}

struct ListNode *createList(int a[], int n)
{
	if(a == NULL || n == 0) {
		return NULL;		
	} else {
		struct ListNode *head = NULL;
		struct ListNode *tail = NULL;
		struct ListNode *p = NULL;
		for (int i = 0; i < n; i++) {
			p = (struct ListNode *)malloc(sizeof(struct ListNode));
			if (p == NULL) {
				return head;
			} else {
				p->val = a[i];
				p->next = NULL;
				if (head == NULL) {
					head = p;
					tail = p;
				} else { // ×·¼Ó 
					tail->next = p;
					tail = p;
				}
			} 
		}
		return head;
	}
}

void printList(struct ListNode *head)
{
	printf("List:");
	while (head != NULL) {
		printf("%d,", head->val);
		head = head->next;
	}
	printf("\n");
}

void freeList(struct ListNode *head)
{
	while (head != NULL) {
		struct ListNode *p = head;
		head = head->next;
		free(p);
	}
}

int main()
{
	// int a1[] = {4,1,8,4,5}; 
	// int a2[] = {5,0,1,8,4,5}; 
	int a1[] = {1,5}; 
	int a2[] = {2,6,4}; 
	int skipA = 2, skipB = 3;
	// int a1[] = {3}; 
	// int a2[] = {2,3}; 
	// int skipA = 0, skipB = 1;
	int sizeA = sizeof(a1)/sizeof(a1[0]);
	struct ListNode *l1 = createList(a1, skipA);
	printList(l1); 
	struct ListNode *l2 = createList(a2, skipB);
	printList(l2); 
	struct ListNode *l3 = createList(a1 + skipA, sizeA - skipA);
	printList(l3); 
	struct ListNode *lt = NULL;
	if (l1 != NULL) {		
		for (lt = l1; lt->next != NULL; lt = lt->next) {
			;
		}
		lt->next = l3;
	} else {
		l1 = l3;
	}
	printList(l1); 
	
	if (l2 != NULL) {		
		for (lt = l2; lt->next != NULL; lt = lt->next) {
			;
		}
		lt->next = l3;
	} else {
		l2 = l3;
	}
	printList(l2); 
	lt = getIntersectionNode(l1, l2);
	if(lt != NULL) {
		printf("\n%d", lt->val); 
	}
	return 0;
}

