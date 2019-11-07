//三个柱子A,B,C，从A移动到C
#include <iostream>
using namespace std;

//汉诺塔的函数
void hanoi(int n, char src, char mid, char dst)
{
	if (n <= 1)
	{
		cout << n << ":" << src << "--->" << dst << endl;
		return;
	}
	hanoi(n - 1, src, dst, mid);
	cout << n << ":" << src << "--->" << dst << endl;
	hanoi(n - 1, mid, src, dst);
}

int main()
{
	int n;

	cout << "input n(n<=9):";
	cin >> n; //输入整数n=4
	hanoi(n, 'A', 'B', 'C');
	return 0;
}
