#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

char *decodeString(char *s)
{
	if (s == NULL) {
		return NULL;
	}
	char *a = strdup(s);
	while (true) {			
		int len = strlen(a);
		int left = 0, right = len;
		int i = len - 1, num = 0, w = 1;
		for (; i >= 0; i--) {
			if (a[i] == ']') {
				right = i;
			} else if(a[i] == '[') {
				left = i;
			} else if (a[i] >= '0' && a[i] <= '9') {
				do { // 组合数字 
					num += w * (a[i] - '0');
					w *= 10;
					i--; 
				} while (i >= 0 && (a[i] >= '0' && a[i] <= '9'));
				break;
			}		
		}
		if (num == 0) { //没有[]了 
			return a;
		} else {
			int slen = (right - left - 1);
			int count = (i + 1) + (len - right - 1) + num * slen + 1;
			char *t = (char*)calloc(count, sizeof(char));
			if (i + 1 > 0) { // 左 
				memcpy(t, a, i + 1);
			}
			for (int k = 0; k < num; k++) { // 中
				memcpy(t + (i + 1) + k * slen, a + left + 1, slen);
			}
			if (len - right - 1 > 0) {
				memcpy(t + (i + 1) + num * slen, a + right + 1, len - right - 1);
			}
			free(a);
			a = t; 		
		}
	}
}

int main()
{
	//char s[] = "3[a]2[bc]"; // aaabcbc.
	// char s[] = "3[a2[c]]"; // accaccacc
	char s[] = "2[abc]3[cd]ef"; // abcabccdcdcdef
	printf("%s", decodeString(s));
	return 0;
} 


