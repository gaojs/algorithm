#include <cstdlib>
#include <iostream>
using namespace std;

//ͳ�ƱȽϴ����ͽ������� 
const int N=1000000;
static int a[N]={0};
int bj=0,jh=0;

//��ʾ�������е�Ԫ��
void show(int a[], int n)
{
	for(int i=0; i<n; i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

//����a��b������ 
void swap(int &a, int &b)
{
	int t;
	t=a;
	a=b;
	b=t; 
	jh++;//�������� 
} 

//b�ǿ�ʼ��begin����e�ǽ�����end�� 
void QuickSort(int a[], int b, int e)
{
	if(b>=e)
	{//�Ѿ��ź����� 
		return;
	}
	int i=b,j=e;	
	//cout<<"i="<<i<<",j="<<j<<endl;
	//�ؼ�Ԫ�أ�Ĭ��Ϊ��һ�� 
	//������a[k]�Ķ��Ƶ����ұ�
	//��С��a[k]�Ķ��Ƶ������
	while(i<j)
	{
		//���������ҵ�һ�����Խ����� 
		while(j>i && a[j]>=a[i]) 
		{
			bj++;//�Ƚϴ��� 
			j--;
		}
		//if(i>=j) break; 
		swap(a[i], a[j]);
		//show(a,N);//��ʾ 
		//�������ң��ҵ�һ�����Խ����� 
		while(i<j && a[i]<=a[j])
		{
			bj++;//�Ƚϴ��� 
			i++; 
		} 
		//if(i>=j) break; 
		swap(a[i], a[j]);
		//show(a,N);//��ʾ 
	}
	//i=j�Ž�����i�����м�Ԫ�� 
	QuickSort(a, b, i-1);
	QuickSort(a, i+1, e);		
}

//��ں���
int main()
{
	int i,j,t;

	bj=0,jh=0;
	//����һ�������
	for(i=0; i<N; i++)
	{
		a[i]=rand()%100;
	}
	//cout<<"��ʼ���:"<<endl;
	//show(a,N);//��ʾ 
	QuickSort(a,0,N-1); //���� 
	//cout<<"���ս��:"<<endl;
	//show(a,N);//��ʾ 
	//cout<<"�Ƚϣ�" <<bj<<"��������"<<jh;
	return 0;
}
