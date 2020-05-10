#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

bool dfs(char *s, char **wd, int n)
{
	if (s == NULL || wd == NULL || n == 0) {
		return false;
	} else if (s[0] == 0) {
		return true;
	}
	for (int i = 0; i < n; i++) {
		int len = strlen(wd[i]);
		if (strncmp(s, wd[i], len) == 0) {
			if (dfs(s + len, wd, n)) {
				return true;
			}
		}
	} 
	return false;
}

bool wordBreak(char *s, char **wd, int n)
{
	if (s == NULL || wd == NULL || n == 0) {
		return false;
	}
	int count = 128; 
	int sMap[count];// = {0};
	int sLen = strlen(s);
	memset(sMap, 0, sizeof(sMap));
	for (int i = 0; i < sLen; i++) {
		sMap[s[i]] = 1; // s������Щ��ĸ 
	}
	int wdMap[count];// = {0};
	memset(wdMap, 0, sizeof(wdMap));
	for (int i = 0; i < n; i++) {
		int len = strlen(wd[i]);
		for (int j = 0; j < len; j++) {
			wdMap[wd[i][j]] = 1; // wd��ĸ 
		}
	}
	for (int i = 0; i < count; i++) {
		if (sMap[i] > wdMap[i]) {
			printf("%d: %d, %d\n", i, sMap[i], wdMap[i]);
			return false; // ��Щ��ĸ���ֵ��в����� 
		}
	}	
	return dfs(s, wd, n);
}

int main()
{
	char s[] = "leetcode", *wd[] = {"leet", "code"}; // true
	// char s[] = "applepenapple", *wd[] = {"apple", "pen"}; // true
	// char s[] = "catsandog", *wd[] = {"cats", "dog", "sand", "and", "cat"}; // false
	/* char s[] = "bccdbacdbdacddabbaaaadababadad", 
		*wd[] = {"cbc","bcda","adb","ddca","bad","bbb","dad","dac","ba","aa",
			"bd","abab","bb","dbda","cb","caccc","d","dd","aadb","cc","b",
			"bcc","bcd","cd","cbca","bbd","ddd","dabb","ab","acd","a",
			"bbcc","cdcbd","cada","dbca","ac","abacd","cba","cdb",
			"dbac","aada","cdcda","cdc","dbc","dbcb","bdb","ddbdd",
			"cadaa","ddbc","babb"}; */// true
	// char s[] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab",
	//	*wd[] = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
	int n = sizeof(wd) / sizeof(wd[0]);
	
	/*int r = strcmp(wd[0], wd[1]);
		printf("r=%d\n", r);	
	for (int i = 0; i < n; i++) {
		printf("%s\n", wd[i]);
	}*/
	if (wordBreak(s, wd, n)) {
		printf("true");
	} else {
		printf("false");		
	}	 
	return 0;
}
