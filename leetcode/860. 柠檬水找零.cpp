#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 

bool lemonadeChange(int*a, int n)
{
	if (a == NULL || n <= 0) {
		return false;
	} 
	int s5 = 0, s10 = 0, s20 = 0;
	for (int i = 0; i < n; i++) {
		switch (a[i]) {
			case 20: // ��20��15Ԫ 
				if (s10 > 0 && s5 > 0) {
					s20++, s10--, s5--;
					continue; // �ҿ��� 
				}
				if (s5 > 3) {
					s20++, s5 -= 3;
					continue; // �ҿ���
				}
				return false;
			case 10: //��10Ԫ��5Ԫ 
				if (s5 > 0) {
					s10++, s5--;
					continue; // �ҿ���
				}
				return false;
			case 5: // ��5Ԫ
				s5++;
				continue; // ����Ǯ  
			default: // ������ʧ�� 
				return false;
		}
	}
	return true; 
}

int main()
{
	// int a[] = {5,5,5,10,20}; // true
	int a[] = {5,20}; // false
	int n = sizeof(a) / sizeof(a[0]);
	if (lemonadeChange(a, n)) {
		printf("true");
	} else {
		printf("false");		
	}
	return 0;
} 

