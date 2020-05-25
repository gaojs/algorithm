#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_COUNT 10000 // �㹻��

long long num[MAX_COUNT] = {0};
char op[MAX_COUNT] = {0};

long long calc(char *a)
{ // ������ʽa��ֵ
	// �����ֺͷ��ţ���ջ
	memset(num, 0, sizeof(num));
	memset(op, 0, sizeof(op));
	int numCnt = 0, opCnt = 0;
	long long value = 0;
	int len = strlen(a);
	for (int i = 0; i < len; i++) {
		if (a[i] <= '9' && a[i] >= '0') {
			value = value * 10 + (a[i] - '0');
			if (a[i] == '0') { // 05������0��ͷ�����ֲ�����Ҫ��
				if ((i==0 || (i > 0 && (a[i-1] > '9' || a[i-1] < '0')))
					&& (i < len -1 && (a[i+1] <= '9' && a[i+1] >= '0'))) {
					return INT_MIN; // ���ָ�ʽ���ԣ�ֱ�ӷ���
				}
			}
		} else if (a[i] == '*' || a[i] == '+' || a[i] == '-') {
			num[numCnt++] = value;
			op[opCnt++] = a[i];
			value = 0;
		} else {
			return INT_MIN; // ���ָ�ʽ���ԣ�ֱ�ӷ���
		}
	}
	num[numCnt++] = value;
	// �ȼ���˷�
	for (int i = 0; i < opCnt; i++) {
		if (op[i] == '*') {
			num[i] *= num[i + 1];
			if (opCnt - i - 1 > 0) {
				memmove(&num[i+1], &num[i+2], sizeof(num[0]) * (numCnt - i - 2));
				memmove(&op[i], &op[i+1], sizeof(op[0]) * (opCnt - i - 1));
			}
			num[numCnt - 1] = 0;
			op[opCnt - 1] = 0;
			numCnt--;
			opCnt--;
			i--;
		}
	}
	// �ڼ���ӷ��ͼ���
	for (int i = 0; i < opCnt; i++) {
		if (op[i] == '+') {
			num[i] += num[i + 1];
		} else {
			num[i] -= num[i + 1];
		}
		if (opCnt - i - 1 > 0) {
			memmove(&num[i+1], &num[i+2], sizeof(num[0]) * (numCnt - i - 2));
			memmove(&op[i], &op[i+1], sizeof(op[0]) * (opCnt - i - 1));
		}
		num[numCnt - 1] = 0;
		op[opCnt - 1] = 0;
		numCnt--;
		opCnt--;
		i--;
	}
	return num[0];
}

char* newStr(char *a, int len, int pos, const char*op)
{
	char *t = (char*)calloc(sizeof(char), len);
	strncpy(t, a, pos); // ǰ��
	strcat(t, op); // ����
	strcat(t, a + pos); // ���
	return t;
}

void dfs(char *a, int pos, int target, char**p, int* returnSize)
{
	if (a == NULL || p == NULL || returnSize == NULL) {
		return;
	} 
	int len = strlen(a);
	if (pos >= len) { // �����Ѿ���ȫ��
		if (target == calc(a)) { // ����
			if (*returnSize > MAX_COUNT) {
				printf("overflow\n");
				return;
			}
			p[*returnSize] = a;
			(*returnSize)++;
		} else { // �����ϣ�����
			free(a);
		}
	} else {
		char *a1 = newStr(a, len + 2, pos, "*"); // *��
		char *a2 = newStr(a, len + 2, pos, "+"); // +��
		char *a3 = newStr(a, len + 2, pos, "-"); // -��
		dfs(a1, pos + 2, target, p, returnSize); // *��
		dfs(a2, pos + 2, target, p, returnSize); // +��
		dfs(a3, pos + 2, target, p, returnSize); // -��
		dfs(a, pos + 1, target, p, returnSize); // ���ӷ���
	}
}

char **addOperators(char *a, int target, int* returnSize)
{
	if (a == NULL || returnSize == NULL) {
		return NULL;
	}
	char **p = (char**)calloc(MAX_COUNT, sizeof(char*));
	if (p == NULL) {
		return NULL;
	}
	*returnSize = 0;
	dfs(strdup(a), 1, target, p, returnSize);
	return p;
}

int main()
{
	/************************
	char a[] = "123"; // 1+2+3, 1*2*3
	int target = 6; 
	char a[] = "232"; // 2*3+2, 2+3*2
	int target = 8;
	char a[] = "105"; // 1*0+5, 10-5
	int target = 5;
	char a[] = "00"; // 0+0, 0-0, 0*0
	int target = 0; 
	char a[] = "3456237490"; // ""
	int target = 9191; 
	char a[] = "123456789"; // ""
	int target = 45;
	char a[] = "1000000009";
	int target = 9; */
	char a[] = "2147483647";
	int target = 2147483647;
	int returnSize = 0;
	char **p = addOperators(a, target, &returnSize);
	if (p != NULL) {
		for (int i = 0; i < returnSize; i++) {
			printf("%s\n", p[i]);
			free(p[i]);
		}
		free(p);
	} 
	// char s[] = {"2*3+2"};
	// char s[] = {"2+3*2"};
	// char s[] = {"1*0+5"};
	// char s[] = {"3+4*5+62*37*4-9-0"};
	// printf("%s=%ld", s, calc(s));
	return 0;
}

