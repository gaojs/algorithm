#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;

template <class T1,class T2>
struct Closer {
// 在此处补充你的代码
	T1 n;
	T2 f;
	
	Closer(T1 t1, T2 t2) :n(t1), f(t2) {
	}
	
	bool operator()(const T1&a, const T1&b) {
		int d1=f(a,n), d2=f(b,n);
		if (d1 == d2)
			return a < b;
		else return d1<d2;
	}
// 在此处补充你的代码end
};

int Distance1(int n1,int n2) {
	return abs(n1-n2);
}

int Distance2(const string & s1, const string & s2) {
	return abs((int)s1.length()- (int) s2.length());
}

int a[10] = { 0,3,1,4,7,9,20,8,10,15};
string b[6] = {"American","Jack","To","Peking","abcdefghijklmnop","123456789"};

int main() {
	freopen("F:\\aain.txt","r",stdin);
	int n;
	string s;
	while( cin >> n >> s ) {
		sort(a,a+10,Closer<int ,int (*)(int, int)> (n,Distance1));
		for(int i = 0; i < 10; ++i)
			cout << a[i] << "," ;
		cout << endl;
		sort(b,b+6,Closer<string,int (*)(const string &,const string &)> (s,Distance2));
		for(int i = 0; i < 6; ++i)
			cout << b[i] << "," ;
		cout << endl;
	}
	return 0;
}
