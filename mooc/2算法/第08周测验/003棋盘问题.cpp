#include <cstring> 
#include <iostream> 
using namespace std;

const int N=8;
//���ֵ������ 
char a[N+1][N+1]={0};
int sizeofa=0;//�����С 
int count;//������Ŀ

void print(char a[N+1][N+1], int n)
{
	for(int i=0;i<n;i++)
	{//�ӵ�b�п�ʼ���� 
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
	{//ȫ���ڷ������ 
		count++;
	}
	else
	{
		int i,j,r,c;
		char b[N+1][N+1]={0};
		memcpy(b,a,sizeofa);
		//print(b,n);
		for(i=br;i<=n-k;i++)
		{//�ӵ�b�п�ʼ���� 
			for(j=0;j<n;j++)
			{
				if(b[i][j]=='#')
				{
					bool ok=true;
					for(r=0;r<n;r++)
					{//�鿴ͬ�� 
						if(b[r][j]=='@')
						{//ͬ���Ѿ������� 
							ok=false;
							break;
						}
					}
					for(c=0;c<n;c++)
					{//�鿴ͬ�� 
						if(b[i][c]=='@')
						{
							ok=false;
							break;
						}	
					} 
					if(ok)
					{//���԰�
						//cout<<"i="<<i<<",j="<<j<<",k="<<k<<endl;
						b[i][j]='@';//����
						dfs(b,n,k-1,i+1); 
						b[i][j]='#';//���� 
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
	{//����n*n,������k 
		if(n<0 || k<0)
		{//-1��ʾ���� 
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
