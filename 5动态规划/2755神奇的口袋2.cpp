//http://bailian.openjudge.cn/practice/2755/
#include <cstring> 
#include <iostream> 
using namespace std;

const int W = 40;//�ڴ���������40
const int K = 20;//��Ʒ����20��
//ways[w][k]��k����Ʒ���ճ����w�ķ�����
int ways[W + 1][K + 1]; 
int a[K + 1] = { 0 }; 

int main()
{
	int n, i, w, k;

	cin >> n;
	for (i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	memset(ways, 0, sizeof(ways));
	for (k = 0; k <= n; k++)
	{//ֻҪ��ѡ������1�����
		ways[0][k] = 1;
	}
	for (w = 1; w <= W; w++)
	{
		for (k = 1; k <= n; k++)
		{
			//��ѡa[k]�����
			ways[w][k] = ways[w][k - 1];
			if ((w - a[k]) >= 0)
			{//ѡa[k]�����
				ways[w][k] += ways[w - a[k]][k - 1];
			}
		}
	}
	cout << ways[40][n];
	return 0;
}
