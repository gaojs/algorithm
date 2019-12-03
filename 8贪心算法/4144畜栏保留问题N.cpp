//http://bailian.openjudge.cn/practice/4144/
#include <queue> //priority_queue 
#include <algorithm>
#include <iostream>
using namespace std;

struct Cow
{//��ţ 
	int no; //��ţ��ţ���0��ʼ 
	int begin; //��ʼʱ�� 
	int end; //����ʱ��
	
	//���������const����ʾ���ı��Ա���� 
	bool operator<(const Cow& a) const 
	{//������ʱ�����򣬱����ҵ����� 
		return end>a.end; //����Ҫע�� 
	}
};

bool cmp(const Cow& a, const Cow& b) 
{//����ʼʱ������˭�磬�Ȱ���˭ 
	if(a.begin==b.begin) return a.end<b.end;
	else return a.begin<b.begin;
}

//���ȶ��У��õĺܹؼ� 
//priority_queueĬ��Ϊ�󶥶ѣ����Ѷ�Ԫ��Ϊ�������Ԫ��
priority_queue<Cow> pq;//��������ţ
const int N=50000, M=1000000;
//����������õ�Ҳ������ 
int cowStalls[N+1]={0};
Cow a[N+1]={0};

int count(Cow a[], int n)
{	
	int m=0,i;
	for(i=0;i<n;i++)
	{//Ϊÿһͷ��ͷ�������� 
		if(pq.size() && pq.top().end<a[i].begin)
		{//�ܰ��Ž���������������Ѿ�OK
			//��ţ��������ţ����ճ�������ͷ��ţһ�� 
			cowStalls[a[i].no]=cowStalls[pq.top().no]; 
			pq.pop();//����
			pq.push(a[i]);//����			
		}
		else
		{
			m++; //������һ������ 
			cowStalls[a[i].no]=m;
			pq.push(a[i]);//����	
		} 
	}
	return m;
}

int main()
{
	int n,i;
	
	cin>>n;
	for(i=0;i<n;i++)
	{//���� 
		a[i].no=i;
		cin>>a[i].begin;
		cin>>a[i].end;
	}
	sort(a, a+n, cmp); //���� 
	cout<<count(a,n)<<endl;	
	for(i=0;i<n;i++)
	{//��� 
		cout<<cowStalls[i]<<endl;
	}
	return 0;
}
