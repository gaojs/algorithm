#include<iostream>
#include<cstring>
#include<set>
using namespace std;

multiset<int> st;
set<int> st2;
int main() {
	//freopen("F:\\aain.txt","r",stdin);
	char s[10];
	int n,m,i;
	cin>>n;
	for(i=0; i<n; i++) {
		multiset<int>::iterator it;
		cin>>s>>m;
		//cout<<"s="<<s<<",m="<<m<<endl;
		if(strcmp(s,"add")==0) {
			st.insert(m);
			st2.insert(m);
			cout<<st.count(m)<<endl;
		} else if(strcmp(s,"del")==0) {
			cout<<st.count(m)<<endl;
			st.erase(m);
			//st2.erase(m);
		} else if(strcmp(s,"ask")==0) {
			cout<<st2.count(m)<<" "<<st.count(m)<<endl;
		}		
	}
	return 0;
}