#include <cstdio> //scanf更快 
#include <algorithm>
#include <iostream>
using namespace std;

const int N=100000;
int a[N]={0};

//b是begin，e是end，但(b,e)不包括e 
long long ni(int a[], int b, int e)
{ 	
	if(b>=e-1)
	{
		//cout<<"b="<<b<<",e="<<e<<";a["<<b<<"]="<<a[b]<<",s=0"<<endl;
		return 0;
	}
	else
	{
		long long s1,s2,s3; 
		int mid=(b+e)/2, i,j;
		s1=ni(a,b,mid);
		//cout<<"b="<<b<<",e="<<e<<";mid="<<mid<<";s1="<<s1<<endl;
		s2=ni(a,mid,e);
		//cout<<"b="<<b<<",e="<<e<<";mid="<<mid<<";s2="<<s2<<endl;
		sort(a+b,a+mid);
		sort(a+mid,a+e);
		//6		2 6 3 4 5 1
		i=b,j=mid, s3=0;
		while(i<mid && j<e)
		{			
			while(i<mid && a[i]<=a[j])
			{
				i++;			
			}
			while(j<e && a[i]>a[j])
			{
				s3+=mid-i;
				//cout<<"b="<<b<<",e="<<e<<";i="<<i<<",j="<<j<<";m="<<mid<<",s="<<mid-i<<endl; 
				j++;
			}
		}		
		//cout<<"b="<<b<<",e="<<e<<";mid="<<mid<<";s3="<<s3<<endl;		
		return s1+s2+s3;	
	}
}

int main()
{
	int n,i;
	
	//freopen("F:\in.txt","r",stdin);
	cin >> n;
	for(i=0;i<n;i++)
	{
		//cin>>a[i];
		scanf("%d",&a[i]);
	}
	cout<<ni(a,0,n);
	return 0;
}
