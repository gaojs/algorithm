#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void*a, const void*b)
{
	return *(char*)a - *(char*)b;
}

void sort(char a[], int n) {
	// 找最小字符串，环形搜索 
	int min = 0; // 最小字符串的起始点 
	for (int i = 1; i < n; i++) {
		int t = -1; // 比较结果 
		for( int k = 0; k < n; k++) {
			t = a[(min + k) % n];
			t -= a[(i + k) % n];
			if (t != 0) { // 有大小 
				break;
			} 			
		}
		if (t > 0) {
			min = i;
		}	
	}
	// printf("min=%d\n", min);
	// 调整成最小的字符串 
	for (int i = 0; i < min; i++) {
		char c = a[0]; // 往前移动一位 
		memmove(&a[0], &a[1], n - 1);
		a[n - 1] = c;
	}
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


