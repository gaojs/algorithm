#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int cmp(const void *a, const void *b)
{
	const char *a1 = *(const char**)a;
	const char *b1 = *(const char**)b;
	int r = strcmp(a1, b1);	
	// printf("r=%d, a=%s, b=%s\n", r, a1, b1);
	return r;
}

bool dfs(char *s, char **wd, int n)
{
	if (s == NULL || wd == NULL || n == 0) {
		return false;
	} else if (s[0] == 0) {
		return true;
	}
	int left = 0, right = n - 1; 
	while (left <= right) {
		int mid = left + (right - left) / 2;
		int len = strlen(wd[mid]);
		int ret = strncmp(wd[mid], s, len);
		 printf("s=%s l=%d, r=%d, wd[%d]=%s, ret=%d\n", 
		 	s, left, right, mid, wd[mid], ret);
		if (ret == 0) {
			if (dfs(s + len, wd, n)) {
				return true;
			}
			for (int m = mid - 1;  m >= left; m--) { // 左侧找找
				len = strlen(wd[m]);
				ret = strncmp(wd[m], s, len);
				 printf("s=%s l=%d, r=%d, wd[%d]-=%s, ret=%d\n", 
				 	s, left, right, m, wd[m], ret);
				if (ret == 0) {
					if (dfs(s + len, wd, n)) {
						return true;
					}
				} else { // 不等就退 
					break;
				} 
			}
			for (int m = mid + 1;  m <= right; m++) { // 右侧找找
				len = strlen(wd[m]);
				ret = strncmp(wd[m], s, len);
				 printf("s=%s l=%d, r=%d, wd[%d]+=%s, ret=%d\n", 
				 	s, left, right, m, wd[m], ret);
				if (ret == 0) {
					if (dfs(s + len, wd, n)) {
						return true;
					}
				} else { // 不等就退 
					break;
				} 
			}
			break;
		} else if(ret < 0) { 
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}
	return false;
}

bool wordBreak(char *s, char **wd, int n)
{
	if (s == NULL || wd == NULL || n == 0) {
		return false;
	}
	qsort(wd, n, sizeof(char*), cmp);
	for (int i = 0; i < n; i++) {
		printf("%d: %s\n", i, wd[i]);
	} 
	return dfs(s, wd, n);
}

int main()
{
	// char s[] = "leetcode", *wd[] = {"leet", "code"}; // true
	// char s[] = "applepenapple", *wd[] = {"apple", "pen"}; // true
	// char s[] = "catsandog", *wd[] = {"cats", "dog", "sand", "and", "cat"}; // false
	char s[] = "bccdbacdbdacddabbaaaadababadad", 
		*wd[] = {"cbc","bcda","adb","ddca","bad","bbb","dad","dac","ba","aa",
			"bd","abab","bb","dbda","cb","caccc","d","dd","aadb","cc","b",
			"bcc","bcd","cd","cbca","bbd","ddd","dabb","ab","acd","a",
			"bbcc","cdcbd","cada","dbca","ac","abacd","cba","cdb",
			"dbac","aada","cdcda","cdc","dbc","dbcb","bdb","ddbdd",
			"cadaa","ddbc","babb"}; // true
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
