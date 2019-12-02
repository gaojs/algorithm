//http://bailian.openjudge.cn/practice/2806/
//http://cxsjsxmooc.openjudge.cn/privatetest/3/
#include <cstring> 
#include <iostream> 
using namespace std;

const int N=200;
char a[N],b[N];
int c[N+1][N+1]={0};

int common(char a[], int n, char b[], int m)
{
	int i,j;
	
	if(n<=0||m<=0)
	{
		return 0;
	}
	for(i=0;i<=n;i++)
	{
		c[i][0]=0;
	}
	for(j=0;j<=m;j++)
	{
		c[0][j]=0;
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(a[i-1]==b[j-1]) 
			{
				c[i][j]=c[i-1][j-1]+1;
			}
			else
			{
				int n1=c[i-1][j];
				int n2=c[i][j-1];
				c[i][j]=n1>n2?n1:n2;
			}
		}
	}
	return c[n][m];
}
 
int main()
{
	while(cin>>a>>b)//递归仍然会超时，还是动规吧 
	{ 
		cout<<common(a,strlen(a),b,strlen(b))<<endl;
	} 
	return 0;
}
