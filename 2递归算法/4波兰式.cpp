//波兰式（前缀表达式） 
//- * + 3 4 5 6
//= (3+4)*5-6 =7 
#include <iostream>
using namespace std;

double exp()
{//PolishExpression
	char s[32] = { 0 };

	cin >> s;
	switch (s[0])
	{
	case '+':
		return exp() + exp();
		break;
	case '-':
		return exp() - exp();
		break;
	case '*':
		return exp() * exp();
		break;
	case '/':
		return exp() / exp();
		break;
	default:
		return atof(s);
	}
}


int main()
{
	cout << "请输入波兰式（前缀表达式）：";
	cout << "其值为：" << exp();
	return 0;
}
