#include<iostream>
#include<set>
using namespace std;

void put(set<int> &s, int k, int x) {
	if(k<=x) {
		s.insert(k);
		put(s,2*k+1,x);
		put(s,3*k+1,x);
	}
}

int main() {
	int k,x;
	char c;
	set<int> s;

	cin>>k>>c>>x;
	put(s,k,x);
	if(s.find(x)!=s.end()) {
		cout<<"YES";
	} else {
		cout<<"NO";
	}
	return 0;
}
