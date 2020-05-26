#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

char **removeInvalidParentheses(char *s, int* returnSize)
{

}

int main()
{
	/************************
	char a[] = "()())()"; // ["()()()", "(())()"]
	char a[] = "(a)())()"; // ["(a)()()", "(a())()"]
	char a[] = "")(""; // [""]  */
	char a[] = "2147483647";
	int target = 2147483647;
	/*************************/
	int returnSize = 0;
	char **p = removeInvalidParentheses(a, &returnSize);
	if (p != NULL) {
		for (int i = 0; i < returnSize; i++) {
			printf("%s\n", p[i]);
			free(p[i]);
		}
		free(p);
	}  
	return 0;
}

