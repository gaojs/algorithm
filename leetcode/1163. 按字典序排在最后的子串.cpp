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
		bool equal = true; // Ĭ������� 
		for (char *p = last - 1; p >= s; p--) {
			if(equal && *p == *last) { // �ַ���� 
				last = p; // ��ǰ�ƶ� 
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
