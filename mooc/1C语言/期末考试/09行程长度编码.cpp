#include<iostream>
#include <algorithm>
using namespace std;

int main() {
	freopen("F:\\in.txt","r",stdin);
	string s;

	cin>>s;
	transform(s.begin(),s.end(),s.begin(),::toupper);
//	cout<<s<<endl;
	char first=0, tmp;
	int count=0;
	for(string::iterator i=s.begin(); i!=s.end(); ++i) {
		char ch=*i;
		if(count==0) {
			cout<<"("<<ch<<",";
			first=ch;
			count=1;
		} else if(ch==first) {
			count++;
		} else {
			cout<<count<<")";
			cout<<"("<<ch<<",";
			first=ch;
			count=1;
		}
	}
	cout<<count<<")";
	return 0;
}
