#include<iostream>
#include <algorithm>
using namespace std;

int a[3000]= {0};
int b[3000]= {0};
int main() {
	int n,i;

	cin>>n;
	for(i=0; i<n; i++) {
		cin>>a[i];
		if(i>0) {
			b[i-1]=a[i]-a[i-1];
			if(b[i-1]<0)b[i-1]=-b[i-1];
		}
	}
	sort(b,b+i-1);
	for(i=0; i<n-2; i++) {
		if(b[i]!=b[i+1]-1) {
			cout<<"Not jolly";
			return 0;
		}
	}
	cout<<"Jolly";
	return 0;
}
