#include<iostream>
#include <algorithm>
using namespace std;

int main() {

	string a,b,s;
	cin>>a>>b;
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
//	cout<<a<<","<<b<<endl;
	string::iterator i= a.begin(), j=b.begin();
	int t, carry=0;
	for(; i!=a.end() && j!=b.end(); i++, j++) {
		t=*i-'0'+*j-'0'+carry;
		if(t>=10) {
			s.push_back(t+'0'-10);
			carry=1;
		} else {
			s.push_back(t+'0');
			carry=0;
		}
	}
	for(; i!=a.end(); i++) {
		t=*i-'0'+carry;
		if(t>=10) {
			s.push_back(t+'0'-10);
			carry=1;
		} else {
			s.push_back(t+'0');
			carry=0;
		}
	}
	for(; j!=b.end(); j++) {
		t=*j-'0'+carry;
		if(t>=10) {
			s.push_back(t+'0'-10);
			carry=1;
		} else {
			s.push_back(t+'0');
			carry=0;
		}
	}
	if(carry) { //½øÎ»
		s.push_back('1');
	}
	//
	while(*s.rbegin()=='0'&&s.length()>1) { //È¥0
		s.pop_back();//c++11
	}
	reverse(s.begin(),s.end());
	cout<<s<<endl;
	return 0;
}