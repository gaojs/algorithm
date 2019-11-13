//http://bailian.openjudge.cn/practice/2697/
//方程：f(x)=x3-5x2+10x-80=0,精确到小数点后9位
//f'(x)=3x2-10x+10, b2-4ac=100-4*3*10=-20<0
//f(10)=10*10*10-5*10*10+10*10-80=520>0
#include <cmath> //abs
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	const double e = 1e-9;
	double y, x, x1 = 0, x2 = 10;

	while (true)
	{
		x = (x2 + x1) / 2;
		y = x * x * x - 5 * x * x + 10 * x - 80;
		if (abs(y) < e)
		{
			break;
		}
		else if (y > 0)
		{
			x2 = x;
		}
		else
		{
			x1 = x;
		}
	}
	cout << fixed << setprecision(9) << x << " ";
	return 0;
}
