#include <iostream>
#include <iomanip>
using namespace std;
int a[10000]={0};
int main() {
//	freopen("F:\\aain.txt","r",stdin);
	const double PI = 3.1415926535897;
	const double DELTA = 0.000001;
	double max=0,min=0,val,mv=0;
	int n,m,i,count;
	
	cin>>n>>m;
	for(i=0; i<n; i++) {
		cin>>a[i];
		a[i]*=a[i];
		if(max<a[i]) max=a[i];
	}
	while(max-min>DELTA) {
		val=(max+min)/2;
//		cout<<"max="<<max<<",min="<<min<<",val="<<val;
		count=0;
		for(i=0; i<n; i++) {
			count+=a[i]/val;
		}
//		cout<<",count="<<count<<endl;
		if(count>=m+1){
			if(mv<val)mv=val;
			min=val;
		}
		else max=val;
	}
	cout<<fixed<<setprecision(3)<<mv*PI<<endl;
	return 0;
}