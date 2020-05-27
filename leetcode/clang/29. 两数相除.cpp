#include <stdio.h>
#include <limits.h>

int divide(int dividend, int divisor)
{
    if (divisor == 0) {
        return INT_MAX;
    } else {
        int sign = 1;
        long long de = dividend;
        if (de < 0) { // ������
            de = -de;
            sign *= -1;
        }
        long long di = divisor;
        if (di < 0) { // ����
            di = -di;
            sign *= -1;
        }
        printf("%d * %d/%d\n", sign, de, di);
        long long result = 0;
        long long b = 1;
        while (di < de) { // �����b
            b <<= 1;
            di <<= 1;
        }
    	printf("s=%d, %d/%d\n", b, de, di);
        while (true) {
            while (di > de) { // ������b
	            b >>= 1; // �����ĸ���
	            di >>= 1; // ����
        	}
	        printf("s=%d, %d/%d\n", b, de, di);
        	if (b > 0) { // b>0ʱ����Ҫ����
	            result += b; // ����ۼ�
	            de -= di; // �ü����������
	        	printf("r=%d, %d/%d\n", result, de, di);        		
			} else { // b=0ʱ����������
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
