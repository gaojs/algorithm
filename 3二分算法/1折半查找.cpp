#include <cstdlib> //rand()/qsort()
#include <iostream> //cout() 
using namespace std;

//��ʾ�������е�Ԫ��
void show(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

//qsortҪ�Լ����庯���������Ƕ���ĺ���
int cmp(const void* a, const void* b)
{
	//a>b,f=1; a=b,f=0; a<b,f=-1; 
	return *(int*)a - *(int*)b;
}

//��ں���
int main()
{
	const int N = 10, M = 100;
	int a[N] = { 0 }, i, j, n, m, c;

	//����������� 
	for (i = 0; i < N; i++)
	{
		a[i] = rand() % 100;
	}
	//cstdlib����Ŀ���������
	qsort(a, N, sizeof(int), cmp);
	show(a, N);
	//��ʾ�û���������ҵ�Ԫ��
	cout << "input n(0~99)��";
	cin >> n;
	//��ʼ�۰���� 
	i = 0, j = N, c = 0;
	while (i <= j)
	{
		c++;
		m = (i + j) / 2;
		if (a[m] == n)
		{
			cout << "Found, it's at " << i << "." << endl;
			cout << "We find it " << c << " times." << endl;
			return 0;
		}
		else if (a[m] < n)
		{
			i = m + 1;
		}
		else
		{
			j = m - 1;
		}
	}
	cout << "Not found!" << endl;
	cout << "We find it " << c << " times." << endl;
	return 0;
}
