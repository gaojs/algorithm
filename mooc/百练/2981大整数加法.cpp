//http://bailian.openjudge.cn/practice/2981/
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

string trim(const string & a)
{//删除前导字符0 
	bool first_zero = true;
	string::const_iterator it;
	string b;
	
	for(it=a.begin();it!=a.end();++it)
	{//倒序追加 
		if(first_zero && *it!='0')
		{
			first_zero=false;
		}
		if(!first_zero)
		{
			b.push_back(*it);
		}
	}
	if(b.length()==0)
	{//全为0，保留1个 
		b.push_back('0');
	} 
	return b;	 
}

int main()
{
	string a,b;
	
	cin>>a>>b;
	cout<<add(trim(a), trim(b));
	return 0;
} 
