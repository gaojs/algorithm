#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


#define MAX_COUNT 100

bool isValid(char *s)
{
    if (s == NULL) {
        return false;
    }
    int left, right;
    left = right = 0;
    for (; s[0]; s++) {
        switch (s[0]) {
        case '(':
            left++;
            break;
        case ')':
            right++;
            if (right > left) {
                return false;
            }
            break;
        default:
            break;
        }
    }
    return (left == right);
}

char **removeInvalidParentheses(char *s, int* returnSize)
{
    if (s == NULL || returnSize == NULL) {
        return NULL;
    }
    return NULL;
    *returnSize = 0;
    char **result = (char**)calloc(MAX_COUNT, sizeof(char*));

    return result;
}

int main()
{
    /*************************/
    char a[] = "()())()"; // ["()()()", "(())()"]
    // char a[] = "(a)())()"; // ["(a)()()", "(a())()"]
    // char a[] = ")("; // [""]  
    int returnSize = 0;
    char **p = removeInvalidParentheses(a, &returnSize);
    if (p != NULL) {
        for (int i = 0; i < returnSize; i++) {
            printf("%s\n", p[i]);
            free(p[i]);
        }
        free(p);
    }
    if (isValid(a)) {
        printf("true");
    } else {
        printf("false");
    }
    return 0;
}

