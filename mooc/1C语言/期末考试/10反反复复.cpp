#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	int n,m,i,j;
	string s;

	cin>>n>>s;
	vector<string> a;
	for(i=0,m=0; i<s.length(); i+=n,m++) {
		string str=s.substr(i,n);
		if(m%2) {
			reverse(str.begin(),str.end());
		}
		a.push_back(str);
	}
	for(i=0; i<n; i++) {
		for(j=0; j<m; j++) {
			cout<<a[j][i];
		}
	}
	return 0;
}
