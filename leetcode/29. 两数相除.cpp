#include <stdio.h>
#include <limits.h>

int divide(int dividend, int divisor)
{
    if (divisor == 0) {
        return INT_MAX;
    } else {
        int sign = 1;
        long long de = dividend;
        if (de < 0) { // 被除数
            de = -de;
            sign *= -1;
        }
        long long di = divisor;
        if (di < 0) { // 除数
            di = -di;
            sign *= -1;
        }
        printf("%d * %d/%d\n", sign, de, di);
        long long result = 0;
        long long b = 1;
        while (di < de) { // 找最大b
            b <<= 1;
            di <<= 1;
        }
    	printf("s=%d, %d/%d\n", b, de, di);
        while (true) {
            while (di > de) { // 找其他b
	            b >>= 1; // 除数的个数
	            di >>= 1; // 除数
        	}
	        printf("s=%d, %d/%d\n", b, de, di);
        	if (b > 0) { // b>0时，还要再找
	            result += b; // 结果累计
	            de -= di; // 用减法答题除法
	        	printf("r=%d, %d/%d\n", result, de, di);        		
			} else { // b=0时，无需再找
				break;
			} 
        }        
        result *= sign;
        if (result < INT_MIN || result > INT_MAX) {
            return INT_MAX;
        }
        return result;
    }
}

int main()
{
	int d = divide(10,3);
	printf("%d\n", d);
	return 0;
}
