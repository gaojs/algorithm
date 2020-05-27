#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 128 // ×Ö·ûµÄ¸öÊý

void calcMap(char *s, int sMap[N])
{
    if (s == NULL || sMap == NULL) {
        return;
    }
    memset(sMap, 0, sizeof(int)*N);
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        sMap[s[i]]++;
    }
}

bool isAnagram(char *s, char *t)
{
    if (s == NULL || t == NULL) {
        return false;
    }
    int sMap[N], tMap[N];
    calcMap(s, sMap);
    calcMap(t, tMap);
    for (int i = 0; i < N; i++) {
        if (sMap[i] != tMap[i]) {
            return false;
        }
    }
    return true;
}

int main()
{
    /*****************************
    */
    // const char *s = "anagram", *t = "nagaram"; // true
    const char *s = "rat", *t = "car"; // false;
    if (isAnagram((char*)s, (char*)t)) {
        printf("true");
    } else {
        printf("false");
    }
    return 0;
}

