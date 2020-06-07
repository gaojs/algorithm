#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>

#define strdup _strdup

void dfs(char *s, char **ms)
{
    bool del = false;
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (s[i] == s[j]) {
                char *s1 = strdup(s);
                char *s2 = strdup(s);
                memmove(&s1[i], &s1[i + 1], len - i);
                dfs(s1, ms);
                memmove(&s2[j], &s2[j + 1], len - j);
                dfs(s2, ms);
                del = true;
            }
        }
    }
    if (!del) {
        if (*ms == NULL) {
            *ms = strdup(s);
        } else if (strcmp(*ms, s) > 0) {
            *ms = strdup(s);
        }
    }
    free(s);
    s = NULL;
}

char* RemoveDuplicateLetters(char* s)
{
    if (s == NULL) {
        return (char*)"";
    }
    char *ms = NULL;
    dfs(strdup(s), &ms);
    return ms;
}

int main()
{
    // char s[] = "bcabc"; // abc
    char s[] = "cbacdcbc"; // acdb
    printf("%s", RemoveDuplicateLetters(s));
    return 0;
}
