#include<iostream>
#include<vector>
using namespace std;

int main() {
	vector<string> a;
	string s;

	while(cin>>s) {
		a.push_back(s);
	}
	for(vector<string>::reverse_iterator i=a.rbegin(); 
		i!=a.rend(); ++i) {
		cout<<*i<<" ";
	}
	return 0;
}
