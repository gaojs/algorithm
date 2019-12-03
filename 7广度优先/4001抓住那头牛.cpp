//http://bailian.openjudge.cn/practice/4001/
#include <cstring>
#include <queue>
#include <iostream>
using namespace std;

const int N=100000, M=10*N;
//����������⣬�����Ǹ��ö���
queue<int> que; 
//�ߵ�s[i]����i�����Ѿ����ߵĲ��� 
int s[M+1]={0}; //step=-1��Ч 

int cost(int n, int step, int k)
{	
	memset(s,-1,sizeof(s));
	s[n]=step; //��ʼֵ 
	que.push(n);
	while(que.size())
	{
		int t=que.front();
		que.pop(); //���� 
		if(t==k) 
		{//ץ���� 
			break;
		}
		if(t>0)
		{//�� 
			if(s[t-1]<0)
			{//δ��ֵ 
				s[t-1]=s[t]+1;
				que.push(t-1);
			}			
		}
		if(t<M)
		{//�� 
			if(s[t+1]<0)
			{//δ��ֵ 
				s[t+1]=s[t]+1;
				que.push(t+1);
			}			
		}
		if(t*2<M)
		{//�� 
			if(s[t*2]<0)
			{//δ��ֵ 
				s[t*2]=s[t]+1;
				que.push(t*2);
			}						
		}		
	} 
	return s[k];
}


int main()
{
	int n,k;
	
	cin>>n>>k;
	cout<<cost(n,0,k);
	return 0;
}

