#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>

#define MAX_COUNT 10000 // 足够大
typedef struct {
    int d[MAX_COUNT]; // 数据data
    int m[MAX_COUNT]; // 最小值min
	int count; // 元素个数
} MinStack;

MinStack* minStackCreate() {
	static MinStack g_ms;
	memset(&g_ms, 0, sizeof(g_ms));
	return &g_ms;
}

void minStackPush(MinStack* obj, int x) {
	if (obj->count == 0) {
		obj->d[obj->count] = x;
		obj->m[obj->count] = x;
	} else {
		int pre = obj->m[obj->count - 1];
		obj->m[obj->count] = pre < x ? pre : x;
		obj->d[obj->count] = x;
	}
	obj->count++;
}

void minStackPop(MinStack* obj) {
	if (obj->count > 0) {
		obj->count--;
		obj->d[obj->count] = 0;
		obj->m[obj->count] = 0;
	}
}

int minStackTop(MinStack* obj) {
	if (obj->count > 0) {
		return obj->d[obj->count - 1];
	}
	return 0;
}

int minStackGetMin(MinStack* obj) {
	if (obj->count > 0) {
		return obj->m[obj->count - 1];
	}
	return 0;
}

void minStackFree(MinStack* obj) {
}

int main()
{
	MinStack* obj = minStackCreate();
	minStackPush(obj, -2);
	minStackPush(obj, 0);
	minStackPush(obj, -3);
	int m = minStackGetMin(obj);
	printf("m=%d\n", m);
	minStackPop(obj);
	int t = minStackTop(obj);
	printf("t=%d\n", t);
	m = minStackGetMin(obj);
	printf("m=%d\n", m);
	minStackFree(obj);
	return 0;
}


