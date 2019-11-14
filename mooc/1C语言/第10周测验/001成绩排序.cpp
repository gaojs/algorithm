#include<iostream>
#include<cstring>
using namespace std;
struct S {
	char n[20];
	int s;
};

int main() {
	int n,i,j;
	S a[20],t;
	cin>>n;
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
	for(i=0; i<n; i++) {
		cout<<a[i].n<<" "<<a[i].s<<endl;
	}
	return 0;
}