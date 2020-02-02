#include<iostream>
#include<algorithm>
#include<vector>
#include<bitset>
using namespace std;

class Printer
{
// 在此处补充你的代码
public:
	Printer(int x){}
	
	Printer(int x, int y)
	{
		if(y>x)
		{
			cout<<y<<" ";
		}		
	}
	
	Printer(int x, string s)
	{
		if(s.length()>x)
		{
			cout<<s<<" ";
		}		
	}
}; 
// 在此处补充你的代码

int main()
{
	int t;
	cin >> t;
	while(t--) {
		int n,x;
		cin>>x>>n;
		
		vector<int> intVec;
		for(int i = 0;i < n; ++i) {
			int y;
			cin >> y;
			intVec.push_back(y);
		}
		for_each(intVec.begin(), intVec.end(), Printer(x));
		cout<<endl;
		
		vector<string> strVec;
		for(int i = 0;i < n; ++i) {
			string str;
			cin >> str;
			strVec.push_back(str);
		}
		for_each(strVec.begin(), strVec.end(), Printer(x));
		cout<<endl;
	}
	return 0;
}

