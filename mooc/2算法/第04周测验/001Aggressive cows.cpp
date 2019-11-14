#include<iostream>
using namespace std;

int a[100000]= {0};

bool ok(int a[], int n, int c, int v) {
	int i,j,d=0,dt,ct=1;
//	cout<<"--------"<<endl;
//	cout<<"ct="<<ct<<";"<<a[0]<<",";
	for(i=1; i<n; i++) {
		dt=a[i]-a[i-1];
		if(d+dt>=v) {
			ct++;
//			cout<<endl<<"ct="<<ct<<";"<<a[i]<<",";
			d=0;
		} else {
//			cout<<a[i]<<",";
			d+=dt;
		}
	}
//	cout<<endl<<"ct="<<ct<<endl;
	if(ct>=c) return true;
	return false;
}

int main() {
//	freopen("F:\\aain.txt","r",stdin);
	int n,c,i,j,t,min,max,val,mv=0;
	scanf("%d %d",&n,&c);
//	cout<<"n="<<n<<",c="<<c<<endl;
	for(i=0; i<n; i++) {
		scanf("%d",&a[i]);
		for(j=i; j>0; j--){//sort
			if(a[j]<a[j-1]) {
				t=a[j];
				a[j]=a[j-1];
				a[j-1]=t;
			} else break; 
		}
	}
//	for(i=0; i<n; i++) {
//		cout<<a[i]<<",";
//	}
//	cout<<endl;
	min=0,max=(a[n-1]-a[1])/c+1;
	while(max>=min) {
		val=(min+max)/2;
//		cout<<"min="<<min<<",max="<<max<<",val="<<val<<endl;
		if(ok(a,n,c,val)) {
			if(mv<val)mv=val;
			min=val+1;
		} else max=val-1;
	}
	cout<<mv;
}