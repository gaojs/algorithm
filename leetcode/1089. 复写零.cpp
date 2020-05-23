#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void duplicateZeros(int* a, int n)
{
	for (int i = 0; i < n; i++) {
		if (a[i] == 0) {
			if (i < n - 2) { // 往后移动			
				memmove(&a[i+2], &a[i+1], sizeof(int) * (n-2-i));	
			}
			if (i < n - 1) { // 后位设0 
				a[i+1] = 0;
				i++; // 调1位 
			}
		}
	}
}

int main()
{
	int a[] = {1,2,3}; 
	//int a[] = {1,0,2,3,0,4,5,0};
	int n = sizeof(a) / sizeof(a[0]);
	duplicateZeros(a, n);
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	return 0;
} 
