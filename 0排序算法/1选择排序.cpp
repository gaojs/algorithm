#include <cstdlib>
#include <iostream>
using namespace std;

const int N = 100000;
static int a[N] = { 0 };

//��ʾ�������е�Ԫ��
void show(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

//��ں���
int main()
{
	int i, j, t, min;
	int bj = 0, jh = 0;

	//����һ�������
	for (i = 0; i < N; i++)
	{
		a[i] = rand() % 100;
	}
	//cout<<"��ʼ���:"<<endl;
	//show(a,N);//��ʾ 
	for (i = 0; i < N - 1; i++)
	{
		min = i;//��С���� 
		for (j = i + 1; j < N; j++)
		{//ѭ��������С�� 
			bj++;//�Ƚϴ��� 
			if (a[j] < a[min])
			{//�����˸�С�� 
				min = j;
			}
		}
		if (min != i)
		{//��������Ԫ�� 
			jh++;//�������� 
			t = a[i];
			a[i] = a[min];
			a[min] = t;
		}
		//cout<<"i="<<i<<endl;
		//show(a,N);
	}
	//cout<<"���ս��:"<<endl;
	//show(a,N);
	//cout<<"�Ƚϣ�" <<bj<<"��������"<<jh;
	return 0;
}
