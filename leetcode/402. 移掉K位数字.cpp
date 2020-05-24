#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int findPos(char *a, int n)
{ // 查找第一个大于后面数字的位置 
	int i = 0;
	for (; i < n - 1; i++)	{
		if (a[i] > a[i + 1]) {
			break; // 找到位置 
		}
	}
	return i;
}

void removeOne(char *a, int n, int pos)
{ // 移除pos位置的数字 
	if (pos < n - 1) {
		memmove(&a[pos], &a[pos + 1], n - pos - 1);
	}
	a[n - 1] = 0;	
}

char *removeKdigits(char *a, int k)
{
	if (a == NULL || k <= 0) {
		return a;
	}	
	int n = strlen(a);
	for (;k > 0; k--, n--) {	
		int pos = findPos(a, n);
		removeOne(a, n, pos);
	}
	while (n > 0 && a[0] == '0') {
		removeOne(a, n, 0);
		n--;
	}
	if (n == 0) {
		a[0] = '0';
	}
	return a;
}

int main()
{
	// char s[] = "1432219";
	// int k = 3; // 1219
	char s[] = "10200"; 
	int k = 1;
	// char s[] = "10"; 
	// int k = 2;
	// char s[] = "0"; 
	// int k = 0;
	printf("%s", removeKdigits(s, k));
	return 0;
} 


