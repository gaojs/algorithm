#include <cstring> 
#include <iostream> 
using namespace std;

const int N=8;
//存放值的数组 
char a[N+1][N+1]={0};
int sizeofa=0;//矩阵大小 
int count;//方案数目

void print(char a[N+1][N+1], int n)
{
	for(int i=0;i<n;i++)
	{//从第b行开始尝试 
		for(int j=0;j<n;j++)
		{
			cout<<a[i][j]; 
		}
		cout<<endl;
	} 	
}

void dfs(char a[N+1][N+1], int n, int k,int br) 
{
	//cout<<"dfs,n="<<n<<",k="<<k<<",br="<<br<<endl;
	if(k==0)
	{//全部摆放完毕了 
		count++;
	}
	else
	{
		int i,j,r,c;
		char b[N+1][N+1]={0};
		memcpy(b,a,sizeofa);
		//print(b,n);
		for(i=br;i<=n-k;i++)
		{//从第b行开始尝试 
			for(j=0;j<n;j++)
			{
				if(b[i][j]=='#')
				{
					bool ok=true;
					for(r=0;r<n;r++)
					{//查看同行 
						if(b[r][j]=='@')
						{//同行已经有棋子 
							ok=false;
							break;
						}
					}
					for(c=0;c<n;c++)
					{//查看同列 
						if(b[i][c]=='@')
						{
							ok=false;
							break;
						}	
					} 
					if(ok)
					{//可以摆
						//cout<<"i="<<i<<",j="<<j<<",k="<<k<<endl;
						b[i][j]='@';//摆上
						dfs(b,n,k-1,i+1); 
						b[i][j]='#';//撤回 
					}
				} 
			} 
		}
	} 	
}

int main()
{		
	int n,k,i,j,r,c;
	
	sizeofa=sizeof(a);
	while(cin>>n>>k)
	{//棋盘n*n,棋子数k 
		if(n<0 || k<0)
		{//-1表示结束 
			break;
		} 
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				cin>>a[i][j];
			} 
		}
		count=0;
		dfs(a,n,k,0);
		cout<<count<<endl;
	}
	return 0;
}
