#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void*a, const void*b)
{
	return *(char*)a - *(char*)b;
}

void sort(char a[], int n) {
	// 找最小字符串，环形搜索 
	char *min = strdup(a);
	for (int i = 1; i < n; i++) {
		char *t = (char*)calloc(n+1, sizeof(char));
		memcpy(t, &a[i], n - i);
		memcpy(t + n - i, a, i);
		if (strcmp(min, t) > 0) {
			free(min);
			min = t;
		} else {
			free(t);
		}
	}
	// 调整成最小的字符串 
	memcpy(a, min, n);
	free(min);
}		

char *orderlyQueue(char *s, int k)
{
	if(s == NULL || k <= 0) {
		return NULL;
	}
	int n = strlen(s);
	char *a = (char*)calloc(n + 1, sizeof(char));
	if (a == NULL) { //申请内存； 
		return NULL;
	}	
	memcpy(a, s, n);
	if (k == 1) { // 单环
		sort(a, n);
	} else { // 任何两个字母可互换 
		qsort(a, n, sizeof(char), cmp);
	}
	return a;
}

int main()
{
	// char s[] = "cba", k = 1; // acb
	// char s[] = "baaca", k = 3; // aaabc
	char s[] = "abdcaa", k = 1; // aaabdc
	// char s[] = "abdcaa", k = 2; // aaabcd
	printf("%s", orderlyQueue(s, k));
	return 0;
} 


