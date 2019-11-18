//http://bailian.openjudge.cn/practice/4132/
//表达式(expression)是由若干项(term)相加或相减得来的,
//而一个项(term)是由若干因子(factor)相乘或相除的得来的。
//因子(factor)可以是一个整数构成，也可以由括号括起来的表达式。
//如表达式：(2 + 3) * (5 + 7) + 9 / 3
//(2 + 3) * (5 + 7)是一个项，9 / 3 也是一个项，
//前者由两个因子构成，其中因子又由表达式构成。
//后者也是由两个因子构成，这两个因子由整数构成。
#include <iostream>
#include <iomanip>
using namespace std;

double exp();
double factor()
{//(
	double a = 0;
	while (true)
	{
		char c = cin.peek();
		switch (c)
		{
		case ' ':
			c = cin.get();
			continue;
		case '(':
			c = cin.get();
			a = exp();
			c = cin.get();
			return (a);
		default:
			cin >> a;
			return a;
		}
	}
}

double term()
{//*/
	double a = factor(), b = 0;
	while (true)
	{
		char c = cin.peek();
		switch (c)
		{
		case ' ':
			c = cin.get();
			continue;
		case '*':
			c = cin.get();
			b = factor();
			a = (a * b);
			break;
		case '/':
			c = cin.get();
			b = factor();
			a = (a / b);
			break;
		case '=':
		default:
			return a;
		}
	}
}

double exp()
{//+-
	double a = term(), b = 0;
	while (true)
	{
		char c = cin.peek();
		switch (c)
		{
		case ' ':
			c = cin.get();
			continue;
		case '-':
			c = cin.get();
			b = term();
			a = (a - b);
			break;
		case '+':
			c = cin.get();
			b = term();
			a = (a + b);
			break;
		case '=':
		default:
			return a;
		}
	}
}


int main()
{
	//cout << "请输入一个算术表达式：";
	cout << fixed << setprecision(2) << exp() << endl;
	return 0;
}
