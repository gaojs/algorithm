//http://bailian.openjudge.cn/practice/2737/
#include <string> 
#include <iostream>
using namespace std;

string trim(const string & a)
{//ɾ��ǰ���ַ�0 
	bool first_zero = true;
	string::const_iterator it;
	string b;
	
	for(it=a.begin();it!=a.end();++it)
	{//����׷�� 
		if(first_zero && *it!='0')
		{
			first_zero=false;
		}
		if(!first_zero && *it!='\0')
		{
			b.push_back(*it);
		}
	}
	if(b.length()==0)
	{//ȫΪ0������1�� 
		b.push_back('0');
	} 
	return b;	 
}

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

int cmp(const string &s1, const string &s2)
{
	int len1=s1.length(), len2=s2.length();
	if(len1<len2)
	{
		return -1;
	}
	else if(len1>len2)
	{
		return 1;
	}
	else// if(len1==len2)
	{
		return s1.compare(s2);
	}
}

void append2(string& s, int& t, int& c)
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

string sub(const string &a, const string &b)
{
	int len1, len2, i=0, t1=0, t2=0, t=0, c=0;
	string s1, s2, s; //c=carry��λ 
	bool swapped; 

	if(cmp(a,b)<0)
	{//����s1��s2 
		s1=reverse(b); 
		s2=reverse(a); 
		swapped = true;
	}
	else
	{//���ý��� 
		s1=reverse(a); 
		s2=reverse(b); 
		swapped = false;
	}
	len1=s1.length(), len2=s2.length();
	for(i=0;i<len1&&i<len2;i++)
	{//����ӷ� 
		t1=s1[i]-'0';
		t2=s2[i]-'0'; 
		t=t1-t2-c;
		append2(s,t,c); 
	}
	for(;i<len1;i++)
	{//����s1
		t1=s1[i]-'0';
		t=t1-c;
		append2(s,t,c); 
	}
	s=trim(reverse(s)); 
	if(swapped)
	{//��������Ϊ������ǰ���-�� 
		s.insert(s.begin(), '-');
	} 
	return s;
}

string div(const string &a, const string &b, string &m)
{//a/b,m=a%b; 	
	string sa=a.substr(0,b.length()),s;	
	for(int i=b.length();i<=a.length();i++)
	{
		int d=0;
		while(cmp(sa,b)>=0)
		{		
			sa=sub(sa,b);		
			d++;		
		}
		s.push_back(d+'0');
		sa.push_back(a[i]);
		sa=trim(sa); //����Ϊ00
	}	
	m=sa;
	return trim(s);
}

int main()
{
	string a,b,d,m;
	
	cin>>a>>b;
	d=div(trim(a), trim(b), m);
	cout<<d<<endl<<m<<endl;
	return 0;
} 
