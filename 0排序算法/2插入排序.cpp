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
	int i, j, k, t;
	int bj = 0, yd = 0;

	//����һ�������
	for (i = 0; i < N; i++)
	{
		a[i] = rand() % 100;
	}
	//cout<<"��ʼ���:"<<endl;
	//show(a,N);//��ʾ 
	for (i = 1; i < N; i++)
	{
		for (j = 0; j < i; j++)
		{//ѭ�����Ҳ���λ�� 
			bj++;//�Ƚϴ��� 
			if (a[j] > a[i])
			{//�ҵ�����λ�� 	
				t = a[i];//��ʱ���� 
				//ѭ�������ƶ� 
				for (k = i; k > j; k--)
				{
					yd++;//�ƶ����� 
					a[k] = a[k - 1];
				}
				a[j] = t;//����	
				//cout<<"i="<<i<<",";		
				//cout<<"j="<<j<<endl;
				//show(a,N);	
				break;
			}
		}
	}
	//cout<<"���ս��:"<<endl;
	//show(a,N);
	//cout<<"�Ƚϣ�" <<bj<<"���ƶ���"<<yd;
	return 0;
}
