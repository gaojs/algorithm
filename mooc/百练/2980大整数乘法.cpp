//http://bailian.openjudge.cn/practice/2980/
#include <string> 
#include <iostream>
using namespace std;

string reverse(const string &a)
{//���ַ�����ת�����ڽ������� 
	string b;
	string::const_reverse_iterator it;
	for(it=a.rbegin();it!=a.rend();++it)
	{//����׷�� 
		b.push_back(*it);
	}
	return b;
}

void append(string& s, int& t, int& c)
{
	if(t>=10)
	{//�н�λ 
		t-=10;
		c=1;
	}
	else
	{//�޽�λ	
		c=0;
	}
	s.push_back(t+'0');
}

string add(const string &a, const string &b)
{
	string s1=reverse(a), s2=reverse(b), s;
	int len1=s1.length(), len2=s2.length();
	int i=0, t1=0, t2=0, t=0, c=0;//carry��λ 
	
	for(i=0;i<len1&&i<len2;i++)
	{//����ӷ� 
		t1=s1[i]-'0';
		t2=s2[i]-'0'; 
		t=t1+t2+c;
		append(s,t,c); 
	}
	for(;i<len1;i++)
	{//����s1
		t1=s1[i]-'0';
		t=t1+c;
		append(s,t,c); 
	}
	for(;i<len2;i++)
	{//����s2
		t2=s2[i]-'0';
		t=t2+c;
		append(s,t,c); 
	}
	if(c>0)
	{//�����λ 
		t=c,c=0;
		append(s,t,c); 
	}
	return reverse(s);
}

void append_sub(string& s, int& t, int& c)
{
	if(t<0)
	{//�н�λ 
		t+=10;
		c=1;
	}
	else
	{//�޽�λ	
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
	{//ȫΪ0����ʾ0
		s.push_back('0');
	} 
	return s;	
}

int main()
{
	string a,b;
	
	cin>>a>>b;
	cout<<mul(a, b);
	return 0;
} 
