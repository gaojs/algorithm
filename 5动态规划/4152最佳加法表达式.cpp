//http://bailian.openjudge.cn/practice/4152/
//http://cxsjsxmooc.openjudge.cn/2019t2fall6/003/
//http://cxsjsxmooc.openjudge.cn/2019t2fallall/014/
#include <string>
#include <iostream>
using namespace std;

int cmp(const string& s1, const string& s2)
{//�Ƚϴ�С�����ж�(s1-s2)��ֵ
	if (s1.length() < s2.length())
	{//s1<s2������-1
		return -1;
	}
	else if (s1.length() > s2.length())
	{//s1>s2������1
		return 1;
	}
	else //if (s1.length() == s2.length())
	{//s1==s2������0
		return s1.compare(s2);
	}
}

string reverse(const string& s)
{//��תһ���ַ���
	string t;
	string::const_reverse_iterator it;
	for (it = s.rbegin(); it != s.rend(); ++it)
	{
		t.push_back(*it);
	}
	return t;
}

void append(string& result, int& t, int& carry)
{//��������t�ͽ�λ��־carry��׷���ַ����ַ�����
	if (t >= 10)
	{//�н�λ
		carry = 1;
		t -= 10;
	}
	else
	{//�޽�λ
		carry = 0;
	}
	result.push_back(t + '0');
}

string add(const string& s1, const string& s2)
{
	string s1r = reverse(s1), s2r = reverse(s2);
	int len1 = s1r.length(), len2 = s2r.length();
	int t1, t2, t, i, carry = 0; //��λ
	string result; //���
	for (i = 0; i < len1 && i < len2; i++)
	{//��0λ��ʼ����s1r+s2r
		t1 = s1r[i] - '0';
		t2 = s2r[i] - '0';
		t = t1 + t2 + carry;
		append(result, t, carry);
	}
	for (; i < len1; i++)
	{//��iλ��ʼ����s1r
		t1 = s1r[i] - '0';
		t = t1 + carry;
		append(result, t, carry);
	}
	for (; i < len2; i++)
	{//��iλ��ʼ����s2r
		t2 = s2r[i] - '0';
		t = t2 + carry;
		append(result, t, carry);
	}
	if (carry)
	{//���н�λ
		t = 0; //�ѽ�λҲ����
		append(result, carry, t);
	}
	return reverse(result);
}

const int M = 49, N = 50; //�ַ�������󳤶�
const string MAX = string(N, '9'); //���ֵ
//v[m][n]��ʾ��m�����Ų��뵽n�������е���Сֵ
string v[M][N];

string find(int m, const string& s)
{
	int n = (int)s.length();
	if (m == 0)
	{//û�мӺţ�ԭֵ
		return s;
	}
	else if (m >= n)
	{//�Ӻ�̫�࣬�Ų���
		return MAX;
	}
	else
	{//�ӺŴ�1��ʼ��
		for (int nt = 0; nt <= n; nt++)
		{//0�����ŵ����
			v[0][nt] = s.substr(0, nt);
		}
		for (int mt = 1; mt <= m; mt++)
		{//m�����ŵ����
			for (int nt = mt + 1; nt <= n; nt++)
			{//n�����ֵ����
				string min = v[0][nt];
				for (int i = mt; i < nt; i++)
				{//���һ���Ӻŵ�λ�ã��������ҳ���
					string t1 = v[mt - 1][i];
					if (cmp(t1, min) > 0) continue;
					string t2 = s.substr(i, nt - i);
					if (cmp(t2, min) > 0) continue;
					string sum = add(t1, t2); //����Ҫ��add()
					if (cmp(min, sum) > 0) //����Ҫ��cmp()
					{//�ҵ���С��ֵ��
						min = sum;
					}
				}
				v[mt][nt] = min;
			}
		}
		return v[m][n];
	}
}

int main()
{
	string s;
	int m;

	while (cin >> m)
	{
		cin >> s;
		cout << find(m, s) << endl;
	}
	return 0;
}
