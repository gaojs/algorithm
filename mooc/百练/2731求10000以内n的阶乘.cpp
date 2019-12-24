//http://bailian.openjudge.cn/practice/2731/
#include <cstdio> 
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

string factor(int n)
{//��n�Ľ׳� 
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
{//21!�ͳ��� 
	int n;
	cin>>n;
	cout<<factor(n);
	return 0;
} 
