//http://bailian.openjudge.cn/practice/4152/
//http://cxsjsxmooc.openjudge.cn/2019t2fall6/003/
//http://cxsjsxmooc.openjudge.cn/2019t2fallall/014/
#include <vector>
#include <string>
#include <iostream>
using namespace std;

int cmp(const string& s1, const string& s2)
{//比较大小，即判断(s1-s2)的值
	if (s1.length() < s2.length())
	{//s1<s2，返回-1
		return -1;
	}
	else if (s1.length() > s2.length())
	{//s1>s2，返回1
		return 1;
	}
	else //if (s1.length() == s2.length())
	{//s1==s2，返回0
		return s1.compare(s2);
	}
}

string reverse(const string& s)
{//反转一个字符串
	string t;
	string::const_reverse_iterator it;
	for (it = s.rbegin(); it != s.rend(); ++it)
	{
		t.push_back(*it);
	}
	return t;
}

void append(string& result, int& t, int& carry)
{//根据整数t和进位标志carry，追加字符到字符串后
	if (t >= 10)
	{//有进位
		carry = 1;
		t -= 10;
	}
	else
	{//无进位
		carry = 0;
	}
	result.push_back(t + '0');
}

string add(const string& s1, const string& s2)
{
	string s1r = reverse(s1), s2r = reverse(s2);
	int len1 = s1r.length(), len2 = s2r.length();
	int t1, t2, t, i, carry = 0; //进位
	string result; //结果
	for (i = 0; i < len1 && i < len2; i++)
	{//从0位开始处理s1r+s2r
		t1 = s1r[i] - '0';
		t2 = s2r[i] - '0';
		t = t1 + t2 + carry;
		append(result, t, carry);
	}
	for (; i < len1; i++)
	{//从i位开始处理s1r
		t1 = s1r[i] - '0';
		t = t1 + carry;
		append(result, t, carry);
	}
	for (; i < len2; i++)
	{//从i位开始处理s2r
		t2 = s2r[i] - '0';
		t = t2 + carry;
		append(result, t, carry);
	}
	if (carry)
	{//还有进位
		t = 0; //把进位也加上
		append(result, carry, t);
	}
	return reverse(result);
}

const int M = 50; //字符串的最大长度
string MAX = string(M, '9'); //最大值

string find(const string& s, int m)
{
	if (m == 0)
	{//没有加号，原值
		return s;
	}
	else if (m >= (int)s.length())
	{//加号太多，放不下
		return MAX;
	}	 
	else
	{//加号从1开始放
		string t1, t2, sum, min = MAX;
		int i, len = (int)s.length();
		for (i = 1; i <= len - m; i++)
		{//第一个加号的位置，从左往右尝试
			t1 = s.substr(0, i);
			if (cmp(t1, min) > 0) continue;
			t2 = find(s.substr(i), m - 1);
			if (cmp(t2, min) > 0) continue;
			sum = add(t1, t2); //这里要用add()
			if (cmp(min, sum) > 0) //这里要用cmp()
			{//找到更小的值了
				min = sum;
			}
		}
		return min;
	}
}

int main()
{
	int m;
	string s;

	while (cin >> m)
	{
		cin >> s;
		cout << find(s, m) << endl;
	}
	return 0;
}
