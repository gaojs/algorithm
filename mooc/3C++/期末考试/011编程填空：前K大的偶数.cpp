#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <string>
#include <map>
#include <set>
using namespace std;

class MyQueue
{
// 在此处补充你的代码
public:
	int n;
	multiset<int>st;
	MyQueue(int nn):n(nn){}
	
	friend istream & operator>>(istream& is, MyQueue&q)
	{
		int t;
		
		is>>t;
		q.st.insert(t);
	}
	friend ostream &operator<<(ostream & os, const MyQueue&q) 
	{
		int t; 
		set<int>::reverse_iterator it;
		for(t=0,it=q.st.rbegin();t<q.n&&it!=q.st.rend();++it)
		{
			if(*it%2==0)
			{
				os<<*it<<" ";
				++t; 
			}			
		}
	}
// 在此处补充你的代码
};

int main()
{
	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		MyQueue q(k);
		for (int i = 0; i < n; ++i)
			cin >> q;
		cout<<q;
		cout << endl;
	}
	return 0; 
}
