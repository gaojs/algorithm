#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 

char *reverseOnlyLetters(char *s)
{
	if (s == NULL) {
		return NULL;
	}
	int len = strlen(s);
	char *a = (char*)malloc(sizeof(char) * (len + 1));
	memcpy(a, s, sizeof(char) * (len + 1));
	int i = 0, j = len - 1; // 首尾指针 
	while(i < j) { // 双指针王中间移动 
		while (i < j && !isalpha(a[i])) {
			i++;
		} 
		while (i < j && !isalpha(a[j])) {
			j--;
		} 
		if (i < j ) {
			char t = a[i];
			a[i] = a[j];
			a[j] = t;
			i++, j--;
		}
	}
	return a;
}

int main()
{
	// char s[] = "ab-cd"; // dc-ba
	// char s[] = "a-bC-dEf-ghIj"; // j-Ih-gfE-dCba
	char s[] = "Test1ng-Leet=code-Q!"; // Qedo1ct-eeLg=ntse-T!
	char *p = reverseOnlyLetters(s);
	if (p != NULL) {
		printf("%s", p);
		free(p);		
	}
	return 0;
} 

