#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
	multiset<int> mst;
	set<int> st;
	int n,i,e;
	string s;

	cin>>n;
	for(i=0; i<n; i++) {
		cin>>s>>e;
		if(s=="add") {
			st.insert(e);
			mst.insert(e);
			cout<<mst.count(e)<<endl;
		} else if(s=="del") {
			cout<<mst.count(e)<<endl;
			mst.erase(e);
		} else if(s=="ask") {
			cout<<st.count(e)<<" "<<mst.count(e)<<endl;
		}
	}
	return 0;
}
