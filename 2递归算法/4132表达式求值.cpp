//http://bailian.openjudge.cn/practice/4132/
//���ʽ(expression)����������(term)��ӻ����������,
//��һ����(term)������������(factor)��˻�����ĵ����ġ�
//����(factor)������һ���������ɣ�Ҳ�����������������ı��ʽ��
//����ʽ��(2 + 3) * (5 + 7) + 9 / 3
//(2 + 3) * (5 + 7)��һ���9 / 3 Ҳ��һ���
//ǰ�����������ӹ��ɣ������������ɱ��ʽ���ɡ�
//����Ҳ�����������ӹ��ɣ��������������������ɡ�
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
	//cout << "������һ���������ʽ��";
	cout << fixed << setprecision(2) << exp() << endl;
	return 0;
}
