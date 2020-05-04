#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int cmp(const void*a, const void *b)
{
	return *(int*)a - *(int*)b; // 正序 
}

struct node {
	int value;
	int count;
};

int cmp2(const void*a, const void *b)
{
	struct node *n1 = (struct node*)a;
	struct node *n2 = (struct node*)b;	
	return n2->count - n1->count; // 逆序 
}

int majorityElement(int* nums, int numsSize)
{
	if (nums == NULL || numsSize == 0) {
		return 0;
	}
	struct node *p = (struct node *)calloc(sizeof(struct node), numsSize);
	if (p == NULL) {
		return 0;
	}
	qsort(nums, numsSize, sizeof(int), cmp);	
	int cnt = 1; // 数量 
	int v = nums[0]; // 数值 
	p[cnt - 1].value = v;
	p[cnt - 1].count = 1;
	for (int i = 1; i < numsSize; i++) {
		if (nums[i] == v) {
			p[cnt - 1].count++;		
		} else {
			v = nums[i];
			p[cnt].value = v;
			p[cnt].count = 1;
			cnt++;
		}
	}
	qsort(p, cnt, sizeof(struct node), cmp2);
	v =  p[0].value;
	cnt = p[0].count;
	free(p);
	return v;
}

int main()
{
	int a1[] = {3,2,3}; 
	int a2[] = {2,2,1,1,1,2,2}; 
	int sizeA = sizeof(a2)/sizeof(a2[0]);
	printf("\n%d", majorityElement(a2, sizeA)); 
	return 0;
}

