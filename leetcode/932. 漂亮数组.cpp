#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ���÷���˼�룬�ҳ�һ�ַŷ�����֤�������⡣
// a�Ǹ����飬n������Ԫ�صĸ�������������ߣ�ż�����ұߡ�
// ��n1��ʼ������Ϊstep�����֣��ŵ�p1��p2��������λ���ϡ�
void dfs(int *a, int n, int p1, int p2, int n1, int step) 
{
	if (a == NULL || n <= 0 || p1 >=n || p2 >=n || p1 > p2) {
		return; // �������� 
	} else if (p1 == p2) { // ֻ��1��Ԫ�� 
		a[p1] = n1;
	} else { // 3��Ԫ�ؼ�����
		int p = (p1 + p2) / 2; // �м�λ�� 
		dfs(a, n, p1, p, n1, step * 2); // ���
		dfs(a, n, p + 1, p2, n1 + step, step * 2); // �ұ�
	} 
} 

int* beautifulArray(int n, int* returnSize)
{
	if (n < 1 || returnSize == NULL) {
		return NULL;
	} else {
		int size = sizeof(int) * n;
		int *a = (int*)malloc(size);			
		if (a == NULL) {			
			*returnSize = 0;
			return NULL;
		}
		dfs(a, n, 0, n - 1, 1, 1);
		*returnSize = n;
		return a;
	}
}

int main()
{
	//for (int n = 1; n < 20; n++) {	
		{ int n = 4;
		int returnSize = 0;
		int *a = beautifulArray(n, &returnSize);
		if (a != NULL) {
			printf("%d: ", n);
			for (int i = 0; i < returnSize; i++) {
				printf("%d ", a[i]);
			}
			printf("\n");
			free(a);
		}
	}
	return 0;
} 

