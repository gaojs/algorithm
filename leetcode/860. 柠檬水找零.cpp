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
			case 20: // 给20找15元 
				if (s10 > 0 && s5 > 0) {
					s20++, s10--, s5--;
					continue; // 找开了 
				}
				if (s5 > 3) {
					s20++, s5 -= 3;
					continue; // 找开了
				}
				return false;
			case 10: //给10元找5元 
				if (s5 > 0) {
					s10++, s5--;
					continue; // 找开了
				}
				return false;
			case 5: // 给5元
				s5++;
				continue; // 不找钱  
			default: // 其他都失败 
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

