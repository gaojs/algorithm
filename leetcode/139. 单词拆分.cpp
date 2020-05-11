#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

bool wordBreak(char *s, char **wd, int n)
{
	if (s == NULL || wd == NULL || n == 0) {
		return false; // 参数错误
	}
	int len = strlen(s);
	// dp[i] = dynamic plan, 前i个字符串，是否OK
	bool *dp = (bool *)calloc(sizeof(bool), len + 1);
	if (dp == NULL) { // 内存申请失败
		return false;
	}
	dp[0] = true; // 前0个字符串，认为OK
	for (int i = 1; i <= len; i++) {
		for (int j = 0; j < n; j++) {
			int wdlen = strlen(wd[j]);
			int k = i - wdlen; // 前段
			if (k < 0) { //不够长
				continue;
			}
			dp[i] = (dp[k] && strncmp(s + k, wd[j], wdlen) == 0) || dp[i];
			/*if (dp[k] && strncmp(s + k, wd[j], wdlen) == 0) {
				printf("i=%d, k=%d,  s=%s, wd[%d]=%s, wdlen=%d,  dp[%d]=%d, dp[%d]=%d\n",
					i, k, s + k, j, wd[j], wdlen, k, dp[k], i, dp[i]);
			}*/
		}
	}
	/*for (int i = 1; i <= len; i++) {
		printf("%d:%d ", i, dp[i]);
	}
	printf("\n");
	*/
	bool ret = dp[len];
	free(dp); // 释放内存
	return ret;
}

int main()
{
	// const char s[] = "leetcode", *wd[] = {"leet", "code"}; // true
	// const char s[] = "applepenapple", *wd[] = {"apple", "pen"}; // true
	// const char s[] = "catsandog", *wd[] = {"cats", "dog", "sand", "and", "cat"}; // false
	/* const char s[] = "bccdbacdbdacddabbaaaadababadad",
		*wd[] = {"cbc","bcda","adb","ddca","bad","bbb","dad","dac","ba","aa",
			"bd","abab","bb","dbda","cb","caccc","d","dd","aadb","cc","b",
			"bcc","bcd","cd","cbca","bbd","ddd","dabb","ab","acd","a",
			"bbcc","cdcbd","cada","dbca","ac","abacd","cba","cdb",
			"dbac","aada","cdcda","cdc","dbc","dbcb","bdb","ddbdd",
			"cadaa","ddbc","babb"}; */// true
	const char s[] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab",
		*wd[] = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
	int n = sizeof(wd) / sizeof(wd[0]);
	
	/*int r = strcmp(wd[0], wd[1]);
		printf("r=%d\n", r);	
	for (int i = 0; i < n; i++) {
		printf("%s\n", wd[i]);
	}*/
	if (wordBreak((char*)s, (char**)wd, n)) {
		printf("true");
	} else {
		printf("false");		
	}	 
	return 0;
}
