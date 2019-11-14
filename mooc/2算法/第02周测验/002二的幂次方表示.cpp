#include<iostream>
using namespace std;

void p(int n) {
	if(n==1) {
		cout<<"2(0)";
	} else if(n==2) {
		cout<<"2";
	} else {
		int m=n,t=0;;
		while(m>1) {
			m/=2;
			t++;
		}
		cout<<"2";
		if(t>1) {
			cout<<"(";
			p(t);
			cout<<")";
		}
		m=n-(1<<t);
		if(m>0) {
			cout<<"+";
			p(m);
		}
	}
}

int main() {
//	freopen("F:\\aain.txt","r",stdin);
	int n;
	cin>>n;
	p(n);
	return 0;
}
