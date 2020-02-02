#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cmath>
#include <map>
#include <set>

using namespace std;
class MyFunc
{
// 在此处补充你的代码
private:
	int v;
public:
	MyFunc(int n)
	{//带单参数的构造函数（基本数据类型=>自定义数据类型）
		v=n;
	}
	operator MyFunc()
	{//用户自定义类的强制类型转换
		return v;
	}
	operator int()
	{//类型转换函数（自定义数据类型=>基本数据类型）
		return v;
	}
// 在此处补充你的代码
};

int main()
{
	int n;
	cin >> n;
	while(n--) 
	{
		vector<MyFunc> v;
		for (int i = 0; i < 5; ++i)
			v.push_back(MyFunc(i+1));
		int ans = 1;
		for (int i = 0; i < 5; ++i)
		{
			int m;
			cin >> m;
			ans += v[i](m);
		}
		cout << ans <<endl;
	}
}
