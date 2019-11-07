//ʹ�õݹ��㷨�����Խ����ѭ��ת���ɵݹ飬��˼· 
//�˻ʺ����⣬�ӵ�һ�п�ʼ�ڷţ�����ÿ�м���Ƿ��ͻ 
#include <cmath> //�õ�abs()
#include <iostream>
using namespace std;

//N����֧�ֵ��������������� (���б�Ŵ�1��ʼ)
const int N = 100;
//QueenPos[i]��ʾ��i�еĻʺ����������� (i��1��ʼ)
int QueenPos[N + 1] = { 0 };

//����n�ʺ�����ĵ�k�еĽ������ 
void Queen(int k, int n)
{
	int i, j;

	if (k > n)
	{//�Ѿ��������n�� 
		for (k = 1; k <= n; k++)
		{//kΪ����
			cout << QueenPos[k] << " ";
		}
		cout << endl;
		return;
	}
	//���ҵ�k�еİڷ�λ�� 
	for (i = 1; i <= n; i++)
	{//kΪ������iΪ���� 
		//�������֮ǰk-1���Ƿ��ͻ 
		for (j = 1; j <= k - 1; j++)
		{//jΪ������ QueenPos[j]Ϊ���� 
			if (i == QueenPos[j])
			{//������ͬ�������ͻ 
				break;
			}
			if (abs(k - j) == abs(i - QueenPos[j]))
			{//�в����в���ͬ��б���ͻ 
				break;
			}
		}
		if (j == k)
		{//����ͻ 
			QueenPos[k] = i;
			//�����ڷ���һ�� 
			Queen(k + 1, n);
		}
	}
}

int main()
{
	int n;

	cout << "input n(n<=100):";
	cin >> n; //���뼸�м��е�n 
	Queen(1, n); //�ӵ�1�п�ʼ 
	return 0;
}
