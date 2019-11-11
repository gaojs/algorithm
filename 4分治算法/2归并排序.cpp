#include <cstdlib>
#include <iostream>
using namespace std;

//ͳ�ƱȽϴ����ͽ������� 
const int N = 1000000;
static int a[N] = { 0 };
static int b[N] = { 0 };
int bj = 0, yd = 0;

//��ʾ�������е�Ԫ��
void show(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

//s�ǿ�ʼ��start����m���м䣨middle����e�ǽ�����end�� 
void Merge(int a[], int s, int m, int e)
{
	int i = s, j = m + 1, k = 0;
	while (i <= m && j <= e)
	{
		bj++;//�Ƚϴ��� 
		if (a[i] <= a[j])
		{
			yd++;//�ƶ����� 
			b[k++] = a[i++];
		}
		else
		{
			yd++;//�ƶ����� 
			b[k++] = a[j++];
		}
	}
	while (i <= m)
	{
		yd++;//�ƶ����� 
		b[k++] = a[i++];
	}
	while (j <= e)
	{
		yd++;//�ƶ����� 
		b[k++] = a[j++];
	}
	for (i = 0; i < e - s + 1; i++)
	{
		yd++;//�ƶ����� 
		a[s + i] = b[i];
	}

}

//s�ǿ�ʼ��start����e�ǽ�����end�� 
void MergeSort(int a[], int s, int e)
{
	if (s >= e)
	{//�Ѿ��ź����� 
		return;
	}
	int m = s + (e - s) / 2;
	MergeSort(a, s, m);
	MergeSort(a, m + 1, e);
	Merge(a, s, m, e);
	//cout<<"i="<<s<<",j="<<e<<endl;
	//show(a,N);//��ʾ 
}

//��ں���
int main()
{
	int i, j, t;

	bj = 0, yd = 0;
	//����һ�������
	for (i = 0; i < N; i++)
	{
		a[i] = rand() % 100;
	}
	//cout<<"��ʼ���:"<<endl;
	//show(a,N);//��ʾ 
	MergeSort(a, 0, N - 1); //���� 
	//cout<<"���ս��:"<<endl;
	//show(a,N);//��ʾ 
	//cout<<"�Ƚϣ�" <<bj<<"���ƶ���"<<yd;
	return 0;
}
