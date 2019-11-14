#include<iostream>
using namespace std;

int main() {
	int n,m;

	cin>>n;
	for(m=0; n>0; n>>=1) {
		if(n&1) m++;
	}
	cout<<m;
	return 0;
}
