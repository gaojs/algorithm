#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void*a, const void*b)
{
	return *(char*)a - *(char*)b;
}

void sort(char a[], int n) {
	// ����С�ַ������������� 
	int min = 0; // ��С�ַ�������ʼ�� 
	for (int i = 1; i < n; i++) {
		int t = -1; // �ȽϽ�� 
		for( int k = 0; k < n; k++) {
			t = a[(min + k) % n];
			t -= a[(i + k) % n];
			if (t != 0) { // �д�С 
				break;
			} 			
		}
		if (t > 0) {
			min = i;
		}	
	}
	// printf("min=%d\n", min);
	// ��������С���ַ��� 
	for (int i = 0; i < min; i++) {
		char c = a[0]; // ��ǰ�ƶ�һλ 
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
	if (a == NULL) { //�����ڴ棻 
		return NULL;
	}	
	memcpy(a, s, n);
	if (k == 1) { // ����
		sort(a, n);
	} else { // �κ�������ĸ�ɻ��� 
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


