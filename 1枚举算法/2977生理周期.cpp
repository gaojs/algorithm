//http://bailian.openjudge.cn/practice/2977/
//����23�죬����28�죬����33�죬�߷���
//���������߷���ֵ�����p��e��i���Լ�d
//��d֮���´������߷�ͬʱ���ֵ����� 
//input & output sample:
//4 5 6 7		//16994
#include <iostream>
using namespace std;

int main()
{
	const int P = 23, E = 28, I = 33;//���� 
	int p, e, i, d, k;

	cin >> p >> e >> i >> d;
	for (k = d + 1; (k - p) % P != 0; k++);
	for (; (k - e) % E != 0; k += P);
	for (; (k - i) % I != 0; k += P * E);
	cout << (k - d) << endl;
	return 0;
}
