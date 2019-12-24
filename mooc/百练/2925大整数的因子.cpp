//http://bailian.openjudge.cn/practice/2925/
#include <string> 
#include <iostream>
using namespace std;

int mod(const string &s, int k)
{
	int c=0,i;
	for(i=0;i<s.length();i++)
	{
		c=c*10+s[i]-'0';
		c=c%k;
	}
	return c;
}

void factor(const string &s)
{//求s的2~9的因子 
	bool exist = false;		
	for(int k=2;k<=9;k++)
	{
		if(mod(s,k)==0)
		{
			cout<<k<<" ";
			exist = true;
		}
	}	
	if(!exist)
	{
		cout<<"none";
	}
}

int main()
{
	string s;
	
	cin>>s;
	factor(s);
	return 0;
} 
