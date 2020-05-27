#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *minWindow(char *s, char *t)
{
	if (s == NULL || t == NULL) {
		return (char*)""; // 参数错误 
	} 	
	int sLen = strlen(s);
	int tLen = strlen(t);
	// printf("sLen=%d, tLen=%d\n", sLen, tLen);
	if (sLen < tLen) { // 长度不够 
		return (char*)"";
	} 
	#define CHAR_NUM 128
	int sMap[CHAR_NUM] = {0};
	int tMap[CHAR_NUM] = {0};	
	for (int i = 0; i < tLen; i++) {
		sMap[s[i]]++;
		tMap[t[i]]++;
	}
	int left = 0; 
	int right = tLen;
	int start = 0;
	int len = INT_MAX; 
	while (right <= sLen) {	
		bool included = true;	
		// printf("left=%d, right=%d\n", left, right);
		if (right - left < tLen) {
			included = false; // 长度不够 
		} else { // 循环查找，看看是否包含 
			for (int i = 0; i < CHAR_NUM; i++) {
				if (sMap[i] < tMap[i]) {
					included = false;
					break;
				}
			}
		}
		if (included) {
			// printf("len=%d, right-left=%d\n", len, right - left);
			if (len > right - left) {
				len = right - left;
				start = left;
			}
			sMap[s[left]]--;
			left++;
		} else {
			sMap[s[right]]++;
			right++;
		}
	}
	if (len == INT_MAX) { // 未找到 
		return (char*)"";
	} else {
		char *p = (char*)calloc(sizeof(char), len + 1);
		if (p == NULL) { // 内存申请失败 
			return (char*)"";
		} else {
			strncpy(p, s + start, len);
		}
		return p;
	} 	
}

int main()
{
	// char S[] = "ADOBECODEBANC", T[] = "ABC"; // BANC
	char S[] = "a", T[] = "aa"; // a
	char *p =  minWindow(S, T);
	if (p != NULL) {
		printf("%s", p);
		if (p[0] != 0) {
			free(p);
		}
	}	
	return 0;
}
