//http://bailian.openjudge.cn/practice/2731/
#include <cstdio> 
#include <string> 
#include <iostream>
using namespace std;

string reverse(const string &a)
{//将字符串反转，便于进行运算 
	string b;
	string::const_reverse_iterator it;
	for(it=a.rbegin();it!=a.rend();++it)
	{//倒序追加 
		b.push_back(*it);
	}
	return b;
}

void append(string& s, int& t, int& c)
{
	if(t>=10)
	{//有进位 
		t-=10;
		c=1;
	}
	else
	{//无进位	
		c=0;
	}
	s.push_back(t+'0');
}

string add(const string &a, const string &b)
{
	string s1=reverse(a), s2=reverse(b), s;
	int len1=s1.length(), len2=s2.length();
	int i=0, t1=0, t2=0, t=0, c=0;//carry进位 
	
	for(i=0;i<len1&&i<len2;i++)
	{//处理加法 
		t1=s1[i]-'0';
		t2=s2[i]-'0'; 
		t=t1+t2+c;
		append(s,t,c); 
	}
	for(;i<len1;i++)
	{//处理s1
		t1=s1[i]-'0';
		t=t1+c;
		append(s,t,c); 
	}
	for(;i<len2;i++)
	{//处理s2
		t2=s2[i]-'0';
		t=t2+c;
		append(s,t,c); 
	}
	if(c>0)
	{//处理进位 
		t=c,c=0;
		append(s,t,c); 
	}
	return reverse(s);
}

void append_sub(string& s, int& t, int& c)
{
	if(t<0)
	{//有进位 
		t+=10;
		c=1;
	}
	else
	{//无进位	
		c=0;
	}
	s.push_back(t+'0');
}

string mul(const string &a, const string &b)
{
	string sa=a, sb=reverse(b),s;
	int len=sb.length(),i,t,j;
	
	for(i=0;i<len;i++)
	{
		t=sb[i]-'0';
		for(j=0;j<t;j++)
		{
			s=add(s,sa);
		}
		sa.push_back('0');
	}
	if(s.length()==0)
	{//全为0，显示0
		s.push_back('0');
	} 
	return s;	
}

string factor(int n)
{//求n的阶乘 
	string s("1"),sn;
	for(int i=1;i<=n;i++)
	{
		char a[10]={0};
		snprintf(a,sizeof(a),"%d",i);
		sn=string(a);
		s=mul(s,sn);
		//cout<<i<<","<<sn<<","<<s<<endl;
	}
	return s;	
}

int main()
{//21!就超了 
	int n;
	cin>>n;
	cout<<factor(n);
	return 0;
} 
