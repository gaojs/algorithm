#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

const int N=100000;
int a[N]={0};

void swap(int &a, int &b)
{
	int t=a;
	a=b;
	b=t;	
}

//��ǰk����������ƶ�������� 
void move(int a[], int n, int k)
{
	int i=0,j=n-1;	
	//cout<<"n="<<n<<",k="<<k<<endl;
	while(i<j)
	{//����a[0]��Ķ��Ƶ���� 
		while(i<j && a[i]>=a[j]) j--;
			swap(a[i],a[j]);
		//cout<<"j="<<j<<" ";
		while(i<j && a[i]>=a[j]) i++;
			swap(a[i],a[j]);
		//cout<<",i="<<i<<endl;
	}
	if(i+1==k) return; //i+1�������� 
	if(i+1<k)	move(a+i+1,n-i-1,k-i-1);  
	else if(i+1>k) move(a,i+1,k);
}

int main()
{
	int n,k,i;
	
	cin >> n;
	for(i=0;i<n;i++)
	{
		//cin>>a[i];
		scanf("%d",&a[i]);
	}
	cin>>k;	
	move(a,n,k);
	sort(a,a+k,greater<int>());
	for(i=0;i<k;i++)
	{
		//cout<<a[i]<<endl;
		printf("%d\n",a[i]);
	}	
	return 0;
}
