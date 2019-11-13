//http://bailian.openjudge.cn/practice/2697/
//y=f(x)=x*x*x+x+a=0(a>0)£¬Îó²îÎªb(<0.1)
#include <cmath> //abs
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		double a, b, x, y, x1, x2;
		cin >> a >> b;
		x1 = -a, x2 = a;
		while (abs(x2 - x1) > b)
		{
			x = (x2 + x1) / 2;
			y = x * x * x + x + a;
			if (y > 0)
			{
				x2 = x;
			}
			else
			{
				x1 = x;
			}
		}
		x = (x2 + x1) / 2;
		y = x * x * x + x + a;
		cout << fixed << setprecision(6) << x << " ";
		cout << fixed << setprecision(6) << y << endl;
	}
	return 0;
}
