#include <cstdlib>
#include <iostream>
using namespace std;

const int N=100000;
static int a[N]={0};

//��ʾ�������е�Ԫ��
void show(int a[], int n)
{
	for(int i=0; i<n; i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

//��ں���
int main()
{
	int i,j,t;
	int bj=0,jh=0;

	//����һ�������
	for(i=0; i<N; i++)
	{
		a[i]=rand()%100;
	}
	//cout<<"��ʼ���:"<<endl;
	//show(a,N);//��ʾ 
	for(i=0; i<N; i++)
	{
		bool jhg=false;//������ 
		for(j=0;j<N-i-1;j++) 
		{
			bj++;//�Ƚϴ��� 
			if(a[j]>a[j+1])
			{//��������Ԫ�� 
				jh++;//�������� 
				jhg=true;
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t; 
			}	
		}
		if(!jhg)//һ����û��������
		{//��˵�������Ѿ������� 
			break;
		}
		//cout<<"i="<<i<<endl;
		//show(a,N);
	}
	//cout<<"���ս��:"<<endl;
	//show(a,N);
	//cout<<"�Ƚϣ�" <<bj<<"��������"<<jh;
	return 0;
}
