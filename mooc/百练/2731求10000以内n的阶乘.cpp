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
	//cout<<"s="<<s<<",t="<<t<<",c="<<c<<endl;
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

string add(string &a, int b, int n)
{//加法 
	int len=a.length(),i,t1,t2,t,c=0;
	string s=a.substr(0,n);
	 
	for(i=len;i<n;i++)
	{//容错 
		s.push_back('0');	
	}
	for(i=n;i<len&&b>0;i++,b/=10)
	{//处理a+b
		t1=a[i]-'0';
		t2=b%10;
		t=t1+t2+c;
		append(s,t,c);
	}
	for(;i<len;i++)
	{//处理a
		t1=a[i]-'0';
		t=t1+c;
		append(s,t,c);		
	}
	for(;b>0;b/=10)
	{//处理b 
		t2=b%10;
		t=t2+c;
		append(s,t,c);	
	}
	if(c>0)
	{//处理进位 
		t=c,c=0;
		append(s,t,c); 
	}
	return s;
}

string mul(const string &a, int n)
{//乘法 
	int len=a.length(),i,t,j;
	string s;
	//cout<<"a="<<a<<endl;
	for(i=0;i<len;i++)
	{
		t=(a[i]-'0')*n;
		//cout<<"s="<<s<<",t="<<t<<",i="<<i<<endl;
		s=add(s,t,i);
	}
	return s;	
}

string factor(int n)
{//求n的阶乘 
	string s("1");
	for(int i=1;i<=n;i++)
	{
		s=mul(s,i);
		//cout<<i<<":"<<reverse(s)<<endl; 
	}
	return reverse(s);	
}

int main()
{//n=21,longlong就超了 
	int n=6;
	cin>>n;
	if(n<=0) cout<<0;
	else cout<<factor(n);
	return 0;
} 
