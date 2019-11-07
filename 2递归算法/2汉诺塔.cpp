//��������A,B,C����A�ƶ���C
#include <iostream>
using namespace std;

//��ŵ���ĺ���
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
	cin >> n; //��������n=4
	hanoi(n, 'A', 'B', 'C');
	return 0;
}
