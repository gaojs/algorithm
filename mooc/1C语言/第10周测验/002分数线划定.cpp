#include<iostream>
#include<cstring>
using namespace std;
struct S {
	char n[5];
	int s;
};

S a[10000],t;
int main() {
	int n,m,i,j,s;
	cin>>n>>m;
	for(i=0; i<n; i++) {
		cin>>a[i].n>>a[i].s;
	}
	for(i=0; i<n; i++) {
		for(j=i+1; j<n; j++) {
			if(a[i].s<a[j].s||a[i].s==a[j].s&&strcmp(a[i].n,a[j].n)>0) {
				t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
	}
	s=a[m*3/2-1].s;
	for(m=0; m<n; m++) {
		if(a[m].s<s)break;
	}
	cout<<s<<" "<<m<<endl;
	for(i=0; i<m; i++) {
		cout<<a[i].n<<" "<<a[i].s<<endl;
	}
	return 0;
}