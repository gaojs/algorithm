#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *lastSubstring(char *s)
{
	if (s == NULL) {
		return NULL;
	} else {
		int len = strlen(s);
		if (len <= 1) {
			return s;
		}
		char *last = &s[len - 1];
		bool equal = true; // 默认是相等 
		for (char *p = last - 1; p >= s; p--) {
			if(equal && *p == *last) { // 字符相等 
				last = p; // 往前移动 
			} else {
				equal = false; 
				if(strcmp(p, last) > 0) {
					last = p;					
				}
			}
		}
		return last;
	}
}

int main()
{
	// const char *s = "abab"; // bab 
	const char *s = "zrziy"; // zrziy 
	s = lastSubstring((char*)s);
	printf("%s", s);
	return 0;
} 
