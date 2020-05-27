#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *lastSubstring(char *s)
{
	if (s == NULL) {
		return NULL;
	} else {
		int len = strlen(s);
	    int ans = 0;
	    for (int i = 1; i < len; i++) {
	        if (s[i] <= s[i - 1]) {
	            continue;
	        }
	        if (strcmp(&s[i], &s[ans]) > 0) {
	            ans = i;
	        }
	    }
	    return &s[ans];
	}
}

int main()
{
	// const char *s = "abab"; // bab 
	const char *s = "zrziy"; // zrziy 
	const char *s = "aaabbbaaa"; // bbbaaa 
	s = lastSubstring((char*)s);
	printf("%s", s);
	return 0;
} 
