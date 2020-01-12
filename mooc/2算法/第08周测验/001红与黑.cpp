#include <iostream> 
using namespace std;

const int W=20,H=20;
//存放值的数组 
char a[H][W]={0};
int count=0;

void dfs(char a[H][W], int h, int w, int r, int c) 
{
	//cout<<"r="<<r<<",c="<<c<<",a="<<a[r][c]<<endl;
	if(a[r][c]=='.')
	{//当前位置，可以走 
		count++;
		a[r][c]='@'; //走过 
		if(r>0&&a[r-1][c]=='.') 
		{//上 
			dfs(a,h,w,r-1,c);
		}
		if(r<h-1&&a[r+1][c]=='.')
		{//下 
			dfs(a,h,w,r+1,c);
		}
		if(c>0&&a[r][c-1]=='.') 
		{//左 
			dfs(a,h,w,r,c-1);
		}
		if(c<w-1&&a[r][c+1]=='.') 
		{//右 
			dfs(a,h,w,r,c+1);
		}
	}
}

int main()
{		
	int w,h,i,j,r,c;
	
	while(cin>>w>>h && w && h)//宽和高 
	{//逐个输入各组数据 
		//cout<<"w="<<w<<",h="<<h<<endl;
		for(i=0;i<h;i++)
		{
			for(j=0;j<w;j++)
			{
				cin>>a[i][j];
				if(a[i][j]=='@')
				{//起始点 
					a[i][j]='.';
					r=i,c=j;	
				}	
			} 
		}
		count=0;
		dfs(a,h,w,r,c);
		cout<<count<<endl;
	}
	return 0;
}
