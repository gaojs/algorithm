#include<iostream>
using namespace std;
struct S {
	char n[10];
	int s,i;
};
int cmp(S a,S b) {
	if(a.s>=60)
		if(b.s>=60) 
			if(a.s>b.s) return 1;
			else if(a.s<b.s) return -1;
			else return b.i-a.i;
		else return 1;
	else if(b.s>=60) return -1;
	else return b.i-a.i;
}

S a[100],t;
int main() {
	int n,i,j;
	cin>>n;
	for(i=0; i<n; i++) {
		cin>>a[i].n>>a[i].s;a[i].i=i;
	}
	for(i=0; i<n; i++) {
		for(j=i+1; j<n; j++) {
			if(cmp(a[i],a[j])<0) {
				t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
	}
	for(i=0; i<n; i++) {
		cout<<a[i].n<<endl;
	}
	return 0;
}