//http://bailian.openjudge.cn/practice/4001/
#include <cstring>
#include <queue>
#include <iostream>
using namespace std;

const int N=100000, M=10*N;
//解决广搜问题，队列是个好东西
queue<int> que; 
//走到s[i]坐标i处，已经行走的步数 
int s[M+1]={0}; //step=-1无效 

int cost(int n, int step, int k)
{	
	memset(s,-1,sizeof(s));
	s[n]=step; //初始值 
	que.push(n);
	while(que.size())
	{
		int t=que.front();
		que.pop(); //出队 
		if(t==k) 
		{//抓到了 
			break;
		}
		if(t>0)
		{//左 
			if(s[t-1]<0)
			{//未赋值 
				s[t-1]=s[t]+1;
				que.push(t-1);
			}			
		}
		if(t<M)
		{//右 
			if(s[t+1]<0)
			{//未赋值 
				s[t+1]=s[t]+1;
				que.push(t+1);
			}			
		}
		if(t*2<M)
		{//半 
			if(s[t*2]<0)
			{//未赋值 
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

