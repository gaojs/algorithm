#include<iostream>
using namespace std;
int a[100000]= {0};

bool ok(int a[],int n, int m, int v) {
	int i=0,s,c;
//	cout<<endl<<"-----------"<<endl;
//	cout<<"i="<<i<<",";
	for(s=c=i=0; i<n; i++) {
		if(a[i]>v) return false;
		else if(s+a[i]>v) {
			c++;
//			cout<<"c="<<c<<","<<endl;
//			cout<<"i="<<i<<","<<a[i]<<",";
			s=a[i];
		} else {
//			cout<<a[i]<<",";
			s+=a[i];
		}
	}
	if(s>0)c++;
//	cout<<"c="<<c<<endl;
//	cout<<"-----------"<<endl;
	if(c>m) return false;
	return true;
}

int main() {
//	freopen("F:\\aain.txt","r",stdin);
	int n,m,i,sum=0,mx=0,min,max,val,mv;
	cin>>n>>m;
//	cout<<"n="<<n<<",m="<<m<<endl;
	for(i=0; i<n; i++) {
		cin>>a[i];
		if(mx<a[i])mx=a[i];
		sum+=a[i];
	}
	min=mx,max=sum,mv=sum;
	while(max>=min) {
		val=(max+min)/2;
//		cout<<"min="<<min<<",max="<<max<<",val="<<val<<endl;
		if(ok(a,n,m,val)){
			if(mv>val)mv=val;
			max=val-1;
		}
		else min=val+1;
	}
	cout<<mv;
	return 0;
}