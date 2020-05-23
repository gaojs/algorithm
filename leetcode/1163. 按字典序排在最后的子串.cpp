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
		char *last = s;
		for (char *p = s+1; *p; p++) {
			if(strcmp(last, p) < 0) {
				last = p;
			}
		}
		return last;
	}
}

int main()
{
	const char *s = "abab"; // bab 
	s = lastSubstring((char*)s);
	printf("%s", s);
	return 0;
} 
