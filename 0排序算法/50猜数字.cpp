#include <cstdlib>
#include <iostream>
using namespace std;

//��ں���
int main()
{
	const int N = 100;
	int n = rand() % N, m = 0;

	cout << "��ѡ��һ����n��0<=n<100�����������ɶ�������룺";
	while (true)
	{
		cin >> m;
		if (m == n)
		{
			cout << "��ϲ�㣬�¶��ˣ�����" << n << endl;
			break;
		}
		else if (m < n)
		{
			cout << "��С�ˣ��������";
		}
		else
		{
			cout << "�´��ˣ��������";
		}
	}
	return 0;
}
